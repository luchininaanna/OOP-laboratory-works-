#pragma once
#include "SolidShape.h"
#include "Point.h"

class CRectangle : public CSolidShape
{
public:
	CRectangle();
	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth();
	double GetHeight();
	~CRectangle();

private:
	CPoint m_leftTop, m_rightBottom;
	double m_width, m_height;
};

