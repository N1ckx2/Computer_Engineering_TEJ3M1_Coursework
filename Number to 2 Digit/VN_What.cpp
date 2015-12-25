/*

Nicholas Vadivelu
TEJ3M1-05
November 3, 2014
*/

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <iomanip>

using namespace std;
extern int n = 0;
extern string l = "";

//**********************************Converting an Integer into an integer for 7 Segment**********************
int Splitter(){
	int tens, ones, final;
	system("cls");
	do 
	{
		cout << "Input any number from 0 to 99: ";
    	cin >> n;
	} while (n > 99 || n < 0);
	
	tens = n / 10;
	ones = n % 10;
	final = tens + (ones*16);
	system("cls");
	return final;
}

//***************************Converting an Integer into a binary***********************************************

string Binary(int y){
	l = "";
	for(int x = 128; x >= 1; x/=2)
	{
          if (y/x >= 1) 
          {
               l = "1" + l;
               y -= x;
          }
          else if (y/x == 0) l = "0" + l;
    }
    return l;
}
//***********************Main Menu*************************
int main()
{ 
int choice;

    do
    {
    system ("cls");
        cout <<"Nicholas Vadivelu"<<  endl << "--------------------------" << endl << endl;
    	cout <<"1 - "<<"\n\n";
    
    	cout <<"0. Exit "<<"\n\n";
    	cin >>choice;
    	if (choice== 1 ) 
		{
			int num = Splitter();
			cout << "The number " << n << " becomes " << num << " => " << Binary(num) << endl;
		}
        cin.get ();	   
        cout << endl << endl << "Press any key to continue..." ;
        getch();  
    } while (choice != 0 );
cout << endl << endl;
cout <<"Goodbye!!!";
getch();
return (0);
}
