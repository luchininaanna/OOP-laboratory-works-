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

	return std::make_shared<CCircle>(center, radius, fillColor, outlineColor);
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

	return std::make_shared<CRectangle>(leftTop, width, height, fillColor, outlineColor);
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


std::shared_ptr<IShape> GetFigure(std::string & figureWithParameters)
{
	std::stringstream input{figureWithParameters};
	std::string figureType;
	input >> figureType;

	std::cout << figureType;

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
	
	return nullptr;
}


//static bool AreaCompare(auto& left, auto& right)
//{
//	return left->GetArea() < right->GetArea();
//}

std::shared_ptr<IShape> GetFigureWithTheMaxArea(std::vector<std::shared_ptr<IShape>> & figures)
{
	return *max_element(figures.begin(), figures.end(), [](auto& left, auto& right) {
		return left->GetArea() < right->GetArea();
	});

	//return *max_element(figures.begin(), figures.end(), AreaCompare) {
	//	return std::distance(v.begin(), result);
	//});
}


std::shared_ptr<IShape> GetFigureWithTheMinPerimeter(std::vector<std::shared_ptr<IShape>> & figures)
{
	return *min_element(figures.begin(), figures.end(), [](auto& left, auto& right) {
		return left->GetPerimeter() < right->GetPerimeter();
	});
}