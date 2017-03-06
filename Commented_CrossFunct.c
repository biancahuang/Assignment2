#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"cross.h"

char str[5]="Ogre",str2[4]="Elf",str3[6]="Human",str4[7]="Wizard"; // Used in AssignType function NOTE: see line 114

/*void ModStr(struct Player *player){ Two functions to modify player capabilities when moved to a certain slot type. NOTE: has not been implemented yet

	if(player->Dexterity <50){

		player->Strength -= 10;
	}
	else if(player->Dexterity >=60){

		player->Strength += 10;
	}
}
void ModMag(struct Player *player){

	if(player->Smartness > 60){

		player->Magic_Skills += 10;
	}
	else if(player->Smartness<=50){

		player->Magic_Skills -= 10;
	}
}*/

void OGRE(struct Player *player){ // Assigns correct stats to ogre type player

	int max=100,min=80;

	int rngD = rand()%(max-min)+min;
	int rngL = rand()%30 + 1;
	int rngS = rand()%20 + 1;
	int rngSt = rand()%(max-min)+min;

	player->Life_Points = 100;
	player->Dexterity = rngD;
	player->Luck = rngL;
	player->Magic_Skills = 0;
	player->Smartness = rngS;
	player->Strength = rngSt;
}

void ELF(struct Player *player){ // Assigns correct stats to elf type player

	int max=100,min=60,minM=51,maxM=79,minS=70,maxS=100;

	int rngD = rand()%100 + 1;
	int rngL = rand()%(max-min)+min;
	int rngM = rand()%(maxM-minM)+minM;
	int rngS = rand()%(maxS-minS)+minS;
	int rngSt = rand()%50 + 1;

	player->Life_Points = 100;
	player->Dexterity = rngD;
	player->Luck = rngL;
	player->Magic_Skills = rngM;
	player->Smartness = rngS;
	player->Strength = rngSt;

}

void WIZARD(struct Player *player){ // Assigns correct stats to wizard type player

	int minM=80,maxM=100,minL=50,maxL=100;

	int rngD = rand()%100 + 1;
	int rngL = rand()%(maxL-minL)+minL;
	int rngM = rand()%(maxM-minM)+minM;
	int rngS = rand()%100 + 1;
	int rngSt = rand()%20 + 1;

	player->Life_Points = 100;
	player->Dexterity=rngD;
	player->Luck=rngL;
	player->Magic_Skills=rngM;
	player->Smartness=rngS;
	player->Strength=rngSt;
}

void HUMAN(struct Player *player){ // Assigns correct stats to Human type player


		int rngD = rand()%100 + 1;
		int rngL = rand()%100 + 1;
		int rngM = rand()%100 + 1;
		int rngS = rand()%100 + 1;
		int rngSt = rand()%100 + 1;

		int sum = rngD+rngL+rngM+rngS+rngSt;

		player->Life_Points = 100;
		player->Dexterity=rngD;
		player->Luck=rngL;
		player->Magic_Skills=rngM;
		player->Smartness=rngS;
		player->Strength=rngSt;

		printf("Sum of human is: %d\n",sum);
}

void AssignType(struct Player *player){ // Assigns type to player depending on type picked by player

	if(strcmp(player->Player_Type,str)==0){

		OGRE(player);
	}
	else if(strcmp(player->Player_Type,str2)==0){

		ELF(player);
	}
	else if(strcmp(player->Player_Type,str3)==0){

		do{ // repeats HUMAN function if sum of capabilities is greater than 300
			HUMAN(player);
			printf("\n");
		}while(player->Dexterity + player->Luck + player->Magic_Skills + player->Smartness + player->Strength > 300);
	}
	else if(strcmp(player->Player_Type,str4)==0){

		WIZARD(player);
	}
}

/*If the Strength points of the attacked player are <=70,
then attacked player life points = life points - 0.5 * his/her Strength points.
If the strength points of the attacked player are > 70, the attacker life points = life points - 0.3 * (attacked player’s strength points).
void PlayerAttack(struct Player *player){

	player->Life_Points -= 0.5 * player->Strength;
}
void PlayerAttacked(struct Player *player, int strength){

	player->Life_Points -= 0.3 * strength;
}*/
