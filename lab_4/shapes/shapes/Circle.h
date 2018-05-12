#pragma once
#include "SolidShape.h"
#include "Point.h"

class CCircle : public CSolidShape
{
public:
	double GetArea() const override;
	double GetPerimeter() const override;
	string ToString() const override;
	string GetOutlineColor() const override;

	CCircle();
	CCircle(CPoint const & center, double radius);

	CPoint GetCenter() const;
	double GetRadius();
	~CCircle();

private:
	CPoint m_center;
	double m_radius;
};

