#ifndef CHARACTER
#define CHARACTER

#include <iostream>
#include <string>


//forward declaration
class enemy;
class NPC;
class inventory;

//BASE CHARACTER
class character
{
public:

	character();
	character(std::string name, int hp, int att, int def);

	//I really think we don't need setters... why would we need to set the hp of your character in game?
	std::string get_name();
	void set_name(std::string name);
	int get_hp();
	int get_maxhp();//this has maxhp, not maxHP is there a difference??
	void set_hp(int hp);
	void set_maxHp(int maxHp);//like here
	int get_att();
	void set_att(int att);
	int get_def();
	void set_def(int def);
	int get_lvl();
	int get_winNum();
	int getLife();
	int getExit();
	int getEnd();
	void setBubQuest(int x);
	void bubMomKill();

	//for items
	int get_healUp();
	int get_attUp();
	int get_defUp();
	int get_deadRat();
	int get_slipperySoap();
	int get_cleaningTips();
	int get_Whendex();
	int get_Mirror();
	int getTokens();
	int getPath();
	void acq_healUp();
	void acq_attUp();
	void acq_defUp();
	void acq_deadRat();
	void use_healUp();
	void use_attUp();
	void use_defUp();
	void use_deadRat();
	void use_slipperySoap();
	void use_cleaningTips(enemy& e);
	void use_Whendex();
	void use_Mirror();
	void acq_slipperySoap();
	void acq_cleaningTips();
	void acq_Whendex();
	void acq_Mirror();
	void acq_cleanPath();
	void Rat_Sale(int num);

	//attack getters
	std::string get_aName1();
	std::string get_aName2();
	std::string get_aName3();
	std::string get_aName4();
	virtual void set_AttackNames();

	//level up
	void increaseHP(int exp);
	void increaseAtt(int exp);
	void increaseDef(int exp);
	void resetStats();
	void expPt();	//checks how many battles the character won, and increases stats accordingly
	void winBattleMoney();

	virtual void displayStats();
	virtual void describeAttacks();
	void damaged(int oppAtt);

	//abilities
	virtual void Attack1(enemy& e);
	virtual void Attack2(enemy& e);
	virtual void Attack3(enemy& e);
	virtual void Attack4(enemy& e);

	//for inventory
	bool noItems();
	void useInventory(enemy& e);
	void checkInventory();

	int getRun();
	void resetRun();


	//for quests
	int getBub();
	void bubKill();
	void bubAdvance();

	//for character progression
	void die();
	void exitingGame();
	void gameCompleted();

	void addMoney(int value);
	void takeMoney(int value);


protected:

	//private members
	std::string name;
	int hp;	//the current hp
	int maxHp; //the constant hp
	int att;
	int maxAtt;
	int def;
	int maxDef;

	int winNum = 0; //checks how many battles character has won
	int lvl = 1;	//level
	int ExpReq = 1; //a counter that tracks how many battles are required to level up
	int HighScore = 0;//a int to track what the character's highscore is in the snake game


	int healUp = 0;	//counter for how many potions a character has
	int attUp = 0;	//counter for how many attack up potions a character has
	int defUp = 0;	//counter for how many defense up potions a character has
	int deadRat = 0; //counter for how many dead rats the character has (its a useless item)
	int slipperySoap = 0;
	int cleaningTips = 0;
	int Whendex = 0;
	int Mirror = 0;
	int cleanPath = 0;

	int life = 1; //1 is alive; 0 is dead
	int exit = 0; //0 is not exit; 1 is exit
	int end = 0;	//0 is not end; 1 is end
	int run = 0;


	int SoapTokens = 0;

	//quest members
	/*depending on your progress, member++*/
	int bubbleQuest = 0;

	//attack names
	std::string aName1;
	std::string aName2;
	std::string aName3;
	std::string aName4;
};

//DERIVED CHARACTER BROOMBA
class Broomba : public character
{
public:
	//constuctor
	Broomba(std::string name, int hp, int att, int def);
	//set attack names
	void set_AttackNames();

	//display stats
	void displayStats();
	void describeAttacks();

	//abilities
	void Attack1(enemy& e);
	void Attack2(enemy& e);
	void Attack3(enemy& e);
	void Attack4(enemy& e);
};

//DERIVED CHARACTER SWIFTERJETWET
class SwifterJetWet : public character
{
public:
	//constructor
	SwifterJetWet(std::string name, int hp, int att, int def);

	//set attack names
	void set_AttackNames();

	//display stats
	void displayStats();
	void describeAttacks();

	//abilities
	void Attack1(enemy& e);
	void Attack2(enemy& e);
	void Attack3(enemy& e);
	void Attack4(enemy& e);
};

//DERIVED CHARACTER BYSONV8
class BysonV8 : public character
{
public:
	//constructor
	BysonV8(std::string name, int hp, int att, int def);

	//set attack names
	void set_AttackNames();

	//display stats
	void displayStats();
	void describeAttacks();

	//abilities
	void Attack1(enemy& e);
	void Attack2(enemy& e);
	void Attack3(enemy& e);
	void Attack4(enemy& e);
};

#endif 