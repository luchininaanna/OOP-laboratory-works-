#pragma once
#include "Shape.h"

class CSolidShape : public CShape
{
public:
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;

	CSolidShape();
	std::string GetFillColor() const;
	~CSolidShape();

private:
	std::string m_fillColor;
};

