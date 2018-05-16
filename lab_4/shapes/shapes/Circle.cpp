#include "stdafx.h"
#include "Circle.h"


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


std::string CCircle::GetOutlineColor() const
{
	return "";
}


CCircle::CCircle()
{
}


CCircle::CCircle(CPoint const & center, double radius)
	: m_center(center), m_radius(radius)
{}


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
