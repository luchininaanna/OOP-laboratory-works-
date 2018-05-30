#pragma warning(disable : 4250)
#pragma once

#include <string>

class IShape
{
public:
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
	virtual std::string GetOutlineColor() const = 0;
	virtual void SetOutlineColor(const std::string & color) = 0;

};