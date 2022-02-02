#pragma once
#include<vector>
#include<array>
#include "Item.h"
#include"StatMulti.h"
#include "Move.h"
//multiplier class (name, number)
class Player {
private:
	/*std::vector<StatMulti*> multis{};*/
	int tAtk;
	int tDef;
	int tHP;
public:
	Item eq[7] = { {0,0,0,0,""},{0,0,0,0,""} ,{0,0,0,0,""} ,{0,0,0,0,""} ,{0,0,0,0,""} ,{0,0,0,0,""} ,{0,0,0,0,""} };
	//Item eqHelmet;
	//Item eqChest;
	//Item eqPants;
	//Item eqBoots;
	//Item eqWep;
	//Item eqAccs1;
	//Item eqAccs2;
	array<Move,4> bMoves = {Move("Normal Attack",1,0,false,0),Move("Strong Attack",1,3,false,0),Move("Heal",2,0,false,0),Move("Attack Debuff",3,0,true,1.2,1)};//1- type(1-attack,2-heal,3-debuff,4-buff) 2-added Value 3- if adds a multiplier 4-the multiplier 5-debuffed stat(1-Atk,2-Def,3-mHP)
	vector<Move> allMoves{};
	int cAtk;
	int cDef;
	int cHP;
	int gettAtk() {
		return tAtk;
	}
	int gettDef() {
		return tDef;
	}
	int gettHP() {
		return tHP;
	}
	void settAtk(int a) {
		tAtk = a;
	}
	void settDef(int a) {
		tDef = a;
	}
	void settHP(int a) {
		tHP = a;
	}
	Player(){}
	Player(int atk, int def, int hp) {
		settAtk(atk);
		settDef(def);
		settHP(hp);
			cAtk = gettAtk();
			cDef = gettDef();
			cHP = gettHP();
	}
};