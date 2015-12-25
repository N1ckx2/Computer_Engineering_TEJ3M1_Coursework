/*Nicholas Vadivelu
tej 3m1-05
5 January 2015
Input*/

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

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
void test_write(void) 
{

    int input; //declares var
    do
    {
        input = Inp32 (PPORT_INP); //Recieves input
        //cin >> input;
        //******************************************0**********************************************
        if (input == 120)
        {
            cout << "No buttons were pressed" << endl;
            cout << "No pins on the parrallel port" << endl;
        }
        //******************************************1**********************************************
        else if (input == 56)
        {
            cout << "Button 1 was pressed" << endl;
            cout << "Pin 10 on the parrallel port" << endl;
        }
        //******************************************2**********************************************
        else if (input == 248)
        {
            cout << "Button 2 was pressed" << endl;
            cout << "Pin 11 on the parrallel port" << endl;
        }
        //******************************************3**********************************************
        else if (input == 88)
        {
            cout << "Button 3 was pressed" << endl;
            cout << "Pin 12 on the parrallel port" << endl;
        }
        //******************************************4**********************************************
        else if (input == 104)
        {
            cout << "Button 4 was pressed" << endl;
            cout << "Pin 13 on the parrallel port" << endl;
        }
        //******************************************5**********************************************
        else if (input == 112)
        {
            cout << "Button 5 was pressed" << endl;
            cout << "Pin 15 on the parrallel port" << endl;
        }
        //******************************************10+11**********************************************
        else if (input == 184)
        {
            cout << "Button 1 and 2 was pressed" << endl;
            cout << "Pin 10 and 11 on the parrallel port" << endl;
        }
        //******************************************10+12**********************************************
        else if (input == 24)
        {
            cout << "Button 1 and 3 was pressed" << endl;
            cout << "Pin 10 and 12 on the parrallel port" << endl;
        }
        //******************************************1+4**********************************************
        else if (input == 40)
        {
            cout << "Button 1 and 4 was pressed" << endl;
            cout << "Pin 10 and 13 on the parrallel port" << endl;
        }
		//******************************************10+15**********************************************
        else if (input == 48)
        {
            cout << "Button 1 and 5 were pressed" << endl;
            cout << "Pin 10 and 15 on the parrallel port" << endl;
        }
		//******************************************2 + 3**********************************************
        else if (input == 216)
        {
            cout << "Button 2 and 3 were pressed" << endl;
            cout << "Pin 11 and 12 on the parrallel port" << endl;
        }
        //******************************************2+ 4**********************************************
        else if (input == 232)
        {
            cout << "Button 2 and 4 were pressed" << endl;
            cout << "Pin 11 and 13 on the parrallel port" << endl;
        }
        //******************************************2+5**********************************************
        else if (input == 240)
        {
            cout << "Button 2 and 5 were pressed" << endl;
            cout << "Pin 11 and 15 on the parrallel port" << endl;
        }
        //******************************************3+4**********************************************
        else if (input == 72)
        {
            cout << "Button 3 and 4 were pressed" << endl;
            cout << "Pin 12 and 13 on the parrallel port" << endl;
        }
        //******************************************3+5**********************************************
        else if (input == 80)
        {
            cout << "Button 3 and 5 were pressed" << endl;
            cout << "Pin 12 and 15 on the parrallel port" << endl;
        }
        //******************************************4, 5**********************************************
        else if (input == 96)
        {
            cout << "Buttons 4 and 5 were pressed" << endl;
            cout << "Pins 13 and 15 on the parrallel port" << endl;
        }
        //******************************************1, 2, 3**********************************************
        else if (input == 152)
        {
            cout << "Button 1, 2, and 3 were pressed" << endl;
            cout << "Pin 10, 11, and 12 on the parrallel port" << endl;
        }
        //******************************************1, 2, 4**********************************************
        else if (input == 168)
        {
            cout << "Button 1, 2, and 4 were pressed" << endl;
            cout << "Pin 10, 11, and 13 on the parrallel port" << endl;
        }
        //******************************************1, 2, 5**********************************************
        else if (input == 176)
        {
            cout << "Button 1, 2, and 5 were pressed" << endl;
            cout << "Pin 10, 11, and 15 on the parrallel port" << endl;
        }
        //******************************************1, 3, 4**********************************************
        else if (input == 8)
        {
            cout << "Button 1, 3, and 4 were pressed" << endl;
            cout << "Pin 10, 12, and 13 on the parrallel port" << endl;
        }
        //******************************************1, 3, 5**********************************************
        else if (input == 16)
        {
            cout << "Button 1, 3, and 5 were pressed" << endl;
            cout << "Pin 10, 12, and 15 on the parrallel port" << endl;
        }
        //******************************************1, 4, 5**********************************************
        else if (input == 32)
        {
            cout << "Button 1, 4, and 5 were pressed" << endl;
            cout << "Pin 10, 13, and 15 on the parrallel port" << endl;
        }
        //******************************************2, 3, 4**********************************************
        else if (input == 200)
        {
            cout << "Buttons 2, 3, and 4 were pressed" << endl;
            cout << "Pin 11, 12, and 13 on the parrallel port" << endl;
        }
        //******************************************2, 3, 5**********************************************
        else if (input == 208)
        {
            cout << "Buttons 2, 3, and 5 were pressed" << endl;
            cout << "Pin 11, 12, and 15 on the parrallel port" << endl;
        }
        //******************************************2, 4, 5**********************************************
        else if (input == 224)
        {
            cout << "Buttons 2, 4, and 5 were pressed" << endl;
            cout << "Pin 11, 13, and 15 on the parrallel port" << endl;
        }
        //******************************************3, 4, 5**********************************************
        else if (input == 64)
        {
            cout << "Buttons 3, 4, and 5 were pressed" << endl;
            cout << "Pin 12, 13, and 15 on the parrallel port" << endl;
        }
        //******************************************1, 2, 3, 4**********************************************
        else if (input == 136)
        {
            cout << "Buttons 1, 2, 3, and 4 were pressed" << endl;
            cout << "Pins 10, 11, 12, and 13 on the parrallel port" << endl;
        }
        //******************************************1, 2, 4, 5**********************************************
        else if (input == 160)
        {
            cout << "Buttons 1, 2, 4, and 5 were pressed" << endl;
            cout << "Pins 10, 11, 13 and 15 on the parrallel port" << endl;
        }
        //******************************************1, 3, 4, 5**********************************************
        else if (input == 0)
        {
            cout << "Buttons 1, 3, 4, and 5 were pressed" << endl;
            cout << "Pins 10, 12, 13, and 14 on the parrallel port" << endl;
        }
        //******************************************2, 3, 4, 5**********************************************
        else if (input == 192)
        {
            cout << "Buttons 2, 3, 4, and 5 were pressed" << endl;
            cout << "Pins 11, 12, 13, and 15 on the parrallel port" << endl;
        }
        //******************************************1, 2, 3, 4, 5**********************************************
        else if (input == 128)
        {
            cout << "Buttons 1, 2, 3, 4, and 5 were pressed" << endl;
            cout << "Pins 10, 11, 12, 13, and 15 on the parrallel port" << endl;
        }
		
		cout << input << endl << "Hit the keyboard to quit..." << endl << endl;
        Sleep (1000);
    } while (!kbhit());
    cout << "Program Terminated";
    getch ();
     return ;
}

void test_write_datum(short datum) {
     short x;
     int i;

     i=PPORT_BASE;
     x = datum;

     /*****  Write the data register */
     Out32(i,x);

     printf("Port write to 0x%X, datum=0x%2X\n" ,i ,x);

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

