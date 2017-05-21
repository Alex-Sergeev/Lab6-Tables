#include "Polinoms.h"
#include <string>

using namespace std;

int PartOfStringToInt(string str, int& pos)
{
	int res;
	int j = pos;
	int count = 0;
	char *str2;
	string tmpstr;
	while ((str[j] >= '0') && (str[j] <= '9'))
	{
		count++;
		j++;
	}
	tmpstr = str.substr(pos,count);
	str2 = new char[tmpstr.size() + 1];
	pos = j;
	for (j = 0; j < tmpstr.size() + 1; j++)
		str2[j] = tmpstr[j];
	res = strtod(str2, NULL);

	return res;
}

int TPolinom::maxDegree;

TPolinom::TPolinom()
{
	this->pFirst = new TLink;
	this->pFirst->monom.coef = 0;
	this->pFirst->monom.degree = -1;
	this->pFirst->pNext = pFirst;
}

TPolinom::TPolinom(char* strch)
{
	setlocale(LC_ALL, "Russian");
	string str(strch);
	int size = str.size();
	string tmpstr;
	char now;
	int i, j, count;
	for (i = 0; i < size; i++)
	{
		now = str[i];
		if (!((now == '*') || (now == '^') || (now == '+') || (now == '-') || (now == 'x') || (now == 'y') || (now == 'z') || ((now >= '0') && (now <= '9'))) || (now == ' '))
			throw"Введён недопустимый символ";
	}
	TLink* linkStart = new TLink;
	linkStart->monom.degree = -1;
	linkStart->monom.coef = 0;
	TLink* currentPartOfLink = linkStart;
	i = 0;
	while (i < size)
	{
		j = i;
		count = 0;
		if ((str[j] == '-') || (str[j] == '+'))
		{
			j++;
			count++;
		}
		while ((str[j] != '+') && (str[j] != '-'))
		{
			count++;
			j++;
			if (j == size)
				break;
		}
		tmpstr = str.substr(i, count);
		j = 0;
		currentPartOfLink->pNext = new TLink;
		currentPartOfLink = currentPartOfLink->pNext;
		currentPartOfLink->monom.coef = 1;
		if (tmpstr[j] == '-')
		{
			currentPartOfLink->monom.coef = -1;
			j++;
		}
		if (tmpstr[j] == '+')
			j++;
		if ((tmpstr[j] >= '0') && (tmpstr[j] <= '9'))
			currentPartOfLink->monom.coef *= PartOfStringToInt(tmpstr, j);
		else if ((tmpstr[j] == 'x') || (tmpstr[j] == 'y') || (tmpstr[j] == 'z'));
		else
			throw"Ошибка ввода полинома: Неверно начат полином";
		if (tmpstr[j] == '*')
			j++;
		currentPartOfLink->monom.degree = 0;
		if (tmpstr[j] == 'x')
		{
			j++;
			if (tmpstr[j] == '^')
			{
				j++;
				if (!((tmpstr[j] >= '0') && (tmpstr[j] <= '9')))
					throw "Ошибка ввода полинома: Неправильная запись монома 1";
			}
			if ((tmpstr[j] >= '0') && (tmpstr[j] <= '9'))
				currentPartOfLink->monom.degree += maxDegree*maxDegree*PartOfStringToInt(tmpstr, j);
			else
				currentPartOfLink->monom.degree += maxDegree*maxDegree * 1;
		}
		if (tmpstr[j] == '*')
			j++;
		if (tmpstr[j] == 'y')
		{
			j++;
			if (tmpstr[j] == '^')
			{
				j++;
				if (!((tmpstr[j] >= '0') && (tmpstr[j] <= '9')))
					throw"Ошибка ввода полинома: Неправильная запись монома 2";
			}
			if ((tmpstr[j] >= '0') && (tmpstr[j] <= '9'))
				currentPartOfLink->monom.degree += maxDegree*PartOfStringToInt(tmpstr, j);
			else
				currentPartOfLink->monom.degree += maxDegree * 1;
		}
		if (tmpstr[j] == '*')
			j++;
		if (tmpstr[j] == 'z')
		{
			j++;
			if (tmpstr[j] == '^')
			{
				j++;
				if (!((tmpstr[j] >= '0') && (tmpstr[j] <= '9')))
					throw"Ошибка ввода полинома: Неправильная запись монома 3";
			}
			if ((tmpstr[j] >= '0') && (tmpstr[j] <= '9'))
				currentPartOfLink->monom.degree += PartOfStringToInt(tmpstr, j);
			else
				currentPartOfLink->monom.degree += 1;
		}
		if (j != tmpstr.size())
			throw"Ошибка ввода полинома: Неправильная запись монома 4";
		i += j;
	}
	currentPartOfLink->pNext = linkStart;
	this->pFirst = linkStart;
	this->SortByMaxDegree();
}

TPolinom::TPolinom(string str)
{
	setlocale(LC_ALL, "Russian");
	int size = str.size();
	string tmpstr;
	char now;
	int i, j, count;
	for (i = 0; i < size; i++)
	{
		now = str[i];
		if (!((now == '*') || (now == '^') || (now == '+') || (now == '-') || (now == 'x') || (now == 'y') || (now == 'z')||((now>='0')&&(now<='9'))) || (now == ' '))
			throw"Введён недопустимый символ";
	}
	TLink* linkStart = new TLink;
	linkStart->monom.degree = -1;
	linkStart->monom.coef = 0;
	TLink* currentPartOfLink = linkStart;
	i = 0;
	while (i < size)
	{
		j = i;
		count = 0;
		if ((str[j] == '-') || (str[j] == '+'))
		{
			j++;
			count++;
		}
		while ((str[j] != '+') && (str[j] != '-'))
		{
			count++;
			j++;
			if (j == size)
				break;
		}
		tmpstr = str.substr(i, count);
		j = 0;
		currentPartOfLink->pNext = new TLink;
		currentPartOfLink = currentPartOfLink->pNext;
		currentPartOfLink->monom.coef = 1;
		if (tmpstr[j] == '-')
		{
			currentPartOfLink->monom.coef = -1;
			j++;
		}
		if (tmpstr[j] == '+')
			j++;
		if ((tmpstr[j] >= '0') && (tmpstr[j] <= '9'))
			currentPartOfLink->monom.coef *= PartOfStringToInt(tmpstr, j);
		else if ((tmpstr[j] == 'x') || (tmpstr[j] == 'y') || (tmpstr[j] == 'z'));
		else
			throw"Ошибка ввода полинома: Неверно начат полином";
		if (tmpstr[j] == '*')
			j++;
		currentPartOfLink->monom.degree = 0;
		if (tmpstr[j] == 'x')
		{
			j++;
			if (tmpstr[j] == '^')
			{
				j++;
				if (!((tmpstr[j] >= '0') && (tmpstr[j] <= '9')))
					throw "Ошибка ввода полинома: Неправильная запись монома 1";
			}
			if ((tmpstr[j] >= '0') && (tmpstr[j] <= '9'))
				currentPartOfLink->monom.degree += maxDegree*maxDegree*PartOfStringToInt(tmpstr, j);
			else
				currentPartOfLink->monom.degree += maxDegree*maxDegree*1;
		}
		if (tmpstr[j] == '*')
			j++;
		if (tmpstr[j] == 'y')
		{
			j++;
			if (tmpstr[j] == '^')
			{
				j++;
				if (!((tmpstr[j] >= '0') && (tmpstr[j] <= '9')))
					throw"Ошибка ввода полинома: Неправильная запись монома 2";
			}
			if ((tmpstr[j] >= '0') && (tmpstr[j] <= '9'))
				currentPartOfLink->monom.degree += maxDegree*PartOfStringToInt(tmpstr, j);
			else
				currentPartOfLink->monom.degree += maxDegree*1;
		}
		if (tmpstr[j] == '*')
			j++;
		if (tmpstr[j] == 'z')
		{
			j++;
			if (tmpstr[j] == '^')
			{
				j++;
				if (!((tmpstr[j] >= '0') && (tmpstr[j] <= '9')))
					throw"Ошибка ввода полинома: Неправильная запись монома 3";
			}
			if ((tmpstr[j] >= '0') && (tmpstr[j] <= '9'))
				currentPartOfLink->monom.degree += PartOfStringToInt(tmpstr, j);
			else
				currentPartOfLink->monom.degree += 1;
		}
		if (j != tmpstr.size())
			throw"Ошибка ввода полинома: Неправильная запись монома 4";
		i += j;
	}
	currentPartOfLink->pNext = linkStart;
	this->pFirst = linkStart;
	this->SortByMaxDegree();
}

TPolinom::TPolinom(const TPolinom &polinom)
{
	this->pFirst = new TLink;
	this->pFirst->monom.coef = 0;
	this->pFirst->monom.degree = -1;
	TLink* tmp = new TLink;
	TLink* startTmp = tmp;
	TLink* curentTLink = polinom.pFirst;
	curentTLink = curentTLink->pNext;
	if (curentTLink->monom.degree == -1)
	{
		startTmp->pNext = this->pFirst;
	}
	while (curentTLink->monom.degree != -1)
	{
		tmp->pNext = new TLink;
		tmp = tmp->pNext;
		tmp->monom.coef = curentTLink->monom.coef;
		tmp->monom.degree = curentTLink->monom.degree;
		curentTLink = curentTLink->pNext;
	}
	this->pFirst->pNext = startTmp->pNext;
	tmp->pNext = this->pFirst;
}

TPolinom::~TPolinom()
{
	TLink *tmp = this->pFirst;
	tmp = tmp->pNext;
	TLink *tmpDel;
	while (tmp->monom.degree != -1)
	{
		tmpDel = tmp;
		tmp = tmp->pNext;
		delete tmpDel;
	}
	delete tmp;
}

void TPolinom::SortByMaxDegree()
{
	int maxDegree;
	int start = 1;
	TLink* tmp;
	TLink* prePointer;
	TLink* lastPointer;
	TLink* maxPointer;
	TLink* Pointer;
	TLink* tmpDel;
	int count = 0;
	tmp = this->pFirst;
	tmp = tmp->pNext;
	while (tmp->monom.degree != -1)
	{
		tmp = tmp->pNext;
		count++;
	}
	for (int j = 0; j < count; j++)
	{
		tmp = this->pFirst;
		for (int i = 0; i < start; i++)
		{
			lastPointer = tmp;
			tmp = tmp->pNext;
		}
		maxDegree = -1;
		while (tmp->monom.degree != -1)
		{
			if (tmp->monom.degree > maxDegree)
			{
				maxDegree = tmp->monom.degree;
				maxPointer = tmp;
				prePointer = lastPointer;
			}
			lastPointer = tmp;
			tmp = tmp->pNext;
		}
		tmp = this->pFirst;
		for (int k = 0; k < start - 1; k++)
			tmp = tmp->pNext;
		if (tmp->pNext->monom.degree != maxPointer->monom.degree)
		{
			Pointer = tmp->pNext;
			prePointer->pNext = maxPointer->pNext;
			maxPointer->pNext = Pointer;
			tmp->pNext = maxPointer;
		}
		start++;
	}
	tmp = this->pFirst;
	lastPointer = tmp;
	tmp = tmp->pNext;
	for (int j = 0; j < count; j++)
	{
		if (tmp->monom.coef == 0)
		{
			lastPointer->pNext = tmp->pNext;
			tmpDel = tmp;
			tmp = tmp->pNext;
			delete tmpDel;
		}
		else
		{
			lastPointer = tmp;
			tmp = tmp->pNext;
		}
	}
}

TPolinom TPolinom::operator+(const TPolinom &polinom)
{
	TPolinom tmpPolinom;
	TLink* result = tmpPolinom.pFirst;
	TLink* Pol1Link = this->pFirst;
	Pol1Link = Pol1Link->pNext;
	TLink* Pol2Link = polinom.pFirst;
	Pol2Link = Pol2Link->pNext;
	while ((Pol1Link->monom.degree != -1) || (Pol2Link->monom.degree != -1))
	{
		if (Pol1Link->monom.degree < Pol2Link->monom.degree)
		{
			result->pNext = new TLink;
			result = result->pNext;
			result->monom.degree = Pol2Link->monom.degree;
			result->monom.coef = Pol2Link->monom.coef;
			Pol2Link = Pol2Link->pNext;
		}
		else if (Pol1Link->monom.degree > Pol2Link->monom.degree)
		{
			result->pNext = new TLink;
			result = result->pNext;
			result->monom.degree = Pol1Link->monom.degree;
			result->monom.coef = Pol1Link->monom.coef;
			Pol1Link = Pol1Link->pNext;
		}
		else if (Pol1Link->monom.degree == Pol2Link->monom.degree)
		{
			if ((Pol1Link->monom.coef + Pol2Link->monom.coef) == 0)
			{
				Pol1Link = Pol1Link->pNext;
				Pol2Link = Pol2Link->pNext;
				continue;
			}
			result->pNext = new TLink;
			result = result->pNext;
			result->monom.degree = Pol1Link->monom.degree;
			result->monom.coef = Pol1Link->monom.coef + Pol2Link->monom.coef;
			Pol1Link = Pol1Link->pNext;
			Pol2Link = Pol2Link->pNext;
		}
	}
	result->pNext = tmpPolinom.pFirst;

	return tmpPolinom;
}

TPolinom TPolinom::operator*(double var)
{
	TPolinom tmpPolinom = *this;
	TLink* tmp = tmpPolinom.pFirst;
	tmp = tmp->pNext;
	while (tmp->monom.degree != -1)
	{
		tmp->monom.coef = tmp->monom.coef*var;
		tmp = tmp->pNext;
	}

	return tmpPolinom;
}

TPolinom TPolinom::operator*(const TPolinom &polinom)
{
	double var = polinom.pFirst->pNext->monom.coef;
	TPolinom tmpPolinom = *this;
	TLink* tmp = tmpPolinom.pFirst;
	tmp = tmp->pNext;
	while (tmp->monom.degree != -1)
	{
		tmp->monom.coef = tmp->monom.coef*var;
		tmp = tmp->pNext;
	}

	return tmpPolinom;
}
TPolinom TPolinom::operator/(const TPolinom &polinom)
{
	double var = polinom.pFirst->pNext->monom.coef;
	TPolinom tmpPolinom = *this;
	TLink* tmp = tmpPolinom.pFirst;
	tmp = tmp->pNext;
	while (tmp->monom.degree != -1)
	{
		tmp->monom.coef = tmp->monom.coef/var;
		tmp = tmp->pNext;
	}

	return tmpPolinom;
}

TPolinom TPolinom::operator=(const TPolinom &polinom)
{
	this->pFirst = new TLink;
	this->pFirst->monom.coef = 0;
	this->pFirst->monom.degree = -1;
	TLink* tmp = new TLink;
	TLink* startTmp = tmp;
	TLink* curentTLink = polinom.pFirst;
	curentTLink = curentTLink->pNext;
	if (curentTLink->monom.degree == -1)
	{
		startTmp->pNext = this->pFirst;
	}
	while (curentTLink->monom.degree != -1)
	{
		tmp->pNext = new TLink;
		tmp = tmp->pNext;
		tmp->monom.coef = curentTLink->monom.coef;
		tmp->monom.degree = curentTLink->monom.degree;
		curentTLink = curentTLink->pNext;
	}
	this->pFirst->pNext = startTmp->pNext;
	tmp->pNext = this->pFirst;
	return *this;
}

void TPolinom::ShowPolinom()
{
	TLink *tmp = this->pFirst;
	tmp = this->pFirst;
	tmp = tmp->pNext;
	if (tmp->monom.degree == -1)
		cout << "0";
	while (tmp->monom.degree != -1)
	{
		if (tmp->monom.coef != 1)
			cout << tmp->monom.coef;
		if ((tmp->monom.coef == 1) && (tmp->monom.degree == 0))
			cout << tmp->monom.coef;
		if (tmp->monom.degree / (maxDegree*maxDegree) > 0)
		{
			cout << "x";
			if (tmp->monom.degree / (maxDegree*maxDegree) > 1)
				cout << "^" << tmp->monom.degree / (maxDegree*maxDegree);
		}
		if (tmp->monom.degree / maxDegree % maxDegree > 0)
		{
			cout << "y";
			if (tmp->monom.degree / maxDegree % maxDegree > 1)
				cout << "^" << tmp->monom.degree / maxDegree % maxDegree;
		}
		if (tmp->monom.degree % maxDegree > 0)
		{
			cout << "z";
			if (tmp->monom.degree % maxDegree > 1)
				cout << "^" << tmp->monom.degree % maxDegree;
		}
		tmp = tmp->pNext;
		if (tmp->monom.coef != 0)
			if (tmp->monom.coef > 0)
				cout << "+";
	}
	cout << endl;
}

double TPolinom::Calculate(double x, double y, double z)
{
	TLink *tmp = this->pFirst;
	double count = 0;
	double res = 0;
	double tmpint;
	tmp = tmp->pNext;
	while (tmp->monom.degree != -1)
	{
		count = tmp->monom.coef;
		tmpint = 1;
		if (tmp->monom.degree / (maxDegree*maxDegree) != 0)
		{
			for (int i = 0; i < (tmp->monom.degree / (maxDegree*maxDegree)); i++)
				tmpint *= x;
			count *= tmpint;
		}
		tmpint = 1;
		if ((tmp->monom.degree / maxDegree) % maxDegree != 0)
		{
			for (int i = 0; i < (tmp->monom.degree / maxDegree % maxDegree); i++)
				tmpint *= y;
			count *= tmpint;
		}
		tmpint = 1;
		if (tmp->monom.degree % maxDegree != 0)
		{
			for (int i = 0; i < (tmp->monom.degree % maxDegree); i++)
				tmpint *= z;
			count *= tmpint;
		}
		res += count;
		tmp = tmp->pNext;
	}
	return res;
}

TPolinom TPolinom::Differentiate(int difVar)
{
	TPolinom result;
	TLink *tmp = this->pFirst;
	tmp = tmp->pNext;
	TLink *currentPartOfLink = result.pFirst;
	while (tmp->monom.degree != -1)
	{
		if (difVar == 1)
		{
			if ((tmp->monom.degree / (maxDegree*maxDegree) - 1) >= 0)
			{
				currentPartOfLink->pNext = new TLink;
				currentPartOfLink = currentPartOfLink->pNext;
				currentPartOfLink->monom.degree = tmp->monom.degree;
				currentPartOfLink->monom.degree -= 1*maxDegree*maxDegree;
				currentPartOfLink->monom.coef = tmp->monom.coef*(tmp->monom.degree / (maxDegree*maxDegree));
			}
		}
		if (difVar == 2)
		{
			if (((tmp->monom.degree / maxDegree % maxDegree) - 1) >= 0)
			{
				currentPartOfLink->pNext = new TLink;
				currentPartOfLink = currentPartOfLink->pNext;
				currentPartOfLink->monom.degree = tmp->monom.degree;
				currentPartOfLink->monom.degree -= 1 * maxDegree;
				currentPartOfLink->monom.coef = tmp->monom.coef*(tmp->monom.degree / maxDegree % maxDegree);
			}
		}
		if (difVar == 3)
		{
			if ((tmp->monom.degree % maxDegree - 1) >= 0)
			{
				currentPartOfLink->pNext = new TLink;
				currentPartOfLink = currentPartOfLink->pNext;
				currentPartOfLink->monom.degree = tmp->monom.degree;
				currentPartOfLink->monom.degree--;
				currentPartOfLink->monom.coef = tmp->monom.coef*(tmp->monom.degree % maxDegree);
			}
		}
		tmp = tmp->pNext;
	}
	currentPartOfLink->pNext = result.pFirst;
	return result;
}

TPolinom TPolinom::Integrate(int integrVar)
{
	TPolinom result;
	TLink *tmp = this->pFirst;
	tmp = tmp->pNext;
	TLink *currentPartOfLink = result.pFirst;
	while (tmp->monom.degree != -1)
	{
		if (integrVar == 1)
		{
			if ((tmp->monom.degree / (maxDegree*maxDegree))+1 == maxDegree)
			{
				cout << "Невозможно проинтегрировать слишком большая степень в результате" << endl;
				TPolinom zero;
				return zero;
			}
				currentPartOfLink->pNext = new TLink;
				currentPartOfLink = currentPartOfLink->pNext;
				currentPartOfLink->monom.degree = tmp->monom.degree;
				currentPartOfLink->monom.degree += 1 * maxDegree*maxDegree;
				currentPartOfLink->monom.coef = tmp->monom.coef / ((tmp->monom.degree / (maxDegree*maxDegree)) + 1);
		}
		if (integrVar == 2)
		{
			if ((tmp->monom.degree / maxDegree % maxDegree)+1 == maxDegree)
			{
				cout << "Невозможно проинтегрировать слишком большая степень в результате" << endl;
				TPolinom zero;
				return zero;
			}
				currentPartOfLink->pNext = new TLink;
				currentPartOfLink = currentPartOfLink->pNext;
				currentPartOfLink->monom.degree = tmp->monom.degree;
				currentPartOfLink->monom.degree += 1 * maxDegree;
				currentPartOfLink->monom.coef = tmp->monom.coef / ((tmp->monom.degree / maxDegree % maxDegree) + 1);

		}
		if (integrVar == 3)
		{
			if ((tmp->monom.degree % maxDegree) + 1 == maxDegree)
			{
				cout << "Невозможно проинтегрировать слишком большая степень в результате" << endl;
				TPolinom zero;
				return zero;
			}
				currentPartOfLink->pNext = new TLink;
				currentPartOfLink = currentPartOfLink->pNext;
				currentPartOfLink->monom.degree = tmp->monom.degree;
				currentPartOfLink->monom.degree++;
				currentPartOfLink->monom.coef = tmp->monom.coef / ((tmp->monom.degree % maxDegree) + 1);
		}
		tmp = tmp->pNext;
	}
	currentPartOfLink->pNext = result.pFirst;
	return result;
}

string TPolinom::PolinomToString()
{
	string str;
	TLink *tmp = this->pFirst;
	int count = 0;
	tmp = tmp->pNext;
	while (tmp->monom.degree != -1)
	{
		tmp = tmp->pNext;
		count++;
	}
	if (count == 0)
	{
		str = "0";
		return str;
	}
	tmp = this->pFirst;
	tmp = tmp->pNext;
	for (int i = 0; i < count; i++)
	{
		if (tmp->monom.coef != 1)
			str+= to_string(tmp->monom.coef);
		if ((tmp->monom.coef == 1) && (tmp->monom.degree == 0))
			str += to_string(tmp->monom.coef);
		if (tmp->monom.degree / (maxDegree*maxDegree) > 0)
		{
			str += "x";
			if (tmp->monom.degree / (maxDegree*maxDegree) > 1)
			{
				str += "^";
				str += to_string(tmp->monom.degree / (maxDegree*maxDegree));
			}
		}
		if (tmp->monom.degree / maxDegree % maxDegree > 0)
		{
			str += "y";
			if (tmp->monom.degree / maxDegree % maxDegree > 1)
			{
				str += "^";
				str += to_string(tmp->monom.degree / maxDegree % maxDegree);
			}
		}
		if (tmp->monom.degree % maxDegree > 0)
		{
			str += "z";
			if (tmp->monom.degree % maxDegree > 1)
			{
				str += "^";
				str += to_string(tmp->monom.degree % maxDegree);
			}
		}
		tmp = tmp->pNext;
		if (tmp->monom.coef != 0)
			if (tmp->monom.coef > 0)
				str+="+";
	}

	return str;
}