#include "Sec1_Header.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

Plattform::Plattform(const std::string& name) 
	: name(name)
{
}

void Plattform::kurs_hinzufuegen(const std::string& name, const std::string& beschreibung)
{
	kurse.emplace_back(name, beschreibung);
}

void Plattform::benutzer_hinzufuegen(Benutzer* benutzer_object)
{
	if (benutzer_object == nullptr)
	{
		return;
	}

	if (std::find(registrierte_benutzer.begin(), registrierte_benutzer.end(), benutzer_object) == registrierte_benutzer.end())
	{
		registrierte_benutzer.push_back(benutzer_object);
	}
}

Kurs& Plattform::get_kurse(int index)
{
	return kurse[index];
}


//*****************************************************************************************************


Kurs::Kurs(const std::string& name, const std::string& beschreibung) 
	: name(name), beschreibung(beschreibung)
{
}

void Kurs::lektion_erstellen(const std::string& titel)
{
	lektion.emplace_back(titel);
}

Lektion& Kurs::lektion_zugreifen(int index)
{
	return lektion[index];
}


//*****************************************************************************************************


Benutzer::Benutzer(const std::string& name) : name(name)
{
}

void Benutzer::kurs_einschreiben(Kurs* kurs, int index)
{
	if (kurs == nullptr)
	{
		return;
	}

	kurs->lektion_zugreifen(index);
}

void Benutzer::plattform_registrieren(Plattform* plattform)
{
	if (plattform == nullptr)
	{
		return;
	}

	plattform->benutzer_hinzufuegen(this);

}


//*****************************************************************************************************

Lektion::Lektion(const std::string& titel) : titel(titel)
{
}

void Lektion::inhalt_hinzufuegen(const std::string& text)
{
	inhalt.emplace_back(text);
}

Inhalt Lektion::inhalt_zugreifen(int index) const
{
	return inhalt[index];
}


//*****************************************************************************************************

Inhalt::Inhalt(const std::string& text) : text(text)
{
}

std::string Inhalt::get_text() const
{
	return text;
}