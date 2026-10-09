#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Book.h"
#include "json.hpp"

class Transaction {
private:
    int Transaction_id;
    int Book_id;
    int Customer_id;
    bool isReturned;
public:
    Transaction() = default;
    Transaction(int t_id, int b_id, int c_id) :
        Transaction_id(t_id),
        Book_id(b_id),
        Customer_id(c_id),
        isReturned(false) {}

    void setid(const int& i);
    int getTransaction_id() const;
    int getBook_id() const;
    int getCustomer_id() const;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(
        Transaction,
        Transaction_id,
        Book_id,
        Customer_id,
        isReturned)
};

#endif // TRANSACTION_H
