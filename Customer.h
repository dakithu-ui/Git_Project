#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Transaction.h"
#include "json.hpp"

#include <string>
#include <vector>

class Customer{
private:
    int Customer_id;
    std::string Name;
    double Account_Balance;
    std::vector<int> Transaction_History;
public:
    Customer() = default;
    Customer(std::string Name, int C_id) :
        Name(Name),
        Customer_id(C_id),
        Account_Balance(0)
    {}

    Customer(int C_id, std::string Name, double Account_Balance, std::vector<int> History) :
        Customer_id(C_id),
        Name(Name),
        Account_Balance(Account_Balance),
        Transaction_History(History) {}

    int getId() const;
    std::string getName() const;
    double getAccount_Balance() const;
    std::vector<int> getTransaction_History() const;

    void setid(const int& i);
    void addTransaction(const int& i);

    virtual bool isVip() const { return false;} ;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(
        Customer,
        Customer_id,
        Name,
        Account_Balance,
        Transaction_History
    )

    virtual ~Customer() = default;
};

#endif // CUSTOMER_H
