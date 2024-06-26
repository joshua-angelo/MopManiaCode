#ifndef N_PC
#define N_PC

#include <iostream>
#include <string>

//forward declaration
class character;

//NPC CHARACTER
class NPC
{
public:
	//functions
	NPC();
	bool alreadyTalkedto();
	void finished();
	virtual void dialogue(character& c);
protected:
	int isDone = 0;	//not done
};


//NPC 1

class Duster : public NPC
{
public:

	Duster();

	void dialogue(character& c);
};

//NPC 2 (Eljay)

class Latherus : public NPC
{
public:

	Latherus();

	void dialogue(character& c);
};

//NPC 3 (Eljay)
class Scruberty : public NPC
{
public:

	Scruberty();

	void dialogue(character& c);
};

//NPC 4 (Eljay)

class Fizzletider : public NPC
{
public:

	Fizzletider();

	void dialogue(character& c);
};

//NPC 5 (Eljay)
class Bristlebeard : public NPC
{
public:

	Bristlebeard();

	void dialogue(character& c);
};

//NPC 6 (Seamus)
class bubbleBoy : public NPC
{
public:


	int dilly(character& c);
};

//Bubble Mama (seamus)
class bubbleMama : public NPC
{
public:
	bubbleMama();

	int dilly(character& c);
};

//NPC 7 (Eljay)

/*class DustySwift : public NPC
{
public:

	DustySwift();

	void dialogue(character& c);
};

//NPC 8 (Eljay)

class SirMopsworth : public NPC
{
public:

	SirMopsworth();

	void dialogue(character& c);
};*/

class MrsClean : public NPC
{
public:
	MrsClean();

	void dialogue(character& c);
};

#endif