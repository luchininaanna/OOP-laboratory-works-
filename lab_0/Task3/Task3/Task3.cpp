#include "stdafx.h"
#include <iostream>

using namespace std;

int PrintFibonacciSequence(int bound)
{
	int predecessor = 1;
	int currentElement = 1;

	if (predecessor <= bound)
	{
		int i = 0;
		bool isNewString = true;

		printf("%d", predecessor);
		i++;
		isNewString = false;

		const int MAX_ELEMENT_IN_LINE = 5;
		bool isError = false;

		while (not isError)
		{

			isError = (predecessor > INT_MAX - currentElement) || (currentElement + predecessor > bound);
			
			if (isNewString)
		    {
				isNewString = false;
		    }
			else
			{
				printf(", ");
			}

			printf("%d", currentElement);
			i++;

			if (i == MAX_ELEMENT_IN_LINE)
			{
				printf("\n");
				i = 0;
				isNewString = true;
			}

			currentElement = currentElement + predecessor;
			predecessor = currentElement - predecessor;
		}
	}
	return 0;
}

int main()
{
	int minValue = 0;
	int maxValue;
	bool err;

	cout << "Enter the integer parameter (upper limit - N)" << "\n";
	cin >> maxValue;

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