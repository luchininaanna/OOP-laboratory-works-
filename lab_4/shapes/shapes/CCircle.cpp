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


std::string CCircle::ToString() const
{
	return "";
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


CCircle::~CCircle()
{
}
