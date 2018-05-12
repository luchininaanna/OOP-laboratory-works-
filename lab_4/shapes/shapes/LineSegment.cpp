#include "stdafx.h"
#include "LineSegment.h"


double CLineSegment::GetArea() const
{
	return 0;
}


double CLineSegment::GetPerimeter() const
{
	return 0;
}


string CLineSegment::ToString() const
{
	return "";
}


string CLineSegment::GetOutlineColor() const
{
	return "";
}


CLineSegment::CLineSegment()
{
}

CLineSegment::CLineSegment(CPoint const & startPoint, CPoint const & endPoint)
	:m_startPoint(startPoint), m_endPoint(endPoint)
{}


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
