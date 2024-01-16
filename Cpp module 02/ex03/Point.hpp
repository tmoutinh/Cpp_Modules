#ifndef _POINT_HPP
# define _POINT_HPP
# include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;
public:
	Point();
	~Point();
	Point(const float num1, const float num2);
	Point& operator=(const Point& other);
};






#endif