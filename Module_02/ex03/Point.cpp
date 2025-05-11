#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point( float x, float y ) : x(x), y(y) {}

Point::Point( const Point &copy ) : x(copy.x), y(copy.y) {}

Point::~Point() {}

Fixed Point::getX() const { return x; }
Fixed Point::getY() const { return y; }

std::ostream &operator<<(std::ostream &out, const Point &puanto)
{
    out << "x: " << puanto.getX() << "y: " << puanto.getY() << std::endl;
    return out;
}

static Fixed area2(Point const& P, Point const& Q, Point const& R)
{
	// 2×Fläche = |(Q−P)×(R−P)|
	Fixed cross = (Q.getX()-P.getX())*(R.getY()-P.getY())
				- (R.getX()-P.getX())*(Q.getY()-P.getY());
	return (cross < Fixed(0)) ? -cross : cross;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed A0 = area2(a,b,c);
	Fixed A1 = area2(point,b,c);
	Fixed A2 = area2(a,point,c);
	Fixed A3 = area2(a,b,point);
	return (A1.toFloat() + A2.toFloat() + A3.toFloat()) == A0.toFloat();
}
