// Task2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include "stdafx.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{

	unsigned char Invert(unsigned char x);
	{
		int base = 256;

		unsigned char res = 0;
		while (x != 0)
		{
			res += (x & 1) * (base >>= 1);
			x >>= 1;
		}

		return res;
	}

	

	//проверка на корректность полученного значения
	int resultNumber = Invert(6);

	cout << resultNumber << endl;

	return 0;
}
