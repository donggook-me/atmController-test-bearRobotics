#ifndef ATM_CONTROLLER_H
#define ATM_CONTROLLER_H

#include <string>
#include "bank_api.h"
#include "bank_factory.h"

class ATMController {
public:
    ATMController(BankFactory* bank_factory);
    bool insertCard(const std::string& card_id);
    bool enterPin(const std::string& pin);
    bool selectAccount(const std::string& account_id);
    int seeBalance() const;
    bool deposit(int amount);
    bool withdraw(int amount);
    void ejectCard();

private:
    BankFactory* bank_factory;
    BankAPI* bank_api;
    std::string currentCardID;
    std::string currentAccountID;
};

class ATMException : public std::runtime_error {
public:
    explicit ATMException(const std::string& message) : std::runtime_error(message) {}
};

#endif // ATM_CONTROLLER_H