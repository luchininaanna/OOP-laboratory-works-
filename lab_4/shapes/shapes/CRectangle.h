#pragma once
#include "CSolidShape.h"
#include "CPoint.h"

class CRectangle : public CSolidShape
{
public:
	CRectangle();
	CRectangle(CPoint const & leftTop, CPoint const & rightBottom, 
		const std::string & fillColor, const std::string& outlineColor);

	virtual double GetArea() const override;
	virtual double GetPerimeter() const override;
	virtual std::string ToString() const override;

	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth();
	double GetHeight();

	~CRectangle();

private:
	CPoint m_leftTop, m_rightBottom;
	double m_width, m_height;
};