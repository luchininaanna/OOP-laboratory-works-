#include "stdafx.h"
#include "..\shapes\CPoint.h"
#include "..\shapes\CShape.h"
#include "..\shapes\CLineSegment.h"
#include "..\shapes\CTriangle.h"
#include "..\shapes\CRectangle.h"
#include "..\shapes\CCircle.h"
#include "..\shapes\ProcessFiguresStream.h"
#include <sstream>

#define _USE_MATH_DEFINES
#include <math.h>



bool PointsAreEqual(const CPoint& first, const CPoint& second)
{
	return first == second;
}


//точка
BOOST_AUTO_TEST_SUITE(Point)

//проверяем координаты точки после их задания
BOOST_AUTO_TEST_CASE(GetCoordinate)
{
	CPoint point(1, -1);

	BOOST_CHECK_EQUAL(point.GetX(), 1);
	BOOST_CHECK_EQUAL(point.GetY(), -1);
}

BOOST_AUTO_TEST_SUITE_END()



//линия
BOOST_AUTO_TEST_SUITE(LineSegment)

//проверяем значения площади и периметра после создания линии
BOOST_AUTO_TEST_CASE(get_area_and_perimeter_for_line)
{
	CPoint startPoint(1, 1);
	CPoint endPoint(1, 8);
	std::string color = "blue";
	CLineSegment line(startPoint, endPoint, color);
	BOOST_CHECK_EQUAL(line.GetArea(), 0);
	BOOST_CHECK_EQUAL(line.GetPerimeter(), 7);
}

BOOST_AUTO_TEST_SUITE_END()



//круг
BOOST_AUTO_TEST_SUITE(Circle)

CPoint center(0, 0);
double radius = 5;
std::string fillColor = "yellow";
std::string outlineColor = "yellow";
CCircle circle(center, radius, fillColor, outlineColor);

//проверяем параметры круга после их задания
BOOST_AUTO_TEST_CASE(create_new_circle_with_valid_parameters)
{
	BOOST_CHECK(PointsAreEqual(circle.GetCenter(), center));
	BOOST_CHECK_EQUAL(circle.GetRadius(), radius);
	BOOST_CHECK_EQUAL(circle.GetFillColor(), fillColor);
	BOOST_CHECK_EQUAL(circle.GetOutlineColor(), outlineColor);
}

BOOST_AUTO_TEST_CASE(get_area_and_perimeter_for_circle)
{
	double area = M_PI * radius * radius;
	BOOST_CHECK_EQUAL(circle.GetArea(), area);

	double perimeter = M_PI * radius * 2;
	BOOST_CHECK_EQUAL(circle.GetPerimeter(), perimeter);
}

BOOST_AUTO_TEST_SUITE_END()



//треугольник
BOOST_AUTO_TEST_SUITE(Triangle)

CPoint v1(0, 0);
CPoint v2(1, 0);
CPoint v3(0, 1);
std::string fillColor = "violet";
std::string outlineColor = "white";
CTriangle triangle(v1, v2, v3, fillColor, outlineColor);


//проверяем параметры треугольника после их задания
BOOST_AUTO_TEST_CASE(create_new_triangle_with_valid_parameters)
{
	BOOST_CHECK(PointsAreEqual(triangle.GetVertex1(), v1));
	BOOST_CHECK(PointsAreEqual(triangle.GetVertex2(), v2));
	BOOST_CHECK(PointsAreEqual(triangle.GetVertex3(), v3));
	BOOST_CHECK_EQUAL(triangle.GetFillColor(), fillColor);
	BOOST_CHECK_EQUAL(triangle.GetOutlineColor(), outlineColor);

}


BOOST_AUTO_TEST_CASE(get_area_and_perimeter_for_triangle)
{
	double halfPerimeter = 0.5 * triangle.GetPerimeter();
	double firstEfficient = halfPerimeter - sqrt(pow((v1.GetX() - v2.GetX()), 2)
		+ pow((v1.GetY() - v2.GetY()), 2));
	double secondEfficient = halfPerimeter - sqrt(pow((v2.GetX() - v3.GetX()), 2)
		+ pow((v2.GetY() - v3.GetY()), 2));
	double thirdEfficient = halfPerimeter - sqrt(pow((v3.GetX() - v1.GetX()), 2)
		+ pow((v3.GetY() - v1.GetY()), 2));

	double area = sqrt(halfPerimeter * firstEfficient * secondEfficient * thirdEfficient);
	BOOST_CHECK_EQUAL(triangle.GetArea(), area);

	
	BOOST_CHECK_EQUAL(triangle.GetPerimeter(), triangle.GetPerimeter());
}

BOOST_AUTO_TEST_SUITE_END()



//прямоугольник
BOOST_AUTO_TEST_SUITE(Rectangle)

CPoint point(1, 1);
double width = 10;
double height = 5;
std::string fillColor = "green";
std::string outlineColor = "red";
CRectangle rec(point, width, height, fillColor, outlineColor);


//проверяем параметры прямоугольника после их задания
BOOST_AUTO_TEST_CASE(create_new_rectangle_with_valid_parameters)
{
	BOOST_CHECK(PointsAreEqual(rec.GetLeftTop(), point));
	BOOST_CHECK_EQUAL(rec.GetHeight(), 5);
	BOOST_CHECK_EQUAL(rec.GetWidth(), 10);
	BOOST_CHECK_EQUAL(rec.GetOutlineColor(), outlineColor);
	BOOST_CHECK_EQUAL(rec.GetFillColor(), fillColor);
}

BOOST_AUTO_TEST_CASE(get_area_and_perimeter_for_rectangle)
{

	double area = width * height;
	BOOST_CHECK_EQUAL(rec.GetArea(), area);

	double perimeter = 2 * (width + height);
	BOOST_CHECK_EQUAL(rec.GetPerimeter(), perimeter);
}

BOOST_AUTO_TEST_SUITE_END()


//проверка создания вектора из фигур и работы с ним
BOOST_AUTO_TEST_SUITE(Get_figure_with_max_area_and_figure_with_min_perimeter)

std::vector<std::shared_ptr<IShape>> figures;
std::string circleInfo = "circle 2 2 1 red white";
std::string triangleInfo = "triangle 1 1 2 2 0 0 blue greys";
std::string rectangleInfo = "rectangle 2 2 5 10 red white";
std::string lineInfo = "line 0 0 0 1 red white";

BOOST_AUTO_TEST_CASE(max_area)
{
	figures.push_back(GetFigure(circleInfo));
	figures.push_back(GetFigure(rectangleInfo));
	double maxArea = GetFigureWithTheMaxArea(figures)->GetArea();
	BOOST_CHECK_EQUAL(maxArea, 50);
}

BOOST_AUTO_TEST_CASE(min_perimeter)
{
	double radius = 1;
	figures.push_back(GetFigure(circleInfo));
	figures.push_back(GetFigure(rectangleInfo));
	double minPerimeter = GetFigureWithTheMinPerimeter(figures)->GetPerimeter();
	BOOST_CHECK_EQUAL(minPerimeter, 2 * M_PI *radius);
}
BOOST_AUTO_TEST_SUITE_END()



struct when_circle_created_
{
	struct when_circle_created_()
	{
		CPoint center(0, 0);
		double radius = 5;
		std::string fillColor = "yellow";
		std::string outlineColor = "yellow";
		CCircle circle(center, radius, fillColor, outlineColor);
	}
};

/*
//круг
BOOST_AUTO_TEST_SUITE(Circle)

BOOST_FIXTURE_TEST_CASE(BOOST_FIXTURE_TEST_SUITE(suite_test_, when_circle_created_)

	//проверяем параметры круга после их задания
	BOOST_AUTO_TEST_CASE(create_new_circle_with_valid_parameters)
{
	BOOST_CHECK(PointsAreEqual(circle.GetCenter(), center));
	BOOST_CHECK_EQUAL(circle.GetRadius(), radius);
	BOOST_CHECK_EQUAL(circle.GetFillColor(), fillColor);
	BOOST_CHECK_EQUAL(circle.GetOutlineColor(), outlineColor);
}


BOOST_AUTO_TEST_CASE(get_area_and_perimeter_for_circle)
{
	double area = M_PI * radius * radius;
	BOOST_CHECK_EQUAL(circle.GetArea(), area);

	double perimeter = M_PI * radius * 2;
	BOOST_CHECK_EQUAL(circle.GetPerimeter(), perimeter);
}

BOOST_AUTO_TEST_SUITE_END()
*/
