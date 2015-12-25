/*Nicholas Vadivelu
TEJ 3M1-05
November 5, 2014
Array Demo*/

#include <iostream>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main (){
	int anArray[10];              // declares an array of integers and allocates memory for 10 integers

    anArray [0] = 100; // initialize first element
    anArray [1] = 200; // initialize second element
    anArray [2] = 300; // etc.
    anArray [3] = 400;
    anArray [4] = 500;
    anArray [5] = 600;
    anArray [6] = 700;
    anArray [7] = 800;
    anArray [8] = 900;
    anArray [9] = 1000;

    cout << "Element at index 0: " << anArray [0] << endl;//looking at the content of element 1
    cout << "Element at index 1: " << anArray [1] << endl;
    cout << "Element at index 2: " << anArray [2] << endl;
    cout << "Element at index 3: " << anArray [3] << endl;
    cout << "Element at index 4: " << anArray [4] << endl;
    cout << "Element at index 5: " << anArray [5] << endl;
    cout << "Element at index 6: " << anArray [6] << endl;
    cout << "Element at index 7: " << anArray [7] << endl;
    cout << "Element at index 8: " << anArray [8] << endl;
    cout << "Element at index 9: " << anArray [9] << endl;//looking at the content of element 2
    cin.get();
    return 0;
    //Why not use a for loop to do all this. See ArrayForLoopDemo
}
