/*Nicholas Vadivelu
TEJ 3M1-05
October 8, 2014
8 LED*\

  /*Parallel Port Ouput
Simple version Feb 8 11
Mr. Brossard
For more info see notes at the end
or refer to more complex program*/

#include <iostream>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <conio.h>

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
void Count255(){
	     system("cls");
	//1.	From 0 to 255 and then from 255 to 0. 
	for(int x = 0; x<=255; x++) // runs the loop as long as x is less than 255
	{
		cout << x << endl;
            Out32(x,255); // outputs x
            Sleep(50); // makes the program wait
    }
    cout << "\nPress any key to count down from 255" << endl; 
    getch(); //waits for user input
    for (int y = 255; y>=0; y--) //counts down from 255
    {
	cout << y << endl;
        Out32(y,255);
        Sleep(50);
    }
    getch();
}
void MultipleOf2(){
		//2.	In multiples of 2. i.e. 1 2 4 8 16 32 64 128 64 32 16 8 4 2 1
    system("cls");
    for(int x=1; x<=128; x*=2) //loops while x is less than 128, doubles each time
    {
         Out32(x,255);    //prints x with a space
         Sleep(50);
    } 
    for (int y = 64; y>=1; y/=2) // counts down by 2s
    {
        Out32(y,255); // prints y
        Sleep(50);
    }
    getch();
}
void Binary(){
		/*3.	The user can enter a decimal number and the screen and the LEDs show the binary . 
	equivalent. Use error checking to prevent negative numbers and positive 
	numbers above 255. A sample for binary output is attached. */
	system("cls");
	int num;  //works even if number is over 32 bit, but only up to 128 bit
	cout << "Type any integer (0-255) and <Enter>: "; // prompts user
	cin >> num;
	while(true)
	{
        if (num < 0 || num > 255) //checks if integer is between 0-255
        {
                cout << "Retry: ";    
                cin >> num;     
        } 
        else break;
    }
	Out32(num,255);
    getch();
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
     char choice;
    do{
        system("cls");
        cout << "8 LED by Nicholas Vadivelu\n";
        cout << "--------------\n";
        cout << "1. Count255\n";
        cout << "2. MultipleOf2\n";
        cout << "3. Binary\n";
        cout << "0. Quit\n";

        cin >> choice;

        if(choice == '1') Count255();
        else if(choice == '2') MultipleOf2();
        else if(choice == '3') Binary();
    } while(choice != '0');
     
     getch ();
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

