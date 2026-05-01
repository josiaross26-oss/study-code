#include <iostream>
#include <vector>
#include <algorithm>

void print(const std::vector<int> &vector)
{
	for (int hilfe : vector)
	{
		std::cout << hilfe << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> vector = { 42, 17, 42, 5, 99, 17, 63, 12 };
	print(vector);
	
	std::sort(vector.begin(), vector.end());
	print(vector);

	auto it = std::find(vector.begin(), vector.end(), 63); //erste Möglichkeit für Iterator mit auto
	if (*it == 63)
	{
		std::cout << "Die Zahl existiert" << std::endl;
	}
	else
	{
		std::cout << "Die Zahl existiert nicht" << std::endl;
	}
	std::cout << "\n\n\n\n";



	std::vector<int> vector_task7 = { 7, -1, 13, -1, 21, 21, 8, -1, 8 };
	int anzahl = 0;
	for (std::vector<int>::iterator it_task7 = vector_task7.begin(); it_task7 < vector_task7.end(); it_task7++) //zweite Möglichkeit für Iterator mit explizitem Datentyp
	{
		if (*it_task7 == -1)
		{
			*it_task7 = 0;
		}

		else if (*it_task7 == 8)
		{
			anzahl++;
		}
	}
	print(vector_task7);
	std::cout << anzahl << std::endl;
	std::reverse(vector_task7.begin(), vector_task7.end());
	print(vector_task7);


	//Tast 8: schon mit den Tasks davor gemacht
	//*it: Dereferenziert den Iterator -> man kann auf den Wert zugreifen
	//++it: Zählt den Iterator um eins hoch -> zeigt aufs nächste Element

	return 0;
}