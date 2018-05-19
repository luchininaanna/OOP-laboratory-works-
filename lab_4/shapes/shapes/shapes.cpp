#include "stdafx.h"
#include <iostream>
#include <string>
#include "CTriangle.h"
#include "CPoint.h"
#include "CRectangle.h"
#include "CCircle.h"
#include "CLineSegment.h"
#include <vector>

using namespace std;


void AddTriangle()
{
	cout << "AddTriangle" << endl;

	double x, y;

	cin >> x >> y;
	CPoint point1(x, y);

	cin >> x >> y;
	CPoint point2(x, y);

	cin >> x >> y;
	CPoint point3(x, y);

	string fillColor;
	cin >> fillColor;

	string outlineColor;
	cin >> outlineColor;

	CTriangle newTriangle(point1, point2, point3, fillColor, outlineColor);
}

void AddRectangle()
{
	cout << "AddRectangle" << endl;

	double x, y;

	cin >> x >> y;
	CPoint leftTop(x, y);

	cin >> x >> y;
	CPoint rightBottom(x, y);

	string fillColor;
	cin >> fillColor;

	string outlineColor;
	cin >> outlineColor;

	CRectangle newRectangle(leftTop, rightBottom, fillColor, outlineColor);
}

void AddCircle()
{
	cout << "AddCircle" << endl;

	double x, y;
	double radius;

	cin >> x >> y;
	CPoint center(x, y);

	cin >> radius;

	string fillColor;
	cin >> fillColor;

	string outlineColor;
	cin >> outlineColor;

	CCircle newCircle(center, radius, fillColor, outlineColor);
}

void AddLineSegment() 
{
	cout << "AddLineSegment" << endl;

	double x, y;

	cin >> x >> y;
	CPoint startLine(x, y);

	cin >> x >> y;
	CPoint endLine(x, y);

	string outlineColor;
	cin >> outlineColor;

	CLineSegment newLineSegment(startLine, endLine, outlineColor);
}



void GetParametersForParticularShape(const string & shape, vector <CShape> & shapesArray)
{
	if (shape == "triangle")
	{
		AddTriangle();
	}

	if (shape == "rectangle")
	{
		AddRectangle();
	}

	if (shape == "circle")
	{
		AddCircle();
	}

	if (shape == "line_segment")
	{
		AddLineSegment();
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

	while (getline(cin, param, ' ')) {
		cout << "*" << param << "*" << endl;
	}

    return 0;
}

