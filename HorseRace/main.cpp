#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <iomanip>

#include "Penalty.h"
#include "Equipage.h"

using namespace std;

Equipage * addEquipages(Equipage *pHead)
{
	char sure = 'N';
	
	for (int i = 1;; i++)
	{
		system("cls");
		Equipage *pNew = new Equipage();
		cout << "Enter the Player information!" << endl 
			<< "The number is:  " << i << endl
			<< "<Enter \"quit\" to leave>" << endl;
		cout << "Enter name:" << endl;
		cin >> pNew->name;
		if (pNew->name == "quit")
			break;
		cout << "Enter country:" << endl;
		cin >> pNew->country;
		if (pNew->country == "quit")
			break;
		pNew->number = i;
		pNew->pNext = NULL;

		if (pHead == NULL)
		{
			pHead = pNew;
		}
		else
		{
			Equipage *pCurrent = pHead;
			while (pCurrent->pNext != NULL)
			{
				pCurrent = pCurrent->pNext;
			}
			pCurrent->pNext = pNew;
		}
	}
	return pHead;
}

void printAllEquipages(Equipage *pHead)
{
	if (pHead == NULL)
		cout << "No Equipage!" << endl;
	else
	{
		Equipage *p = pHead;
		while (p != NULL)
		{
			cout << "The Number is: " << p->number << endl
				<< "The Name is: " << p->name << endl
				<< "The Country is: " << p->country << endl;
			p = p->pNext;
		}
	}
}

void printResult(Equipage *pHead)
{
	Equipage *p = pHead;
	while (p != NULL)
	{
		cout << "hhhhhhhh" << endl;
	}
}

void printMainMenu()
{
	cout << "1. Horsre Race Menu" << endl
		 << "2. Print the information about the program" << endl
		 << "3. Exit the program" << endl;
}

void printHorseRaceMenu()
{
	cout << "1.Add the Equipages" << endl
		<< "2.Start Horse Race" << endl
		<< "3.Print Resault" << endl
		<< "4.Return Main Menu" << endl;
}

void EnterHorseRace(Equipage *pHead)
{
	system("cls");
	double startTime, passStartLineTime, exceedTime, endTime;
	double preparationTime = 0;
	double maxTime = 0;
	string getInput = "XMG";

	cout << "Enter preparation time:" << endl;
	cin >> preparationTime;
	cout << "Enter the max time:" << endl;
	cin >> maxTime;
	system("cls");

	Equipage *pEquipage = pHead;
	int i = 0;
	if (pEquipage == NULL)
	{
		cout << "Please add Equipages first! " << endl;
		system("pause");
		return;
	}
	while (pEquipage != NULL)
	{
		//规定输出格式，只有一位小数
		cout << fixed << setprecision(1);
		i++;
		cout << "!!! Start number " << i << endl;
		cout << "<press enter at clearance to start>" << endl
			<< "[n = stop result recording]" << endl;
		while (true)
		{
			cin >> getInput;
			if (getInput.empty())
				break;
			cout << "Input Wrong!" << endl;
		}

		startTime = clock() / 1000.0;
		//startTime = time(NULL);
		cout << "countdown from " << preparationTime << " started" << endl << endl;

		cout << "<press enter at start line passage>";
		while (true)
		{
			cin >> getInput;
			if (getInput.empty())
				break;
			cout << "Input Wrong!" << endl;
		}

		passStartLineTime = clock() / 1000.0;
		cout << "preparation took " << passStartLineTime - startTime << " seconds" << endl;
		exceedTime = passStartLineTime - startTime - preparationTime;
		if (exceedTime > 0)
			cout << "timing started at " << exceedTime << " seconds" << endl << endl;
		else
		{
			exceedTime = 0;
			cout << "timing started at " << 0 << " seconds" << endl << endl;
		}

		cout << "<record penalties and press enter to stop timing> " << endl
			<< "[p = pulldown, r = refusal, d = dnf, (number) = paus time]" << endl;
		string penaltyStr;
		cin >> penaltyStr;
		endTime = clock() / 1000.0;
		Penalty penalty;
		penalty.Resove(penaltyStr);
		cout << "timing stopped at " << exceedTime + endTime - passStartLineTime << " seconds" << endl << endl;
		cout << "Total time " << exceedTime + endTime - passStartLineTime - penalty.pTime << " seconds ";
		if (exceedTime + endTime - passStartLineTime - penalty.pTime > maxTime)
			cout << "( " << exceedTime + endTime - passStartLineTime - penalty.pTime - maxTime << " seconds above max)" << endl;
		int penaltyNum = 0;
		penaltyNum = 4 * penalty.pNum;
		if (penalty.rNum > 0)
			penaltyNum += 4;
		cout << "Total penalties : " << penaltyNum << " (2 due to time)" << endl << endl;

		system("pause");
		system("cls");
		pEquipage = pEquipage->pNext;
	}
}

void printInfoAboutProgram()
{
	cout << "Name: Horse Race" << endl
		<< "Author: XMG" << endl
		<< "Copyright: 2014 XMG" << endl
		<< "Year: 2014" << endl
		<< "Version: 1.0.0.0" << endl;
}

int main()
{
	string orderNum;
	while (true)
	{
		printMainMenu();
		cin >> orderNum;
		cin.clear();//处理非法输入，Ctrl+z
		if (orderNum == "1")
		{
			Equipage *pHead = NULL;
			while (true)
			{
				system("cls");
				printHorseRaceMenu();
				cin >> orderNum;
				if (orderNum == "1")
				{
					system("cls");
					pHead = addEquipages(pHead);
					/*printAllEquipages(pHead);
					system("pause");*/
				}
				else if (orderNum == "2")
				{
					EnterHorseRace(pHead);
				}
				else if (orderNum == "3")
				{
					printResult(pHead);
				}
				else if (orderNum == "4")
				{
					system("cls");
					break;
				}
				else
				{
					cout << "Input Error! Try again!" << endl;
				}
			}
		}
		else if (orderNum == "2")
		{
			printInfoAboutProgram();
			system("pause");
			system("cls");
		}
		else if (orderNum == "3")
		{
			break;
		}
		else
		{
			cout << "Input Error! Try again!" << endl;
			system("pause");
			system("cls");
		}
	}
	return 0;
}