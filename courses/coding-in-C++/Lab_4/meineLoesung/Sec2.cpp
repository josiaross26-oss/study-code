#include <iostream>

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

class Form //Abstrakte Klasse: man kann kein Objekt von Form mehr erzeugen -> Pointer gehen noch
{
public:
	virtual ~Form() = default; //es braucht einen Destuktor, da abgeleitete Klassen die Funktion mit einem Zeiger aufrufen -> dieser Zeiger muss auch wieder deleted werden
	virtual double flaecheBerechnen() const = 0; //das ist nur eine Vorlage, da es sich um eine Basisklasse handelt -> sollte virtual sein, damit abgeleitete Klassen diese überschreiben können
	void printFlaeche() const;
};

void Form::printFlaeche() const
{
	std::cout << "Flaeche = " << flaecheBerechnen() << std::endl;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

class Kreis : public Form
{
public:
	Kreis(double radius);
	double flaecheBerechnen() const override; //override ist sinnvoll, weil damit sichergestellt werden kann, dass die abgeleitete Klasse die virtuelle Funktion der Basisklasse korrekt überschreibt

private:
	double radius;
	static constexpr double PI = 3.141592653589793;
};

Kreis::Kreis(double radius) 
	: radius(radius)
{
}

double Kreis::flaecheBerechnen() const
{
	return PI * radius * radius;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

class Rechteck : public Form
{
public:
	Rechteck(double laenge, double breite);
	double flaecheBerechnen() const override;

private:
	double laenge;
	double breite;
};

Rechteck::Rechteck(double laenge, double breite)
	: laenge(laenge), breite(breite)
{
}
 
double Rechteck::flaecheBerechnen() const
{
	return laenge * breite;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

int main()
{
	Kreis k1(5.0);
	Rechteck r1(3.0, 6.0);
	Kreis k2(1.0);
	Rechteck r2(2.0, 4.0);

	k1.printFlaeche();
	r1.printFlaeche();
	k2.printFlaeche();
	r2.printFlaeche();

	std::cout << "\n\n";

	Form* arr[4]; //WICHTIG BASISKLASSE KANN ALLE OBJEKTE ANSPRECHEN!!! -> POLYMORPHISMUS
	arr[0] = &k1; //AUßERDEM: WICHTIG, DASS ES EIN POINTER IST,
	arr[1] = &k2; //NUR SO KANN MAN MEHRERE ABGELEITETE KLASSEN MIT EINER BASISKLASSE ANSPRECHEN
	arr[2] = &r1; //OBJECT SLICING BEI ZB:
	arr[3] = &r2; //Form arr[4]; -> arr[0] = k1;

	for (Form* temp : arr)
	{
		temp->printFlaeche();
	}


	return 0;
}

//virtual wird in C++ verwendet, damit bei Vererbung die passende Methode zur Laufzeit ausgewählt wird.Wenn also ein Objekt einer abgeleiteten Klasse über einen Zeiger oder eine Referenz der Basisklasse angesprochen wird, sorgt virtual dafür, dass die überschreibende Methode der tatsächlichen Klasse aufgerufen wird.
//
//Overriding bedeutet, dass eine abgeleitete Klasse eine Methode der Basisklasse mit gleicher Signatur neu implementiert.Zum Beispiel überschreibt Kreis die Methode flaecheBerechnen() von Form.Overloading bedeutet dagegen, dass mehrere Methoden denselben Namen haben, aber unterschiedliche Parameter besitzen.
//
//Eine rein virtuelle Funktion ist eine virtuelle Methode ohne eigene normale Implementierung in der Basisklasse.Sie wird mit = 0 deklariert:
//
//virtual double flaecheBerechnen() const = 0;
//
//Dadurch wird die Klasse abstrakt.
//
//Abstrakte Klassen sind nützlich, weil sie als gemeinsame Vorlage für abgeleitete Klassen dienen.Man kann festlegen, welche Methoden jede konkrete Unterklasse besitzen muss, ohne dass die Basisklasse selbst ein vollständiges Objekt darstellt.Zum Beispiel ist Form nur ein allgemeines Konzept, während Kreis und Rechteck konkrete Formen sind.