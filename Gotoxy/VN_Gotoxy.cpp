/*Nicholas Vadivelu
TEJ 3M1-05
November 20, 2014
The GOTOXY program*/

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>

using namespace std;
//#include <windows.h>
//This is the go to x(horizontal) and y (vertical) prototype.
void gotoxy(int x, int y)
{
	srand(time(NULL));
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void OverHere()
{
	//Calling the gotoxy prototype.
	srand(time(NULL));
	do
	{
		system("CLS");
		gotoxy(rand() % (90), rand() % (24));
		cout << "I am over here!!!";
		Sleep(10);
	} while (!kbhit());
}

void ImHere()
{
	int i;
	for (i = 0; i<=20; i++)
	{
		gotoxy(i, i); //moves the position down and right one space every iteration
		cout << "I am over here!!!"; //prints the text in that spot
		Sleep(100); //programs waits before iterating through the loop
	}
	for (i = 20; i>=0; i--)
	{	
		gotoxy((i+30), i); //moves the position of the cursor up and to the right every iteration
		cout << "And I am here!!!"; //prints the text in that spot
		Sleep(100); //program waits before iterating through the loops
	}
	gotoxy(0, 21);
}
 
int main ()
{    
	int choice;
    do
    {
    system ("cls");
        cout <<"Nicholas Vadivelu's Gotoxy"<<  endl << "--------------------------" << endl << endl;
    	cout <<"1 - Over Here "<<"\n\n";    	
    	cout <<"2 - I am here!!! "<<"\n\n";	    
    	cout <<"0 - Exit "<<"\n\n";
    	cin >>choice;
    	system("CLS");
    	if (choice== 1 )
    		OverHere();
    
    	else if (choice == 2)
    		ImHere();
    		
        cin.get ();	   
        cout << endl << endl << "Press any key to continue..." ;
        getch();  
    } while (choice != 0 );
	cout << endl << endl;
	cout <<"Goodbye!!!";
	getch();
	return (0); //returns 0 to reset the RAM
}    


 
