#pragma once
#include "stdafx.h"

std::shared_ptr<IShape> GetFigure(std::string & figureWithParameters);

std::shared_ptr<IShape> GetFigureWithTheMaxArea(std::vector<std::shared_ptr<IShape>> & figures);

std::shared_ptr<IShape> GetFigureWithTheMinPerimeter(std::vector<std::shared_ptr<IShape>> & figures);