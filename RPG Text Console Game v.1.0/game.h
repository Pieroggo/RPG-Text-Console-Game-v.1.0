#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include "Render.h"
#include "AdvSpace.h"
#include "Story.h"
#include "Move.h"
#include <random>
#include <time.h>
using namespace std;
class Game {
private:
	Renderer render;
	AdvSpace advspace;
	storyboard sb;
	bool run = true;
	bool inGame = true;
	bool gameOn = true;
	bool dev = false;
	int enemiesBeaten = 0; //pierwszy tekst przed walk¹ z nastêpnym, drugi w walce
public:
	char inputChar;
	std::string inputString;
	char slowInput() {
		char c;
		std::cin >> c;
		return c;
	}
	char fastInput() {
		return _getch();
	}
	std::string commInput() {
		std::string a;
		std::cin >> a;
		return a;
	}
	void Run() {
		while (run == true) {
			gameStart();
			system("pause");
		}

	}
	void gamePart1() {
		render.clear();
		int charstat[5][3]{ {3,3,25},{5,1,20},{2,5,40},{4,4,15},{999,999,9999} };

		cout << "Pick a character: \n1-Warrior\n2-Assasin\n3-Tank\n4-Warlord" << endl;
		if (dev == true) {
			cout << "5-Admin (very overpowered stats, can create his own moves, only dev option)" << endl;
		}
		int inp = (int)(slowInput())-49;
		if (inp == 4 && dev == false) {
			cout << "Warning - insufficient clearance for this option." << endl;
			system("pause");
			render.clear();
			gamePart1();
		}
		advspace.createPlayer(charstat[inp][0], charstat[inp][1], charstat[inp][2]);
		gamePart2();
	}
	void gamePart2() {
		Player* pl = advspace.getPlayer();
		render.clear();
		while (inGame == true && run == true) {
			advspace.createNewEnemyRep(enemiesBeaten);
			Enemy* en = advspace.getCurrEnemy();
			sb.printStory(2 * enemiesBeaten);
			render.menuPrint();
			if (dev == true)
				cout << "/mc - move creator, for Dev Mode only" << endl;
			menu(en, pl);
			enemiesBeaten++;
			advspace.destroyCurrEnemy();
			if (enemiesBeaten >= 15) {
				cout << "As you beat the spoon the reality warps around you and the wormhole sucks you in. (Continuation of story in another game ;)  " << endl;
				cout << "You Win!";
				inGame = false;
			}
		}
			run = false;
	}
	void batlfield(Player* pl) {
		cout << "Welcome to the battlefield! You can refight your previous enemies." << endl;//use item chance with fake enemiesBeaten
		system("pause");
		bool battleOn = true;
		while (battleOn == true) {
			mt19937 generator(time(nullptr));
			uniform_int_distribution<int> dist(1, enemiesBeaten-1);
			int rand = dist(generator);
			advspace.createNewEnemyRep(rand-1);
			battleMenu(advspace.getCurrEnemy(), pl, rand-1);
			cout << "Do you want to continue fighting? (y/n)" << endl;
			char c = fastInput();
			if (c == 'n')
				battleOn = false;
		}
		system("pause");
		gamePart2();
	}
	void moveCreator(Player* pl) {
		render.clear();
		Move x;
		cout << "Welcome to Move Creator!\nPick a move type:\n1-Attack\n2-Heal\n3-Debuff\n4-Buff" << endl;
		int inp;
		cin >> inp;
		if (inp >= 1 && inp <= 4) {
			x.type = inp;
			if (inp == 3 || inp == 4) {
				cout << "Pick the stat to buff/debuff." << endl;
				cin >> inp;
				if (inp >= 1 && inp <= 3) {
					x.debuffedStat = inp;
				}
				else {
					cout << "Invalid value, going back to the game." << endl;
					system("pause");
					gamePart2();
				}
			}
		}
		else {
			cout << "Invalid value, going back to the game." << endl;
			system("pause");
			gamePart2();
		}
		cout << "Insert the value added on top of character's Atk. (Insert 0 for no added value)." << endl;
		cin >> inp;
		x.value = inp;
		cout << "Is the move have a multiplier? (Pick 1 if yes, 0 if no)." << endl;
		cin >> inp;
		if (inp == 1 || inp == 0) {
			x.isMulti = (bool)(inp);
			if (inp == 1) {
				cout << "Insert the multiplier (floating-point number format)." << endl;
				double doubleInsert;
				cin >> doubleInsert;
				x.multiValue = doubleInsert;
			}
		}
		else {
			cout << "Invalid value, going back to the game." << endl;
			system("pause");
			gamePart2();
		}
		std::string s;
		cout << "Name your move." << endl;
		cin >> s;
		x.name = s;
		cout << "Pick the slot for the move ( 1->Q , 2->W , 3->E , 4->R )" << endl;
		int input;
		cin >> input;
		if (input >= 1 && input <= 4) {
			pl->allMoves.push_back(pl->bMoves[input - 1]);
			pl->bMoves[input - 1] = x;
			cout << "Move set!" << endl;
			system("pause");
			gamePart2();
		}
		else {
			cout << "Invalid value, going back to the game." << endl;
			system("pause");
			gamePart2();
		}
	}
	void menu(Enemy* e,Player* p) {
		advspace.setCodeMap();
		advspace.setItemNames();
		inputString = commInput();
		int x=advspace.CommandCode[inputString];
		cout << x << endl;
		switch (x) {
			case 1:
				render.menuPrint();
				menu(e,p);
				break;
			case 2:
				sb.printStory(2*enemiesBeaten+1);
				battleMenu(e,p,enemiesBeaten);
				break;
			case 3:
				render.printEq(p);
				menu(e, p);
				break;
			case 4:
				std::cout << "Stats:" << std::endl;
				render.printPlayerStats(advspace.getPlayer());
				menu(e,p);
				break;
			case 5:
				render.sit();
				advspace.sit(p);
				render.printPlayerHP(p);
				menu(e, p);
				break;
			case 6:
				if (enemiesBeaten >= 5) {
					batlfield(p);
				}
				else {
					cout << "Warning: not enough enemies beaten. Beat at least 5 different monsters to enter." << endl;
				}
				menu(e, p);
				break;
			case 7:
				if (dev == false) {
					cout << "Warning - insufficient clearance for this option." << endl;
					menu(e, p);
				}
				else {
					moveCreator(p);
				}
			default:
				std::cout << "";
				menu(e,p);
				break;
			}
		}
	
	void battleMenu(Enemy* enemy,Player* player,int enemyCount) {
		render.enemyAppears(enemy);
		render.printEnemyStats(enemy);
		render.printMoveset(player);
		while (advspace.getCurrEnemy()->cHP> 0 && advspace.getPlayer()->cHP > 0) {
			char c = fastInput();
			switch (c) {
			case 'q': {
				advspace.playerMoveAttack(advspace.getPlayer(), advspace.getCurrEnemy(), player->bMoves[0]);
				render.printPAttack(advspace.getCurrEnemy(), advspace.getPlayer(), player->bMoves[0]);
				render.newLine(1);
				if (advspace.getCurrEnemy()->cHP >= 0) {
					advspace.enemyMoveAttack(advspace.getCurrEnemy(), advspace.getPlayer(), 1);
					render.printEAttack(advspace.getCurrEnemy(), 1);
					render.printPlayerHP(advspace.getPlayer());
				}
				render.newLine(1);
				break;
			}
			case 'w': {
				advspace.playerMoveAttack(advspace.getPlayer(), advspace.getCurrEnemy(), player->bMoves[1]);
				render.printPAttack(advspace.getCurrEnemy(), advspace.getPlayer(), player->bMoves[1]);
				render.newLine(1);
				if (advspace.getCurrEnemy()->cHP >= 0) {
					advspace.enemyMoveAttack(advspace.getCurrEnemy(), advspace.getPlayer(), 1);
					render.printEAttack(advspace.getCurrEnemy(), 1);
					render.printPlayerHP(advspace.getPlayer());
				}
				render.newLine(1);
				break;
			}
			case 'e': {
				render.printPAttack(advspace.getCurrEnemy(), advspace.getPlayer(), player->bMoves[2]);
				advspace.playerMoveAttack(advspace.getPlayer(), advspace.getCurrEnemy(), player->bMoves[2]);
				render.newLine(1);
				if (advspace.getCurrEnemy()->cHP >= 0) {
					advspace.enemyMoveAttack(advspace.getCurrEnemy(), advspace.getPlayer(), 1);
					render.printEAttack(advspace.getCurrEnemy(), 1);
					render.printPlayerHP(advspace.getPlayer());
				}
				render.newLine(1);
				break;
			}
			case 'r': {
				advspace.playerMoveAttack(advspace.getPlayer(), advspace.getCurrEnemy(), player->bMoves[3]);
				render.printPAttack(advspace.getCurrEnemy(), advspace.getPlayer(), player->bMoves[3]);
				render.newLine(1);
				if (advspace.getCurrEnemy()->cHP >= 0) {
					advspace.enemyMoveAttack(advspace.getCurrEnemy(), advspace.getPlayer(), 1);
					render.printEAttack(advspace.getCurrEnemy(), 1);
					render.printPlayerHP(advspace.getPlayer());
				}
				render.newLine(1);
				break;
			}
			case 'i': {
				render.printEq(player);
			}
			default:
				std::cout << "";
				break;
			}
		}
		if (player->cHP <= 0) {
			cout << "You Died! Game Over!" << endl;
			inGame = false;
			run = false;
		}
		if (advspace.getCurrEnemy()->cHP <= 0) {
			cout << "You killed the " << advspace.getCurrEnemy()->getName() << "." << endl;
			advspace.itemChance(enemyCount,advspace.getCurrEnemy(), advspace.getPlayer());
		}
	}
	void gameChoice() {
		int a{};
		cin >> a;
		switch (a) {
		case 1: {
			gamePart1();
			break; }
		case 2: {
			gameRules(dev);
			break; }
		case 3: {
			quit();
			break;
		}
		default: {
			cout << "";
				gameChoice();
			break;
		}

		}
	}
	void gameStart(){
		render.clear();
		cout << "RPG test game: v. alpha 1.0" << endl;
		cout << "Pick an option:\n1-Play the Game\n2-Check the rules\n3-Quit" << endl;
		gameChoice();
	}
	void options() {
		cout << "Options Menu:" << endl;

	}
	void quitBack() {
		int pick{};
		pick = _getch();
		int i = 1;
		while (i != 0) {
			switch (pick) {
			case 49: {
				i = 0;
				gameStart();
				break;
			}
			case 50: {
				i = 0;
				gameStart();
				break;
			}
			case 51: {
				i = 0;
				gameRules(dev);
				break;
			}
			default: {
				cout << "";
				quitBack();
				break;
			}
			}
		}
	}
	void quitCheck() {
		int c;
		c = _getch();
		int i = 1;
		while (i != 0) {

			switch (c) {
			case 27: {
				i = 0;
				run = false;
				break;
			}
			case 13: {
				i = 0;
				cout << "Pick the menu you want to go to.\n1-Start Game\n2-Main Menu\n3-Rules Menu" << endl;//maybe return to point in progress?
				quitBack();
				break;
			}
			default: {
				cout << "";
				quitCheck();
			}
			}
		}
	}
	void quit() { //residue if i want to implement point in gameplay save
		system("cls");
		cout << "Are you sure you want to exit the game?\nPress Esc to quit. Press Enter to go back to the game" << endl;
		quitCheck();
	}	
	void ruleCheck(bool devOn) {
		char c = _getch();
		int i = 1;
		cout << c << endl;
		while (i != 0) {
			switch (c) {
			case 68: {
				i = 0;
				cout << "Input the code:" << endl;
				string s =commInput();
				if (s == "DEV")
					dev = true;
				gameStart();
				break;
			}
			case 13: {
				i = 0;
				gameStart();
				break;
			}
			default: {
				cout << "";
				ruleCheck(devOn);
			}
			}
		}
	}
	void gameRules(bool devOn=false) {
		system("cls");
		cout << "insert random rulz lol" << endl;
		cout << "Dev Mode: ";
		if (devOn == 1)
		cout << "On\nPress Enter to go back to the main menu.";
		else
		cout << "Off\nDev Mode offers a new character with overpowered stats and a mechanic of creating new moves.\n If you want to activate Dev Mode, press D then enter 'DEV', or to get back to main menu, press the Enter key. ";
		
	
		ruleCheck(devOn);
	}

};