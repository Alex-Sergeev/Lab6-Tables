#ifndef __LINEAR_H__
#define __LINEAR_H__

#include <string>
#include <iostream>
#include "Polinoms.h"

using namespace std;

struct TLine
{
	TPolinom polinom;
	string name;
};

struct LinearLink
{
	LinearLink* pNext;
	TLine line;
};

class LinearTable
{
private:
	LinearLink* pFirst;
	LinearLink* pLast;
	int amountOfRecords;
public:
	LinearTable()
	{
		pFirst = NULL;
		pLast = NULL;
		amountOfRecords = 0;
	}
	LinearTable(string tmpName, TPolinom pol)
	{
		pFirst = new LinearLink;
		pFirst->line.name = tmpName;
		pFirst->line.polinom = pol;
		pFirst->pNext = NULL;
		pLast = pFirst;
		amountOfRecords = 1;
	}
	~LinearTable()
	{
		LinearLink *tmp = this->pFirst;
		LinearLink *tmpDel;
		for (int i = 0; i < amountOfRecords - 1; i++)
		{
			tmpDel = tmp;
			tmp = tmp->pNext;
			delete tmpDel;
		}
		delete tmp;
	}

	TLine Search(string SName)
	{
		LinearLink* tmp = this->pFirst;
		for (int i = 0; i < amountOfRecords - 1; i++)
		{
			if (tmp->line.name == SName)
				return tmp->line;
			tmp = tmp->pNext;
		}
		if (tmp->line.name == SName)
			return tmp->line;
		TLine Error;
		Error.name = "Not Found";
		return Error;
	}
	void Insert(string tmpName, TPolinom pol)
	{
		if (amountOfRecords == 0)
		{
			pFirst = new LinearLink;
			pFirst->line.name = tmpName;
			pFirst->line.polinom = pol;
			pFirst->pNext = NULL;
			pLast = pFirst;
			amountOfRecords = 1;
		}
		else
		{
			pLast->pNext = new LinearLink;
			pLast = pLast->pNext;
			pLast->pNext = NULL;
			pLast->line.name = tmpName;
			pLast->line.polinom = pol;
			amountOfRecords++;
		}
	}
	void Delete(string DName)
	{
		if (amountOfRecords == 0)
			return;
		LinearLink* tmp = pFirst;
		if (DName == pFirst->line.name)
		{
			if (amountOfRecords > 1)
			{
				pFirst = pFirst->pNext;
				delete tmp;
				amountOfRecords--;
				return;
			}
			else
			{
				delete tmp;
				pFirst = NULL;
				pLast = NULL;
				amountOfRecords--;
			}
		}
		LinearLink* preTemp;
		for (int i = 0; i < amountOfRecords - 1; i++)
		{
			preTemp = tmp;
			tmp = tmp->pNext;
			if (DName == tmp->line.name)
			{
				preTemp->pNext = tmp->pNext;
				if (i == amountOfRecords - 2)
					pLast = preTemp;
				delete tmp;
				amountOfRecords--;
				return;
			}
		}
	}
	void ShowTable()
	{
		setlocale(LC_ALL, "Russian");
		cout << "        Линейная Таблица" << endl;
		LinearLink* tmp = this->pFirst;
		for (int i = 0; i < amountOfRecords; i++)
		{
			cout << tmp->line.name<<"   ";
			tmp->line.polinom.ShowPolinom();
			tmp = tmp->pNext;
		}
	}
};

#endif
