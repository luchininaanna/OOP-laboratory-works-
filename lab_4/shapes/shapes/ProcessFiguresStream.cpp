#include "stdafx.h"
#include "ProcessFiguresStream.h"


std::shared_ptr<IShape> GetLine(std::istream& input)
{
	double x, y;

	input >> x >> y;
	CPoint startPoint(x, y);

	input >> x >> y;
	CPoint endPoint(x, y);

	std::string color;
	input >> color;

	return std::make_shared<CLineSegment>(startPoint, endPoint, "red");
}

std::shared_ptr<IShape> GetCircle(std::istream& input)
{
	double x, y;
	input >> x >> y;
	CPoint center(x, y);

	double radius;
	input >> radius;

	std::string fillColor, outlineColor;
	input >> fillColor >> outlineColor;

	if (radius > 0)
	{
		return std::make_shared<CCircle>(center, radius, fillColor, outlineColor);
	}

	return nullptr;
}

std::shared_ptr<IShape> GetRectangle(std::istream& input)
{
	double x, y;
	input >> x >> y;
	CPoint leftTop(x, y);

	double width, height;
	input >> width >> height;

	std::string fillColor, outlineColor;
	input >> fillColor >> outlineColor;

	if (width > 0 && height > 0) {
		return std::make_shared<CRectangle>(leftTop, width, height, fillColor, outlineColor);
	}

	return nullptr;
}

std::shared_ptr<IShape> GetTriangle(std::istream& input)
{
	double x, y;

	input >> x >> y;
	CPoint vertex1(x, y);

	input >> x >> y;
	CPoint vertex2(x, y);

	input >> x >> y;
	CPoint vertex3(x, y);

	std::string fillColor, outlineColor;
	input >> fillColor >> outlineColor;

	return std::make_shared<CTriangle>(vertex1, vertex2, vertex3, fillColor, outlineColor);
}


std::shared_ptr<IShape> GetFigure(const std::string & figureWithParameters)
{
	std::stringstream input{ figureWithParameters };
	std::string figureType;
	input >> figureType;

	if (figureType == "line")
	{
		return GetLine(input);
	}
	else if (figureType == "circle")
	{
		return GetCircle(input);
	}
	else if (figureType == "rectangle")
	{
		return GetRectangle(input);
	}
	else if (figureType == "triangle")
	{
		return GetTriangle(input);
	}
	else {
		return nullptr;
	}
}


std::shared_ptr<IShape> GetFigureWithTheMaxArea(const std::vector<std::shared_ptr<IShape>> & figures)
{
	if (figures.empty())
	{
		return nullptr;
	}

	return *max_element(figures.begin(), figures.end(), [](auto& left, auto& right) {
		return left->GetArea() < right->GetArea();
	});
}


std::shared_ptr<IShape> GetFigureWithTheMinPerimeter(const std::vector<std::shared_ptr<IShape>> & figures)
{
	if (figures.empty())
	{
		return nullptr;
	}

	return *min_element(figures.begin(), figures.end(), [](auto& left, auto& right) {
		return left->GetPerimeter() < right->GetPerimeter();
	});
}