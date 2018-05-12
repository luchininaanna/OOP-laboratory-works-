#pragma once
#include "SolidShape.h"
#include "Point.h"

class CTriangle : public CSolidShape
{
public:
	CTriangle();
	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;
	~CTriangle();

private:
	CPoint m_p1, m_p2, m_p3;
};

