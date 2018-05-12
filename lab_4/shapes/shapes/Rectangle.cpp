#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle()
{
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
