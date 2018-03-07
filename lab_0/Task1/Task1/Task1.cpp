#include "stdafx.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int i;
	int maxRangeValue = 100;
	int minRangeValue = 1;
	const int CHECKING_NUMBER = 2;
	int lastResultValue;

	lastResultValue = minRangeValue;
	lastResultValue = (lastResultValue / CHECKING_NUMBER + 1) * CHECKING_NUMBER;

	for (i = maxRangeValue; i >= minRangeValue; --i)
	{
		if (i % CHECKING_NUMBER == 0)
		{
			cout << ("%d", i);

			if (i != lastResultValue)
			{
				cout <<  ", ";
			}
		}

	}
	cout << "\n";
	return 0;
}