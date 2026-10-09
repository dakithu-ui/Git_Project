#include "Customer.h"

int Customer::getId() const {
    return Customer_id;
}

std::string Customer::getName() const {
    return Name;
}

double Customer::getAccount_Balance() const {
    return Account_Balance;
}

std::vector<int> Customer::getTransaction_History() const {
    return Transaction_History;
}

void Customer::setid(const int& i) {
    Customer_id = i;
}

void Customer::addTransaction(const int& i) {
    Transaction_History.push_back(i);
}