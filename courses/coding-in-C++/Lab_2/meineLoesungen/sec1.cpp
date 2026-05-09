#include <iostream>
#include <string>

class BankAccount
{
private:
	std::string owner;
	double balance;

public:

	BankAccount() : owner("Unbekannt"), balance(0.0)
	{
	}

	void setOwner(std::string ownerName)
	{
		owner = ownerName;
	}

	std::string getOwner() const
	{
		return owner; 
	}

	void deposit(double amount)
	{
		if (amount > 0)
		{
			balance = balance + amount;
			std::cout << "Neuer Konotstand ist: " << getBalance() << std::endl;
		}
		else
		{
			std::cout << "Bitte zahle mehr als 0 Euro ein\n";
		}
	}

	void withdraw(double amount)
	{
		if (amount < balance)
		{
			balance = balance - amount;
			std::cout << "Der neue Kontostand beträgt: " << getBalance() << std::endl; // WIESO WIRD HIER IN DER MUSTERLÖSUNG GETBALANCE() AUFGERUFEN???
		}
		else
		{
			std::cout << "Nicht genug Geld auf dem Konto vorhanden\n";
		}
	}

	double getBalance() const;
	void getAccountInfo() const;
};

double BankAccount::getBalance() const
{
	return balance;
}

void BankAccount::getAccountInfo() const
{
	std::cout << "Eigentuemer: " << getOwner() << std::endl;
	std::cout << "Geld: " << getBalance() << std::endl;
}

int main()
{
	BankAccount myAccount;
	myAccount.setOwner("Josia");

	myAccount.deposit(0);
	myAccount.deposit(500);

	myAccount.withdraw(0);
	myAccount.withdraw(200);

	myAccount.getAccountInfo();

	//es sollte ein Konstruktor genutzt werden, um den Kontostand am Anfang auf Null zu setzen

	return 0;
}