#pragma once  

#include "CSolidShape.h"
#include "CPoint.h"

class CCircle : public CSolidShape
{
public:
	double GetArea() const override;
	double GetPerimeter() const override;

	CCircle();
	CCircle(CPoint const & center, double radius, 
		const std::string & fillColor, const std::string& outlineColor);

	CPoint GetCenter() const;
	double GetRadius();

protected:
	void ShowProperties(std::ostream & strm) const override;

private:
	CPoint m_center;
	double m_radius;
};

