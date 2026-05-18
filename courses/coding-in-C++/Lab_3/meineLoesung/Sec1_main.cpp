#include "Sec1_Header.hpp"
#include <iostream>


int main()
{
	Plattform plat("moodle");

	plat.kurs_hinzufuegen("kurs 1", "test_kurs");

	plat.get_kurse(0).lektion_erstellen("Lektion1");

	plat.get_kurse(0).lektion_zugreifen(0).inhalt_hinzufuegen("Genau so hat das funktioniert");

	std::cout << plat.get_kurse(0).lektion_zugreifen(0).inhalt_zugreifen(0).get_text() << std::endl;



	Benutzer stud("josia");

	stud.plattform_registrieren(&plat);
	stud.kurs_einschreiben(&plat.get_kurse(0), 0);

	return 0;
}