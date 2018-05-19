#pragma once

#include "CSolidShape.h"
#include "CPoint.h"

class CCircle : public CSolidShape
{
public:
	virtual double GetArea() const override;
	virtual double GetPerimeter() const override;
	virtual std::string ToString() const override;

	CCircle();
	CCircle(CPoint const & center, double radius, 
		const std::string & fillColor, const std::string& outlineColor);

	CPoint GetCenter() const;
	double GetRadius();
	~CCircle();

private:
	CPoint m_center;
	double m_radius;

	double m_Pi = 3.14;
};

