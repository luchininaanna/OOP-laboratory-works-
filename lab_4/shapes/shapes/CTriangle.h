#pragma once
#include "CSolidShape.h"
#include "CPoint.h"

class CTriangle : public CSolidShape
{
public:
	CTriangle(CPoint const & p1, CPoint const & p2, CPoint const & p3, 
		const std::string & fillColor, const std::string& outlineColor);

	virtual double GetArea() const override;
	virtual double GetPerimeter() const override;
	virtual std::string ToString() const override;

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

private:
	double m_GetSideLength(CPoint const & p1, CPoint const & p2) const
	{
		return sqrt(pow((p1.GetX() - p2.GetX()), 2)
			+ pow((p1.GetY() - p2.GetY()), 2));
	}

	CPoint m_vertex1, m_vertex2, m_vertex3;
};