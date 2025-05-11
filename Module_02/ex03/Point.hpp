#pragma once
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;
	public:
		Point();
		Point( float x, float y );
		Point( const Point &copy );
		Point &operator=( const Point &src );
		~Point();

		Fixed getX() const;
		Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);