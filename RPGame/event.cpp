#include "event.h"
#include "enemy.h"
#include "character.h"
#include "battle.h"

/*base event*/
event::event() {};
event::event(std::string music)
{
	this->music = music;
}
void event::trigger(character& c)
{
	if (this->isDone == true) {
		return;	//if character has already triggered the event in this node
	}
	else {
		playMusic("metalPipe.wav");
		std::cout << "Things will happen" << std::endl;
		this->isDone = true;
		system("pause");
		return;
	}
}


/*waiting room event*/
waitingRoomEvent::waitingRoomEvent(std::string music, enemy* one, enemy* two, enemy* three, battle* b)
{
	this->one = one;
	this->two = two;
	this->three = three;
	this->Garbagebattle = b;
}
void waitingRoomEvent::trigger(character& c)
{
	if (this->isDone == true) {
		return;	//if character has already triggered the event in this node
	}
	else {
		endMusic();
		//playMusic();
		Sdelay(2);
		std::cout << "You entered the waiting room... ";
		MSdelay(1000);
		std::cout << "A rancid stench fills the air..." << std::endl;
		MSdelay(2000);
		std::cout << "You feel a dark presence around you..." << std::endl;
		MSdelay(3000);
		std::cout << "A garbage can fell to the ground and trash fell all over the place...";
		MSdelay(3000);
		Dotdot();
		color(4);
		std::cout << "OHH...";
		MSdelay(100);
		std::cout << "NOOO!!!" << std::endl;
		Sdelay(2);
		color(7);
		std::cout << "A GarbageDan appeared from nowhere!" << std::endl;
		playSFX("battle!.wav");
		Sdelay(2);
		Garbagebattle->Battle_Sequence(c, *one);
		if (c.getLife() == 0) {
			return;	//if the character is dead
		}
		Sdelay(2);
		std::cout << "The stench is still in the air..." << std::endl;
		MSdelay(3000);
		Dotdot();
		color(4);
		std::cout << "OHH...";
		MSdelay(200);
		std::cout << "NOOO!!!" << std::endl;
		Sdelay(2);
		color(7);
		std::cout << "Another GarbageDan appeared from nowhere!" << std::endl;
		playSFX("battle!.wav");
		Sdelay(2);
		Garbagebattle->Battle_Sequence(c, *two);
		if (c.getLife() == 0) {
			return;	//if the character is dead
		}
		Sdelay(2);
		std::cout << "The stench is starting to dissipate..." << std::endl;
		MSdelay(3000);
		Dotdot();
		color(4);
		std::cout << "OHH...";
		MSdelay(200);
		std::cout << "NOOO!!!" << std::endl;
		Sdelay(2);
		color(7);
		std::cout << "Another GarbageDan appeared from nowhere!" << std::endl;
		playSFX("battle!.wav");
		Sdelay(2);
		Garbagebattle->Battle_Sequence(c, *three);
		if (c.getLife() == 0) {
			return;	//if the character is dead
		}
		Dotdot();
		std::cout << "The stench is gone!" << std::endl;
		Sdelay(3);
		clear();
		playMusic("void.wav");
		color(6);
		std::cout << "Janitorius: You have done well my dear " << c.get_name() << "..." << std::endl;
		Sdelay(4);
		std::cout << "You have restored this room to how it once was..." << std::endl;
		Sdelay(2);
		std::cout << "It smells... so good now..." << std::endl;
		Sdelay(4);
		clear();
		std::cout << "I have faith in you... ";
		Sdelay(3);
		std::cout << "Continue on your journey...and..." << std::endl;
		Sdelay(3);
		std::cout << "save... ";
		MSdelay(2500);
		std::cout << "me... ";
		MSdelay(2500);
		std::cout << "from... my mis-";
		MSdelay(1000);
		endMusic();

		this->isDone = true;
		return;
	}

}


/*StorageRoomevent*/
storageRoomevent::storageRoomevent(std::string music, enemy* one, battle* b)
{
	this->one = one;
	this->Vacuumbattle = b;
}
void storageRoomevent::trigger(character& c)
{
	if (this->isDone == true) {
		return;	//if character has already triggered the event in this node
	}
	else {
		endMusic();
		//playMusic();
		Sdelay(2);
		std::cout << "You entered the Storage room... ";
		MSdelay(2000);
		std::cout << "It smells like there was some sort of gas leak in here..." << std::endl;
		MSdelay(3000);
		std::cout << "You see tons of smashed-in anesthesia canisters scattered about the room..." << std::endl;
		MSdelay(4000);
		std::cout << "Finally you see a vacuum, slowly emerge from a large pile of these canisters...";
		MSdelay(3000);
		std::cout << "The vacuum is convulsing, its eyes blood-shot ...";
		MSdelay(3000);
		Dotdot();
		color(4);
		std::cout << "OHH...";
		MSdelay(100);
		std::cout << "NOOO!!!" << std::endl;
		Sdelay(2);
		color(7);
		std::cout << "The Crazed Vaccum lunged forward at you!" << std::endl;
		playSFX("battle!.wav");
		Sdelay(2);
		Vacuumbattle->Battle_Sequence(c, *one); //lets make the crazed vaccum very strong, since its the only enemy  
		if (c.getLife() == 0) {
			return;	//if the character is dead
		}
		Dotdot();
		std::cout << "The vacuum lets out a loud hissing noise!" << std::endl;
		Sdelay(3);
		std::cout << "The room quickly becomes filled with anesthesia!" << std::endl;
		Sdelay(3);
		std::cout << "*you pass out*" << std::endl;
		Sdelay(3);
		Dotdot();
		Dotdot();
		std::cout << "*you feel something poking you*" << std::endl;
		Sdelay(3);
		std::cout << "*you hear a muffled voice*" << std::endl;
		color(3);
		std::cout << "Hey..."; Sdelay(1); std::cout << " you..." << std::endl;
		Sdelay(1);
		Dotdot();
		std::cout << "WAKE UP!!!";
		MSdelay(500); std::cout << "."; MSdelay(500); std::cout << "."; MSdelay(500); std::cout << "." << std::endl; Sdelay(2);
		color(7);
		clear();
		std::cout << "*you slowly sit up*" << std::endl;
		Sdelay(2);
		std::cout << "You see the vacuum in front of you, now looking fully healed..." << std::endl;
		Sdelay(2);
		color(3);
		std::cout << "Thank goodness you're okay!!!"; Sdelay(3); std::cout << " Thank you soap much for saving me!" << std::endl; Sdelay(3);
		clear();
		std::cout << "You're probably wondering how I ended up in here..." << std::endl;
		Sdelay(4);
		std::cout << "Well, I saw what had happened to Le' Hospitale, and wanted to help clean things up..." << std::endl;
		Sdelay(3);
		std::cout << "I had lived here for my whole life, that is, before the Grime Reaper came along..." << std::endl;
		Sdelay(3);
		std::cout << "He banished us from our homes, and made a mess of our once spotless community..." << std::endl;
		Sdelay(3);
		std::cout << "So I crafted a plan..."; Sdelay(1); std::cout << " I would sneak in here and start cleaning things up, without him noticing..." << std::endl;
		Sdelay(3);
		std::cout << "However..."; Sdelay(1); std::cout << " when I started vacuuming up this room, I felt strange..." << std::endl;
		Sdelay(3);
		std::cout << "And after I cleaned up the whole room..."; Sdelay(1); std::cout << " I felt R"; MSdelay(200); std::cout << "e"; MSdelay(200); std::cout << "A"; MSdelay(200); std::cout << "l"; MSdelay(200); std::cout << "L"; MSdelay(200); std::cout << "y"; MSdelay(200); std::cout << " S"; MSdelay(200); std::cout << "t"; MSdelay(200); std::cout << "R"; MSdelay(200); std::cout << "a"; MSdelay(200); std::cout << "N"; MSdelay(200); std::cout << "g"; MSdelay(200); std::cout << "E"; MSdelay(200); std::cout << "."; MSdelay(200); std::cout << "."; MSdelay(200); std::cout << "." << std::endl;
		Sdelay(3);
		std::cout <<"I kinda just blacked out til just now, guess that gas I sucked up, made me a little loopy." << std::endl;
		Sdelay(3);
		clear();
		std::cout <<"I'm real sorry about attacking you earlier by the way." << std::endl;
		Sdelay(3);
		std::cout <<"Here's some soap tolkens to hopefully make up for it..." << std::endl;
		Sdelay(3);
		c.addMoney(500);
		endMusic();

		this->isDone = true;
		return;
	}

}


/*CellarEvent*/
/*CellarEvent::CellarEvent(std::string music, enemy* one, battle* b)//more of a boss type music?
{
	this->one = one;
	this->PutridPythonBattle = b;
}
void CellarEvent::trigger(character& c)
{
	if (this->isDone == true) {
		return;	//if character has already triggered the event in this node
	}
	else {
		endMusic();
		//playMusic();
		Sdelay(2);
		std::cout << "You entered The Cellar... ";
		MSdelay(1000);
		std::cout << "The room is dark, and the air thick as mud, with a wretched stench of rotting flesh..." << std::endl;
		MSdelay(2000);
		std::cout << "You walk towards the back of the room and can faintly see a lengthy crack in the wall..." << std::endl;
		MSdelay(3000);
		std::cout << "Suddenly you see a pair slitted eyes blink open, their yellow glow slightly lighting up the room " << std::endl;
		MSdelay(3000);
		clear();
		std::cout <<MSdelay(500)<<".";MSdelay(500); std::cout << ".";MSdelay(500); std::cout << "."<< std::endl;
		std::cout << "*a voice then calls out to you in a raspy tone*" << std::endl;
		MSdelay(3000);
		
		color(2);
		std::cout << "Putrid Python: You thereee";MSdelay(500); std::cout << ", yesssss";MSdelay(500); std::cout << ", you there with the moppy facccccce...";
		MSdelay(3000);
		std::cout << "I need your assistanccccce";MSdelay(500); std::cout << "I have great rewardsssss";MSdelay(500); std::cout << " to offer you" << std::endl;
		Sdelay(2);
		std::cout << "And all you must do isssssss";MSdelay(500); std::cout << "give me a few of those ratssssss";MSdelay(500); std::cout << "of yoursssss" << std::endl; 
		MSdelay(2000);
		clear();
		color(7);
		std::cout << "*sniff sniff*";color(2); std::cout << "I can already smell "<<c.get_deadRat()<<" dead rats on you, already"<< std::endl; 
		MSdelay(2000);
		Sdelay(2);
		color(7);
		std::cout << "The Crazed Vaccum lunged forward at you!" << std::endl;
		Sdelay(2);
		Garbagebattle->Battle_Sequence(c, *one);//lets make the crazed vaccum very strong, since its the only enemy  
		if (c.getLife() == 0) {
			return;	//if the character is dead
		}
	
	
		color(7);
		std::cout << "*you recived 500 soap tolkens*" << std::endl;
		Sdelay(2);
		addMoney(500);
		endMusic();

		this->isDone = true;
		return;
	}

}*/