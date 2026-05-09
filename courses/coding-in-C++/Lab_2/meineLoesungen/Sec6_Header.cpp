#include "Sec6_Header.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//*****************************************************************************
//WEBSITE
Website::Website(const std::string& url, const std::string& information, int ranking) : url(url), information(information), ranking(ranking)
{
}

std::string Website::get_url() const
{
	return url;
}

std::string Website::get_information() const
{
	return information;
}

int Website::get_ranking() const
{
	return ranking;
}

bool Website::beliebt() const
{
	if (ranking > 5)
	{
		return true;
	}

	return false;
}
//*****************************************************************************






//*****************************************************************************
//SUCHANFRAGE
Suchanfrage::Suchanfrage(const std::string& suchbegriff, int max_anzahl_ergebnisse) : suchbegriff(suchbegriff), max_anzahl_ergebnisse(max_anzahl_ergebnisse)
{
}

bool Suchanfrage::gueltig() const
{
	if (suchbegriff.find_first_not_of(" \t\n\r") != std::string::npos)
	{
		return true;
	}

	else
	{
		return false;
	}
}

std::string Suchanfrage::get_suchbegriff() const
{
	return suchbegriff;
}

void Suchanfrage::set_suchbegriff(const std::string& suchbegriff)
{
	this->suchbegriff = suchbegriff;
}


int Suchanfrage::get_anzahl_ergebnisse() const
{
	return max_anzahl_ergebnisse;
}

void Suchanfrage::set_anzahl_ergebnisse(int anzahl)
{
	max_anzahl_ergebnisse = anzahl;
}
//*****************************************************************************








//*****************************************************************************
//SUCHMASCHINE
int Suchmaschine::anzahl_anfragen = 0;

Suchmaschine::Suchmaschine() : suche("", 0)
{
}

void Suchmaschine::set_websites(const std::string& url, const std::string& information, int ranking)
{
	websites.emplace_back(url, information, ranking);
}


void Suchmaschine::print_Info() const
{
	std::cout << "anzahl anfragen: " << anzahl_anfragen << std::endl;
}

int Suchmaschine::get_anzahl_anfragen()
{
	return anzahl_anfragen;
}

void Suchmaschine::inc_anzahl_anfragen()
{
	anzahl_anfragen++;
}

void Suchmaschine::suchen()
{
	inc_anzahl_anfragen();

	if (!suche.gueltig())
	{
		std::cout << "Suchtext nicht valide\n";
		return;
	}

	for (const Website& website : websites)
	{
		if (website.get_url().find(suche.get_suchbegriff()) != std::string::npos)
		{
			aktuelle_Suchergebnisse.push_back(website);
		}
		else if (website.get_information().find(suche.get_suchbegriff()) != std::string::npos)
		{
			aktuelle_Suchergebnisse.push_back(website);
		}
	}

	std::sort(aktuelle_Suchergebnisse.begin(), aktuelle_Suchergebnisse.end(),
		[](const Website& web1, const Website& web2)
		{
			return web1.get_ranking() > web2.get_ranking();
		});

	ergebnis_ausgeben();

	aktuelle_Suchergebnisse.clear();
}

void Suchmaschine::ergebnis_ausgeben() const
{
	int anzahl = 1;
	std::cout << "\n\n\n\n";
	for (const Website& website : aktuelle_Suchergebnisse)
	{
		if (anzahl > get_suche().get_anzahl_ergebnisse())
		{
			return;
		}

		std::cout << "Adresse: " << website.get_url() << std::endl
			<< "Inhalt: " << website.get_information() << "\n\n";
		anzahl++;
	}
}

Suchanfrage Suchmaschine::get_suche() const
{
	return suche;
}

void Suchmaschine::set_suche(const std::string& text, int anzahl_ergebnisse)
{
	suche.set_suchbegriff(text);
	suche.set_anzahl_ergebnisse(anzahl_ergebnisse);
}

void Suchmaschine::delete_Website(const std::string& url)
{
	for (std::vector<Website>::iterator it = websites.begin(); it != websites.end(); ++it)
	{
		if (it->get_url() == url)
		{
			websites.erase(it);
			return;
		}
	}
}
//*****************************************************************************