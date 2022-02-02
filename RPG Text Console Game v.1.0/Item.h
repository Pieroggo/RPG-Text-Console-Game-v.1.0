#pragma once
#include <string>
class Item {
public:
	int Atk;
	int Def;
	int mHP;
	int type;
	string name;
	Item(){}
	Item(int a, int d, int h, int t, string n) {
		Atk = a;
		Def = d;
		mHP = h;
		type = t;
		name = n;
	}
};