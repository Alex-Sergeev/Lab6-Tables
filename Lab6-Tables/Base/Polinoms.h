#ifndef __POLINOMS_H__
#define __POLINOMS_H__
#include <string>
#include <iostream>

using namespace std;

struct TMonom
{
	double coef;
	int degree;
};

struct TLink
{
	TMonom monom;
	TLink* pNext;
};

class TPolinom
{
	TLink* pFirst;
	static int maxDegree;

	void SortByMaxDegree();

public:
	TPolinom();
	TPolinom(char* strch);
	TPolinom(string str);
	TPolinom(const TPolinom &polinom);
	~TPolinom();

	static void SetMaxDegree(unsigned int var)
	{
		if (var > 10000)
			throw("Слишком большая степень");
		if ((var == 10) || (var == 100) || (var == 1000))
			maxDegree = var;
		else
			throw("Степень должна быть кратна 10");
	}
	TPolinom operator+(const TPolinom &polinom);
	TPolinom operator*(double var);
	TPolinom operator*(const TPolinom &polinom);
	TPolinom operator/(const TPolinom &polinom);
	TPolinom operator=(const TPolinom &polinom);
	void ShowPolinom();
	string PolinomToString();
	double Calculate(double x, double y, double z);       
	TPolinom Differentiate(int difVar);        
	TPolinom Integrate(int integrVar);         
};

#endif
