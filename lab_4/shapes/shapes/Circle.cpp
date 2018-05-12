#include "stdafx.h"
#include "Circle.h"


double CCircle::GetArea() const
{
	return 0;
}


double CCircle::GetPerimeter() const
{
	return 0;
}


string CCircle::ToString() const
{
	return "";
}


string CCircle::GetOutlineColor() const
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
