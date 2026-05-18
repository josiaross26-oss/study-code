#ifndef SEC1_HEADER
#define SEC1_HEADER

#include <string>
#include <vector>

class Inhalt;
class Kurs;
class Benutzer;
class Lektion;


class Plattform
{
private:
	std::string name;
	std::vector<Kurs> kurse;
	std::vector<Benutzer*> registrierte_benutzer;

public:
	Plattform(const std::string& name);
	void kurs_hinzufuegen(const std::string& name, const std::string& beschreibung);
	void benutzer_hinzufuegen(Benutzer* benutzer_object);
	Kurs& get_kurse(int index);
};

class Kurs
{
private:
	std::string name; 
	std::string beschreibung;
	std::vector<Lektion> lektion;

public:
	Kurs(const std::string& name, const std::string& beschreibung);
	void lektion_erstellen(const std::string& titel);
	Lektion& lektion_zugreifen(int index);
};

class Benutzer
{
private:
	std::string name; 

public:
	Benutzer(const std::string& name);
	void kurs_einschreiben(Kurs* kurs, int index);
	void plattform_registrieren(Plattform* plattform);
};

class Lektion
{
private:
	std::string titel;
	std::vector<Inhalt> inhalt;

public:
	Lektion(const std::string& titel);
	void inhalt_hinzufuegen(const std::string& text);
	Inhalt inhalt_zugreifen(int index) const;
};

class Inhalt
{
private:
	std::string text;

public:
	Inhalt(const std::string& text);
	std::string get_text() const;
};

#endif