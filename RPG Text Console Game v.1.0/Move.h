#pragma once
#include<string>
 class Move {
public:
	string name;
	int type;
	int value;
	int debuffedStat = 0;
	bool isMulti;
	double multiValue=0;
	Move(){}
	Move(string name,int type, int value,bool isMulti,double multiValue=0, int debuffedStat = 0) {
		this->name = name;
		this->type = type;
		this->value = value;
		this->debuffedStat = debuffedStat;
		this->isMulti = isMulti;
		this->multiValue = multiValue;
	}
};