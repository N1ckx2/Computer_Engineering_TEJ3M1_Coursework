 /* Nicholas Vadivelu
 November 24, 2014
 TEJ 3M1-05
 Bidirectional*/

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
     int i, y;
    /*****  Write the data register */

     i=PPORT_BASE;
     x=0x75;
     //************************Parallel Output code below****************************
     //Change the number after i, Out32 (i,change number here) to see the binary
     //numbers on your LEDs
     int choice;
     do
     {
          system("cls");
          cout <<"Nicholas Vadivelu's Bi-Directional Motor Program"<<  endl << "------------------------------------------------" << endl << endl;
          cout << "1 - Spin Clockwise" << endl;
          cout << "2 - Spin Counter Clockwise" << endl;
          cout << "3 - Pulse" << endl;
          cout << "0 - Exit" << endl << endl;
          cout << "Choice: ";
          cin >> choice;
          if (choice == 1 || choice == 2) 
          {
          		int spin;
               system("cls");
               cout << "How long do you want the motor to spin (milliseconds)? ";
               cin >> spin;
            	Out32(i, choice);
            	cout << "Spinning..." << endl;
                Sleep(spin);
                cout << "The motor is done spinning. Press any key to continue...";
                Out32(i, 0);
               getch();   
          }  else if (choice == 3)
          {
          		int choose, pulses, length, fr;
                 system("cls");
                 cout << "1 - Clockwise" << endl;
          		cout << "2 - Counter Clockwise" << endl;
          		cout << "3 - Alternating" << endl << endl;
                 cout << "Which direction do you want the motor to spin? ";
                 cin >> choose;
                 cout << "How many pulses? ";
                 cin >> pulses;
                 cout << "How long do you want each pulse to be (milliseconds)? ";
                 cin >> length;
                 if (choose == 1 || choose == 2)
                 {
                 	cout << "Spinning..." << endl;
                 	for (fr=0; fr < pulses; fr++)
                 	{
                 		Out32(i, choose);
                		Sleep(length);
                		Out32(i, 0);
                		Sleep(length);
                 	}
                 } else if (choose == 3)
                 {
                 	cout << "Spinning..." << endl;
                 	for (fr=0; fr < pulses; fr++)
                 	{
                 		if (fr % 2 == 0)
                 		{
                 			Out32(i, 2);
                			Sleep(length);
                 		} else 
                 		{
                 			Out32(i, 1);
                 			Sleep(length);
                 		} 
                 		Out32(i, 0);
                		Sleep(length);
                 	}
                 }
                 Out32(i, 0);
                 cout << "The motor is done spinning. Press any key to continue...";
               	getch();
          }
          cin.get();
          cout << endl;
          //system("PAUSE"); 
     } while (choice != 0);
     cout << endl;
     cout <<"Goodbye!!!";
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

