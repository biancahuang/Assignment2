#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "cross.h"

char Hill[5]="Hill",Ground[7]="Ground",City[5]="City";

int main(void){

	srand(time(NULL));
	int maxPlayers=0;

	printf("How many players will play (Maximum 6!)\n");
	fflush(stdout);
	scanf("%d",&maxPlayers);
	struct Player player[maxPlayers];

	for(size_t i=1;i<=maxPlayers;i++){

		printf("Please enter name for player %zd\n",i);
		fflush(stdout);
		scanf("%s",player[i].Player_Name);

	}
	for(size_t i=1;i<=maxPlayers;i++){

		printf("Please enter player %zd type\n",i);
		fflush(stdout);
		scanf("%s",player[i].Player_Type);
	}

	for(size_t i=1;i<=maxPlayers;i++){

		AssignType(&player[i]);
	}

	for(size_t i=1;i<=maxPlayers;i++){

		printf("Player type is: %s\n",player[i].Player_Type);
		printf("Player Name is: %s\n",player[i].Player_Name);
		printf("Player Life-points: %d\n",player[i].Life_Points);
		printf("Dexterity: %d\n",player[i].Dexterity);
		printf("Luck: %d\n",player[i].Luck);
		printf("Magic Skills: %d\n",player[i].Magic_Skills);
		printf("Smartness: %d\n",player[i].Smartness);
		printf("Strength: %d\n",player[i].Strength);
		printf("\n");
	}

	int maxSlots=0;

	do{
		printf("Please enter the number of slots (Max 20!) Max slots must be > Max Players.\n");
		fflush(stdout);
		scanf("\n%d",&maxSlots);
	}while(maxSlots<maxPlayers);

	struct Slot slot[maxSlots];
	//start slot assignment loop
	for(size_t i=1;i<=maxSlots;i++){

		int max=100,min=1;
		int rng = rand()%(max-min)+min;
		int rng1 = rand()%(max-min)+min;
		int rng2 = rand()%(max-min)+min;

		if(rng>rng1 && rng>rng2){

			strcpy(slot[i].Slot_Type,City);
		}
		else if(rng1>rng&&rng1>rng2){

			strcpy(slot[i].Slot_Type,Ground);
		}
		else if(rng2>rng1&&rng2>rng){

			strcpy(slot[i].Slot_Type,Hill);
		}
	}//end loop
	for(size_t i=1;i<=maxSlots;i++){

		printf("slot %zd: %s\n",i,slot[i].Slot_Type);
		fflush(stdout);
	}

	printf("\n");
	//for Random player assignment to slot, save slot number and position
	for(size_t i=1;i<=maxPlayers;i++){

		int rnd = rand()%20+1;

		printf("Player %s has been assigned to slot[%d] Type: %s\n",player[i].Player_Name,rnd,slot[rnd].Slot_Type);
		player[i].Current_PosNo = rnd;
		strcpy(player[i].Current_Pos,slot[rnd].Slot_Type);
	}
	printf("\n");
	for(size_t i=1;i<=maxPlayers;i++){

		printf("Player current position is: [%d] %s\n",player[i].Current_PosNo,player[i].Current_Pos);
		fflush(stdout);
	}
	//modify player capabilities for slot type.

}
