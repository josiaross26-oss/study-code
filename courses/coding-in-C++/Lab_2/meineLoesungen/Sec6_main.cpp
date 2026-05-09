#include "Sec6_Header.hpp"

int main()
{
	Suchmaschine maschine;

	maschine.set_websites("url", "das ist eine url", 5);

	maschine.set_websites("ulurlul", "das ist random", 1);

	maschine.set_websites("keine lur", "das ist keine lur", 2);

	maschine.set_websites("priourl", "diese url hat prio", 10);

	maschine.set_suche("url", 1);
	maschine.suchen();

	maschine.set_suche("keine", 1);
	maschine.suchen();

	maschine.set_suche("random", 1);
	maschine.suchen();

	maschine.print_Info();

	maschine.delete_Website("url");

	maschine.set_suche("url", 5);
	maschine.suchen();

	return 0;
}