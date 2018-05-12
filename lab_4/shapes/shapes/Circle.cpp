#include "stdafx.h"
#include "Circle.h"


CCircle::CCircle()
{
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
