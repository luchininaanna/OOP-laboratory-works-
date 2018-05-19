#include "stdafx.h"
#include "CLineSegment.h"
#include <string>


double CLineSegment::GetArea() const
{
	return 0;
}


double CLineSegment::GetPerimeter() const
{
	return sqrt(pow((m_endPoint.GetX() - m_startPoint.GetX()), 2)
		+ pow((m_endPoint.GetY() - m_startPoint.GetY()), 2));
}


std::string CLineSegment::ToString() const
{
	return "";
}


CLineSegment::CLineSegment()
{
}


CLineSegment::CLineSegment(CPoint const & startPoint, CPoint const & endPoint, const std::string& color)
	:m_startPoint(startPoint), m_endPoint(endPoint)
{
	SetOutlineColor(color);
}


CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}


CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}


CLineSegment::~CLineSegment()
{
}
