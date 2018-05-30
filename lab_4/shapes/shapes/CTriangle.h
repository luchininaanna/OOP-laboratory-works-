#pragma once
#include "CSolidShape.h"
#include "CPoint.h"

class CTriangle : public CSolidShape
{
public:
	CTriangle(CPoint const & p1, CPoint const & p2, CPoint const & p3, 
		const std::string & fillColor, const std::string& outlineColor);

	double GetArea() const override;
	double GetPerimeter() const override;

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;
	
protected:
	void AppendProperties(std::ostream & strm) const override;

private:
	double GetSideLength(CPoint const & p1, CPoint const & p2) const;

	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
};