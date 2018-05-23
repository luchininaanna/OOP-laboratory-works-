#pragma once
#include "CShape.h"
#include "CPoint.h"

class CLineSegment : public CShape
{
public:
	CLineSegment();
	CLineSegment(CPoint const & startPoint, CPoint const & endPoint, const std::string& color);

	virtual double GetArea()const override;
	virtual double GetPerimeter()const override;

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

protected:
	void ShowProperties(std::ostream & strm) const override;

private:
	CPoint m_startPoint , m_endPoint;
};

