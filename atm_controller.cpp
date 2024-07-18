#include "atm_controller.h"

ATMController::ATMController(BankFactory* bank_factory)
    : bank_factory(bank_factory), bank_api(nullptr) {}

bool ATMController::insertCard(const std::string& card_id) {
    currentCardID = card_id;
    bank_api = bank_factory->createBankAPI(card_id);
    if (!bank_api) {
        throw ATMException("Unable to connect to bank system.");
    }
    return true;
}

bool ATMController::enterPin(const std::string& pin) {
    if (!bank_api->validatePin(currentCardID, pin)) {
        throw ATMException("Invalid PIN entered.");
    }
    return true;
}

bool ATMController::selectAccount(const std::string& account_id) {
    if (bank_api->hasAccount(account_id)) {
        currentAccountID = account_id;
        return true;
    }
    throw ATMException("Account not found.");
}

int ATMController::seeBalance() const {
    if (!currentAccountID.empty()) {
        return bank_api->getBalance(currentAccountID);
    }
    throw ATMException("No account selected.");
}

bool ATMController::deposit(int amount) {
    if (!currentAccountID.empty()) {
        return bank_api->deposit(currentAccountID, amount);
    }
    throw ATMException("No account selected.");
}

bool ATMController::withdraw(int amount) {
    if (!currentAccountID.empty()) {
        return bank_api->withdraw(currentAccountID, amount);
    }
    throw ATMException("No account selected.");
}

void ATMController::ejectCard() {
    currentAccountID.clear();
    currentCardID.clear();
    bank_api = nullptr;
}