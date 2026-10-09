#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H

#include "Book.h"
#include "Customer.h"
#include "VipCustomer.h"
#include "Transaction.h"
#include <iostream>

inline void to_json(json& j, const Book& b) {
    j["Released_Year"] = b.getYear();
    j["Name"] = b.getName();
    j["Author"] = b.getAuthor();
    j["Genre_List"] = b.getGenre();
    j["id"] = b.getId();
}

inline void from_json(const json& j, Book& b) {
    b = Book(
        j.at("Released_Year").get<int>(),
        j.at("Name").get<std::string>(),
        j.at("Author").get<std::string>(),
        j.at("Genre_List").get<std::vector<Genre>>(),
        j.at("id").get<int>()
        );
}

inline void to_json(json& j, const VipCustomer& v) {
    j["Customer_id"] = v.getId();
    j["Name"] = v.getName();
    j["Account_Balance"] = v.getAccount_Balance();
    j["Transaction_History"] = v.getTransaction_History();
    j["VipLevel"] = v.getVipLevel();
    j["Discount"] = v.getDiscount();
    j["Point"] = v.getPoint();
}

inline void from_json(const json& j, VipCustomer& v) {
    v = VipCustomer(
        j.at("Name").get<std::string>(),
        j.at("Customer_id").get<int>(),
        j.at("Account_Balance").get<double>(),
        j.at("Transaction_History").get<std::vector<int>>(),
        j.at("VipLevel").get<VipClass>(),
        j.at("Discount").get<double>(),
        j.at("Point").get<int>()
        );
}
#endif // BOOKMANAGER_H
