#include"Server.h"

char *six[] = { "\nEffortless! Brilliant! MAXIMUM!",
                "\nOUT OF THE PARK FLIES THAT ONE! SIX RUNS!",
                "\nIts a SIX! This calls for change of plans.",
                "\nBLASTED TO THE SPACE! SIX RUNS!\n"};

char *fours[] = { "\nDriven nicely through the covers for FOUR runs!",
                  "\nPoor delivery meets great stroke. FOUR runs!",
                  "\nThat's the perfect example of how to play that stroke. FOUR more!",
                  "\nFOUR! That's Great to watch from the neutral. Not so good for the bowler!"};

char  *outs[] = { "\nOUT! He'll be kicking himself for that as he walks back to the pavilion",
                  "\nOUT! Beautiful delivery!",
                  "\nOUT! He tried to bite more than he could chew there as he's run out by an inch",
                  "\nOops! Straight to the fielder and he doesn't miss it! BEAUTIFULLY TAKEN!\n" };


char *single[] = { "\nSINGLE.Excellent running between the wickets there",
                   "\nEasy SINGLE there.",
                   "\nThe batsmen settle for a SINGLE there.",
                   "\nGood running there as the batsmen come away with a SINGLE\n"};

char * doubles[] = { "\nExquisite running between the wickets there. TWO runs.\n",
                     "\nWonderful stroke but saved boundary. TWO runs.\n",
                     "\nTWO more runs to the total.\n",
                     "\nQuick running between the wickets earns them a DOUBLE.\n"};


int index() // generation random numbers for commmentary
{
    srand(time(0));
    int num = (rand() % 4);
    return num;
}
//
void welcome()
{
            system("color f1");
            int i,y;
            locate(26,5);
            printf(" _ _ _ _ _ _ _ _ _ _  _ _ _ _ ");
            locate(27,7);
            printf("*****************************");
            locate(27,9);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
                    ,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3);
            locate(27,11);
            printf(" %c%c%c!!! YOU ARE WELCOME !!!%c%c%c",2,2,2,2,2,2);
            locate(39,13);
            printf("TO");
            locate(22,15);
            printf(" %c%c%c%c Cricket Commentary Simulation %c%c%c%c",3,3,3,3,3,3);
            locate(27,17);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%"
                    ,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3);
            locate(27,19);
            printf("*****************************");
            locate(27,21);
            printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _");
            Sleep(250);
            for(y=30;y<=38;y++)
                {
                    {
                        locate(27,y);
                        Sleep(400);
                    }
                }
            printf("\n");
    system("color ff");
}

// Generating commentary dialogs
void commentary( int input, int notout )
{
    if (input == 6 && notout == 1 )
    {
        printf("%s\n", six[index()] );
    }
    else if (input == 4 && notout == 1 )
    {
        printf("%s\n", fours[index()] );
    }
    else if (input == 1 && notout == 1 )
    {
        printf("%s\n", single[index()] );
    }
    else if (input == 2 && notout == 1 )
    {
        printf("%s\n", doubles[index()] );
    }
    else if ( input == 3 )
    {
        notout = 0;
        printf("%s\n", outs[2] );
    }
    else if ( input == 5 )
    {
        input = 4;
        printf("%s\n", fours[index()]);
    }
    else if ( notout == 0 )
    {
        printf( "%s\n", outs[index()] );
    }
}


void playgame()
{
    int Overs, totOvers, choice, Toss;
    char player1[50], player2[50];
    srand(time( 0 ));
    printf("Enter Player 1 Name:");
    fflush(stdin);
    gets(player1);
    printf("Enter Player 2 Name:");
    fflush(stdin);
    gets(player2);
    printf("Enter\n1 - Fixed Overs\n2 - Play Until Out\n3 - Exit\n");
Choose_again:
    scanf("%d",&choice);
    while( choice > 0 && choice < 4)
    {
        if (choice == 1)
        {
            printf("Enter No. Of Overs to Play : ");
            scanf( "%d", &Overs );
            GetToss( player1, player2, Overs);
        }
        else if ( choice == 2 )
        {
            GetToss(player1, player2, 0);
        }
        if ( choice >= 4 || choice <= 0 )
        {
            goto Choose_again;
        }
    }
}


void GetToss( char Player1[], char Player2[], int OversToPlay )
{
    int TossChoice, TossResult, Player1WinsToss = 0, Player2WinsToss = 0, BatorBowlChoice;
    char * Coin[3] = {'0', "Heads", "Tails"};
    char * batOrbowl[3] = {'0', "Bat", "Bowl"};
Toss:
    system("cls");
    printf("%s make your choice :\n", Player1);
    printf( "1. Heads\n2. Tails\n" );
    scanf("%d", &TossChoice);
   /* if ( TossChoice != 1 || TossChoice != 2)
    {
        printf("Invalid Choice!\n");
        system("cls");
        goto Toss;
    }*/
    TossResult = (rand() % 2) + 1;
    //printf("%d", TossResult);
    printf("It's %s\n", Coin[TossResult]);

    if ( TossResult == TossChoice )
    {
        printf("%s has won the toss\n", Player1);
        Player1WinsToss = 1;
    }
    else
    {
        printf("%s has won the toss\n", Player2);
        Player2WinsToss = 1;
        BatorBowlChoice = (rand() % 2) + 1;
        printf( "%s has elected to %s first\n", Player2, batOrbowl[BatorBowlChoice] );
    }
    //fflush(stdin);
    /*printf("\n1. Bat\n2. Bowl ");
    scanf("%d", &BatorBowlChoice);
    if ( TossChoice != 1 && TossChoice != 2)
    {
        printf("Invalid Choice!\n");
        //system("cls");
       // goto TossWon;
    }*/
    if (Player1WinsToss == 1)
    {
        printf("\n1. Bat\n2. Bowl\n ");
        scanf("%d", &BatorBowlChoice);
        if( BatorBowlChoice == 1 )
        {
            printf("%s steps up to bat\n\n", Player1);
            Player1score = Batting ( Player1, Player2, OversToPlay );
            printf("The second innings start as %s comes to bat\n\n", Player2);
            Player2score = Inning2 ( Player2, Player1, OversToPlay, Target );
        }
        else
        {
            printf("%s steps up to bat\n\n", Player2);
            Player2score = Batting ( Player2, Player1, OversToPlay );
            printf("The second innings start as %s comes to bat\n\n", Player1);
            Player1score = Inning2 ( Player1, Player2, OversToPlay, Target );
        }
    }
    else
    {
        if( BatorBowlChoice == 1 )
        {
            printf("%s steps up to bat\n", Player2);
            Player2score = Batting ( Player2, Player1, OversToPlay );
            printf("The second innings start as %s comes to bat\n", Player1);
            Player1score = Inning2 ( Player1, Player2, OversToPlay, Target );
        }
        else
        {
            printf("%s steps up to bat\n", Player1);
            Player1score = Batting ( Player1, Player2, OversToPlay );
            printf("The second innings start as %s comes to bat\n", Player2);
            Player2score = Inning2 ( Player2, Player1, OversToPlay, Target );
        }
    }

    if ( Player1score == Player2score )
    {
        printf( "Big time performances by both the players as this game becomes a drawn one!");
        exit(0);
    }

    else if ( Player1score > Player2score )

    {
        printf( "%s has won the game!\n", Player1);
        exit(0);
    }
    else
    {
        printf( "%s has won the game!\n", Player2);
        exit(0);
    }
return Player1WinsToss;
}

// Function for the first innings of play
int Batting ( char Batsman[], char Bowler[], int Max_Overs )
{
    int i,j,battingScore, sum = 0, bowlerScore, flag = 1 ;
    char c;
    if( Max_Overs > 0)
    {
        for( i = 0; i < Max_Overs; i++ )
        {
            for( j = 1; j <= 6; j++ )
            {
                printf("||%s || : || %d Runs||\t",Batsman,sum);
                printf("||%d.%d Overs||",i,j);
                printf("\n_______________________________________________________________\n");
                printf("%s Press Enter key to bowl : ",Bowler);
                fflush(stdin);
                scanf("%c",&c);
                fflush(stdin);
                bowlerScore=(int)rand()%7;//Generate from 0-6 where 0 means no ball
                printf("%s Press Enter key to bat : ",Batsman);
                fflush(stdin);
                scanf("%c",&c);
                fflush(stdin);
                battingScore=rand()%7;//Generate 0-6 runs
                if( battingScore == bowlerScore )
                {
                    flag = 0;
                    printf("-----------------%s is Out----------------\n",Batsman);
                    //printf("Got %d runs\n",battingScore);
                    printf("%s Total Score=%d\n",Batsman,sum);
                    if( sum == 0 )
                        printf("----------- DUCK OUT -----------------\n");
                    commentary( battingScore, flag );
                    fflush(stdin);
                    scanf("%c", &c);
                    system("cls");
                    break;
                }
                else
                {
                    //printf("Got %d runs\n",battingScore);
                    /*if(battingScore==6)
                    printf("Six! Keep it Up\n");
                    if(battingScore==4)
                    printf("Its Four!\n");*/
                    commentary( battingScore, flag );
                    if (battingScore == 3)
                        battingScore = 0;
                    sum += battingScore;
                    //printf("%s Score = %d\n",Batsman,sum);
                    fflush(stdin);
                    scanf("%c", &c);
                    system("cls");
                }
            }
            if( flag == 0 )
                break;
        }
        Target = sum + 1;
        return( sum );
    }
    if( Max_Overs == 0)
    {
        while( flag )
        {
            printf("%s Press Enter key to bowl :",Bowler);
            fflush(stdin);
            scanf("%c",&c);
            fflush(stdin);
            bowlerScore = (int)rand()%7;//Generate from 0-6 where 0 means no ball
            printf("%s Press Enter key to bat :",Batsman);
            fflush(stdin);
            scanf("%c",&c);
            fflush(stdin);
            battingScore=rand()%7;//Generate 0-6 runs
            if(battingScore == bowlerScore || battingScore == 3)
            {
                flag = 0;
                printf("-----------------%s is Out----------------\n",Batsman);
                printf("%s Total Score=%d\n",Batsman,sum);
                if( sum == 0 )
                    printf("-----------Hehehe Duck Out-----------------\n");
                fflush(stdin);
                scanf("%c", &c);
                system("cls");
                break;
            }
            else
            {
                printf("Got %d runs\n",battingScore);
                commentary( battingScore, flag );
                sum += battingScore;
                //printf("%s Score = %d\n",Batsman,sum);
                fflush(stdin);
                scanf("%c", &c);
                system("cls");
            }
        }
        Target = sum + 1;
        return(sum);
   }

}

// Function for second innings of play
int Inning2 ( char Batsman[], char Bowler[], int Max_Overs, int Trg )
{
    int i,j,battingScore,sum = 0,bowlerScore,flag = 1, totOvers = Max_Overs, k = 0;
    char c;
    if( Max_Overs > 0)
    {
        for( i = 0; i < Max_Overs; i++ )
        {
            for( j = 1; j <= 6; j++ )
            {
                printf("||%s : %d Runs||\t",Batsman,sum);
                printf("||%d.%d Overs||\t",i,j);
                printf("%||Target : %d||\n", Trg);
                printf("_______________________________________________________________\n");
                printf("%d Runs required in %d Balls\n", Trg - sum, ((Max_Overs * 6) - ((i*6)+(j-1))));
                //totOvers--;
                printf("_______________________________________________________________\n");
                printf("%s Press Enter key to bowl : ",Bowler);
                fflush(stdin);
                scanf("%c",&c);
                fflush(stdin);
                bowlerScore = (int)rand() % 7;//Generate from 0-6 where 0 means no ball
                printf("%s Press Enter key to bat : ",Batsman);
                fflush(stdin);
                scanf("%c",&c);
                fflush(stdin);
                battingScore = rand() % 7 ;//Generate 0-6 runs
                if( battingScore == bowlerScore )
                {
                    flag = 0;
                    printf("-----------------%s is Gone!----------------\n",Batsman);
                    commentary( battingScore, flag);
                    printf("%s Total Score=%d\n",Batsman,sum);
                    if( sum == 0 )
                    printf("----------- DUCK OUT -----------------\n");
                    fflush(stdin);
                    scanf("%c", &c);
                    system("cls");
                    break;
                }
                else
                {
                    //printf("Got %d runs\n",battingScore);
                    commentary( battingScore, flag );
                    /*if(battingScore==6)
                        printf("Six! Keep it Up\n");
                    if(battingScore==4)
                        printf("Its Four!\n");*/

                    sum += battingScore;
                    if ( sum >= Trg )
                    {
                        printf("%s : %d Runs\t",Batsman,sum);
                        printf("%d.%d Overs\n",i,j);
                        printf("Jubilant celebration in the Crowd as %s wins this game", Batsman);
                        fflush(stdin);
                        scanf("%c", &c);
                        system("cls");
                        exit(0);
                    }
                    //printf("%s Score = %d\n",Batsman,sum);
                    fflush(stdin);
                    scanf("%c", &c);
                    system("cls");
                }
            }
            if( flag == 0 )
                break;
        }
        return( sum );
    }
    if( Max_Overs == 0)
    {
        while( flag )
        {
            printf("%s Press Enter key to bowl :",Bowler);
            fflush(stdin);
            scanf("%c",&c);
            fflush(stdin);
            bowlerScore = (int)rand()%7;//Generate from 0-6 where 0 means no ball
            printf("%s Press Enter key to bat :",Batsman);
            fflush(stdin);
            scanf("%c",&c);
            fflush(stdin);
            battingScore=rand()%7;//Generate 0-6 runs
            if(battingScore == bowlerScore)
            {
                flag = 0;
                printf("-----------------%s is Gone----------------\n",Batsman);
                printf("%s Total Score=%d\n",Batsman,sum);
                if( sum == 0 )
                    printf("-----------Hehehe Duck Out-----------------\n");
                fflush(stdin);
                scanf("%c", &c);
                system("cls");
                break;
            }
            else
            {
                if (battingScore == 5)
                    battingScore = 4;
                //printf("Got %d runs\n",battingScore);
                commentary(battingScore, flag);
                /*if(battingScore==6)
                printf("Six! Keep it Up\n");
                if(battingScore == 4)
                printf("Its a Four Great Man\n")*/;
                sum += battingScore;
                printf("%s Score = %d\n",Batsman,sum);
                fflush(stdin);
                scanf("%c", &c);
                system("cls");
            }
        }
        Target = sum;
        return(sum);
   }

}
int initializeconsolehandles()
{
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    if (rHnd && wHnd)
        return TRUE;
    else
        return FALSE;
}

void locate(int x, int y)
{
    COORD pos = {x,y};
    SetConsoleCursorPosition (wHnd,pos);

}
