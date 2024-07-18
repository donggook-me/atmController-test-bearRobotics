#include "bank_api.h"

MockBankAPI::MockBankAPI() {
    // Initialize mock accounts and card PINs
    accounts["12345"] = {"12345", 500};
    accounts["67890"] = {"67890", 1000};

    cardPins["card1"] = "1234";
    cardPins["card2"] = "5678";
}

bool MockBankAPI::validatePin(const std::string& card_id, const std::string& pin) const {
    auto it = cardPins.find(card_id);
    return it != cardPins.end() && it->second == pin;
}

bool MockBankAPI::hasAccount(const std::string& account_id) const {
    return accounts.find(account_id) != accounts.end();
}

int MockBankAPI::getBalance(const std::string& account_id) const {
    auto it = accounts.find(account_id);
    if (it != accounts.end()) {
        return it->second.balance;
    }
    throw std::runtime_error("Account not found.");
}

bool MockBankAPI::deposit(const std::string& account_id, int amount) {
    auto it = accounts.find(account_id);
    if (it != accounts.end() && amount > 0) {
        it->second.balance += amount;
        return true;
    }
    return false;
}

bool MockBankAPI::withdraw(const std::string& account_id, int amount) {
    auto it = accounts.find(account_id);
    if (it != accounts.end() && amount > 0 && it->second.balance >= amount) {
        it->second.balance -= amount;
        return true;
    }
    return false;
}