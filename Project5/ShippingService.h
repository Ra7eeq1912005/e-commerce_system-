#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "ShippableProduct.h"

class ShippingService {
public:
    static void ship(const std::vector<ShippableProduct*>& items) {
        if (items.empty()) {
            std::cout << "** No shippable items. **\n";
            return;
        }

        std::cout << "** Shipment notice **\n";
        double totalWeight = 0.0;

        for (const auto& item : items) {
            int weightInGrams = static_cast<int>(item->getWeight() * 1000);
            std::cout << std::left << std::setw(20)
                << item->getName()
                << weightInGrams << "g\n";

            totalWeight += item->getWeight();
        }

        std::cout << "Total package weight: "
            << std::fixed << std::setprecision(1)
            << totalWeight << "kg\n";
    }
};
