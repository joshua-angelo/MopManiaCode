#ifndef _GAMEMAP_H
#define _GAMEMAP_H

#include <iostream>
#include <vector>

//forward declarations
class character;
class enemy;
class event;

class locationNode
{
public:
	//constructor
	locationNode();
	locationNode(std::string title, std::string desc1, std::string desc2, event* nodeEvent);

	//functions
	bool isLeaf();
	std::string getName();
	void setName(std::string name);
	std::string getTitle();
	std::string getDesc1();
	std::string getDesc2();
	void setLeftChild(locationNode* node);
	void setMidChild(locationNode* node);
	void setRightChild(locationNode* node);
	void setParent(locationNode* node);
	locationNode* getRight();
	locationNode* getMid();
	locationNode* getLeft();
	locationNode* getParent();

protected:
	//for the node itself
	std::string name;
	std::string title;
	std::string desc1;	//first line of description
	std::string desc2;	//second line of description

	//pointers to other nodes
	locationNode* parentPtr = NULL;	//points to this node's previous node (the parent node)
	locationNode* leftPtr = NULL;	//points to the node's left child
	locationNode* midPtr = NULL;	//points to the node's middle child
	locationNode* rightPtr = NULL;	//points to the node's right child

	//pointer to specific event that will take place in the node
	event* eventPtr = NULL;

};

class gameMap
{
public:
	gameMap();
	int getSize();
	locationNode* getIndex();
	void toRoot();
	//add root only!
	void addRoot(std::string n, std::string d1, std::string d2, event* ev);
	void birth_leftChild(locationNode* mommy, std::string n, std::string d1, std::string d2, event* ev);
	void birth_midChild(locationNode* mommy, std::string n, std::string d1, std::string d2, event* ev);
	void birth_rightChild(locationNode* mommy, std::string n, std::string d1, std::string d2, event* ev);

	//moving index
	void moveIndex_left();
	void moveIndex_middle();
	void moveIndex_right();
	void moveIndex_back();

	//moving a node pointer
	void move_left(locationNode* i);
	void move_middle(locationNode* i);
	void move_right(locationNode* i);
	void move_back(locationNode* i);

	//function to move and play through the map
	void play(locationNode* i, character& c);
	void displayLocation(locationNode* i);
	void Pause_Menu(character& c);

private:
	locationNode* root = NULL;
	locationNode* index = NULL;
	int size = 0;
};

#endif