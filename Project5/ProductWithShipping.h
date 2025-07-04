#pragma once
#include "Product.h"
#include "ShippableProduct.h"

class ProductWithShipping : public Product, public ShippableProduct {
private:
    double weight;

public:
    ProductWithShipping(string name, double price, int quantity, double weight)
        : Product(name, price, quantity), weight(weight) {
    }

    bool isShippable() const override {
        return true;
    }

    double getWeight() const override {
        return weight;
    }

    string getName() const override {
        return getProductName();
    }
};
