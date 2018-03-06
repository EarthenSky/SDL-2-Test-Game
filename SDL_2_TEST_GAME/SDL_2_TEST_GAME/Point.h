#ifndef POINT
#define POINT

//holds two int values
struct Point {
	double x, y;

	//Point operator+(const Point &pnt) const;
};

/*
Point Point::operator+ (const Point &pnt) const
{
	Point out;

	out.x = (*this).x + pnt.x;
	out.y = (*this).y + pnt.y;

	return out;
}*/

#endif