#ifndef CHARACTER
#define CHARACTER

#include <iostream>
#include <string>

//forward declaration
class enemy;
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
	int get_maxhp();
	void set_hp(int hp);
	void set_maxHp(int maxHp);
	int get_att();
	void set_att(int att);
	int get_def();
	void set_def(int def);
	int get_lvl();
	int get_winNum();

	//attack getters
	std::string get_aName1();
	std::string get_aName2();
	std::string get_aName3();
	std::string get_aName4();
	virtual void set_AttackNames();

	//we will use these functions every time you defeat an enemy to level up
	void increaseHP(int exp);
	void increaseAtt(int exp);
	void increaseDef(int exp);
	void expPt();	//checks how many battles the character won, and increases stats accordingly

	virtual void displayStats();
	virtual void describeAttacks();
	void damaged(int oppAtt);

	//abilities
	virtual void Attack1(character& c, enemy& e);
	virtual void Attack2(character& c, enemy& e);
	virtual void Attack3(character& c, enemy& e);
	virtual void Attack4(character& c, enemy& e);

	void Inventory(character& c);

	//public members
	//attack names
	std::string aName1;
	std::string aName2;
	std::string aName3;
	std::string aName4;

protected:

	//private members
	std::string name;
	int hp;	//the current hp
	int maxHp; //the constant hp
	int att;
	int def;
	int winNum = 0; //checks how many battles character has won
	int lvl = 1;	//level
	int ExpReq = 1; //a counter that tracks how many battles are required to level up
	
	//class inventory (linked list?)
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
	void Attack1(character& c, enemy& e);
	void Attack2(character& c, enemy& e);
	void Attack3(character& c, enemy& e);
	void Attack4(character& c, enemy& e);
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
	void Attack1(character& c, enemy& e);
	void Attack2(character& c, enemy& e);
	void Attack3(character& c, enemy& e);
	void Attack4(character& c, enemy& e);
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
	void Attack1(character& c, enemy& e);
	void Attack2(character& c, enemy& e);
	void Attack3(character& c, enemy& e);
	void Attack4(character& c, enemy& e);
};

#endif 