#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point( float x, float y ) : x(x), y(y) {}

Point::Point( const Point &copy )
{
	*this = copy;
}

Point &Point::operator=( const Point &src )
{
	(void)src;
	return (*this);
}

Point::~Point() {}

Fixed Point::getX() const { return x; }
Fixed Point::getY() const { return y; }

Fixed cross(Point const& p1, Point const& p2, Point const& p3)
{

}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{

}
