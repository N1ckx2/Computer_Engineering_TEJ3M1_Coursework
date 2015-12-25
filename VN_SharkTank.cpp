/*Nicholas Vadivelu, Sheila Balu, Moujan Saderi
TEJ3M1 - 05
12 January 2015
Shark Tank TEJ Summatives*/

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <algorithm>  //to shuffle
#include <time.h> //for random number gen

using namespace std;

/* Definitions in the build of inpout32.dll are:            */
/*   short _stdcall Inp32(short PortAddress);               */
/*   void _stdcall Out32(short PortAddress, short data);    */

/* prototype (function typedef) for DLL function Inp32: */

     typedef short (_stdcall *inpfuncPtr)(short portaddr);
     typedef void (_stdcall *oupfuncPtr)(short portaddr, short datum);

#define PPORT_BASE 0x378
#define PPORT_INP (PPORT_BASE+1)

// Prototypes for Test functions
void test_read8(void);
void test_write(void);
void test_write_datum(short datum);

/* After successful initialization, these 2 variables
   will contain function pointers.
 */
     inpfuncPtr inp32fp;
     oupfuncPtr oup32fp;
/* Wrapper functions for the function pointers
    - call these functions to perform I/O.
 */
     short  Inp32 (short portaddr)
     {
          return (inp32fp)(portaddr);
     }

     void  Out32 (short portaddr, short datum)
     {
          (oup32fp)(portaddr,datum);
     } 
     
int main(void)
{
     HINSTANCE hLib;

     short x;
     int i;
     /* Load the library */
     hLib = LoadLibrary("inpout32.dll");
     if (hLib == NULL) {
          fprintf(stderr,"LoadLibrary Failed.\n");
          getch();
          return -1;
                      }
    /* get the address of the function */

     inp32fp = (inpfuncPtr) GetProcAddress(hLib, "Inp32");

     if (inp32fp == NULL) {
          fprintf(stderr,"GetProcAddress for Inp32 Failed.\n");
          getch();
          return -1;
     }
     oup32fp = (oupfuncPtr) GetProcAddress(hLib, "Out32");

     if (oup32fp == NULL) {
          fprintf(stderr,"GetProcAddress for Oup32 Failed.\n");
          getch();
          return -1;
     }

    /*****  Write 0x75 to data register and verify */
     test_write();
     FreeLibrary(hLib);
     return (0);
}

string questions [][5] = 
{
	{"What name is given to half of a Byte (4 bits)?", "HalfByte", "Nibble", "DemiByte", "Bite"}, 
	{"What do the initials GUI stand for?", "Graphical User Interface", "Graphical User Interaction", "Graphics Used Intelligently",  "Greatly Useful Internet"},
	{"How many millimeters is one kilometer?",  "10 000 000", "100 000", "1 000 000", "10 000"},
	{"What colour is Absynth?", "Green", "Red", "Blue","Yellow"},
	{"What is the world's largest ocean?", "Atlantic",  "Pacific", "Indian", "Arctic"},
	{"What  type of animal is a skink?",  "Fish", "Bird", "Rodent", "Lizard"},
	{"What is RAM short for?", "Random Access Memory", "Robust Active Monitor",  "Randomly Activated Memory", "Robot Activated memory"},
	{"What do the dots on one pair of dice add up to?",  "21","42", "36",  "52"},
	{"What term describes a male swan?",  "Covat", "Cob","Cobbler", "Cotus"},
	{"Which flag is raised when a ship is about to leave port?", "Blue Peter", "Black Jack", "Red Robert", "Gray Gavin"},
	{"What is Agoraphobia the fear of?",  "Ovens", "Open doors", "Open Spaces", "Olives" },
	{"Which planet is closest to the sun?",  "Mars",  "Uranus", "Neptune", "Mercury"},
	{"What does the roman numeral C represent?", "1000", "100", "500",  "50"},
	{"What horoscope sign has a crab?", "Cancer", "Leo", "Capricorn", "Taurus"}
};
int aners[] = {2, 1, 3, 1, 1, 4, 1, 2, 2, 1, 3, 4, 2, 1};

int leds[] = {(128+64+32), (64+32), (32)};
int hello = 0;
int score = 0;
void wrong2 (int sleep)
{
	cout << "Sorry, time's up!" << endl;
	Out32(PPORT_BASE, (16 + leds[hello]));
	Sleep(sleep);
	hello++;
	Out32(PPORT_BASE, leds[hello]); 
}

void wrong (int sleep)
{
cout << "Wrong answer!" << endl;
	Out32(PPORT_BASE, (16 + leds[hello]));
	
	hello++;
	Out32(PPORT_BASE, leds[hello]); 
}
// LEDS are: 128, 64, 32

void right ()
{
	score++;
	cout << "Correct! Your score is now: " << score << endl;
}

void menu()
{
     
	int choice = 0;
	do
	{
		srand(time(NULL)); //makes sure random is really random
		int row[14], col[5], answerpos[14]; //these arrays allow me to shuffle the 2D Array
		int input, input2=120, ans, sleep = 1000;
		clock_t start, stop, ticks; //to track time
		int time = 10; //time
		string newQuestions[14][5]; //this 2D array stores the shuffled questions.
		cout << "             Shark Tank" << endl << "By Nicholas V, Sheila B, and Moujan S" << endl << endl; //openinng
	
		row[0] = rand()%14; //starts randomizing position
		col[0] = 0; //makes sure that the first element is always the question (doesn't shuffle)
		for (int i = 1; i < 14; i++)
		{
			do 
			{
				row[i] = rand()%14; //shuffles rows
			} while (row[i] == row[i-1]); //makes sure each position is unique so there are no overlaps
		}
		
		
		for (int i = 0; i < 14; i++)
		{
            time = 10;
            input = 120, input2 = 120;
            Out32(PPORT_BASE,leds[hello]);
			for(int x = 0; x < 5; x++)
			{
				cout << questions[i][x] << endl;
			}
			input = Inp32 (PPORT_INP); //Recieves input
			//cin >> input;
			while (input2 == 120 && time > 0) // 
			{
                     input = Inp32 (PPORT_INP); //Recieves input
                  if (input != 120)
                  {
                            input2 = input;
                            }
				time--;
				Out32(PPORT_BASE, time+leds[hello]);
				Sleep(1000);
			}
			if (input == 120)
			{
				wrong2(sleep);
			}
			else if (aners[i] == 1) 
			{
				if (input == 56) //button 1
				{
					right();
				}
				else if (input == 248 || input == 88 || input == 104) //buttons 2, 3, 4
				{
					wrong(sleep);
				}
				else
				{
					wrong(sleep);
				} 
			}
			else if (aners[i] == 2) 
			{
				if (input == 248) //button 2
				{
					right();
				}
				else if (input == 56 || input == 88 || input == 104) //buttons 1, 3, 4
				{
					wrong(sleep);
				}
				else
				{
					wrong(sleep);
				} 
			}
			else if (aners[i] == 3) 
			{
				if (input == 88) //button 3
				{
					right();
				}
				else if (input == 56 || input == 248 || input == 104) //buttons 1, 2, 4
				{
					wrong(sleep);
				}
				else
				{
					wrong(sleep);
				} 
			}
			else if (aners[i] == 4) 
			{
				if (input == 104) //button 4
				{
					right();
				}
				else if (input == 56 || input == 248 || input == 88) //buttons 1, 2, 3
				{
					wrong(sleep);
				}
				else
				{
					wrong(sleep);
				} 
			}
			if (input == 112 || hello == 3)
			{
				break;
			}
			cout <<endl;
			Sleep(500);
		}
	cout << "Game over. Type 1 to play again, or 0 to exit." << endl;
	} while (choice != 0);
	
	cout << endl << "Your final score was: " << score << endl;
}
void test_write(void) 
{
     short x;
     int i;
    /*****  Write the data register */

     i=PPORT_BASE;
     x=0x75;
     //************************Parallel Output code below****************************
     //Change the number after i, Out32 (i,change number here) to see the binary
     //numbers on your LEDs
     
    menu();
    getch();
}

void test_write_datum(short datum) {
     short x;
     int i;

     i=PPORT_BASE;
     x = datum;

     /*****  Write the data register */
     Out32(i,x);

     printf("\nPort write to 0x%X, datum=0x%2X\n" ,i ,x);

     /***** And read back to verify  */
     x = Inp32(i);
     printf("Port read (%04X)= %04X\n",i,x);
     getch ();
}

/**************************************************/
/***                                            ***/
/*** Test2.c  -- test interface to inpout32.dll ***/
/***  ( http://www.logix4u.net/inpout32.htm )   ***/
/***                                            ***/
/*** Copyright (C) 2005, Douglas Beattie Jr.    ***/
/***                                            ***/
/***    <beattidp@ieee.org>                     ***/
/***    http://www.hytherion.com/beattidp/      ***/
/***                                            ***/
/**************************************************/
/*	Last Update: 2006.05.14
 */

/*******************************************************/
/*                                                     */
/*  Builds with Borland's Command-line C Compiler      */
/*    (free for public download from Borland.com, at   */
/*  http://www.borland.com/bcppbuilder/freecompiler )  */
/*                                                     */
/*   Compile with:                                     */
/*                                                     */
/*   BCC32 -IC:\BORLAND\BCC55\INCLUDE  TEST2.C         */
/*                                                     */
/*                                                     */
/*  Be sure to change PPORT_BASE (Port Base address)   */
/*  accordingly if your LPT port is addressed          */
/*  elsewhere.                                         */
/*                                                     */
/*******************************************************/

