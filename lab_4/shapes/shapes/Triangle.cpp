#include "stdafx.h"
#include "Triangle.h"

using namespace std;

double CTriangle::GetArea() const
{
	return 0;
}


double CTriangle::GetPerimeter() const
{
	return 0;
}


string CTriangle::ToString() const
{
	return "";
}


string CTriangle::GetOutlineColor() const
{
	return "";
}


CTriangle::CTriangle(CPoint const & p1, CPoint const & p2, CPoint const & p3)
	: m_p1(p1), m_p2(p2), m_p3(p3)
{}

CPoint CTriangle::GetVertex1() const
{
	return m_p1;
}


CPoint CTriangle::GetVertex2() const
{
	return m_p2;
}


CPoint CTriangle::GetVertex3() const
{
	return m_p3;
}


CTriangle::~CTriangle()
{
}
