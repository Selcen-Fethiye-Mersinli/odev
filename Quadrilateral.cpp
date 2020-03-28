#include "Quadrilateral.h"

double Quadrilateral::printInfo() const noexcept
{
	cout << "Triangle" << endl << "Number of points: 3" 
		<< endl << "Points: " << "(" << a.x << "," << a.y << ")" 
		<< "(" << b.x << "," << b.y << ")" << "(" << c.x << "," << c.y << ")" 
		<< "(" << d.x << "," << d.y << ")" << endl << "Perimeter: " << getPerimeter() 
		<< endl << "Color: " << getColorAsString() << endl;
}

Quadrilateral::Quadrilateral(const Point& a, const Point& c, const Color& color)
{
	setA(a);
	setC(c);

	pts[1].coords[0] = pts[0].coords[0];
	pts[1].coords[1] = pts[2].coords[1];

	pts[3].coords[0] = pts[2].coords[0];
	pts[3].coords[1] = pts[0].coords[1];

	this->color = color;
}

Quadrilateral::Quadrilateral(const Point& a, double width, double height, const Color& color)
{
	pts[1].coords[0] = pts[0].coords[0] + width;   
	pts[1].coords[1] = pts[0].coords[0];         

	pts[2].coords[0] = pts[0].coords[0] + width; 
	pts[2].coords[1] = pts[0].coords[1] - height; 

	pts[3].coords[0] = pts[0].coords[0];         
	pts[3].coords[1] = pts[0].coords[1] - height;  

	this->color = color;
}

Quadrilateral::Quadrilateral(const Point& a, const Point& b, const Point& c, const Point& d, const Color& color)
{
	setA(a);
	setB(b);
	setC(c);
	setD(d);
}

Quadrilateral::Quadrilateral(const array<Point, NUMBER_OF_CORNERS>& pts, const Color& color)
{
	setA(pts[0]);
	setB(pts[1]);
	setC(pts[2]);
	setD(pts[3]);

	this->color = color;
}

Point Quadrilateral::getA() const noexcept
{
	return a;
}

Point Quadrilateral::getB() const noexcept
{
	return b;
}

Point Quadrilateral::getC() const noexcept
{
	return c;
}

Point Quadrilateral::getD() const noexcept
{
	return d;
}

Quadrilateral::Color Quadrilateral::getColor() const noexcept
{
	return color;
}

string Quadrilateral::getColorAsString() const noexcept
{
	switch (color)
	{
	case Quadrilateral::Color::RED: return "RED";
	case Quadrilateral::Color::GREEN: return "GREEN";
	case Quadrilateral::Color::BLUE: return "BLUE";
	case Quadrilateral::Color::WHITE: return "WHITE";
	case Quadrilateral::Color::BLACK: return "BLACK";
	}
}

double Quadrilateral::getPerimeter() const noexcept
{
	return (b.x - a.x) + (b.y - c.y) + (c.x - d.x) + (a.y - d.y);
}

bool Quadrilateral::isValid() const
{
	if (pts[1].coords[0] - pts[0].coords[0] == pts[3].coords[0] - pts[4].coords[0] && 
		pts[0].coords[1] - pts[3].coords[1] == pts[1].coords[1] - pts[2].coords[1])
		return true;
	else 
		return false;
}

bool Quadrilateral::setA(const Point& pt)
{
	pts[0].coords[0] = pt.coords[0];
	pts[0].coords[1] = pt.coords[1];
	return false;
}

bool Quadrilateral::setB(const Point& pt)
{
	pts[1].coords[0] = pt.coords[0];
	pts[1].coords[1] = pt.coords[1];
	return false;
}

bool Quadrilateral::setC(const Point& pt)
{
	pts[2].coords[0] = pt.coords[0];
	pts[2].coords[1] = pt.coords[1];
	return false;
}

bool Quadrilateral::setD(const Point& pt)
{
	pts[3].coords[0] = pt.coords[0];
	pts[3].coords[1] = pt.coords[1];
	return false;
}
