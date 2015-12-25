 /* Nicholas Vadivelu
 October 15, 2014
 TEJ 3M1-05
 8 LED Output*/

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
          cout <<"Nicholas Vadivelu's 8 LED Output"<<  endl << "------------------------------" << endl << endl;
          cout << "1 - Count 255" << endl;
          cout << "2 - Powers of 2" << endl;
          cout << "3 - Decimal to Binary" << endl;
          cout << "0 - Exit" << endl;
          cin >> choice;
          if (choice == 1) 
          {
               system("cls");
               for (y = 1; y<=255; y++)
               {
                    Out32(i,y);
                    Sleep (50);
                    cout << y << endl;
                    if (kbhit()) break;
               }
               cout << "\nPress any key to count down from 255" << endl << endl;
               getch();
               for (y = 255; y>=0; y--)
               {
                    Out32(i, y);
                    Sleep(50);
                    cout << y << endl;
                    if (kbhit()) break;
               } 
               system("PAUSE");     
          } else if (choice == 2)
          {
               system("cls");
               while(!kbhit())
               {
                   for(y=1; y<=128; y*=2) //loops while x is less than 128, doubles each time
                   {
                         Out32(i, y);
                         Sleep(100);
                         cout << y << " ";
                   } 
                   for (y = 64; y>=1; y/=2) // counts down by 2s
                   {
                        Out32(i, y);
                        Sleep(100);
                        cout << y << " ";
                   }
                   cout << endl;
               }
               cout << endl;
               system("PAUSE"); 
          } else if (choice == 3)
          {
                 system("cls");
                 int m, v;
                 cout << "Type in a number from 1 to 255: ";
                 cin >> m;
                 v = m;
                 while (m > 255 || m < 0) 
                 {
                      cout <<"\n" << "Try again: ";
                      cin >> m;
                      v = m;
                 }
                 Out32(i, m);
                 cout << endl;
                for(int w = 128; w >= 1; w/=2)
                {
                     if (v/w >= 1) 
                     {
                        cout << "1"; //if the number is divisable it will add a 1 to binary
                        v -= w; // it will take away that amount for more accurate future reading
                     } else if (v/w == 0) cout << "0"; //if the number is not divisable it will add a 0
                }
            
                 cout << endl << endl;
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

