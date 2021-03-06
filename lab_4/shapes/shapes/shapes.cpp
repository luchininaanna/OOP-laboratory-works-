#include "stdafx.h"
#include "ProcessFiguresStream.h"

using namespace std;

void PrintInformationForUser()
{
	string informationForUser =
		"Enter shapes with their parameter values.\n"
		"Use lower case.\n"
		"Use spaces for separating of values.\n"
		"After last character enter space.\n"
		"Use underscore to separate compound words.\n"
		"Enter figures in the next form:\n"
		"Line: <line> <start point> <end point> <color>\n"
		"Rectangle: <rectangle> <left top> <width> <height> <fill color> <outline color>\n"
		"Triangle: <triangle> <vertex1> <vertex2> <vertex3> <fill color> <outline color>\n"
		"Circle: <circle> <center> <radius> <fill color> <outline color>\n"
		"Designate the coordinates of Points as follows: <x> <y>";

	cout << informationForUser << endl;
}


int main(int argc, char *argv[])
{
	PrintInformationForUser();

	string figureWithParameters;
	std::vector<std::shared_ptr<IShape>> figures;

	while (getline(cin, figureWithParameters))
	{
		std::shared_ptr<IShape> figurePointer = GetFigure(figureWithParameters);

		if (figurePointer)
		{
			figures.push_back(figurePointer);
			std::cout << figurePointer->ToString() << "\n";
		}
		else
		{
			string informationAboutError =
				"There is invalid form for entering shape parameters.\n"
				"Check the name of figure. Then check amount and validation of parameters.\n";
			std::cout << informationAboutError << endl;
		}

	}

	if (!figures.empty())
	{
		std::cout << "Figure with the max area:\n" << GetFigureWithTheMaxArea(figures)->ToString() << "\n";
		std::cout << "Figure with the min perimeter:\n" << GetFigureWithTheMinPerimeter(figures)->ToString() << "\n";
	}

	system("pause");

	return 0;
}
