#pragma once
#include <iostream>
#include <iomanip>
#include "Customer.h"
#include "Cart.h"
#include "ShippingService.h"

using namespace std;

class CheckoutService {
public:
    static void checkout(Customer& customer, Cart& cart) {
        if (cart.isEmpty()) {
            throw runtime_error("Error: Cart is empty.");
        }

        for (const auto& item : cart.getItems()) {
            if (item.getProduct()->isExpired()) {
                throw runtime_error("Error: Cart contains expired item: " + item.getProduct()->getProductName());
            }
        }

        double subtotal = cart.getSubtotal();
        double shippingFee = 0.0;
        double weights = 0.0;
        vector<ShippableProduct*> shippable = cart.getShippableItems();
        for (auto sp : shippable) {
            //shippingFee += 15.0;
            weights += sp->getWeight();
             
        }
        //cout << weights << "\n";
        shippingFee = weights*1000 * 0.03;

        double totalAmount = subtotal + shippingFee;

        if (customer.getBalance() < totalAmount) {
            throw runtime_error("Error: Insufficient customer balance.");
        }

        if (!shippable.empty()) {
            ShippingService::ship(shippable);
        }

        customer.deductBalance(totalAmount);

        cout << "** Checkout receipt **\n";
        for (const auto& item : cart.getItems()) {
            cout << left << setw(20)
                 << (to_string(item.getQuantity()) + "x " + item.getProduct()->getProductName());
            cout << fixed << setprecision(0)
                 << item.getTotalPrice() << "\n";
        }

        cout << "----------------------\n";
        cout << left << setw(18) << "Subtotal" << fixed << setprecision(0) << subtotal << "\n";
        cout << left << setw(18) << "Shipping" << shippingFee << "\n";
        cout << left << setw(18) << "Amount" << totalAmount << "\n";
        cout << "Remaining Balance: " << customer.getBalance() << "\n";
         
    }
};
