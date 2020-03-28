#include "Triangle.h"
double Triangle::printInfo() const noexcept
{
	cout << "Triangle" << endl << "Number of points: 3" << endl << "Points: "
		<< "(" << a.x << "," << a.y << ")" << "(" << b.x << "," << b.y << ")"
		<< "(" << c.x << "," << c.y << ")" << endl << "Perimeter: " << getPerimeter()
		<< endl << "Color: " << getColorAsString() << endl;
}
Triangle::Triangle(const Point& a, const Point& b, const Point& c, const Color& color)
{
	setA(a);
	setB(b);
	setC(c);
	this->color = color;
}

Triangle::Triangle(const vector<Point>& pts, const Color& color)
{
	setA(pts[0]);
	setB(pts[1]);
	setC(pts[2]);

	this->color = color;
}

Triangle::Triangle(const array<Point, NUMBER_OF_CORNERS>& pts, const Color& color)
{
	setA(pts[0]);
	setB(pts[1]);
	setC(pts[2]);

	this->color = color;
}

Point Triangle::getA() const noexcept
{
	return Point();
}

Point Triangle::getB() const noexcept
{
	return Point();
}

Point Triangle::getC() const noexcept
{
	return Point();
}

Triangle::Color Triangle::getColor() const noexcept
{
	return Color();
}

string Triangle::getColorAsString() const noexcept
{
	switch (color)
	{
		case Triangle::Color::RED: return "RED";
		case Triangle::Color::GREEN: return "GREEN";
		case Triangle::Color::BLUE: return "BLUE";
		case Triangle::Color::PINK: return "PINK";
		case Triangle::Color::WHITE: return "WHITE";
		case Triangle::Color::BLACK: return "BLACK";
	}
}

double Triangle::getPerimeter() const noexcept
{
	return a + b + c;
}

bool Triangle::setA(const Point& pt)
{
	pts[0].coords[0] = pt.coords[0];
	pts[0].coords[1] = pt.coords[1];
	return false;
}

bool Triangle::setB(const Point& pt)
{
	pts[1].coords[0] = pt.coords[0];
	pts[1].coords[1] = pt.coords[1];
	return false;
}

bool Triangle::setC(const Point& pt)
{
	pts[2].coords[0] = pt.coords[0];
	pts[2].coords[1] = pt.coords[1];
	return false;
}

bool Triangle::isValid() const
{
	if (a + b > c && a + c > b && b + c > a)
		return true;
	else 
		return false;
}

