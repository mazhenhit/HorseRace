#pragma once
#include <string>
using namespace std;

class Equipage
{
public:
	Equipage();
	~Equipage();
	Equipage * SortResult(Equipage *pHead);

	string name;
	string country;
	int number;
	double time;
	Equipage *pNext;
};

