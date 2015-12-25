/*Nicholas Vadivelu
TEJ3M1-05
<date>
Set 1
Shows how to use a menu program*/

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

//***********************Wassup*************************
void wassup()
{
cout << "Yo, wass up!!\n";
cout << "You can put any program here";
cout << endl;
}

//***********************Main Menu*************************
int main()
{ 
int choice;

    do
    {
    system ("cls");
    	cout <<"1.Empty " <<"\n\n";
    	
    	cout <<"2.Wassup program "<<"\n\n";	
    	
    	cout <<"3.Empty "<<"\n\n";
    
    	cout <<"4.Empty " <<"\n\n";
    
    	cout <<"0.Exit "<<"\n\n";
    	cin >>choice;
    	if (choice== 1 )
    	cout << "Enter your program here";
    
    	else if (choice == 2)
    	wassup ();
    
    	else if (choice == 3)
    	cout << "Enter your program here";
    
    	else if (choice == 4)
    	cout << "Enter your program here";
        cin.get ();	   
        cout << endl << endl;
        getch();  
    }
    while (choice != 0 );
cout << endl;
cout <<"Goodbye!!!";
getch();
return (0);
}
