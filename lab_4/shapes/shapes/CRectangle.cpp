#include "stdafx.h"
#include "CRectangle.h"


double CRectangle::GetArea() const
{
	return m_width * m_height;
}


double CRectangle::GetPerimeter() const
{
	return 2 * (m_width + m_height);
}


CRectangle::CRectangle()
{
}


CRectangle::CRectangle(CPoint leftTop, double width, double height, 
	const std::string& fillColor, const std::string& outlineColor)
	: m_leftTop(leftTop), m_width(width), m_height(height)
{
	SetFillColor(fillColor);
	SetOutlineColor(outlineColor);
}


CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}


CPoint CRectangle::GetRightBottom() const
{
	CPoint m_rightBottom(m_leftTop.GetX() + m_height, m_leftTop.GetY() + m_width);
	return m_rightBottom;
}


double CRectangle::GetWidth() const
{
	return m_width;
}


double CRectangle::GetHeight() const
{
	return m_height;
}


void CRectangle::ShowProperties(std::ostream & strm) const
{
	std::string figureInfo = "Shape Type : Rectangle\n";

	figureInfo += "LeftTopPoint: " + m_leftTop.ToString()
		+ "\nRightBorromPoint: " + GetRightBottom().ToString()
		+ "\nWidth: " + std::to_string(GetWidth())
		+ "\nHeight: " + std::to_string(GetHeight())
		+ "\nPerimeter: " + std::to_string(GetPerimeter())
		+ "\nArea: " + std::to_string(GetArea());

	strm << figureInfo << std::endl;
}