#pragma once
#include <string>
using namespace std;
class ShippableProduct {
public:
    virtual  string getName() const = 0;
    virtual double getWeight() const = 0;
    virtual ~ShippableProduct() {}
};
