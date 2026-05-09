//WICHTIGE FRAGE: WIESO DARF MAN MANCHMAL DIREKT AUF DAS ATTRIBUT ZUGREIFEN, ABER MANCHMAL NUR ÜBER EINE GETTER METHODE???

//File header fehlt 
#include <iostream>
#include <string>
#include <iomanip> //braucht man nicht
using namespace std; //Fehler 1 - using sollte nicht verwendet werden, da es gegen die Coding-Conventions geht -> einfach weglassen

class Article {
public: //Fehler 2 - Attribute sollen private sein -> gegen die Conventions -> problematisch, da Zugriff nicht geschützt ist
    string name;
    double price;
    int stock;
    string* category; //Pointer und Speicherallokierung hier nicht nötig -> nicht benutzen
    int id;

    Article(string name, double price, int stock, string category, int id) { //Fehler 3 - Konstruktor sollte außerhalb der class definiert werden
        name = name; //Fehler 4 - man sollte das nicht im Konstruktor selbst machen, sondern mit : ... (ohne this)
        price = price; //wenn man das so machen möchte, dann sollte man this verwenden
        stock = stock;
        this->id = id;
        this->category = new string; //sollte nicht dynamisch gemacht werden
        *this->category = category;
    }

    //Fehler 5 - Destruktor fehlt -> hinzufügen -> unbedingt auch mit delete

    void setPrice(double price) {
        price = price; //Fehler 11 - hier sollte this verwendet werden und auf negative Werte prüfen
    }

    void sell(int amount) { //Fehler 6 - sollte auf negative Werte geprüft werden und ob noch so viele im Lager sind wie gekauft werden sollen
        stock = stock - amount;
    }

    void restock(int amount) { //Fehler 12 - hier sollte geprüft werden, ob amount positiv ist
        this->stock += amount; //this kann hier weggelassen werden
    }

    double applyDiscount(double percent) { //Fehler 7 - sollte auf gültige Werte geprüft werden
        price = price - price * percent / 100;
        return price;
    }

    double getPrice() { //Fehler 8 - sollte const sein
        return price;
    }

    bool isAvailable() { //Fehler 9 - sollte auch const sein außerdem sollte man hier laut den Conventions geschweifte Klammern hinzufügen
        if (stock > 0)
            return true;
        else
            return false;
    }

    void printInfo() { //Fehler 10 - es sollten die getFunktionen verwendet werden + const verwenden
        cout << "Article: " << name << endl;
        cout << "Category: " << *category << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
        cout << "ID: " << id << endl;
    }
};

int main() {
    Article a("Laptop", 999.99, 10, "Electronics", 101); //Fehler 12 - evtl. sollte hier nicht a sondern ein sinnvoller Name verwendet werden + keine magic Numbers

    //Fehler 13 - werte alle mist
    a.sell(15);
    a.restock(-5); 
    a.price = -100;
    a.applyDiscount(150);

    if (a.isAvailable()) cout << "Article available" << endl; //Fehler 14 - if Abfrage sauber hinschreiben

    a.printInfo();
}

//Task 2: 
//new sollte nicht verwendet werden, da es hier nicht unbedingt nötig ist
//wenn man mehrere Objekte dieser Klasse kopiert, dann hat man das Problem, dass 
//bei der delete-Funktion versucht wird mehrmals den selben Pointer zu deleten
//man bräuchte wieder einen Copy-Construktor, oder man benutzt einfach kein new
//manche Methoden sollten als const markiert werden, da sie sowieso nichts bearbeiten
//-> durch const stellt man sicher, dass außversehen nichts falsches gemacht wird
//Risiken: man kann das von überhall her bearbeiten