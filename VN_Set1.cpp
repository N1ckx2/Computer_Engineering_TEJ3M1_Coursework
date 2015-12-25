/*
Set 1
Nicholas Vadivelu
TEJ3M1-05
September 17th, 2014
*/

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

//***********************Kilobyte*************************
void Kilobyte()
{
	int kb;
	cout <<"How many KB is the file?"<<"\n";
	cin >> kb;
	kb = kb*1024;
	cout << "\n" << "This file can store " << kb << " characters.";
	
}

//***********************Rectangle*************************
void Rectangle()
{
	cout <<"What is the length of the rectangle in centimeters:  ";
	int len;
	cin >> len;
	cout <<"What is the width of the rectangle in centimeters:  ";
	int width;
	cin >> width;
	int peri= (len*2 + width*2);
	int area = (len*width);
	cout << "\n" <<"The rectangle has a perimeter of " << peri << " centimeters." << endl;
	cout <<"The rectangle has an area of " << area << " centimeters squared.";	
}

//***********************Arithmetic*************************
void Arithmetic()
{
	double one, two;
	cout <<"Operand #1:  ";
	cin >> one;
	cout <<"Operand #2:  ";
	cin >> two;
	
	cout << one << " + " << two << " = " << one+two << "\n";
	cout << one << " - " << two << " = " << one-two << "\n";
	cout << one << " x " << two << " = " << one*two << "\n";
	double divi = one/two;
	cout << one << " / " << two << " = ";
	cout << divi << endl;
}

//***********************Interest*************************
void Interest()
{
	double prin, inte, fin;
	int year;
	cout << "Principal ($):  " << endl;
	cin >> prin;
	cout << "Interest Rate (%):  " << endl;
	cin >> inte;
	inte *= 0.01;
	
	cout.precision(2);
	cout << "Year 1 Interest = $" << inte*prin << endl; 
	cout.precision(2);
	cout << "Year 2 Interest = $" << (prin+inte*prin)*inte << endl;
	
	
}

//***********************Story*************************
void Story()
{
	string name, noun, noun2, verb, adj;
	cout <<"\n" << "Name:  ";
	cin >> name;
	cout <<"\n" << "Noun:  ";
	cin >> noun;
	cout <<"\n" << "Noun:  ";
	cin >> noun2;
	cout <<"\n" << "Verb (past):  ";
	cin >> verb;
	cout <<"\n" << "Adjective:  ";
	cin >> adj;
	cout <<"\n\n" << name << " " << verb << " the " << noun << " into the " << adj << " " << noun2 << "." << endl;
	
}

//***********************Equation*************************
void Equation()
{
	double a, b;
	cout << "\n" << "Enter coefficients for Ax+B = 0" << "\n" << "A = ";
	cin >> a;
	cout << "B = ";
	cin >> b;
	double c = -1*b/a;
	cout <<"\n" << a << "x + " << b << " = 0" << endl;
	cout << a << "x = " << -1*b << endl;
	cout << "x = " << -1*b << "/" << a << endl;
	cout << "x = " << c << endl;
	
}

//***********************Main Menu*************************
int main()
{ 
int choice;

    do
    {
    system ("cls");
    	cout <<"1. Kilobyte" <<"\n\n";
    	
    	cout <<"2. Rectangle"<<"\n\n";	
    	
    	cout <<"3. Arithmetic"<<"\n\n";
    
    	cout <<"4. Interest" <<"\n\n";
    	
    	cout <<"5. Story" <<"\n\n";
    	
    	cout <<"6. Equation" <<"\n\n";
    
    	cout <<"0. Exit "<<"\n\n";
    	cin >>choice;
    	if (choice== 1 )
    		Kilobyte();
    
    	else if (choice == 2)
    		Rectangle();
    		
    	else if (choice == 3)
    		Arithmetic();
    
    	else if (choice == 4)
    		Interest();
    		
    	else if (choice == 5)
    		Story();
    		
    	else if (choice == 6)
    		Equation();
    		
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
