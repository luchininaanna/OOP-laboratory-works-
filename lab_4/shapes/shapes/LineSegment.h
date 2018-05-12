#pragma once
#include "Shape.h"
#include "Point.h"

class CLineSegment
{
public:
	CLineSegment();
	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;
	~CLineSegment();

private:
	CPoint m_startPoint , m_endPoint;
};

