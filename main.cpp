#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <iomanip>

#include "Penalty.h"
#include "Equipage.h"

using namespace std;

void AddEquipages(Equipage *ptr,int num)
{	
	for (int i = 0;i < num; i++)
	{
		system("cls");
		cout << "Enter the Player information!" << endl
			<< "The number is:  " << i + 1 << endl;

		cout << "Enter name:" << endl;
		cin >> ptr->name;

		cout << "Enter country:" << endl;
		cin >> ptr->country;

		ptr->number = i + 1;
		ptr++;
	}
}

void PrintResult(Equipage *ptr, int num)
{
	if (ptr == NULL)
	{
		cout << "Please enter the Equipages first!!!" << endl;
		system("pause");
		return;
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num - i; j++)
		{
			Equipage *t1 = ptr++;
			Equipage *t2 = t1++;
			if (t1->time >t2->time)
			{
				//交换。。。。
				Equipage temp;
				temp = *t1;
				*t1 = *t2;
				*t2 = temp;
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		cout << ptr->name << endl;
		cout << ptr->country << endl << endl;
	}
	system("pause");

}

void PrintMainMenu()
{
	cout << "1. Horsre Race Menu" << endl
		 << "2. Print the information about the program" << endl
		 << "3. Exit the program" << endl;
}

void PrintHorseRaceMenu()
{
	cout << "1.Add the Equipages" << endl
		<< "2.Start Horse Race" << endl
		<< "3.Print Resault" << endl
		<< "4.Return Main Menu" << endl;
}

void EnterHorseRace(Equipage *ptr,int num)
{
	system("cls");
	double startTime, passStartLineTime, exceedTime, endTime;
	double preparationTime = 0;
	double maxTime = 0;
	string getInput;
	if (ptr == NULL)
	{
		cout << "Please Enter the Equipages first!!!" << endl;
		return;
	}
	cout << "Enter preparation time:" << endl;
	cin >> preparationTime;
	cout << "Enter the max time:" << endl;
	cin >> maxTime;
	system("cls");

	for (int i = 0; i < num;i++)
	{
		//规定输出格式，只有一位小数
		cout << fixed << setprecision(1);
		cout << "!!! Start number " << i + 1 << endl;
		cout << "The name is: " << ptr->name << endl;
		cout << "<press enter at clearance to start>" << endl
			<< "[n = stop result recording]" << endl;
		
		char stopFlag = 0;
		while (true)
		{
			cin.get();
			getInput = cin.get();
			if (getInput == "\n")
				break;
			else if (getInput.at(0) == 'n')
			{
				stopFlag = 1;
				break;
			}
			cout << "Input Wrong!" << endl;
		}
		if (stopFlag == 0)
		{
			startTime = clock() / 1000.0;
			cout << "countdown from " << preparationTime << " started" << endl << endl;
			cout << "<press enter at start line passage>";
			while (true)
			{
				getInput = cin.get();
				if (getInput == "\n")
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
			ptr->time = exceedTime + endTime - passStartLineTime - penalty.pTime;
			if (exceedTime + endTime - passStartLineTime - penalty.pTime > maxTime)
				cout << "( " << exceedTime + endTime - passStartLineTime - penalty.pTime - maxTime << " seconds above max)" << endl;
			int penaltyNum = 0;
			penaltyNum = 4 * penalty.pNum;
			if (penalty.rNum > 0)
				penaltyNum += 4;
			cout << "Total penalties : " << penaltyNum << " (2 due to time)" << endl << endl;
			system("pause");
			system("cls");
		}
		else
		{
			cout << "The Number " << i << " stops result recording!!!" << endl;
			system("pause");
			system("cls");
		}		
		ptr++;
	}
}

void PrintInfoAboutProgram()
{
	cout << "Name: Horse Race" << endl
		<< "Author: XMG" << endl
		<< "Copyright: 2014 XMG" << endl
		<< "Year: 2014" << endl
		<< "Version: 1.0.0.0" << endl;
}

int GetNumberOfEquipments(string str)
{
	int num = 0;

	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = num * 10 + str[i] - '0';
		else
			return 0;
	}
	return num;
}

int main()
{
	int numberOfEquipments = 0;
	Equipage *equipagePtr = NULL;
	string orderNum;
	while (true)
	{
		PrintMainMenu();
		cin >> orderNum;
		cin.clear();//处理非法输入，Ctrl+z
		if (orderNum == "1")
		{
			Equipage *pHead = NULL;
			while (true)
			{
				system("cls");
				PrintHorseRaceMenu();
				cin >> orderNum;
				if (orderNum == "1")
				{
					system("cls");
					cout << "Enter the number of the Equipments:" << endl;
					cin >> orderNum;
					cin.clear();
					numberOfEquipments = GetNumberOfEquipments(orderNum);
					while (numberOfEquipments == 0)
					{
						cout << "You entered the worng number!!!" << endl;
						cout << "Please enter again, the number should bingger than zero!!!" << endl;
						cin >> orderNum;
						cin.clear();
						numberOfEquipments = GetNumberOfEquipments(orderNum);
					}
					equipagePtr = new Equipage[numberOfEquipments];

					AddEquipages(equipagePtr, numberOfEquipments);
				}
				else if (orderNum == "2")
				{
					EnterHorseRace(equipagePtr, numberOfEquipments);
				}
				else if (orderNum == "3")
				{
					PrintResult(equipagePtr, numberOfEquipments);
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
			PrintInfoAboutProgram();
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