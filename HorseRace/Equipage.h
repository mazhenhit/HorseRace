#pragma once
#include <string>
using namespace std;

class Equipage
{
public:
	Equipage();
	~Equipage();

	string name;
	string country;
	int number;
	double time;
	Equipage *pNext;
};

