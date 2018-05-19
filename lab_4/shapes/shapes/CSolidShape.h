#pragma once

#include "CShape.h"
#include "ISolidShape.h"


class CSolidShape : public CShape, public ISolidShape
{
public:

	std::string GetFillColor() const override;

	void SetFillColor(const std::string & color);

private:
	std::string m_fillColor;
};
