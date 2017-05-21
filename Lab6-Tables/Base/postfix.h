#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include "Polinoms.h""
#include "LinearTables.h"
#include "HashTables.h"
#include "OrderedTables.h"
#include <string>
#include "stack.h"
#include <iostream>

using namespace std;

class TPostfix
{
  string infix;
  string postfix;
  string *ArifmOperations;
  char* OperationsPriority;
public:
  TPostfix(string Str)
  {
	  OperationsPriority = new char[6];
	  OperationsPriority[0] = 1;
	  OperationsPriority[1] = 1;
	  OperationsPriority[2] = 2;
	  OperationsPriority[3] = 2;
	  OperationsPriority[4] = 0;
	  OperationsPriority[5] = 0;
	  ArifmOperations = new string[6];;
	  ArifmOperations[0] = '+';
	  ArifmOperations[1] = '-';
	  ArifmOperations[2] = '*';
	  ArifmOperations[3] = '/';
	  ArifmOperations[4] = "(";
	  ArifmOperations[5] = ")";
	  infix = Str;
	  postfix = "Not Exist";
  }
  bool ErrorChecking();
  void ToPostfix();
  string GetInfix() { return infix; }
  string GetPostfix() { return postfix; }
  TPolinom Calculate(LinearTable &LinTable, OrderedTable &OrdTable, HashTable &HTable); // Ввод переменных, вычисление по постфиксной форме
};

#endif
