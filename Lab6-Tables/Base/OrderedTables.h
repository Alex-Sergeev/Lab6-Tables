#ifndef __ORDERED_H__
#define __ORDERED_H__

#include <string>
#include <iostream>
#include "Polinoms.h"

using namespace std;

struct OLine
{
	TPolinom polinom;
	string name;
};

class OrderedTable
{
private:
	OLine OrderedArray[100];
	int amountOfRecords;
public:
	OrderedTable()
	{
		amountOfRecords = 0;
	}

	OLine Search(string SName)
	{
		OLine Error;
		Error.name = "Not Found";
		if (amountOfRecords == 0)
			return Error;
		if (OrderedArray[0].name > SName)
			return Error;
		if (OrderedArray[amountOfRecords - 1].name < SName)
			return Error;
		int right = amountOfRecords;
		int left = 0;
		int middle;
		while ((right - left) > 0)
		{
			middle = left + (right - left) / 2;
			if (OrderedArray[middle].name == SName)
				return OrderedArray[middle];
			else if (OrderedArray[middle].name >= SName)
				right = middle;
			else
				left = middle + 1;
		}
		if (OrderedArray[middle].name == SName)
			return OrderedArray[middle];
		return Error;
	}
	void Insert(string IName, TPolinom pol)
	{
		if (amountOfRecords == 100)
			throw("Too much records");
		OrderedArray[amountOfRecords].name = IName;
		OrderedArray[amountOfRecords].polinom = pol;
		amountOfRecords++;
		if (amountOfRecords == 1)
			return;
		OLine tmp;
		for (int i = amountOfRecords - 1; OrderedArray[i].name < OrderedArray[i - 1].name; i--)
		{
			tmp = OrderedArray[i];
			OrderedArray[i] = OrderedArray[i - 1];
			OrderedArray[i - 1] = tmp;
			if (i = 1)
				return;
		}
	}
	void Delete(string DName)
	{
		if (amountOfRecords == 0)
			return;
		if (OrderedArray[0].name > DName)
			return ;
		if (OrderedArray[amountOfRecords - 1].name < DName)
			return ;
		int right = amountOfRecords;
		int left = 0;
		int middle;
		while ((right - left) > 0)
		{
			middle = left + (right - left) / 2;
			if (OrderedArray[middle].name == DName)
			{
				for (int i = middle; i < amountOfRecords - 1; i++)
					OrderedArray[i] = OrderedArray[i + 1];
				amountOfRecords--;
				return;
			}
			else if (OrderedArray[middle].name >= DName)
				right = middle;
			else
				left = middle + 1;
		}
		if (OrderedArray[middle].name == DName)
		{
			for (int i = middle; i < amountOfRecords - 1; i++)
				OrderedArray[i] = OrderedArray[i + 1];
			amountOfRecords--;
			return;
		}
	}
	void ShowTable()
	{
		setlocale(LC_ALL, "Russian");
		cout << "        Упорядоченная Таблица" << endl;
		for (int i = 0; i < amountOfRecords; i++)
		{
			cout << OrderedArray[i].name << "   ";
			OrderedArray[i].polinom.ShowPolinom();
		}
	}
};

#endif
