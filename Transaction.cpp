#include "Transaction.h"

void Transaction::setid(const int& i) {
    Transaction_id = i;
}

int Transaction::getTransaction_id() const {
    return Transaction_id;
}

int Transaction::getBook_id() const {
    return Book_id;
}

int Transaction::getCustomer_id() const {
    return Customer_id;
}

