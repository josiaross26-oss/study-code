#include "Sec5_Header_Korrekt.hpp"
#include <iostream>

int main() {
    const double preis = 499.99;
    const int anzahl = 10;
    const int nummer = 101;

    Article laptop("Laptop", preis, anzahl, "Electronics", nummer);

    laptop.sell(6);
    laptop.restock(5);
    laptop.setPrice(100);
    laptop.applyDiscount(10);

    if (laptop.isAvailable())
    {
        std::cout << "Article available" << std::endl;
    }

    laptop.printInfo();
}