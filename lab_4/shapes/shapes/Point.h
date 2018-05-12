#pragma once
class CPoint
{
public:
	CPoint();
	CPoint(double x, double y);

	double GetX() const;
	double GetY() const;
	~CPoint();

private:
	double m_x, m_y;
};

