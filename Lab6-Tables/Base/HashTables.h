#ifndef __HASH_H__
#define __HASH_H__

#include <string>
#include <iostream>
#include "Polinoms.h"


using namespace std;

struct HLine
{
	TPolinom polinom;
	string name;
};

struct HashLink
{
	HashLink* pNext;
	int Status;
	HLine line;
};

class HashTable
{
private:
	HashLink* HashArray[100];
	int StringToHash(string tmpName)
	{
		int result = 0;
		for (int i = 0; i < tmpName.length(); i++)
		{
			result = result + tmpName[i];
		}
		return (result%100);
	}
public:
	HashTable()
	{
		for (int i = 0; i < 100; i++)
		{
			HashArray[i] = new HashLink;
			HashArray[i]->Status = 0;
			HashArray[i]->pNext = NULL;
		}
	}

	HLine Search(string SName)
	{
		int index = this->StringToHash(SName);
		HashLink* tmp = HashArray[index];
		if (tmp->line.name == SName)
			return tmp->line;
		tmp = tmp->pNext;
		while (tmp != NULL)
		{
			if (tmp->line.name == SName)
				return tmp->line;
			tmp = tmp->pNext;
		}
		HLine Error;
		Error.name = "Not Found";
		return Error;	
	}
	void Insert(string IName, TPolinom polinom)
	{
		int index = this->StringToHash(IName);
		if (HashArray[index]->Status == 0)
		{
			HashArray[index] = new HashLink;
			HashArray[index]->line.name = IName;
			HashArray[index]->line.polinom = polinom;
			HashArray[index]->pNext = NULL;
			HashArray[index]->Status = 1;
			return;
		}
		HashLink* tmp = HashArray[index];
		while (tmp->pNext != NULL)
			tmp = tmp->pNext;
		tmp->pNext = new HashLink;
		tmp = tmp->pNext;
		tmp->line.name = IName;
		tmp->line.polinom = polinom;
		tmp->Status = 1;
		tmp->pNext = NULL;
	}
	void Delete(string DName) 
	{
		int index = this->StringToHash(DName);
		if (HashArray[index]->Status == 0)
			return;
		HashLink* tmp = HashArray[index];
		if ((HashArray[index]->line.name == DName) && (HashArray[index]->pNext == NULL))
		{
			delete tmp;
			HashArray[index] = new HashLink;
			HashArray[index]->Status = 0;
			HashArray[index]->pNext = NULL;
			return;
		}
		if ((HashArray[index]->line.name == DName) && (HashArray[index]->pNext != NULL))
		{
			HashArray[index] = tmp->pNext;
			delete tmp;
			return;
		}
		HashLink* preTmp = tmp;
		tmp = tmp->pNext;
		while (tmp != NULL)
		{
			if (tmp->line.name == DName)
			{
				preTmp->pNext = tmp->pNext;
				delete tmp;
			}
			preTmp = tmp;
			tmp = tmp->pNext;
		}
	}
	void ShowTable()
	{
		HashLink* tmp;
		setlocale(LC_ALL, "Russian");
		cout << "        Хэш Таблица" << endl;
		for (int i = 0; i < 100; i++)
		{
			if (HashArray[i]->Status == 1)
			{
				cout << HashArray[i]->line.name << "   ";
				HashArray[i]->line.polinom.ShowPolinom();
			}
			else 
				continue;
			tmp = HashArray[i];
			while (tmp->pNext != NULL)
			{
				tmp = tmp->pNext;
				cout << tmp->line.name << "   ";
				tmp->line.polinom.ShowPolinom();
			}
		}
	}
};

#endif
