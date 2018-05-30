#pragma once
#include "stdafx.h"

std::shared_ptr<IShape> GetFigure(const std::string & figureWithParameters);

std::shared_ptr<IShape> GetFigureWithTheMaxArea(const std::vector<std::shared_ptr<IShape>> & figures);

std::shared_ptr<IShape> GetFigureWithTheMinPerimeter(const std::vector<std::shared_ptr<IShape>> & figures);