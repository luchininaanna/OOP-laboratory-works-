#include "stdafx.h"
#include "CTriangle.h"

using namespace std;

double CTriangle::GetArea() const
{
	//по формуле Герона

	double perimeterHalf = GetPerimeter() / 2;
	double firstEfficient = perimeterHalf - GetSideLength(m_vertex1, m_vertex2);
	double secondEfficient = perimeterHalf - GetSideLength(m_vertex2, m_vertex3);
	double thirdEfficient = perimeterHalf - GetSideLength(m_vertex3, m_vertex1);
		
	return sqrt(perimeterHalf * firstEfficient * secondEfficient * thirdEfficient);
}


double CTriangle::GetPerimeter() const
{
	double perimeter = GetSideLength(m_vertex1, m_vertex2) + GetSideLength(m_vertex2, m_vertex3)
		+ GetSideLength(m_vertex3, m_vertex1);

	return perimeter;
}


void CTriangle::AppendProperties(std::ostream & strm) const
{
	std::string figureInfo = "Shape Type : Triangle\n";

	figureInfo += "Vertex1: " + GetVertex1().ToString()
		+ "\nVertex2: " + GetVertex2().ToString()
		+ "\nVertex3: " + GetVertex3().ToString()
		+ "\nPerimeter: " + std::to_string(GetPerimeter())
		+ "\nArea: " + std::to_string(GetArea());

	strm << figureInfo << std::endl;
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


double CTriangle::GetSideLength(CPoint const & p1, CPoint const & p2) const
{
	return sqrt(pow((p1.GetX() - p2.GetX()), 2)
		+ pow((p1.GetY() - p2.GetY()), 2));
}