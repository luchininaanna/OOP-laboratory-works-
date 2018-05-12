#pragma once
#include <string>

using namespace std;

class CShape
{
public:
	CShape();

	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual string ToString() const = 0;
	virtual string GetOutlineColor() const = 0;

	~CShape();
};

