#include "stdafx.h"
#include "CTriangle.h"

using namespace std;

double CTriangle::GetArea() const
{
	//�� ������� ������

	double perimeterHalf = GetPerimeter() / 2;
	double firstEfficient = perimeterHalf - m_GetSideLength(m_vertex1, m_vertex2);
	double secondEfficient = perimeterHalf - m_GetSideLength(m_vertex2, m_vertex3);
	double thirdEfficient = perimeterHalf - m_GetSideLength(m_vertex3, m_vertex1);
		
	return sqrt(perimeterHalf * firstEfficient * secondEfficient * thirdEfficient);
}


double CTriangle::GetPerimeter() const
{
	double perimeter = m_GetSideLength(m_vertex1, m_vertex2) + m_GetSideLength(m_vertex2, m_vertex3)
		+ m_GetSideLength(m_vertex3, m_vertex1);

	return perimeter;
}


string CTriangle::ToString() const
{
	return "";
}


CTriangle::CTriangle(CPoint const & p1, CPoint const & p2, CPoint const & p3,
	const std::string & fillColor, const std::string& outlineColor)
	: m_vertex1(p1), m_vertex2(p2), m_vertex3(p3)
{
	SetFillColor(fillColor);
	SetOutlineColor(outlineColor);
}


CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}


CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}


CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}

