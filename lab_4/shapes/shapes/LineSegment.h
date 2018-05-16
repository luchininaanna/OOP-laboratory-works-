#pragma once
#include "Shape.h"
#include "Point.h"

class CLineSegment : virtual CShape
{
public:
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;

	CLineSegment();
	CLineSegment(CPoint const & startPoint, CPoint const & endPoint);
	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;
	~CLineSegment();

private:
	CPoint m_startPoint , m_endPoint;
};

