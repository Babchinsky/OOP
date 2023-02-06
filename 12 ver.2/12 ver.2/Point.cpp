#include "Point.h"


Point::Point() : x(0), y(0) {}

Point::Point(int x) : Point()
{
	this->x = x;
}
Point::Point(int x, int y) : Point(x)
{
	this->y = y;
}

Point& Point::operator=(int k)
{
	x = k;
	y = k;
	return *this;
}
Point Point::operator+(int k) const
{
	Point temp(*this);
	temp.x = temp.x + k;
	temp.y = temp.y + k;
	return temp;
}
Point Point::operator-(int k) const
{
	Point temp(*this);
	temp.x = temp.x - k;
	temp.y = temp.y - k;
	return temp;
}
Point Point::operator*(int k) const
{
	Point temp(*this);
	temp.x = temp.x * k;
	temp.y = temp.y * k;
	return temp;
}
Point Point::operator/(int k) const
{
	Point temp(*this);
	temp.x = temp.x / k;
	temp.y = temp.y / k;
	return temp;
}
Point Point::operator-() const
{
	return Point(-x, -y);
}

bool Point::operator>(const Point& obj) const
{
	return (x > obj.x && y > obj.y);
}
bool Point::operator<(const Point& obj) const
{
	return (x < obj.x && y < obj.y);
}
bool Point::operator>=(const Point& obj) const
{
	return (x >= obj.x && y >= obj.y);
}
bool Point::operator<=(const Point& obj) const
{
	return (x <= obj.x && y <= obj.y);
}


std::ostream& operator<<(std::ostream& os, const Point& obj)
{
	os << '(' << obj.x << ',' << obj.y << ')';
	return os;
}

/*Перегрузка функций*/
Point operator+(int k, const Point& obj)
{
	return Point(obj + k);
}
Point operator-(int k, const Point& obj)
{
	return Point((-obj) + k);
}
Point operator*(int k, const Point& obj)
{
	return Point(obj * k);
}
Point operator/(int k, const Point& obj)
{
	return Point(k / obj.GetX(), k / obj.GetY());
}
