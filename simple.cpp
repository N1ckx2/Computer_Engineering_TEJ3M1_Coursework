/*Sean Purcell
TEJ3M1
October 2 12
8 LED Program*/

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <math.h>



using namespace std;
int numInput(string str){
       cout << str;
       int in;
       
       cin >> in;
       return in;    
}

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
     
     
/********************************************Count*****************************/
void Boo()
{
        cout << 23 << endl;
        Out32(PPORT_BASE,23);  
        getch();   
}
/********************************************Count*****************************/
void count(){
     for(int i = 0; i < 256 && !kbhit(); i=(i<255)?i+1:0)
     
     {
        cout << i << endl;
        Out32(PPORT_BASE,i);
        Sleep(25);        
     }
     getch();
     cout << "Press any key to count back down\n";
     getch();
     
     for(int i = 255; i > 0 && !kbhit(); i--){
        cout << i << endl;
        Out32(PPORT_BASE,i);
        Sleep(25);       
     }
     getch();
}
/********************************************Power*****************************/
void power(){
     while(!kbhit())
     {
        for(int i = 1; i < 256; i *= 2)
        {
           cout << i << " ";
           Out32(PPORT_BASE,i);
           Sleep(25);        
        }
        cout << endl;
     }
     cout << "Press any key to go in reverse." << endl;
     getch();
     getch();
     while(!kbhit())
     {
        for(int i = 128; i >= 1; i /= 2)
        {
           cout << i << " ";
           Out32(PPORT_BASE,i);
           Sleep(25);       
        }
        cout << endl;
     }
     
     cout << "Press any key to go up and down." << endl;
     getch();
     getch();
     
     while(!kbhit())
     {
        for(int i = 1; i < 256; i *= 2)
        {
           cout << i << " ";
           Out32(PPORT_BASE,i);
           Sleep(25);        
        }
        for(int i = 64; i >= 1; i /= 2){
           cout << i << " ";
           Out32(PPORT_BASE,i);
           Sleep(25);       
        }
        cout << endl;
     }
     getch();
}
/********************************************Binary****************************/
string toB2(int digit){
        
        int maxE = 0;
        int base = 2;
        maxE = (int) (log(digit)/log(base));
        string out = "";
        for(int count = maxE; count >= 0; count--){
            
            if(pow(2,count) <= digit){
                 out += "1";
                 digit -= pow(2,count);           
            }else{
                 out += "0"; 
            }
        }
        
        return out;
    }

void binary(){
     cout << "Enter a number from 0 to 255" << endl;
     int in;
     cin >> in;
     cout << "The number in base two is " << toB2(in);
     Out32(PPORT_BASE,in);
     
     getch();
}
/********************************************Menu****************************/
void menu(){
    int choice = -1;
    
    while(choice != 0)
    {
       system("cls");
       choice = numInput("1. Counting\n2. Powers of 2\n3. Binary\n0. End Program\n");
       if(choice == 1)
       {
           system("cls");
           Boo();
                     
       }else if(choice == 2)
           {
               system("cls");
               power();
                         
           }else if(choice == 3)
           {
               system("cls");
               binary();
                         
           }             
    }
    cout << "Program Terminated";
    getch();
   
}

/********************************************Main****************************/     
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
     menu();
     FreeLibrary(hLib);
     return 0;
}




