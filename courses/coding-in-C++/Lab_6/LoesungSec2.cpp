#include <iostream>
#include <string>
#include <stdexcept>

class SensorFailureError : public std::runtime_error
{
public:
	SensorFailureError() : std::runtime_error("Sensor is unreachable") {}
};

class Sensor
{
public:
	Sensor(const std::string& name, double wert, double min_Wert, double max_Wert);
	virtual void update_value(double value);
	double get_value() const;
	void print_info() const;
	void simulate_failure() const;

private:
	std::string name;
	double wert;
	double min_Wert;
	double max_Wert;
};

Sensor::Sensor(const std::string& name, double wert, double min_Wert, double max_Wert)
	: name(name), wert(wert), min_Wert(min_Wert), max_Wert(max_Wert)
{
	if (min_Wert > max_Wert)
	{
		throw std::invalid_argument("Unguelige Sensorkonfiguration");
	}

	update_value(wert);
}

double Sensor::get_value() const
{
	return wert;
}

void Sensor::print_info() const
{
	std::cout << "Sensor: " << name << std::endl
		<< "Wert: " << wert << std::endl;
}

void Sensor::update_value(double value)
{
	if (value < min_Wert || value > max_Wert)
	{
		throw std::out_of_range("Physikalisch unmoegliche Werte");
	}

	wert = value;

	std::cout << "Update erfolgreich\n";
}

void Sensor::simulate_failure() const
{
	throw SensorFailureError();
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//Frage 1: man weiß um welche Fehler es sich handelt
//Frage 2: weil es große Kontainer sind die nicht verändert werden sollen. -> Sie werden kopiert und gleichzeitig vor Veränderung geschützt
//Frage 3: invalid_argument: ein übergebenes Argument ist logisch falsch; runtime_error: während der Laufzeit ist ein Problem aufgetreten, das davor noch nicht herausgefunden werden kann; out_of_range: ein übergebenes Argument liegt außerhalb eines definierten Bereiches
//Frage 4: weil sie genauer beschreiben was für ein Fehler aufgetreten ist und zusätzliche Informationen bereitstellen
//Frage 5: weil dieser catch alle auffangen kann -> man macht ihn als letztes, damit spezifischere zuerst auslösen -> da: wenn einemal einer ausgelöst, dann werden andere nicht mehr durchgegangen
//Frage 6: weil sie im bad-Case sehr ineffizient sind -> nur im Notfall / bei schwerwiegenden Problemen verwenden
//Frage 7: dann wird das Programm beendet

int main()
{
	try
	{
		Sensor sen1("sen1", 50, 25, 60);
	}
	catch (const std::invalid_argument& error)
	{
		std::cout << "fehler: " << error.what() << std::endl;
	}
	catch (const std::out_of_range& error)
	{
		std::cout << "fehler: " << error.what() << std::endl;
	}
	catch (const SensorFailureError& error) //der muss weiter oben stehen!!!!
	{
		std::cout << "fehler: " << error.what() << std::endl;
	}

	try
	{
		Sensor sen1("sen1", 50, 70, 60);
	}
	catch (const std::invalid_argument& error)
	{
		std::cout << "fehler: " << error.what() << std::endl;
	}
	catch (const std::out_of_range& error)
	{
		std::cout << "fehler: " << error.what() << std::endl;
	}
	catch (const SensorFailureError& error) //der muss weiter oben stehen!!!!
	{
		std::cout << "fehler: " << error.what() << std::endl;
	}

	try
	{
		Sensor sen1("sen1", 50, 25, 60);
		sen1.update_value(51);
	}
	catch (const std::invalid_argument& error)
	{
		std::cout << "fehler: " << error.what() << std::endl;
	}
	catch (const std::out_of_range& error)
	{
		std::cout << "fehler: " << error.what() << std::endl;
	}
	catch (const SensorFailureError& error) //der muss weiter oben stehen!!!!
	{
		std::cout << "fehler: " << error.what() << std::endl;
	}

	try
	{
		Sensor sen1("sen1", 50, 25, 60);
		sen1.update_value(70);
	}
	catch (const std::invalid_argument& error)
	{
		std::cout << "fehler: " << error.what() << std::endl;
	}
	catch (const std::out_of_range& error)
	{
		std::cout << "fehler: " << error.what() << std::endl;
	}
	catch (const SensorFailureError& error) //der muss weiter oben stehen!!!!
	{
		std::cout << "fehler: " << error.what() << std::endl;
	}

	try
	{
		Sensor sen1("sen1", 50, 25, 60);
		sen1.simulate_failure();
	}
	catch (const std::invalid_argument& error)
	{
		std::cout << "fehler: " << error.what() << std::endl;
	}
	catch (const std::out_of_range& error)
	{
		std::cout << "fehler: " << error.what() << std::endl;
	}
	catch (const SensorFailureError& error) //der muss weiter oben stehen!!!!
	{
		std::cout << "fehler: " << error.what() << std::endl;
	}
	return 0;
}


//int main()
//{
//	try
//	{
//		Sensor sen1("sen1", 50, 25, 60);
//		Sensor sen2("sen2", 50, 70, 60);
//
//		Sensor sen3("sen3", 50, 25, 60);
//		sen3.update_value(51);
//
//		Sensor sen4("sen1", 50, 25, 60);
//		sen4.update_value(70);
//	}
//	catch (const std::invalid_argument& error)
//	{
//		std::cout << "Fehler: " << error.what() << std::endl;
//	}
//	catch (const std::out_of_range& error)
//	{
//		std::cout << "Fehler: " << error.what() << std::endl;
//	}
//
//
//	//Die Reihenfolge der catch-Blöcke ist wichtig, da ein catch mit zb exception den fehler auffangen würde, obwohl später vielleicht der expilzite Typ noch kommen würde
//	//man sollte besser viele verschiedene try blöcke nehmen, da ein Try-Block beendet wird, sobald der erste Fehler geworfen wird
//
//	return 0;
//}