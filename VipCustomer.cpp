#include "VipCustomer.h"

VipClass VipCustomer::getVipLevel() const {
    return VipLevel;
}

double VipCustomer::getDiscount() const {
    return Discount;
}

int VipCustomer::getPoint() const {
    return Point;
}

