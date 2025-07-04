#pragma once
#include <iostream>
#include <string>
using namespace std;

 class Product { //abstract 
protected:
     string name;
    double price;
    int quantity;

public:
    Product( string name, double price, int quantity)
        : name(name), price(price), quantity(quantity) {
    }

    virtual ~Product() {}  

     string getProductName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    int getQuantity() const {
        return quantity;
    }

    void reduceQuantity(int reductionNum) {
        if (reductionNum > quantity) {
            throw std::runtime_error("Reduction exceeds quantity");
        }
        quantity -= reductionNum;
    }

    
    virtual bool isExpired() const {
        return false;
    }

    virtual bool isShippable() const {
        return false;
    }
};
