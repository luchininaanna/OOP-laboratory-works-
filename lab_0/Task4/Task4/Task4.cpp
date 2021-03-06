#include "stdafx.h"
#include "stdlib.h"
#include <iostream> // std::cout
#include <set>
#include <vector> // std::vector
using namespace std;

double StringToDouble(const char* str, bool& err)
{
	char* pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

double applyOperation(double currentValue, double param, char currentOperation)
{
	if ((currentOperation == '/') && (param == 0))
	{
		printf("Error: It is impossible to divide by zero");
	}
	else
	{
		switch (currentOperation)
		{
		case '+':
		{
			currentValue = currentValue + param;
			break;
		};
		case '-':
		{
			currentValue = currentValue - param;
			break;
		};
		case '*':
		{
			currentValue = currentValue * param;
			break;
		};
		case '/':
		{
			currentValue = currentValue / param;
			break;
		};
		}
	}

	return currentValue;
}

char getOperations(const char* str)
{
	std::vector<char> operations = { '+', '-', '*', '/' };

	char* pLastChar = NULL;
	double param = strtod(str, &pLastChar);

	if ((str == '\0') || (*pLastChar != '\0'))
	{
		//не цифра
		for (auto i : operations)
		{
			if (*pLastChar == i)
			{
				isCorrectOperation = true;
			}
		}
		if (!isCorrectOperation)
		{
			printf("Error: OPERATION is not correct");
		}
	}
	else
	{
		printf("Error: OPERATION was expected, but PARAMETR was got");
	}

	return i;
}

float getOperand(const char* str)
{
	bool err;

	double param = StringToDouble(str, err);
	if (err)
	{
		printf("Error: PARAMETR #%d is not a number\n.", i);
		return 1;
	}
}

int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		printf("Program calculates sum of its command line arguments.\n");
		return 0;
	}
	else
	{
		char currentOperation;
		double currentValue;

		for (int i = 1; i < argc; ++i)
		{
			if (i == 1)
			{
				currentValue = StringToDouble(argv[i], err);
				if (err)
				{
					printf("Error: PARAMETR #%d is not a number\n.", i);
					return 1;
				}
			}

			if (i % 2 == 0)
			{
				//ищем операцию
				char currentOperation = getOperations(argv[i]);
				cout << "operation";
			}
			else
			{
				//ищем аргумент
				double param = getOperand(argv[i]);
				cout << "operand";
			}
		}

		//printf("%.3f", currentValue);
		cout << '\n';
	}

	return 0;
}
