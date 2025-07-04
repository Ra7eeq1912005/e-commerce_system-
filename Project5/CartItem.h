#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "Product.h"

class CartItem {
private:
    Product* product;  
    int productQuantity;

public:
    CartItem(Product* product, int productQuantity)
        : product(product), productQuantity(productQuantity) {
    }

    double getTotalPrice() const {
        return product->getPrice() * productQuantity;
    }

    Product* getProduct() const {
        return product;
    }

    int getQuantity() const {
        return productQuantity;
    }
};
