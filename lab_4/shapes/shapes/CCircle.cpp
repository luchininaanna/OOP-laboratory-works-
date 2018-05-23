#include "stdafx.h"
#include "CCircle.h"

#include <string>


double CCircle::GetArea() const
{
	return m_Pi * m_radius * m_radius;
}


double CCircle::GetPerimeter() const
{
	return 2 * m_Pi * m_radius;
}


void CCircle::ShowProperties(std::ostream & strm) const
{
	std::string figureInfo = "Shape Type : Circle\n";

	figureInfo += "Center: " + m_center.ToString()
		+ "\nRadius: " + std::to_string(m_radius)
		+ "\nPerimeter: " + std::to_string(GetPerimeter())
		+ "\nArea: " + std::to_string(GetArea());

	strm << figureInfo << std::endl;
}


CCircle::CCircle()
{
}


CCircle::CCircle(CPoint const & center, double radius, 
	const std::string & fillColor, const std::string& outlineColor)
	: m_center(center), m_radius(radius)
{
	SetFillColor(fillColor);
	SetOutlineColor(outlineColor);
}


CPoint CCircle::GetCenter() const
{
	return m_center;
}


double CCircle::GetRadius()
{
	return m_radius;
}
