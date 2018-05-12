#pragma once
#include "Shape.h"
#include "Point.h"

class CLineSegment
{
public:
	double GetArea() const override;
	double GetPerimeter() const override;
	string ToString() const override;
	string GetOutlineColor() const override;

	CLineSegment();
	CLineSegment(CPoint const & startPoint, CPoint const & endPoint);
	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;
	~CLineSegment();

private:
	CPoint m_startPoint , m_endPoint;
};

