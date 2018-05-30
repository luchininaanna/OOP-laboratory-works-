#pragma once
#include "IShape.h"

class CShape : virtual public IShape
{
public:
	std::string GetOutlineColor() const override;
	void SetOutlineColor(const std::string & color) override;
	std::string ToString() const override;

protected:
	virtual void ShowProperties(std::ostream & strm) const = 0;

private:
	std::string m_outlineColor;
};