#pragma once
#include "SolidShape.h"
#include "Point.h"

class CTriangle : public CSolidShape
{
public:
	double GetArea() const override;
	double GetPerimeter() const override;
	string ToString() const override;
	string GetOutlineColor() const override;

	CTriangle(CPoint const & p1, CPoint const & p2, CPoint const & p3);
	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;
	~CTriangle();

private:
	CPoint m_p1, m_p2, m_p3;
};

