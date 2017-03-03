#ifndef CROSS_H_
#define CROSS_H_


struct Player{

		char Player_Name[50];
		char Player_Type[50];
		char Current_Pos[50];
		int Current_PosNo;
		int Life_Points;
		int Smartness;
		int Strength;
		int Magic_Skills;
		int Luck;
		int Dexterity;
};

struct Slot{

	char Slot_Type[50];
};

void ELF(struct Player *player);
void WIZARD(struct Player *player);
void HUMAN(struct Player *player);
void OGRE(struct Player *player);
void AssignType(struct Player *player);
void ModStr(struct Player *player);
void ModMag(struct Player *player);
void PlayerAttack(struct Player *player);

#endif
