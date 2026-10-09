#ifndef VIPCUSTOMER_H
#define VIPCUSTOMER_H

#include "Customer.h"
#include <ostream>
#include "json.hpp"

enum class VipClass{
    Silver,
    Gold,
    Platinum
};

NLOHMANN_JSON_SERIALIZE_ENUM(VipClass, {
                                         {VipClass::Silver, "Silver"},
                                        {VipClass::Gold, "Gold"},
                                        {VipClass::Platinum, "Platinum"}
})

inline std::string VipClasstoString(VipClass v) {
    switch(v) {
    case VipClass::Gold: return "Gold";
    case VipClass::Platinum: return "Platinum";
    case VipClass::Silver: return "Silver";
    }
}

inline std::ostream& operator<<(std::ostream& os, const VipClass& v) {
    os << VipClasstoString(v);
    return os;
}

class VipCustomer : public Customer{
private:
    VipClass VipLevel;
    double Discount;
    double Point;
public:
    VipCustomer() = default;
    VipCustomer(std::string Name, int C_id, double Account_Balance, std::vector<int> Transaction_History, VipClass VipLevel, double Discount, int Point) :
        Customer(C_id, Name, Account_Balance, Transaction_History),
        VipLevel(VipLevel),
        Discount(Discount),
        Point(Point) {}

    VipCustomer(std::string Name, int C_id, VipClass VipLevel, double Discount) :
        Customer(Name, C_id),
        VipLevel(VipLevel),
        Discount(Discount),
        Point(0) {}

    bool isVip() const override{ return true;} ;
    VipClass getVipLevel() const;
    double getDiscount() const;
    int getPoint() const;

    void addPoint(const int& a);
};

#endif // VIPCUSTOMER_H
