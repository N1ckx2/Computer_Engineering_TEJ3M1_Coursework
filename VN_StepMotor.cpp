/*Nicholas Vadivelu
TEJ3M1 - 05
17 December 2014
Step Motor*/

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <iostream>

using namespace std;

/* Definitions in the build of inpout32.dll are:            */
/*   short _stdcall Inp32(short PortAddress);               */
/*   void _stdcall Out32(short PortAddress, short data);    */

/* prototype (function typedef) for DLL function Inp32: */

     typedef short (_stdcall *inpfuncPtr)(short portaddr);
     typedef void (_stdcall *oupfuncPtr)(short portaddr, short datum);

#define PPORT_BASE 0x378

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
     return 0;
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
     
     int choice = -1, direction = 1, tur, speed;
    double deg = 15;
    do
    {
       system("cls");
    	cout <<"Nicholas Vadivelu's Step Motor"<<  endl << "--------------------------" << endl;
    	cout <<"1 - Turn every time you press a button" << endl;
    	cout <<"2 - Turn a certain number of degrees" << endl;
    	cout <<"3 - Turn until you press <Enter>" << endl;
		cout <<"0 - Exit "<< "\n\n";
    	cout <<"Your choice: ";
    	cin >> choice;
    	if (choice == 0) break;
    	cout <<"\nChoose which direction" << endl;
    	cout <<"1 - Clockwise "<< "\n";    	
    	cout <<"2 - Counterclockwise "<< "\n";	    
    	cout <<"0 - Exit "<< "\n\n";
    	cout <<"Your choice: ";
    	cin >> direction;
    	if (direction == 0) break;
       system("cls");
       //******************************************Button Turn**********************************************
       if(choice == 1) 
	   {
			char in = '1'; //input to turn
			cout << "Press '1' everytime you want the motor to turn\nPress '0' if you want to exit\n"; //prompt user to turn
			//**************************Clockwise***************************
			if (direction == 1) 
			{
				do
				{
					for (tur = 1; tur <= 8; tur*=2) //turns every time you press 1, but exits when 0 is pressed
					{
						in = getch();
						if (in == '0') break;
						Out32(i, tur);
					}
				} while (in != '0');
			}
			//**************************Counter CLockwise********************
			else if (direction == 2)
			{
				do
				{
					for (tur = 8; tur >= 1; tur/=2) //turns every time you press 1, but exits when 0 is pressed
					{
						in = getch();
						if (in == '0') break;
						Out32(i, tur);
					}
				} while (in != '0');
			}
			Out32(i, 0);
	   }
	   //******************************************Degrees**********************************************
	   else if(choice == 2)
	   {
	   		int degree, x, var, time; //for rotation duration
	   		cout <<"How many degrees do you want the motor to turn (multiple of 30): ";
	   		cin >> degree; //turning
	   		if (degree % 30 != 0)
	   			degree = degree - (degree%30);
	   		cout <<"How fast do you want it to spin (1 ms - fast, 1000 ms - slow): ";
	   		cin >> time;
	   		degree = (degree/30);
	   		//*************************************Clockwise******************************
	   		if (direction == 1)
	   		{
	   			for (x = 1;x<=8;x*=2)
           		{
           			Out32(i,x);
           			cout<<x;
           			Sleep (time);

           		}
	   		}
	   		//*************************************Counter Clockwise******************************
	   		else if (direction == 2)
	   		{
	   			for (x = 8;x>=1;x/=2)
           		{
           			Out32(i,x);
           			cout<<x;
           			Sleep (time);

           		}
	   		}
	   		Out32(i, 0);
	   }
	   //******************************************Turn until stop**********************************************
	   else if(choice == 3)
	   {
	   		cout <<"How fast do you want it to spin (1 ms - fast, 1000 ms - slow): ";
	   		cin >> speed;
	   		cout <<"\nPress any key to stop spinning...";
	   		//*************************************Clockwise******************************
	   		if (direction == 1)
	   		{
	   			do
	   			{
	   				for (int y = 1; y <= 8; y*=2)
	   				{
	   					Out32(i, y);
	   					Sleep(speed);
	   				}
	   			}while (!kbhit());
	   		}
	   		//*************************************Counter Clockwise******************************
	   		else if (direction == 2)
	   		{
	   			do
	   			{
	   				for (int y = 1; y <= 8; y*=2)
	   				{
	   					Out32(i, y);
	   					Sleep(speed);
	   				}
	   			}while (!kbhit());
	   		}
	   		Out32(i, 0);
	   }
	   cout << "Press enter to continue...";
		getch();
    } while(choice != 0);
    cout << "Program Terminated";
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

