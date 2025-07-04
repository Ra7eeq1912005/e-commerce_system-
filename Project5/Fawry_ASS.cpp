#include <iostream>
#include "Customer.h"
#include "ProductWithShipping.h"
#include "Cart.h"
#include "CheckoutService.h"
#include "Product.h"

using namespace std;

int main() {
    try {
         
        Customer customer("Ali", 1000.0);

         
        Product* cheese = new ProductWithShipping("Cheese", 100.0, 10, 0.4);     
        Product* biscuits = new ProductWithShipping("Biscuits", 150.0, 5, 1.0);   
        Product* scratchCard = new Product("Scratch Card", 50.0, 20);            

         
        Cart cart;
        cart.add(cheese, 2);        
        cart.add(biscuits, 1);     
        cart.add(scratchCard, 1);   

         
        CheckoutService::checkout(customer, cart);

         
        delete cheese;
        delete biscuits;
        delete scratchCard;
    }
    catch (const exception& e) {
        cerr << "Checkout failed: " << e.what() << endl;
    }

    return 0;
}
