#include "Sec5_Header_Korrekt.hpp"
#include <iostream>
#include <string>

Article::Article(std::string name, double price, int stock, std::string category, int id)
    : name(name), price(price), stock(stock), category(category), id(id)
{
    if (price < 0.0)
    {
        price = 0.0;
    }

    if (stock < 0)
    {
        stock = 0;
    }
}

//Wieso bei Musterlösung alle Funktionen nicht void sondern bool? -> muss man das so machen, oder kann ich Fehler wie hier bearbeiten?
void Article::setPrice(double price) 
{
    if (price < 0) //Verschenken ist erlaubt
    {
        std::cout << "Bitte setze einen sinnvollen Preis\n";
        return;
    }
    this->price = price;
}

void Article::sell(int amount) 
{
    if (amount <= 0 || amount > stock)
    {
        std::cout << "Keine gueltige Menge\n";
        return;
    }
    stock = stock - amount;
}

void Article::restock(int amount) 
{
    if (amount <= 0)
    {
        std::cout << "Bitte fuege eine sinnvolle Menge hinzu\n";
        return;
    }
    stock += amount;
}

double Article::applyDiscount(double percent) 
{
    if (percent > 100 || percent < 0)
    {
        std::cout << "Bitte gebe einen sinnvollen Rabatt ein\n";
        return price;
    }
    price = price - price * percent / 100;
    return price;
}

bool Article::isAvailable() const
{
    return stock > 0;
}

double Article::getPrice() const
{
    return price;
}

const std::string& Article::getName() const
{
    return name;
}

int Article::getID() const
{
    return id;
}

int Article::getStock() const
{
    return stock;
}

const std::string& Article::getCategory() const
{
    return category;
}

//Wieso in Musterlösung hier nicht die get Funktionen verwendet?
void Article::printInfo() const 
{
    std::cout << "Article: " << getName() << std::endl;
    std::cout << "Category: " << getCategory() << std::endl;
    std::cout << "Price: " << getPrice() << std::endl;
    std::cout << "Stock: " << getStock() << std::endl;
    std::cout << "ID: " << getID() << std::endl;
}