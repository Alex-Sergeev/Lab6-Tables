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
	cout << "                       ������������ ������ �6" << endl;
	cout << "                               �������" << endl;
	cout << "������� ������������ ������� ������" << endl;
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
		cout << "          ����" << endl;
		cout << "1. �������� ��� �������" << endl;
		cout << "2. �������� ��������� �������" << endl;
		cout << "3. ������ ����� ������� �� ��� �������" << endl;
		cout << "4. ������ ����� ������� � ��������� �������" << endl;
		cout << "5. ����� ������� � ��������� �������" << endl;
		cout << "6. ������� ������� � ��������� �������" << endl;
		cout << "7. ������ ������������� ���������" << endl;
		cout << "0. ����� �� ���������" << endl;
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
			cout << "�������� �������:" << endl;
			cout << "1. �������� �������" << endl;
			cout << "2. ������������� �������" << endl;
			cout << "3. ��� �������" << endl;
			cin >> choice2;
			if ((choice2 < 1) || (choice2 > 3))
			{
				cout << "�������� ����" << endl;
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
			cout << "������� �������:" << endl;
			cin >> strIn;
			cout << "������� ��� ��������:" << endl;
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
			cout << "������� �������:" << endl;
			cin >> strIn;
			cout << "������� ��� ��������:" << endl;
			cin >> strName;
			cout << "�������� �������:" << endl;
			cout << "1. �������� �������" << endl;
			cout << "2. ������������� �������" << endl;
			cout << "3. ��� �������" << endl;
			cin >> choice2;
			if ((choice2 < 1) || (choice2 > 3))
			{
				cout << "�������� ����" << endl;
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
			cout << "������� ��� ��������:" << endl;
			cin >> strName;
			cout << "�������� �������:" << endl;
			cout << "1. �������� �������" << endl;
			cout << "2. ������������� �������" << endl;
			cout << "3. ��� �������" << endl;
			cin >> choice2;
			if ((choice2 < 1) || (choice2 > 3))
			{
				cout << "�������� ����" << endl;
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
			cout << "������� ��� ��������:" << endl;
			cin >> strName;
			cout << "�������� �������:" << endl;
			cout << "1. �������� �������" << endl;
			cout << "2. ������������� �������" << endl;
			cout << "3. ��� �������" << endl;
			cin >> choice2;
			if ((choice2 < 1) || (choice2 > 3))
			{
				cout << "�������� ����" << endl;
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
			cout << "������� ���������" << endl;
			cin >> strIn;
			TPostfix Postfix(strIn);
			if (Postfix.ErrorChecking())
			{
				Postfix.ToPostfix();
				cout << "�������������� ���������: " << Postfix.GetInfix() << endl;
				cout << "����������� �����: " << Postfix.GetPostfix() << endl;
				result = Postfix.Calculate(LinTable, OrdTable, HTable);
				cout << "�����:  " << result.ShowPolinom << endl;
				cout << "���������? 1.��" << endl;
				cin >> choice2;
				if (choice2 == 1)
				{
					cout << "������� ��� ��������:" << endl;
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
			cout << "������� ���������" << endl;
			cin >> strIn;
			TPostfix Postfix(strIn);
			if (Postfix.ErrorChecking())
			{
				try
				{
					Postfix.ToPostfix();
					cout << "�������������� ���������: " << Postfix.GetInfix() << endl;
					cout << "����������� �����: " << Postfix.GetPostfix() << endl;
					result = Postfix.Calculate(LinTable, OrdTable, HTable);
					cout << "�����:  ";
					result.ShowPolinom();
					cout << "���������? 1.��" << endl;
					cin >> choice2;
					if (choice2 == 1)
					{
						cout << "������� ��� ��������:" << endl;
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