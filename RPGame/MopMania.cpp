#include "character.h"
#include "enemy.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <Windows.h>
#include <stdlib.h>



//global function definitions
void Start_Menu();	//beginning of the game
void Game_Tester_Menu();	//general form of our menus, probably going to be our pause menu
character Mop_Selection();	//user gets to choose a type of mop, then the function will return an instance of class character
void Pause_Menu();	//pauses game to show menu
void Battle_Sequence();	//in-game battle
void GameShop_Menu();	//shopping menu
void GameOver();	//completely clears the terminal and prints game over, completely ending the code
void BattleStats(character& c, enemy& e);	//displays stats of a character and enemy
void Test(character& c);







/*the game*/
int main()
{
	//Start_Menu();
	//GameOver();
	//Game_Tester_Menu();
	//std::cout << "git RKD" << std::endl;
	character c("Bob", 100, 50, 60);
	enemy e(100, 60, 80);

	BattleStats(c, e);

	return 0;
}








//global function definitions
void Start_Menu()
{
#pragma comment(lib, "winmm.lib")
	//play music (ambient music)
	PlaySound(TEXT("void.wav"), NULL, SND_FILENAME | SND_ASYNC);

	//for different text colors
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "You wake up one day with no body... all you see is the void of darkness" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(6));
	std::cout << "You hear a voice calling in the distance:" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(4));
	SetConsoleTextAttribute(h, 6); //Janitorius (Tyler) is yellow text
	std::cout << "My dear soul,";
	std::cout << " I am Janitorius, the custodian of Le Hospitale." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(4));
	std::cout << "You seem to have lost all your memory from that day." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(4));
	std::cout << "You died...";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << " You unfortunately bit your tongue too hard until your legs began to fall off" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::cout << "\nWell anyways, you failed in your previous life so now I will offer you a new life" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "A life as a cleaning mop...";
	std::this_thread::sleep_for(std::chrono::seconds(4));
	std::cout << " Will you accept this new life?";
	SetConsoleTextAttribute(h, 7);
	std::cout << " type: [y/n]" << std::endl;
	std::string choice;
	std::cin >> choice;
	SetConsoleTextAttribute(h, 6);

	if (choice == "y")
	{
		std::cout << "\nAs you should..." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(4));
	}
	else
	{
		PlaySound(0, 0, 0);
		std::this_thread::sleep_for(std::chrono::seconds(5));
		std::cout << "Okay... time to DIE AGAIN..." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(6));
		std::cout << "\033[2J\033[1;1H";
		SetConsoleTextAttribute(h, 7);

		return Start_Menu();
	}

	//end music
	PlaySound(0, 0, 0);
	//end text color
	SetConsoleTextAttribute(h, 7);
}

void GameOver()
{
	PlaySound(TEXT("dies-irae-chant.wav"), NULL, SND_FILENAME | SND_ASYNC);
	std::cout << "\033[2J\033[1;1H";
	std::cout << "\n\n\t\tGAME OVER, YOU DIED.\n" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(5));

	PlaySound(0, 0, 0);
}

void BattleStats(character& c, enemy& e)
{
	//character stats
	std::cout << "-----[ " << c.get_name() << " ]----- " << '\n';
	std::cout << "HP:" << c.get_hp() << '\n';
	std::cout << "Attack: " << c.get_att() << '\n';
	std::cout << "Defense " << c.get_def() << '\n';
	std::cout << "----------------------------" << '\n';

	//enemy stats
	std::cout << "-----[ " << e.get_name() << " ]----- " << '\n';
	std::cout << "HP:" << e.get_hp() << '\n';
	std::cout << "----------------------------" << '\n';
}

void Game_Tester_Menu()
{
	int choice;
	while (true)
	{
		std::cout << "\nMop Mania\n";
		std::cout << "---------------------------------\n";
		std::cout << "1. Return to Game" << '\n';
		std::cout << "2. Enter Battle" << '\n';
		std::cout << "3. Manage Inventory" << '\n';
		std::cout << "4. Enter Shoppie" << '\n';
		std::cout << "5. Talk to Someone" << '\n';
		std::cout << "6. Quit Game" << '\n';
		std::cout << "---------------------------------\n";

		std::cin >> choice;

		if (choice == 6) {
			std::cout << "\nFarewell Mopdian! Come back again next time!" << '\n';
			break;
		}

		if (choice == 1) {
			//function returnToOverworld()
			std::cout << "returnToOverworld()";
			break;
		}
		else if (choice == 2) {
			//function enterBattle()
			std::cout << "enterBattle()";
			break;
		}
		else if (choice == 3) {
			//function manageInventory()
			std::cout << "Inventory()";
			break;
		}
		else if (choice == 4) {
			//function chatter()
			std::cout << "chatter()";
			break;
		}
		else if (choice == 5) {
			//function quitGame()
			std::cout << "quitGame()";
			break;
		}
		else
		{
			std::cout << "try again" << std::endl;
		}
	}
}
void Battle_Sequence(character& c, enemy& e)
{
	int run = 0;	//if character wants to run away from battle
	while (e.get_hp() >= 0 || c.get_hp() >= 0 || run == 0)
	{

		BattleStats(c, e);
		std::cout << "What would you like to do? " << std::endl;
		int choice;
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			c.Attack1(c, e);
			break;
		case 2:
			c.Attack2(c, e);
			break;
		case 3:
			c.Attack3(c, e);
			break;
		case 4:
			c.Attack4(c, e);
			break;
		case 5:
			std::cout << "\033[2J\033[1;1H";
			std::cout << "You ran..." << std::endl;
			run = 1;
			break;
		default:
			std::cout << "Invalid choice, please choose again" << std::endl;
			continue;
		}
	}
}

void Test(character& c) {
	std::cout << c.get_att();
}