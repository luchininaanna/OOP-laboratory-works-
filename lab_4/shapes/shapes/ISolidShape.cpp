#include "stdafx.h"
#include "SolidShape.h"

double CSolidShape::GetArea() const
{
	return 0;
}


double CSolidShape::GetPerimeter() const
{
	return 0;
}


std::string CSolidShape::ToString() const
{
	return "";
}


std::string CSolidShape::GetOutlineColor() const
{
	return "";
}


CSolidShape::CSolidShape()
{
}


std::string CSolidShape::GetFillColor() const
{
	return m_fillColor;
}


CSolidShape::~CSolidShape()
{
}
