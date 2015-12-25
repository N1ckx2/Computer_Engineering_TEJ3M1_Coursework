/*Nicholas Vadivelu
TEJ 3M1-05
November 5, 2014
Array For Loop Demo*/

#include <iostream>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main (){
    int nums = 0;

    int anArray[10];              // declares an array of integers and allocates memory for 10 integers
    
    for (int i = 0; i < 9; i++)//Loops 9 times to fill the array
    {
        nums += 100;//Goes up by increment of 100
        anArray [i] = nums;//fills the elements of the array by adding 100 every loop  
        cout << "Element at index " << i << ": " << anArray [i] << endl; //looking at the content of element 1
    }
	cin.get();
	return 0;
}
