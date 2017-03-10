/*
 * crossFuncts.h
 *
 *  Created on: 25 Feb 2017
 *      Author: Richie
 */

#ifndef CROSS_H_
#define CROSS_H_


struct Player{

		char Player_Name[50];
		char Player_Type[50];
		char Current_Pos[50]; // is assigned slot type for player
		int Current_PosNo; // is assigned number corresponding to index value of slot type e.g. if slot[2].Slot_Type is City, player.Current_Pos will = City and player.Current_Pos will = 2
		float Life_Points; // is assigned 100 for player life points
		int Smartness; // is assigned a value depending on player.Player_Type.
		int Strength; // see ^
		int Magic_Skills; // see ^
		int Luck; // see ^
		int Dexterity; // see ^
};

struct Slot{

	char Slot_Type[50]; // is assigned a slot type randomly e.g. slot.Slot_Type = "City"
	int Slot_Tag; // used to keep track of who is in what slot
	int counter; // counter used to keep track of if a slot is occupied
};

// Function definitions
void ELF(struct Player *player);
void WIZARD(struct Player *player);
void HUMAN(struct Player *player);
void OGRE(struct Player *player);
void AssignType(struct Player *player);
void ModStr(struct Player *player);
void ModMag(struct Player *player);
void ReverseModStr(struct Player *player);
void ReverseModMag(struct Player *player);
void Attack(struct Player *attacker,struct Player *attacked);


#endif
