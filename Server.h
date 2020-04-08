#include<stdio.h> // for I/O operations
#include<stdlib.h> // for randomizing
#include<time.h> // for random seed generation
#include<windows.h>// for color to screen

//initializing Global variables
int Player1score, Player2score, Target;
HANDLE rHnd, wHnd;

void GetToss( char[] , char[], int );
int initializeconsolehandles();
void locate(int, int);
int Batting ( char[] , char[], int );
int Inning2( char[] , char[], int, int );
void commentary(int, int);
