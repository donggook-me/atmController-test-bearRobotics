#ifndef BANK_FACTORY_H
#define BANK_FACTORY_H

#include "bank_api.h"
#include <string>

class BankFactory {
public:
    virtual BankAPI* createBankAPI(const std::string& card_id) const = 0;
};

class MockBankFactory : public BankFactory {
public:
    BankAPI* createBankAPI(const std::string& card_id) const override;
};

#endif // BANK_FACTORY_H