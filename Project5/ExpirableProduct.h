#pragma once
#include "Product.h"
#include <ctime>
#include <iostream>
#include<string>

class ExpirableProduct : public Product {
public:
    struct Date {
        int day, month, year;
    };

private:
    Date expireDate;

public:
    ExpirableProduct(string  name, double price, int quantity, Date expireDate_ent)
        : Product(name, price, quantity), expireDate(expireDate_ent) {
    }

    bool isExpired() const override {
        time_t now = time(0);
        tm localTime;
        localtime_s(&localTime, &now);   

        int todayYear = 1900 + localTime.tm_year;
        int todayMonth = 1 + localTime.tm_mon;
        int todayDay = localTime.tm_mday;

        if (expireDate.year < todayYear) return true;
        if (expireDate.year > todayYear) return false;

        if (expireDate.month < todayMonth) return true;
        if (expireDate.month > todayMonth) return false;

        return expireDate.day < todayDay;

    }

    Date getExpiryDate() const {
        return expireDate;
    }
};
 