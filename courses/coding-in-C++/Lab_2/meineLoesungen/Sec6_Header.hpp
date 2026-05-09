#ifndef SEC6_HEADER
#define SEC6_HEADER
#include <iostream>
#include <string>
#include <vector>

class Website
{
private:
	std::string url;
	std::string information;
	int ranking;

public:
	Website(const std::string& url, const std::string& information, int ranking);

	std::string get_url() const;
	void set_url(const std::string& url);

	std::string get_information() const;
	void set_information(const std::string& information);

	int get_ranking() const;
	void set_ranking(int ranking);

	bool beliebt() const;
};






class Suchanfrage
{
private:
	std::string suchbegriff;
	int max_anzahl_ergebnisse;

public:
	Suchanfrage(const std::string& suchbegriff, int max_anzahl_ergebnisse);

	bool gueltig() const;

	std::string get_suchbegriff() const;
	void set_suchbegriff(const std::string& suchbegriff);

	int get_anzahl_ergebnisse() const;
	void set_anzahl_ergebnisse(int anzahl);
};







class Suchmaschine
{
private:
	static int anzahl_anfragen;
	std::vector<Website> websites;
	std::vector<Website> aktuelle_Suchergebnisse;
	Suchanfrage suche;

	void ergebnis_ausgeben() const;

public:
	Suchmaschine();

	void print_Info() const;

	static int get_anzahl_anfragen();

	static void inc_anzahl_anfragen();

	Suchanfrage get_suche() const;
	
	void set_suche(const std::string& text, int anzahl_ergebnisse);

	void suchen();

	void set_websites(const std::string& url, const std::string& information, int ranking);

	void delete_Website(const std::string& url);
};





#endif