#include "var.h"

/*OUTPUT FUNC*/
std::ostream& operator<<(std::ostream& os, const var& obj)
{
	if (obj.varType == 0)
		os << obj.Int;
	else if (obj.varType == 1)
		os << obj.Double;
	else if (obj.varType == 2)
		os << obj.Str;
	return os;
}
