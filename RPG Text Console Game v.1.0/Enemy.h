#pragma once
#include<iostream>
#include<map>
#include<string.h>
using namespace std;
class Enemy {
private:
	string name;
	int bAtk;
	int bDef;
	int bHP;
	int dc{};//dc/10000= procent drop q
	
public:
	
	int cAtk;
	int cDef;
	int cHP;
	std::string getName() {
		return name;
	}
	int getbAtk() {
		return bAtk;
	}
	int getbDef() {
		return bDef;
	}
	int getbHP() {
		return bHP;
	}
	int getDc() {
		return dc;
	}
	void setName(std::string a) {
		name = a;
	}
	void setbAtk(int a) {
		bAtk = a;
	}
	void setbDef(int a) {
		bDef = a;
	}
	void setbHP(int a) {
		bHP = a;
	}
	
	void setDc(int a) {
		dc = a;
	}
	
	Enemy(){}
	Enemy(std::string name, int Atk, int Def, int HP, int DC) {
		setName(name);
		setbAtk(Atk);
		setbDef(Def);
		setbHP(HP);
		setDc(DC);
		cAtk = getbAtk();
		cDef = getbDef();
		cHP = getbHP();
	}
	
};

