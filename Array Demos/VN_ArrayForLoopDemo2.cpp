/*Nicholas Vadivelu
TEJ 3M1-05
November 5, 2014
Array For Loop Demo 2*/

#include <iostream>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main (){
    int nums = 0;
    int howMany;//Allows the user to choose the size of the array.  

    //Let the user determine the amount of elements he/she wants
    cout << "Enter the size of the array using an integer: ";
    cin >> howMany;
    int anArray[howMany]; //declares and makes the array the length that the user chose

    for (int i = 0; i <= howMany - 1; i++)//Loops 9 times to fill the array
    {
        nums += 100;//Goes up by increments of 100
        anArray [i] = nums;//fills the elements of the array by adding 100 every loop  
        cout << "Element at index " << i << ": " << anArray [i] << endl; //looking at the content of element 1
    }
    cout << "\n" << "You picked a fine size user." << endl;
    cout << "With just 1 for loop we filled the array efficiently."<< endl;
    cout << "Thank you for the loop."<< endl;
    
	getch();
	return 0;
}
