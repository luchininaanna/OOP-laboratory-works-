#include "stdafx.h"
#include "CPoint.h"


CPoint::CPoint(double x, double y)
{
	m_x = x;
	m_y = y;
}


CPoint::CPoint()
{

}


double CPoint::GetX() const
{
	return m_x;
}


double CPoint::GetY() const
{
	return m_y;
}


CPoint::~CPoint()
{
}


std::string CPoint::ToString() const
{
	std::string pointInfo;
	pointInfo = "[" + std::to_string(GetX()) + ", " + std::to_string(GetY()) + "]";
	return pointInfo;
}
