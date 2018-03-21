// Task1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
//#include <clocale> //Обязательно для функции setlocale()
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	//setlocale(LC_ALL, "rus");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	//определение искомой строки;
	char* soughtExpression = argv[2];
	cout << soughtExpression << "*" << endl;
	int length = sizeof(soughtExpression);
	cout << length << endl; //? на единицу больше

	ifstream fin(argv[1]); // открыли файл для чтения
	int stringNumber = 0; //номер текущей строки
	string currentString;

	while (getline(fin, currentString))
	{
		stringNumber++;
		char* charArray = (char*)currentString.c_str();
		char* ptr;
		ptr = strstr(charArray, soughtExpression);

		if (ptr != NULL)
		{

			int position = ptr - charArray + 1;
			char firstCheckingSymbol = charArray[position-2];
			char secondCheckingSymbol = charArray[position + length - 2];

			if (!isalpha(firstCheckingSymbol) && !isalpha(secondCheckingSymbol))
			{
				cout << stringNumber << endl;
			}
		}
	}

	return 0;
}
