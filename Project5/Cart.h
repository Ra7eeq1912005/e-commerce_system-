#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

#include "CartItem.h"
#include "Product.h"
#include "ShippableProduct.h"

class Cart {
private:
    vector<CartItem> items;

public:
    Cart() {}

    void add(Product* newProduct, int quantity) {
        if (newProduct->isExpired()) {
            throw runtime_error("Cannot add expired product: " + newProduct->getProductName());
        }

        if (newProduct->getQuantity() < quantity) {
            throw runtime_error("Not enough stock for: " + newProduct->getProductName());
        }

        newProduct->reduceQuantity(quantity);  
        CartItem newCartItem(newProduct, quantity);
        items.push_back(newCartItem);
    }

    bool isEmpty() const {
        return items.empty();
    }

    vector<CartItem> getItems() const {
        return items;
    }

    double getSubtotal() const {
        double sum = 0.0;
        for (const auto& item : items) {
            sum += item.getTotalPrice();
        }
        return sum;
    }

    
    vector<ShippableProduct*> getShippableItems() const {
        vector<ShippableProduct*> shipList;
        for (const auto& item : items) {
            Product* p = item.getProduct();
            if (p->isShippable()) {
                ShippableProduct* sp = dynamic_cast<ShippableProduct*>(p);
                if (sp != nullptr) {
                    shipList.push_back(sp);
                }
            }
        }
        return shipList;
    }
};
