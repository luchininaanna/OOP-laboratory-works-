#include "stdafx.h"
#include "Triangle.h"


CTriangle::CTriangle()
{
}


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
