// Task5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	std::string v0;
	std::string a0;

	cout << "Enter v0 (or type \'exit\') > ";
	std::cin >> v0;

	cout << "Enter a0 (or type \'exit\') > ";
	std::cin >> a0;

	std::cout << v0 << "\n";
	std::cout << a0 << "\n";

    return 0;
}

