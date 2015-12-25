/* Nicholas Vadivelu
TEJ 3M1-05
November 4, 2014
Array Demo*/

#include <iostream>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <time.h>

using namespace std;

int main(){
	int array[6]; // even tho this array says size 6, it technically has 7 spaces, because it starts counting from 0
					//but never use the final space, always leave it empty.  This is so there is no stack overflow error
	array[0] = 4; //an array always starts counting from 0
	array[1] = 323; // you can individually assign values to each element in the array
	array[2] = 2;
	array[3] = 1;
	array[4] = 342345;
	array[5] = 0;
	cout << array [0] << endl; //you refer to each element by typing in it's position (in this case 0)
	cout << array [1] << endl; // you CANNOT refer to an element in the array by it's value (so array[323] wont give you 323)
	cout << array [2] << endl;
	cout << array [3] << endl;
	cout << array [4] << endl;
	cout << array [5] << endl;
	cout << "\nPress enter to continue..." << endl;
	getch();
	cout << endl;
	
	int x = 4;  //you can use variables inside arrays
	int array2[4] = {4, x, 34523, 9}; //you can also declare arrays like this
	for (int i = 0; i <= 3; i++) //this is an easier way to go through arrays
	{
		cout << array2[i] << endl; //each time this loop runs, it has a different value of i because i keeps increasing
									// this way you can print each element in the array using a simple loop
		Sleep(500); //delay
	}
	getch();
	return 0;
}
