#include <iostream>
#include <string>
#include <conio.h>
#include<windows.h>
#include <time.h>
using namespace std;

/*********************************
           Horse Race
**********************************/

void printMenu()
{
	cout << "1. Enter the number of the equipages" << endl
		 << "2. Print the information about the program" << endl
		 << "3. Exit the program" << endl;
}

void EnterHorseRace()
{
	time_t startTime, passStartLineTime, exceedTime, endTime, pauseTime;
	int numberEquipages = 0;
	int preparationTime = -1;
	int maxTime = 0;
	int c = 0;
	cin >> numberEquipages;
	if (numberEquipages > 0)
	{
		cout << "Enter preparation time:" << endl;
		cin >> preparationTime;
		cout << "Enter the max time:" << endl;
		cin >> maxTime;

		for (int i = 1; i <= numberEquipages; i++)
		{
			cout << "!!! Start number " << i << endl;
			cout << "<press enter at clearance to start>" << endl
				<< "[n = stop result recording]";
			if ((c = getchar()) == '\n')
			{
				startTime = time(NULL);
				cout << "countdown from " << preparationTime << " started" << endl << endl;
			}
			cout << "<press enter at start line passage>";
			if ((c = getchar()) == '\n')
			{
				passStartLineTime = time(NULL);
				cout << "preparation took " << passStartLineTime - startTime << " seconds" << endl;
				exceedTime = passStartLineTime - startTime - preparationTime;
				if (exceedTime > 0)
					cout << "timing started at " << exceedTime << " seconds" << endl << endl;
				else
					cout << "timing started at " << 0 << " seconds" << endl << endl;

				cout << "<record penalties and press enter to stop timing> " << endl
					<< "[p = pulldown, r = refusal, d = dnf, (number) = paus time]" << endl;
				string penalty;
				cin >> penalty;
				//得到暂停时间等信息
				endTime = time(NULL);
				cout << "timing stopped at 39.46 seconds" << endl << endl;
				cout << "Total time 35.46 seconds (1.46 seconds above max)" << endl
					<< "Total penalties : 14 (2 due to time)" << endl << endl;
			}

		}
	}
}

void printInfoAboutProgram()
{
	cout << "Name: Horse Race" << endl
		<< "Author: Ma Zhen" << endl
		<< "Copyright: 2014 MaZhen" << endl
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
		cin.clear();//处理非法输入，Ctrl+z
		if (orderNum == "1")
			EnterHorseRace();
		else if (orderNum == "2")
			printInfoAboutProgram();
		else if (orderNum == "3")
			break;
		else
			cout << "Input Error! Try again!" << endl;

		system("pause");
		system("cls");
	}
	return 0;
}