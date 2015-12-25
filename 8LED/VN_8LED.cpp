/*
Set 8
Nicholas Vadivelu
TEJ3M1-05
October 7, 2014
*/

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <iomanip>

using namespace std;

//***********************Count to 255*************************
void Two55()
{
     system("cls");
	//1.	From 0 to 255 and then from 255 to 0. 
	for(int x = 0; x<=255; x++) // runs the loop as long as x is less than 255
	{
            cout << x <<endl; // prints x
            Sleep(50); // makes the program wait
    }
    cout << "\nPress any key to count down from 255" << endl << endl; 
    getch(); //waits for user input
    for (int y = 255; y>=0; y--) //counts down from 255
    {
        cout << y << endl;
        Sleep(50);
    }
    getch();
}

//***********************Count by 2s*************************
void Twos()
{
	//2.	In multiples of 2. i.e. 1 2 4 8 16 32 64 128 64 32 16 8 4 2 1
    system("cls");
    while (!kbhit())
    {
          for(int x=1; x<=128; x*=2) //loops while x is less than 128, doubles each time
          {
                  cout << x << " ";    //prints x with a space
                  Sleep(50);
          } 
          for (int y = 64; y>=1; y/=2) // counts down by 2s
          {
              cout << y << " "; // prints y
              Sleep(50);
          }
          cout << endl;
    }
    getch();
}

//***********************Binary*************************
void Binary()
{
	/*3.	The user can enter a decimal number and the screen and the LEDs show the binary . 
	equivalent. Use error checking to prevent negative numbers and positive 
	numbers above 255. A sample for binary output is attached. */
	system("cls");
	int num;  //works even if number is over 32 bit, but only up to 128 bit
	cout << "Type any integer (0-255) and <Enter>: "; // prompts user
	cin >> num;
	while(num < 0 || num > 255)
	{
              cout << "Retry: ";    
              cin >> num;     
     } 
	for(int x = 128; x >= 1; x/=2)
	{
          if (num/x >= 1) 
          {
               cout << "1"; //if the number is divisable it will add a 1 to binary
               num -= x; // it will take away that amount for more accurate future reading
          }
          else if (num/x == 0) cout << "0"; //if the number is not divisable it will add a 0
    }
}


//***********************Main Menu*************************
int main()
{ 
int choice;

    do
    {
    system ("cls");
        cout <<"Nicholas Vadivelu's 8 LED"<<  endl << "--------------------------" << endl << endl;
    	cout <<"1 - Count 255 "<<"\n\n";
    	
    	cout <<"2 - Powers of 2 "<<"\n\n";	
    	
    	cout <<"3 - Decimal to Binary"<<"\n\n";
    
    	cout <<"0. Exit "<<"\n\n";
    	cin >>choice;
    	if (choice== 1 )
    		Two55();
    
    	else if (choice == 2)
    		Twos();
    		
    	else if (choice == 3)
    		Binary();
    		
        cin.get ();	   
        cout << endl << endl << "Press any key to continue..." ;
        getch();  
    } while (choice != 0 );
cout << endl << endl;
cout <<"Goodbye!!!";
getch();
return (0);
}
