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
	//setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы

	//определение искомой строки;
	char* soughtExpression = argv[2];

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
			char checkingSymbol = charArray[position + 2];

			if (!isalpha(checkingSymbol))
			{
				cout << stringNumber << endl;
			}

		}
	}

	return 0;
}
