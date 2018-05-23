#include "stdafx.h"
#include "..\shapes\CPoint.h"
#include "..\shapes\CShape.h"
#include "..\shapes\CLineSegment.h"
#include "..\shapes\CTriangle.h"
#include "..\shapes\CRectangle.h"
#include "..\shapes\CCircle.h"
#include "..\shapes\ProcessFiguresStream.h"
#include <sstream>


bool PointsAreEqual(const CPoint& first, const CPoint& second)
{
	return first == second;
}

BOOST_AUTO_TEST_SUITE(Point)


BOOST_AUTO_TEST_CASE(GetCoord)
{
	CPoint point(1, -1);

	BOOST_CHECK_EQUAL(point.GetX(), 1);
	BOOST_CHECK_EQUAL(point.GetY(), -1);
}

BOOST_AUTO_TEST_SUITE_END()

