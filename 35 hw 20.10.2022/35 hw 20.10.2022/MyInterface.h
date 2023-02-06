#pragma once

struct Intf
{

};

struct IAnimal : public Intf // интерфейс в С++ !!!
{
	virtual void Eat() = 0;
	virtual void Move() = 0;
};
//Принцип разделения интерфейса(Interface segregation principle) SOLID
struct IFly : public Intf
{
	virtual void Fly() = 0;
};
struct ISwim : public Intf
{
	virtual void Swim() = 0;
};
