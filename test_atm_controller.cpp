#include <iostream>
#include "atm_controller.h"
#include "bank_factory.h"
#include "bank_api.h"

void testATM() {
    MockBankFactory bank_factory;
    ATMController atm(&bank_factory);

    // Test case 1: Valid card, valid PIN, valid account, see balance, deposit, withdraw
    try {
        if (atm.insertCard("card1")) {
            std::cout << "Card 1 inserted successfully.\n";
            if (atm.enterPin("1234")) {
                std::cout << "PIN entered successfully.\n";
                if (atm.selectAccount("12345")) {
                    std::cout << "Account selected successfully.\n";
                    std::cout << "Balance: $" << atm.seeBalance() << "\n"; // Should print 500
                    atm.deposit(200);
                    std::cout << "Balance after deposit: $" << atm.seeBalance() << "\n"; // Should print 700
                    atm.withdraw(300);
                    std::cout << "Balance after withdrawal: $" << atm.seeBalance() << "\n"; // Should print 400
                }
                atm.ejectCard();
            }
        }
    } catch (const ATMException& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
    }

    // Test case 2: Valid card, invalid PIN
    try {
        if (atm.insertCard("card2")) {
            std::cout << "Card 2 inserted successfully.\n";
            if (atm.enterPin("wrong_pin")) {
                std::cout << "PIN entered successfully.\n"; // Should not reach here
            }
        }
    } catch (const ATMException& ex) {
        std::cerr << "Error: " << ex.what() << "\n"; // Should print "Invalid PIN entered."
    }

    // Test case 3: Withdraw more than balance
    try {
        if (atm.insertCard("card1")) {
            std::cout << "Card 1 inserted successfully.\n";
            if (atm.enterPin("1234")) {
                std::cout << "PIN entered successfully.\n";
                if (atm.selectAccount("12345")) {
                    std::cout << "Account selected successfully.\n";
                    atm.withdraw(1000); // Should throw an exception
                }
            }
        }
    } catch (const ATMException& ex) {
        std::cerr << "Error: " << ex.what() << "\n"; // Should print "Insufficient funds."
    }

    // Test case 4: Valid card from another bank, valid PIN, valid account
    try {
        if (atm.insertCard("card3")) {
            std::cout << "Card 3 inserted successfully.\n";
            if (atm.enterPin("1111")) {
                std::cout << "PIN entered successfully.\n";
                if (atm.selectAccount("22345")) {
                    std::cout << "Account selected successfully.\n";
                    std::cout << "Balance: $" << atm.seeBalance() << "\n"; // Should print 800
                    atm.deposit(300);
                    std::cout << "Balance after deposit: $" << atm.seeBalance() << "\n"; // Should print 1100
                    atm.withdraw(100);
                    std::cout << "Balance after withdrawal: $" << atm.seeBalance() << "\n"; // Should print 1000
                }
                atm.ejectCard();
            }
        }
    } catch (const ATMException& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
    }

    // Test case 5: Valid card from another bank, invalid PIN
    try {
        if (atm.insertCard("card4")) {
            std::cout << "Card 4 inserted successfully.\n";
            if (atm.enterPin("wrong_pin")) {
                std::cout << "PIN entered successfully.\n"; // Should not reach here
            }
        }
    } catch (const ATMException& ex) {
        std::cerr << "Error: " << ex.what() << "\n"; // Should print "Invalid PIN entered."
    }
}

int main() {
    testATM();
    return 0;
}