#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void getData(string v0, string a0)
{
	const string terminationSignal = "exit";

	enum option { speed, corner };
	option chosenParametr = speed;

	do
	{
		switch (chosenParametr)
		{

		case speed:
			cout << "Enter v0 (or type \'exit\') > ";
			getline(cin, v0);
			break;

		case corner:
			cout << "Enter a0 (or type \'exit\') > ";
			getline(cin, a0);
			break;
		}

		if (chosenParametr == speed)
		{
			chosenParametr = corner;
		}
		else
		{
			chosenParametr = speed;
		}

	} while (a0 != terminationSignal);
}

int processData(string v0, string a0)
{
	// преобразование строки в число (+ ранее совершена проверка на корректность)

	cout << "process" << "\n";
}

int main()
{
	string v0;
	string a0;
	
	getData(v0, a0);

	//объеденить a0 и v0  в одной структуре??
	int distance = processData(v0, a0);

    return 0;
}

//более конкретные названия
//















