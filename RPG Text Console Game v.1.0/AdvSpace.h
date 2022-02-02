#pragma once
#include <iostream>
#include "Enemy.h"
#include"Player.h"
#include <map>
#include<conio.h>
#include<random>
#include<time.h>
using namespace std;  
class AdvSpace {
private:
	Player player;
	Enemy currEnemy;
public:
	Enemy Enemies[15] = {Enemy("Rat",1,1,10,2500), Enemy("Rat x3",1,1,30,10000), Enemy("Slime",2,2,25,3000),Enemy("Mud Monster",4,0,30,2500),Enemy("Manhole",1,3,80,10000),Enemy("Orc",3,3,50,5000),Enemy("Goblin",4,2,50,5000),Enemy("Ent",2,5,100,10000),Enemy("Fairy",1,1,30,10000),Enemy("Elf Lord",5,3,80,10000),Enemy("Dark Sponge",1,6,120,10000),Enemy("Dark Sponge of Doom",1,6,121,10000),Enemy("Dark Fork of Doom",5,2,80,10000),Enemy("Dark Blanket of Misery",1,3,150,10000),Enemy("Dark Spoon of Executive Extermination",6,6,250,10000)};
	int itemStat[21][5]{ {1,0,1,2,1},{2,0,1,4,2},{3,0,1,3,3},{4,0,1,2,4},{5,2,0,0,5},{6,1,0,0,6},{7,0,0,5,7},{8,0,2,6,1}, {9,0,3,10,2}, {10,0,2,8,3}, {11,0,1,5,4}, {12,4,0,1,5}, {13,0,0,15,6}, {14,2,2,2,7}, {15,0,4,20,1}, {16,0,5,30,2}, {17,0,4,25,3}, {18,0,3,15,4} ,{19,8,0,0,5} ,{20,5,5,5,6}, {21,0,0,50,7} };//0-name,1-atk,2-def,3-mhp,4-type
	map<int,string> ItemNames;
	void setItemNames() {
		ItemNames.insert(pair<int,string>(1,"Worn-out Helmet"));
		ItemNames.insert(pair<int,string>(2,"Worn-out Chestplate"));
		ItemNames.insert(pair<int,string>(3,"Worn-out Leggins"));
		ItemNames.insert(pair<int,string>(4,"Worn-out Boots"));
		ItemNames.insert(pair<int,string>(5,"Wimpy Sword"));
		ItemNames.insert(pair<int,string>(6,"Brown Nugget"));
		ItemNames.insert(pair<int,string>(7,"Old Pendant"));
		ItemNames.insert(pair<int,string>(8, "Forest Helmet"));
		ItemNames.insert(pair<int,string>(9, "Forest Chestplate"));
		ItemNames.insert(pair<int,string>(10, "Forest Pants"));
		ItemNames.insert(pair<int,string>(11, "Forest Boots"));
		ItemNames.insert(pair<int,string>(12, "Sharp Stick"));
		ItemNames.insert(pair<int,string>(13, "Gaia's Moss"));
		ItemNames.insert(pair<int,string>(14, "Gaia's Bark"));
		ItemNames.insert(pair<int,string>(15, "Dark Helmet"));
		ItemNames.insert(pair<int,string>(16, "Dark Chestplate"));
		ItemNames.insert(pair<int,string>(17, "Dark Pantsu"));
		ItemNames.insert(pair<int,string>(18, "Dark Boots"));
	    ItemNames.insert(pair<int,string>(19, "Destructor"));
		ItemNames.insert(pair<int,string>(20, "Restructor"));
		ItemNames.insert(pair<int,string>(21, "Constructor"));
	}
	map<string, int> CommandCode;
	void setCodeMap() {
		CommandCode.insert(pair<std::string, int>("/help", 1));
		CommandCode.insert(pair<std::string, int>("/b", 2));
		CommandCode.insert(pair<std::string, int>("/inv", 3));
		CommandCode.insert(pair<std::string, int>("/stat", 4));
		CommandCode.insert(pair<std::string, int>("/sit", 5));
		CommandCode.insert(pair<std::string, int>("/bf", 6));
		CommandCode.insert(pair<std::string, int>("/mc", 7));
	}
	void createNewEnemyRep(int i) {
		currEnemy = Enemies[i];
	}
	void createNewEnemy(string a, int b, int c, int d,int dc) {
		currEnemy = Enemy(a, b, c, d,dc);
	}
	void destroyCurrEnemy() {
		currEnemy = Enemy("", 0, 0, 0,0);
	}
	void createPlayer(int a, int b, int c) {
		player=Player(a, b, c);
	}
	Player* getPlayer() {
		return (&player);
	}
	Enemy* getCurrEnemy() {
		return (&currEnemy);
	}
	void sit(Player* player) {
		player->cHP += 5;
		if (player->cHP > player->gettHP())
			player->cHP = player->gettHP();
		cout << endl;
	}
	void enemyMoveAttack(Enemy* attacker, Player* target, int type) {
		target->cHP -= attacker->cAtk;
	}
	void playerMoveAttack(Player* attacker, Enemy* target,Move move) {
		double x = attacker->cAtk + move.value - target->cDef;
		if (x < 1) {
			x = 1;
		}
		switch (move.type) {
		case 1:
			target->cHP -= x;
			break;
		case 2:
			attacker->cHP += attacker->cAtk+move.value;
			if (attacker->cHP > attacker->gettHP())
				attacker->cHP = attacker->gettHP();
			break;
		case 3:
			switch (move.debuffedStat) {
			case 1:
				target->cAtk /= move.multiValue;
				break;
			case 2:
				target->cDef /= move.multiValue;
				break;
			case 3:
				target->setbHP(target->getbHP() / move.multiValue);
				break;
			default:
				break;
			}
		case 4:
			switch (move.debuffedStat) {
		case 1:
			player.cAtk *= move.multiValue;
			break;
		case 2:
			player.cDef *= move.multiValue;
			break;
		case 3:
			player.settHP(player.gettHP() * move.multiValue);
			break;
		default:
			break;
		}
			break;
		default:
			cout << "bruh"<<endl;
			break;
		}
	}
	string itemType(int t) {
		switch (t) {
		case 1:
			return "Helmet";
			break;
		case 2:
			return "Chest";
			break;
		case 3:
			return"Legggins";
			break;
		case 4:
			return "Boots";
			break;
		case 5:
			return "Weapon";
			break;
		case 6:
			return "Accessory";
			break;
		default:
			return "Undefined";
			break;
		}
	}
	void eqItem(Item x, Player* pl) {
		char i = _getch();
		switch (i) {
		case 'y':
			if (pl->eq[x.type - 1].type!=0) {
				pl->settAtk(pl->gettAtk()-pl->eq[x.type - 1].Atk);
				pl->cAtk -= pl->eq[x.type - 1].Atk;
				pl->settDef(pl->gettDef() - pl->eq[x.type - 1].Def);
				pl->cDef -= pl->eq[x.type - 1].Def;
				pl->settHP(pl->gettHP() - pl->eq[x.type - 1].mHP);
				pl->cHP -= pl->eq[x.type - 1].mHP;
			}
			pl->eq[x.type - 1] = x;
			pl->settAtk(pl->gettAtk() + x.Atk);
			pl->cAtk += x.Atk;
			pl->settDef(pl->gettDef() + x.Def);
			pl->cDef += x.Def;
			pl->settHP(pl->gettHP() + x.mHP);
			pl->cHP += x.mHP;
			break;
		case 'n':
			break;
		default:
			cout << "";
			eqItem(x, pl);
		}
	}
	void createItem(int a,int b,int c,int d, string e,Player* pl) {
		Item x=Item({ a,b,c,d,e });
		cout << "Do you want to equip " << e << "?";
		if (pl->eq[d - 1].type != 0) {
			cout<<"(current "<<itemType(d)<<"-> "<<pl->eq[d-1].name<<" )";
		}
		cout << endl;
		cout << "Press y to agree, n to decline." << endl;
		eqItem(x, pl);
	}
	
	void itemChance(int enemiesBeaten,Enemy* e,Player* pl) {
		mt19937 generator(time(nullptr));
		uniform_int_distribution<int> dist(1, 10'000);
		int x = dist(generator);
		int zone = enemiesBeaten / 5;
		if (x <= currEnemy.getDc()) {
			cout << "Got a drop!" << endl;
			uniform_int_distribution<int> drop(1, 7);
			int item = drop(generator);
				createItem(itemStat[zone*7+item-1][1], itemStat[zone * 7 + item - 1][2], itemStat[zone * 7 + item - 1][3], itemStat[zone * 7 + item - 1][4], ItemNames[zone*7+item],&(player));
		}
		else {
			cout << "Drop failed." << endl;
		}
	}
	
};