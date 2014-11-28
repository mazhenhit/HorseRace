#include "Equipage.h"


Equipage::Equipage()
{
	time = 999999.99;
}


Equipage::~Equipage()
{
}

Equipage * Equipage::SortResult(Equipage *pHead)
{
	if (pHead == NULL)
	{
		return NULL;
	}
	else
	{
		Equipage *pXunHuan = pHead;
		if (pXunHuan->pNext == NULL)
		{
			return pHead;
		}
		Equipage *temp = pXunHuan->pNext;
		if (temp->pNext == NULL)
		{
			if (pXunHuan->time > temp->time)
			{
				temp->pNext = pXunHuan;
				pXunHuan->pNext = NULL;
				return temp;
			}
			else
				return pHead;
		}
		while (pXunHuan != NULL)
		{
			Equipage *pAhead = pXunHuan;
			Equipage *pCurrent = pAhead->pNext;
			Equipage *pBehind = pCurrent->pNext;
			while (pBehind != NULL)
			{
				if (pCurrent->time > pBehind->time)
				{
					pCurrent->pNext = pBehind->pNext;
					pBehind->pNext = pCurrent;
					pAhead->pNext = pBehind;
					
					pAhead = pBehind;
					pBehind = pCurrent->pNext;
				}
				else
				{
					pAhead = pCurrent;
					pCurrent = pBehind;
					pBehind = pBehind->pNext;
				}
			}
			pXunHuan = pXunHuan->pNext;
		}
		return pHead;
	}
}

