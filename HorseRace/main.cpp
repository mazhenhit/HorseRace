#include <iostream>
#include <string>
using namespace std;

/*********************************
           Horse Race
**********************************/

void printMenu()
{
	cout << "1. Print commands list" << endl
		 << "2. Print the information about the program" << endl
		 << "3. Exit the program" << endl;
}

void printCommandsList()
{
	cout << "printCommandsList" << endl;
}

void printInfoAboutProgram()
{
	cout << "Name: Horse Race" << endl
		<< "Author: Ma Zhen" << endl
		<< "Copyright: All Right Reserved By Ma Zhen" << endl
		<< "Year: 2014" << endl
		<< "Version: 1.0.0.0" << endl;
}

int main()
{
	string orderNum;
	while (true)
	{
		printMenu();
		cin >> orderNum;
		if (orderNum == "1")
			printCommandsList();
		else if (orderNum == "2")
			printInfoAboutProgram();
		else if (orderNum == "3")
			break;
		else
			cout << "Input Error! Try again!" << endl;
	}
	return 0;
}