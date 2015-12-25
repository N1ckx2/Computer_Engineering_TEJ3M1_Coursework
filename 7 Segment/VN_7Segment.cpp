 /* Nicholas Vadivelu
 November 7, 2014
 TEJ 3M1-05
 7 Segment Output*/

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
     int choice, n, tens, ones, final;
     do
     {
          system("cls");
          cout <<"Nicholas Vadivelu's 7 Segment Display Program"<<  endl << "------------------------------" << endl;
          cout << "1 - Output Number 0-99" << endl;
          cout << "2 - Count 0 - 99" << endl;
          cout << "3 - Count 0 - 99 by 3s" << endl;
          cout << "0 - Exit" << endl;
          cin >> choice;
          if (choice == 1) 
          {
             
                system("cls");
               	string l = "";
				do 
				{
					cout << "Input any number from 0 to 99: ";
			    	cin >> n;
				} while (n > 99 || n < 0);
				
				tens = n / 10;
				ones = n % 10;
				final = tens + (ones*16);
				y = final;
				for(int x = 128; x >= 1; x/=2)
				{
			          if (y/x >= 1) 
			          {
			               l = "1" + l;
			               y -= x;
			          }
			          else if (y/x == 0) l = "0" + l;
			    }
				system("cls");
               Out32 (i, final);
               cout << "The number " << n << " becomes " << final << " => " << l << endl << endl;
               system("PAUSE");     
          } else if (choice == 2)
          {
          		system("cls");
          		n = 0;
          		do
          		{
					tens = n / 10;
					ones = n % 10;
					final = tens + (ones*16);
					cout << n << endl;
					Out32 (i, final);
					Sleep(150);
					n++;
					if (n == 100) n = 0;
				} while(!kbhit());
				cout << endl;
				system("PAUSE");
          } else if (choice == 3)
          {
          		system("cls");
          		n = 0;
          		do
          		{
					tens = n / 10;
					ones = n % 10;
					final = tens + (ones*16);
					cout << n << endl;
					Out32 (i, final);
					Sleep(150);
					n+=3;
					if (n > 99) n = 0;
				} while(!kbhit());
				cout << endl;
				system("PAUSE");
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

