#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <windows.h>

using namespace std;

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char* soughtExpression = argv[2];

	ifstream fin(argv[1]);
	int stringNumber = 0; //����� ������� ������
	string currentString;
	bool isFind = false;

	while (getline(fin, currentString))
	{
		stringNumber++;
		int pos = currentString.find(soughtExpression); // �����
		if (pos > 0) {
			isFind = true;
			cout << stringNumber << endl;
		}
	}

	if (!isFind) {
		cout << "Text not found";
	}

	return 0;
}
