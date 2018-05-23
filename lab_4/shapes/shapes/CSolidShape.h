#pragma once

#include "CShape.h"
#include "ISolidShape.h"


class CSolidShape : public CShape, public ISolidShape
{
public:
	std::string GetFillColor() const override;
	void SetFillColor(const std::string & color);
	std::string ToString() const override;

protected:
	void ShowProperties(std::ostream & strm) const = 0;

private:
	std::string m_fillColor;
};
