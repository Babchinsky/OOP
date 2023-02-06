#pragma once

struct IAnimal // интерфейс в С++ !!!
{
	virtual void Eat() = 0;
	virtual void Move() = 0;
};
//Принцип разделения интерфейса(Interface segregation principle) SOLID
struct IFly
{
	virtual void Fly() = 0;
};

struct ISwim
{
	virtual void Swim() = 0;
};
