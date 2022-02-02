#pragma once
#include <string>
class StatMulti {
public:
	std::string Multiname;
	double value;
	StatMulti() {}
	StatMulti(std::string name, double v) {
		Multiname = name;
		value = v;
	}

};