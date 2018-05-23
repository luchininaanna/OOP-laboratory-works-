#pragma once
#include "CSolidShape.h"
#include "CPoint.h"

class CRectangle : public CSolidShape
{
public:
	CRectangle();
	CRectangle(CPoint leftTop, double width, double height, 
		const std::string& fillColor, const std::string& outlineColor);

	virtual double GetArea() const override;
	virtual double GetPerimeter() const override;

	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;

protected:
	void ShowProperties(std::ostream & strm) const override;

private:
	CPoint m_leftTop, m_rightBottom;
	double m_width, m_height;
};