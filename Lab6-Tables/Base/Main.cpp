#include "Polinoms.h"
#include <string>
#include "LinearTables.h"
#include "HashTables.h"
#include "OrderedTables.h"
#include "postfix.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string strIn;
	string strName;
	unsigned int degree;
	int choice;
	int choice2;
	OrderedTable OrdTable;
	LinearTable LinTable;
	HashTable HTable;
	cout << "                       Лабораторная работа №6" << endl;
	cout << "                               Таблицы" << endl;
	cout << "Введите максимальную степень монома" << endl;
	cin >> degree;
	TPolinom result;
	try
	{
		TPolinom::SetMaxDegree(degree);
	}
	catch (char* ch)
	{
		cout << ch << endl;
		return 1;
	}
	while (true)
	{
		cout << endl;
		cout << "          Меню" << endl;
		cout << "1. Показать все таблицы" << endl;
		cout << "2. Показать выбранную таблицу" << endl;
		cout << "3. Ввести новый полином во все таблицы" << endl;
		cout << "4. Ввести новый полином в выбранную таблицу" << endl;
		cout << "5. Найти полином в выбранной таблице" << endl;
		cout << "6. Удалить полином в выбранной таблице" << endl;
		cout << "7. Ввести арифмитичекое выражение" << endl;
		cout << "0. Выйти из программы" << endl;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			LinTable.ShowTable();
			OrdTable.ShowTable();
			HTable.ShowTable();
			break;
		case 2:
			cout << "Выберите таблицу:" << endl;
			cout << "1. Линейная таблица" << endl;
			cout << "2. Упорядоченная таблица" << endl;
			cout << "3. Хэш таблица" << endl;
			cin >> choice2;
			if ((choice2 < 1) || (choice2 > 3))
			{
				cout << "Неверный ввод" << endl;
				break;
			}
			switch (choice2)
			{
			case 1:
				LinTable.ShowTable();
				break;
			case 2:
				OrdTable.ShowTable();
				break;
			case 3:
				HTable.ShowTable();
				break;
			}
			break;
		case 3:
			cout << "Введите полином:" << endl;
			cin >> strIn;
			cout << "Введите имя полинома:" << endl;
			cin >> strName;
			try
			{
				TPolinom Polinom(strIn);
				LinTable.Insert(strName, strIn);
				OrdTable.Insert(strName, strIn);
				HTable.Insert(strName, strIn);
			}
			catch (char* ch)
			{
				cout << ch << endl;
			}
			break;
		case 4:
			cout << "Введите полином:" << endl;
			cin >> strIn;
			cout << "Введите имя полинома:" << endl;
			cin >> strName;
			cout << "Выберите таблицу:" << endl;
			cout << "1. Линейная таблица" << endl;
			cout << "2. Упорядоченная таблица" << endl;
			cout << "3. Хэш таблица" << endl;
			cin >> choice2;
			if ((choice2 < 1) || (choice2 > 3))
			{
				cout << "Неверный ввод" << endl;
				break;
			}
			try
			{
				TPolinom Polinom(strIn);
				switch (choice2)
				{
				case 1:
					LinTable.Insert(strName, strIn);
					break;
				case 2:
					OrdTable.Insert(strName, strIn);
					break;
				case 3:	
					HTable.Insert(strName, strIn);
					break;
				}
			}
			catch (char* ch)
			{
				cout << ch << endl;
			}
			break;
		case 5:
			cout << "Введите имя полинома:" << endl;
			cin >> strName;
			cout << "Выберите таблицу:" << endl;
			cout << "1. Линейная таблица" << endl;
			cout << "2. Упорядоченная таблица" << endl;
			cout << "3. Хэш таблица" << endl;
			cin >> choice2;
			if ((choice2 < 1) || (choice2 > 3))
			{
				cout << "Неверный ввод" << endl;
				break;
			}
			switch (choice2)
			{
			case 1:
				cout << LinTable.Search(strName).name << "    ";
				LinTable.Search(strName).polinom.ShowPolinom();
				break;
			case 2:
				cout << OrdTable.Search(strName).name << "    ";
				OrdTable.Search(strName).polinom.ShowPolinom();
				break;
			case 3:
				cout << HTable.Search(strName).name << "    ";
				HTable.Search(strName).polinom.ShowPolinom();
				break;
			}
			break;
		case 6:
			cout << "Введите имя полинома:" << endl;
			cin >> strName;
			cout << "Выберите таблицу:" << endl;
			cout << "1. Линейная таблица" << endl;
			cout << "2. Упорядоченная таблица" << endl;
			cout << "3. Хэш таблица" << endl;
			cin >> choice2;
			if ((choice2 < 1) || (choice2 > 3))
			{
				cout << "Неверный ввод" << endl;
				break;
			}
			switch (choice2)
			{
			case 1:
				LinTable.Delete(strName);
				break;
			case 2:
				OrdTable.Delete(strName);
				break;
			case 3:
				HTable.Delete(strName);
				break;
			}
			break;
		/*case 7:
			cout << "Введите выражение" << endl;
			cin >> strIn;
			TPostfix Postfix(strIn);
			if (Postfix.ErrorChecking())
			{
				Postfix.ToPostfix();
				cout << "Арифметическое выражение: " << Postfix.GetInfix() << endl;
				cout << "Постфиксная форма: " << Postfix.GetPostfix() << endl;
				result = Postfix.Calculate(LinTable, OrdTable, HTable);
				cout << "Ответ:  " << result.ShowPolinom << endl;
				cout << "Сохранить? 1.Да" << endl;
				cin >> choice2;
				if (choice2 == 1)
				{
					cout << "Введите имя полинома:" << endl;
					cin >> strName;
					LinTable.Insert(strName, result);
					OrdTable.Insert(strName, result);
					HTable.Insert(strName, result);
				}
			}
			break;
			*/
		case 0:
			return 0;
		}
		if (choice == 7)
		{
			cout << "Введите выражение" << endl;
			cin >> strIn;
			TPostfix Postfix(strIn);
			if (Postfix.ErrorChecking())
			{
				try
				{
					Postfix.ToPostfix();
					cout << "Арифметическое выражение: " << Postfix.GetInfix() << endl;
					cout << "Постфиксная форма: " << Postfix.GetPostfix() << endl;
					result = Postfix.Calculate(LinTable, OrdTable, HTable);
					cout << "Ответ:  ";
					result.ShowPolinom();
					cout << "Сохранить? 1.Да" << endl;
					cin >> choice2;
					if (choice2 == 1)
					{
						cout << "Введите имя полинома:" << endl;
						cin >> strName;
						LinTable.Insert(strName, result);
						OrdTable.Insert(strName, result);
						HTable.Insert(strName, result);
					}
				}
				catch (char* ch)
				{
					cout << ch << endl;
					return 1;
				}
			}
		}
	}

	return 0;
}