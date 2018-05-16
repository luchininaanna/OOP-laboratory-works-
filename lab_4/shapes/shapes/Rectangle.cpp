#include "stdafx.h"
#include "Rectangle.h"


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


std::string CRectangle::GetOutlineColor() const
{
	return "";
}


CRectangle::CRectangle()
{
}


CRectangle::CRectangle(CPoint const & leftTop, CPoint const & rightBottom)
	: m_leftTop(leftTop), m_rightBottom(rightBottom)
{}


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
