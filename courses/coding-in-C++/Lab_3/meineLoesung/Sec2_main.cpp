#include <iostream>
#include <string>

class User
{
protected:
	std::string name;
	int id;

public:
	User(const std::string& name, int id);
	void printfInfo() const;
};

User::User(const std::string& name, int id) : name(name), id(id)
{
}

void User::printfInfo() const
{
	std::cout << "User: " << std::endl
		<< "Name: " << name << std::endl
		<< "ID: " << id << std::endl;
}

class Student : public User
{
private:
	int hausnummer;

public:
	Student(const std::string& name, int id, int hausnummer);
	void printRole() const;
};

Student::Student(const std::string& name, int id, int hausnummer) : User(name, id), hausnummer(hausnummer)
{
}

void Student::printRole() const
{
	std::cout << "Student: " << std::endl
		<< "Name: " << name << std::endl
		<< "ID: " << id << std::endl
		<< "Hausnummer: " << hausnummer << std::endl;
}

class Instructor : public User
{
private:
	int alter;

public:
	Instructor(const std::string& name, int id, int alter);
	void printRole() const;
};

Instructor::Instructor(const std::string& name, int id, int alter) 
	: User(name, id), alter(alter)
{
}

void Instructor::printRole() const
{
	std::cout << "Instructor: " << std::endl
	<< "Name: " << name << std::endl
	<< "ID: " << id << std::endl
	<< "Alter: " << alter << std::endl;
}

//protected wird genommen, da man so auf die vererbten attribute zugreifen kann, bei public könnte man das nicht
//wenn man das public weglässt und einfach nichts schreibt, dann wird automatisch alles private
//der Konstruktor muss aufgerufen werden, damit alles korrekt initialisiert wird

int main()
{
	Student stud1("josia", 123, 25);
	Instructor inst1("asdfasdf", 312, 33);

	stud1.printfInfo();
	stud1.printRole();

	inst1.printfInfo();
	inst1.printRole();



	return 0;
}