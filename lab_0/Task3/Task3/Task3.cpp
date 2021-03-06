#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int PrintFibonacciSequence(int bound)
{
	int predecessor = 1;
	int currentElement = 1;

	if (predecessor <= bound)
	{
		int i = 0;

		cout << ("%d", predecessor);
		cout << ", ";
		i++;

		const int MAX_ELEMENT_IN_LINE = 5;
		bool overflow = false;

		while (!overflow)
		{
			if (i == 0)
			{
				cout << endl;
			}

			overflow = (predecessor > INT_MAX - currentElement) || (currentElement + predecessor > bound);

			cout << ("%d", currentElement);

			if (not overflow)
			{
				cout << ", ";
			}

			i++;

			if (i == MAX_ELEMENT_IN_LINE)
			{
				i = 0;
			}

			currentElement = currentElement + predecessor;
			predecessor = currentElement - predecessor;
		}
	}
	return 0;
}

int main(int argc, char* argv[])
{
	int minValue = 0;
	int maxValue;
	bool err;

	if (argc > 1)
	{
		maxValue = atoi(argv[1]);
		if ((maxValue <= INT_MAX) && (maxValue > 0))
		{
			PrintFibonacciSequence(maxValue);
		}
		else
		{
			cout << "Error: You input invalid value";
			cout << "Input the number (bound) until 2 000 000 000";
		}
	}
	else
	{
		cout << "This program prints FibonacciSequence" << endl;
		cout << "Error: The program did not receive input data" << endl;
		cout << "Input the number (bound) until 2 000 000 000";
	}

	cout << endl;
    return 0;
}