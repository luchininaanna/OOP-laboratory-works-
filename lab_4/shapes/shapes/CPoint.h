#pragma once
class CPoint
{
public:
	CPoint();
	CPoint(double x, double y);
	std::string ToString() const;

	double GetX() const;
	double GetY() const;

private:
	double m_x, m_y;
};


bool operator == (CPoint left, CPoint right)
{
return (left.GetX() == right.GetX() && left.GetY() == right.GetY()) ? true : false;
}



