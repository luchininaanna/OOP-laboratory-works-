#pragma once
#include "SolidShape.h"
#include "Point.h"

class CRectangle : public CSolidShape
{
public:
	double GetArea() const override;
	double GetPerimeter() const override;
	string ToString() const override;
	string GetOutlineColor() const override;

	CRectangle();
	CRectangle(CPoint const & leftTop, CPoint const & rightBottom);
	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth();
	double GetHeight();
	~CRectangle();

private:
	CPoint m_leftTop, m_rightBottom;
	double m_width, m_height;
};

