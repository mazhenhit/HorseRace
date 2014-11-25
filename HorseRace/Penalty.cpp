#include "Penalty.h"

Penalty::Penalty()
{
	pNum = 0;
	rNum = 0;
	dNum = 0;
	pTime = 0.0;
}

void Penalty::Resove(string a)
{
	int flag = 0;
	for (unsigned int i = 0; i < a.length(); i++)
	{
		if (a[i] == 'p')
			pNum++;
		else if (a[i] == 'r')
			rNum++;
		else if (a[i] == 'd')
			dNum++;
		else if (a[i] >= '0' && a[i] <= '9')
		{
			if (flag == 0)
				pTime = pTime * 10 + a[i] - '0';
			else
				pTime = pTime + (a[i] - '0') / 10;
		}
		else if (a[i] == '.')
			flag = 1;
	}
}

