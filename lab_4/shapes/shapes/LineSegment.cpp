#include "stdafx.h"
#include "LineSegment.h"


CLineSegment::CLineSegment()
{
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
