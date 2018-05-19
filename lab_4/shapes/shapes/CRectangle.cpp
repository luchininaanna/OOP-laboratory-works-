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


std::string CRectangle::ToString() const
{
	return "";
}


CRectangle::CRectangle()
{
}


CRectangle::CRectangle(CPoint const & leftTop, CPoint const & rightBottom,
	const std::string & fillColor, const std::string& outlineColor)
	: m_leftTop(leftTop), m_rightBottom(rightBottom)
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
	return m_rightBottom;
}


double CRectangle::GetWidth()
{
	return m_width;
}


double CRectangle::GetHeight()
{
	return m_height;
}


CRectangle::~CRectangle()
{
}
