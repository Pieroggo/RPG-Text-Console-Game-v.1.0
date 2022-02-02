#pragma once
#include "AdvSpace.h"
#include<iostream>
#include <string>
class Renderer {
public:
	string itemTypeR(int t) {
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
		case 7:
			return "Accessory";
			break;
		default:
			return "Undefined";
			break;
		}
	}
	void menuPrint() {
		std::cout << "/help - shows the command list \n/b - proceeds to next story battle\n/inv - checks inventory\n/stat - shows player's stats\n/sit - heals player for 5HP\n/bf - lets player fight previously defeated monsters for loot" << endl;
		/*std::cout<<"Write /help for command list."*/ //s³u¿y jako default
	}
	void enemyAppears(Enemy* enemy) {
		std::cout << enemy->getName() << " attacks!" << endl;
	}
	void printEnemyStats(Enemy* enemy) {
		std::cout << "--- -------- --- -------- --- -------- ---\n||| Atk:" << enemy->cAtk << " ||| Def:" << enemy->cDef << " ||| HP:" << enemy->cHP << "|||\n--- -------- --- -------- --- -------- ---" << std::endl;
	}
	void printPlayerStats(Player* player) {
		cout << "--- -------- --- -------- --- -------- ---\n||| Atk:" << player->cAtk << " ||| Def:" << player->cDef << " ||| HP:" << player->cHP << "|||\n--- -------- --- -------- --- -------- ---" << std::endl;
	}
	void printMoveset(Player* player) {
		cout << "Your Moveset:" << endl;
		cout << "--- -------- --- ---------- --- -------- --- -------- ---\n||| Q:" << player->bMoves[0].name << " ||| W:" << player->bMoves[1].name << " ||| E:" << player->bMoves[2].name << "||| R:"<<player->bMoves[3].name<<"\n-- - -------- -- - -------- -- - -------- -- - -------- -- - " << std::endl;
	}
	void printPAttack(Enemy* target, Player* player, Move move) {
		int x, v;
		double a = player->cAtk + move.value - target->cDef;
		if (a < 1)
			a = 1;
		cout << "You used " << move.name << "!" << endl;
		switch (move.type) {
		case 1:
			
			cout << (target->getName()) << " was hit for " << a << " damage.";
			printEnemyHP(target);
			break;
		case 2:
			cout <<"You healed yourself for " << player->cAtk << " HP.";
			printPlayerHP(player);
			break;
		case 3:
			x = (int)((move.multiValue * 100) - 100);
			cout << (target->getName()) << "'s ";
			switch (move.debuffedStat) {
			case 1:
				cout << "attack ";
				cout << "was decreased by " << x << " percent.";
				printEnemyAtk(target);
				break;
			case 2:
				cout << "defense ";
				cout << "was decreased by " << x << " percent.";
				printEnemyDef(target);
				break;
			case 3:
				cout << "max HP ";
				cout << "was decreased by " << x << " percent.";
				printEnemyHP(target);
				break;
			default:
				cout << "undefined stat ";
				cout << "was decreased by " << x << " percent."<<endl<<"error";
				break;
			}
			break;
		case 4:
			v = (int)((move.multiValue * 100) - 100);
			cout <<"You increased your ";
			switch (move.debuffedStat) {
			case 1:
				cout << "attack ";
				break;
			case 2:
				cout << "defense ";
				break;
			case 3:
				cout << "max HP ";
				break;
			default:
				cout << "undefined stat ";
				break;
			}
			cout << "by " << v << " percent.";
			break;
		default:
			cout << "Move does nothing." << endl;
			break;
}
}
	void printEAttack(Enemy* enemy, int atkType) {
		cout <<"You were hit for " << enemy->cAtk << " damage.";
	}
	void printEnemyHP(Enemy* enemy) {
		cout << "(Enemy's HP: " << enemy->cHP << ")";
	}
	void printEnemyAtk(Enemy* enemy) {
		cout << "(Enemy's Atk: " << enemy->cAtk << ")";
	}
	void printEnemyDef(Enemy* enemy) {
		cout << "(Enemy's Def: " << enemy->cDef << ")";
	}
	void printPlayerHP(Player* player) {
		cout << "(Your HP: " << player->cHP << ")";
	}
	void printPlayerAtk(Player* player) {
		cout << "(Your HP: " << player->cAtk << ")";
	}
	void printPlayerDef(Player* player) {
		cout << "(Your HP: " << player->cDef << ")";
	}
	void newLine(int a) {
		for (int i = 1; i <= a; i++) {
			std::cout << std::endl;
		}
	}
	void printEq(Player* pl){
		bool invemp = true;
		for (int i = 0; i < 7; i++) {
			if (pl->eq[i].type != 0)
				invemp = false;
			if (pl->eq[i].name == "")
				continue;
				cout <<" "<< itemTypeR(i + 1) <<":"<< pl->eq[i].name<<" (ATK="<<pl->eq[i].Atk <<",DEF="<<pl->eq[i].Def<<",HPup="<<pl->eq[i].mHP<<")"<< endl;
			
			
		}
		if (invemp == true) {
			cout << "No equipment got" << endl;
		}
	}
	void sit() {
		cout << "You sit down for a moment and let the wounds heal.";
	}
	void clear() {
		system("cls");
	}
};