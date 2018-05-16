#pragma once
#include "Shape.h"

class CSolidShape : public CShape
{
public:
	CSolidShape();
	std::string GetFillColor() const;
	~CSolidShape();

private:
	std::string m_fillColor;
};

