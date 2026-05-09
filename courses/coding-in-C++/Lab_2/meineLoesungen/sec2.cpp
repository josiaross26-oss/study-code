#include <iostream>
#include <string>

class note
{
public:
	note(std::string input);
	~note();
	void display();
	note(const note& othernote);


private:
	std::string* text;
};

note::note(std::string input)
{
	text = new std::string(input); //oder: text = new std::string; *text = input;
}

note::~note()
{
	delete text;
	text = nullptr;
	std::cout << "Speicher freigegeben\n";
}

note::note(const note& othernote)
{
	text = new std::string;
	*text = *othernote.text;
}

void note::display()
{
	std::cout << *text << std::endl;
}






int main()
{
	note note1("josia");

	note note2 = note1;

	note1.display();
	note2.display();



	return 0;
}