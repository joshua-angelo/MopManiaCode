#ifndef ENEMY
#define ENEMY
#include <cstdlib>

//forward declaration
class character;

class enemy
{

public:
	enemy();
	enemy(int lvl);
	std::string get_name();
	void set_name(std::string name); 
	int get_def();
	int get_hp();
	int get_lvl();
	int get_att();
	int get_maxhp();
	int get_maxAtt();
	int get_maxDef();
	void add_hp(int val);
	void add_att(int val);
	void add_def(int val);
	void set_stats(int hp, int att, int def, int lvl);
	bool get_isDead();
	void makeDead();
	void makeAlive();

	//we will use these functions whenever you finish a level to make the enemies harder
	void increaseHP(int exp);
	void increaseAtt(int exp);
	void increaseDef(int exp);

	void nextMove(character& c, int random);
	int RandomNum();
	void damaged(int oppAtt);

	void displayStats();

	virtual void Attack1(character& c);
	virtual void Attack2(character& c);
	virtual void Attack3(character& c);
	virtual void Attack4(character& c);
	virtual void Heal(character& c);
	virtual void Fortify(character& c);
	virtual void Enrage(character& c);

private:

	int att;
	int def;
	int hp;
	std::string name;
	int lvl = 1;
	bool isDead = false;
};

class GarbageDan : public enemy
{
public:
	//constructor
	GarbageDan(int lvl);	//Base: 60 HP, 40 att, 100 defense (high defense but low attack)

	//abilities
	void Attack1(character& c);	//Trash Bash
	void Attack2(character& c);	//Bin Blast
	void Attack3(character& c);	//Stale Food Shooter
	void Attack4(character& c);	//Stench Smear
	void Heal(character& c);	//Mold Sandwich
	void Fortify(character& c);	//Dumpster Dive (raise defense)
	void Enrage(character& c);	//Broken Glass Shuffle

};

class Stainiac : public enemy
{
public:
	//constructor
	Stainiac(int lvl);
};

//enemy (eljay)
class MucusMaw : public enemy
{
public:
	//constructor
	MucusMaw(int lvl);	//Base: 70HP , 60 ATT, 30 DEF (Heavy hitter, but very fraile)
	//abilities
	void Attack1(character& c);	//Slime Spit
	void Attack2(character& c);	//Gooey Grip
	void Attack3(character& c);	//Viscous Vomit
	void Attack4(character& c);	//Flash BOOger
	void Heal(character& c);	//Slimewave Mend
	void Fortify(character& c);	//Slime Shield (raise defense)
	void Enrage(character& c);	//Mucous FURY

};

//level 1 Boss
class GrimeReaper : public enemy
{
	//constructor
	GrimeReaper(int lvl);	//Base: 100 HP, 80 att, 30 def (fast and powerful but low defense boss)

	//abilities
	void Attack1(character& c);
	void Attack2(character& c);
	void Attack3(character& c);
	void Attack4(character& c);
	void Heal(character& c);
	void Fortify(character& c);
	void Enrage(character& c);

};

#endif

