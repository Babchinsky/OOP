#pragma once
#include "Transport.h"
using namespace transport;

namespace bicycle
{
	class Bicycle : public Transport
	{
	protected:
		char* Type;
	public:
		Bicycle();
		Bicycle(const char* name, unsigned short number_of_seats, unsigned short fuel_consumption, const char* type);
		Bicycle(Bicycle& obj);
		~Bicycle();
	
		void Init();
		void Show() const;
	};
}