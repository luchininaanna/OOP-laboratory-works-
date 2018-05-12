#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void GetParametersForParticularShape(const string & shape)
{
	cout << "It is " << shape << endl;

	if (shape == "triangle")
	{
		cout << "***" << endl;
	}

	if (shape == "rectangle")
	{
		cout << "****" << endl;
	}

	if (shape == "circle")
	{
		cout << "*" << endl;
	}

	if (shape == "line_segment")
	{
		cout << "**" << endl;
	}
	

	//функции для создания элемента

}

int main(int argc, char *argv[])
{
	cout << "Enter shapes with their parameter values." << endl;
	cout << "Use spaces for separating of values." << endl;
	cout << "After last character enter space." << endl;

	string shape;

	while (getline(cin, shape, ' ')) {
		// строка прочитана успешно, с ней можно работать
		cout << "*" << shape << "*" << endl;
		GetParametersForParticularShape(shape);

	}

	system("pause");
    return 0;
}

