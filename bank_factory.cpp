#include "bank_factory.h"
#include "bank_api.h"

BankAPI* MockBankFactory::createBankAPI(const std::string& card_id) const {
    // For simplicity, always return an instance of MockBankAPI
    return new MockBankAPI();
}