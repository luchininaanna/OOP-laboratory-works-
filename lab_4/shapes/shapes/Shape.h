#pragma once
#include <string>

class CShape
{
public:
	CShape();

	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
	virtual std::string GetOutlineColor() const = 0;

	~CShape();
};
