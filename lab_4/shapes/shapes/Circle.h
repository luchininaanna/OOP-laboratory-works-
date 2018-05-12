#pragma once
#include "SolidShape.h"
#include "Point.h"

class CCircle : public CSolidShape
{
public:
	CCircle();
	CPoint GetCenter() const;
	double GetRadius();
	~CCircle();

private:
	CPoint m_center;
	double m_radius;
};

