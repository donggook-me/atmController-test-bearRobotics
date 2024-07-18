#ifndef BANK_API_H
#define BANK_API_H

#include <string>
#include <unordered_map>

class BankAPI {
public:
    virtual bool validatePin(const std::string& card_id, const std::string& pin) const = 0;
    virtual bool hasAccount(const std::string& account_id) const = 0;
    virtual int getBalance(const std::string& account_id) const = 0;
    virtual bool deposit(const std::string& account_id, int amount) = 0;
    virtual bool withdraw(const std::string& account_id, int amount) = 0;
};

class MockBankAPI : public BankAPI {
public:
    MockBankAPI();
    bool validatePin(const std::string& card_id, const std::string& pin) const override;
    bool hasAccount(const std::string& account_id) const override;
    int getBalance(const std::string& account_id) const override;
    bool deposit(const std::string& account_id, int amount) override;
    bool withdraw(const std::string& account_id, int amount) override;

private:
    struct Account {
        std::string account_id;
        int balance;
    };
    std::unordered_map<std::string, Account> accounts;
    std::unordered_map<std::string, std::string> cardPins;
};

#endif // BANK_API_H