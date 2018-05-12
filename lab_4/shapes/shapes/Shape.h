#pragma once
#include <string>

using namespace std;

class CShape
{
public:
	CShape();

	double GetArea();
	double GetPerimeter();
	string ToString();
	string GetOutlineColor();

	~CShape();
};

