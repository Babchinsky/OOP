#pragma once
class Base
{
protected:
	static int people_on_base;
	static int vehicle_on_base;
	static int petrol_on_base;
	static int goods_on_base;
public:
	Base();
	Base(const int, const int, const int, const int);
	
	void Input();
	void Print() const;
};

