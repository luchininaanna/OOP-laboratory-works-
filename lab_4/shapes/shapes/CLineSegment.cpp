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


void CLineSegment::AppendProperties(std::ostream & strm) const
{
	std::string figureInfo = "Shape Type : Line\n";

	figureInfo += "StartPoint: " + m_startPoint.ToString()
		+ "\nEndPoint: " + m_endPoint.ToString()
		+ "\nPerimeter: " + std::to_string(GetPerimeter())
		+ "\nArea: " + std::to_string(GetArea());

	strm << figureInfo << std::endl;
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