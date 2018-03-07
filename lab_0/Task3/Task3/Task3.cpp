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
		bool isError = false;

		while (not isError)
		{
			if (i == 0)
			{
				cout << "\n";
			}

			isError = (predecessor > INT_MAX - currentElement) || (currentElement + predecessor > bound);

			cout << ("%d", currentElement);

			if (not isError)
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
	}
	else
	{
		cout << "Error: Еhe program did not receive input data";
	}

	if ((maxValue <= INT_MAX) && (maxValue > 0))
	{
		PrintFibonacciSequence(maxValue);
	}
	else
	{
		cout << "Error: You input invalid value";
	}

	printf("\n");
    return 0;
}