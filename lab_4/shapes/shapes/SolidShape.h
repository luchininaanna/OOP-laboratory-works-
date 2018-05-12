#pragma once
#include "Shape.h"

class CSolidShape : public CShape
{
public:
	CSolidShape();
	string GetFillColor() const;
	~CSolidShape();

private:
	string m_fillColor;
};

