#include "stdafx.h"
#include <iostream>
#include <string>
#include "Triangle.h"
#include "Point.h"
#include "Rectangle.h"
#include "Circle.h"
#include "LineSegment.h"
#include <vector>

using namespace std;


void AddTriangle(vector <CShape> & shapesArray)
{
	cout << "AddTriangle" << endl;

	double x, y;

	cin >> x >> y;
	CPoint point1(x, y);

	cin >> x >> y;
	CPoint point2(x, y);

	cin >> x >> y;
	CPoint point3(x, y);

	CTriangle newTriangle(point1, point2, point3);

	shapesArray.push_back(newTriangle);
}

void AddRectangle(vector <CShape> & shapesArray)
{
	cout << "AddRectangle" << endl;

	double x, y;

	cin >> x >> y;
	CPoint leftTop(x, y);

	cin >> x >> y;
	CPoint rightBottom(x, y);

	CRectangle newRectangle(leftTop, rightBottom);

	shapesArray.push_back(newRectangle);
}

void AddCircle(vector <CShape> & shapesArray)
{
	cout << "AddCircle" << endl;

	double x, y;
	double radius;

	cin >> x >> y;
	CPoint center(x, y);

	cin >> radius;

	CCircle newCircle(center, radius);

	shapesArray.push_back(newCircle);
}

//LineSegment не наследуется от CShape (проблемы с типом вектора)
void AddLineSegment(vector <CShape> & shapesArray) 
{
	cout << "AddLineSegment" << endl;

	double x, y;

	cin >> x >> y;
	CPoint startLine(x, y);

	cin >> x >> y;
	CPoint endLine(x, y);

	//CLineSegment newLineSegment(startLine, endLine);

	//shapesArray.push_back(newLineSegment);
}

void GetParametersForParticularShape(const string & shape, vector <CShape> & shapesArray)
{
	if (shape == "triangle")
	{
		AddTriangle(shapesArray);
	}

	if (shape == "rectangle")
	{
		AddRectangle(shapesArray);
	}

	if (shape == "circle")
	{
		AddCircle(shapesArray);
	}

	if (shape == "line_segment")
	{
		AddLineSegment(shapesArray);
	}

}

int main(int argc, char *argv[])
{
	cout << "Enter shapes with their parameter values." << endl;
	cout << "Use lower case." << endl;
	cout << "Use spaces for separating of values." << endl;
	cout << "After last character enter space." << endl;
	cout << "Use underscore to separate compound words." << endl;


	string param;
	//vector <CShape> shapesArray;

	while (getline(cin, param, ' ')) {
		if (!param.empty())
		{
			//cout << "*" << param << "*" << endl;
			//GetParametersForParticularShape(param, shapesArray);
		}
	}

    return 0;
}

