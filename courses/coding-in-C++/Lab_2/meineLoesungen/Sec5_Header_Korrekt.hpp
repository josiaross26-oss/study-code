#ifndef SEC5_HEADER_KORREKT
#define SEC5_HEADER_KORREKT

#include <string>

class Article {

private:
    std::string name;
    double price;
    int stock;
    std::string category;
    int id;


public:
    //Destruktor braucht man nicht, da keine dynamische Speicherverwaltung -> delete braucht man nicht -> kein Destruktor nötig
    Article(std::string name, double price, int stock, std::string category, int id);

    void setPrice(double price);

    void sell(int amount);

    void restock(int amount);

    double applyDiscount(double percent);

    bool isAvailable() const;

    double getPrice() const;

    const std::string& getName() const;

    int getID() const;

    int getStock() const;

    const std::string& getCategory() const;

    void printInfo() const;
};

#endif // !"SEC5_HEADER_KORREKT"
