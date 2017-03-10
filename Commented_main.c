#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "Comment_cross.h"

char Hill[5]="Hill",Ground[7]="Ground",City[5]="City"; // slot type strings to be used when assigning slot types

int main(void){

	srand(time(NULL));
	int maxPlayers=0; // maxPlayers is the variable that the user inputs max 6 used as index size for struct array player

	printf("How many players will play (Maximum 6!)\n");
	fflush(stdout);
	scanf("%d",&maxPlayers); // user input stored in max players. set number of players
	struct Player player[maxPlayers]; // declare a struct array player with size maxPlayers. NOTE: See cross.h line 12 for declaration of struct Player

	for(size_t i=1;i<=maxPlayers;i++){ // loop to fill struct type Player_Name

		printf("Please enter name for player %u\n",i);
		fflush(stdout);
		scanf("%s",player[i].Player_Name); // iterates through player array and gives each player a user input name

	}// end loop
	for(size_t i=1;i<=maxPlayers;i++){ // loop to fill struct type PLayer_Type

		printf("Please enter player %u type\n",i);
		fflush(stdout);
		scanf("%s",player[i].Player_Type); // stores Player_Type. Player Type is referenced when distributing player capabilities. NOTE: Types must must entered in the format of Elf,Wizard,Human,Ogre. Capital letter first!!
	} // end of loop

	for(size_t i=1;i<=maxPlayers;i++){ // loop iterates through each player and assigns capabilities based on player type

		AssignType(&player[i]); // call to function AssignType. See line 114 of crossFuncts.c.
	} // end loop

	for(size_t i=1;i<=maxPlayers;i++){ // prints each players capabilties, name and type.

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

	int maxSlots=0; // Variable maxSlots used as index in struct array slot

	do{ // do while slots are less than players.
		printf("Please enter the number of slots (Max 20!) Max slots must be > Max Players.\n");
		fflush(stdout);
		scanf("\n%d",&maxSlots);
	}while(maxSlots<maxPlayers);

	struct Slot slot[maxSlots]; // declare struct array slot with index size of maxSlots. NOTE: See cross.h line 28 for declaration of struct Slot.
	//start slot assignment loop
	for(size_t i=1;i<=maxSlots;i++){ // start of loop to fill slot array randomly with City,Ground or Hill type

		int max=100,min=1; // initialise three random numbers with min value 1 and max 100
		int rng = rand()%(max-min)+min;
		int rng1 = rand()%(max-min)+min;
		int rng2 = rand()%(max-min)+min;

		if(rng>rng1 && rng>rng2){ // if rng is greater than rng1 and rng2 slot[i].Slot_Type will get assigned city type.

			strcpy(slot[i].Slot_Type,City);
		}
		else if(rng1>rng&&rng1>rng2){ // same as above exept rng1 and Ground will be assigned

			strcpy(slot[i].Slot_Type,Ground);
		}
		else if(rng2>rng1&&rng2>rng){ // same except rng2 and Hill will be assigned

			strcpy(slot[i].Slot_Type,Hill);
		}
	}//end loop
	for(size_t i=1;i<=maxSlots;i++){ // loop to print each slot type

		printf("slot %u: %s\n",i,slot[i].Slot_Type);
		fflush(stdout);
	} // end loop

	//for Random player assignment to slot, save slot number and position
	for(size_t i=1;i<=maxPlayers;i++){ // loop to assign a random slot to player[i]

		int rnd = rand()%20+1; // random number between 1 and 20

		printf("Player %s has been assigned to slot[%d] Type: %s\n",player[i].Player_Name,rnd,slot[rnd].Slot_Type); // slot[rnd] will be a random index value which will give back a random slot type
		player[i].Current_PosNo = rnd; // stores the random value in player[i].Current_PosNo. This is how will will keep track of where each player is between rounds. will be updated after each turn.
		strcpy(player[i].Current_Pos,slot[rnd].Slot_Type); // copies slot type to current_position of player. This will be how we keep tarck of and modify capabilities according to rules of the game. Will be updated after each turn.
	}
	printf("\n");
	for(size_t i=1;i<=maxPlayers;i++){ // loop prints values assigned in previous section. Just to make sure evrything is working. can be removed in final version.

		printf("Player current position is: [%d] %s\n",player[i].Current_PosNo,player[i].Current_Pos);
		fflush(stdout);
	} // end loop


	for(size_t i = 1;i<=maxPlayers;i++){ // movement loop
             // My problem: Since one slot can only hold one player, how to make sure that after movements there is no slot holding more than 1 player?

				int input;
				printf("Current Player: player[%u]. Where would you like to move?\n",i);
				fflush(stdout);

				printf("Press 0 to move up or 1 to move down\n");
				fflush(stdout);

				scanf("%d",&input);

				if(player[i].Current_PosNo==20){

					int a = player[i].Current_PosNo-1;
					strcpy(player[i].Current_Pos,slot[a].Slot_Type);
					player[i].Current_PosNo=a;
				}
				else if(player[i].Current_PosNo==1){

					int a = player[i].Current_PosNo+1;
					strcpy(player[i].Current_Pos,slot[a].Slot_Type);
					player[i].Current_PosNo=a;
				}
				else if(input==1){

						int a = player[i].Current_PosNo+1;
						strcpy(player[i].Current_Pos,slot[a].Slot_Type);
						player[i].Current_PosNo=a;
				}
				else if(input==0){

					int a = player[i].Current_PosNo-1;
					strcpy(player[i].Current_Pos,slot[a].Slot_Type);
					player[i].Current_PosNo=a;

				}

				printf("\nNew position is %d and slot type is %s", player[i].Current_PosNo,player[i].Current_Pos);
				fflush(stdout);
				printf("\n");
		}

    for(size_t i = 1;i<=maxPlayers;i++){  //Change player points loop

                if(strcmp(player[i].Current_Pos,Hill)==0)
                {
                       ModStr(&player[i]); // When player move to hill, call ModStr function
                }
                else if (strcmp(player[i].Current_Pos,City)==0)
                {
                        ModMag(&player[i]); // When player move to City, call ModMag function
                }
    }

    for(size_t i=1;i<=maxPlayers;i++)
    {
        for(size_t j=i; j<=maxPlayers;j++)
        {
            if ((player[i].Current_PosNo == player[j].Current_PosNo +1) || (player[i].Current_PosNo == player[j].Current_PosNo +1))
            {     // If player[j] besides player[i], ask player[i] to attack or not
                printf("Does player %u want to attack player %u (enter 0 for yes, 1 for no)?", i, j);
                int decide;
                scanf("%d", &decide);
                if (decide == 0)
                {
                    if (player[j].Strength <= 70) // Change player points due to different situation
                    {
                        PlayerAttacked(&player[j]);
                    }
                    else if (player[j].Strength > 70)
                    {
                        PlayerAttacker(&player[i], player[j].Strength);
                    }
                }
            }
        }
    }

    for (size_t i=1; i<=maxPlayers; i++) //print the final result
    {
        printf("%s (%s, %d)\n", player[i].Player_Name, player[i].Player_Type, player[i].Life_Points);
    }

    return 0;
}
