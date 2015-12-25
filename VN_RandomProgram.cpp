/* Nicholas Vadivelu
TEJ 3M1-05
November 4, 2014
Random Program*/

#include <iostream>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <time.h>

using namespace std;

int main(){
	unsigned long long one, start, stop, range, t;
	do
	{
		cout << "What do you want the range of the numbers to be\nThe starting number must be smaller than the ending number?\n\tStarting Number: ";
		cin >> start;
		cout << "\tEnding Number: ";
		cin >> stop;
		cout << endl;
		//prompts user for start and end number and keep prompting until data is correct.
	} while (start > stop);
	//cout << "How long do you want the delay to be: ";
	//cin >> t;
	range = stop - start;
	unsigned long long num[stop+1]; //creates an array for every possible random value
	srand(time(NULL));
	system ("cls");
	for (int i = 0; i <= stop + 1; i++)
	{
		num[i] = 0;
	}
	do
	{
		one = rand() % (range+1) + start;
		cout << one << " ";
		num [one]++;
		//Sleep(t);
	}while(!kbhit());
	system("cls");
	cout << "Number of times each number appears: ";
	for (int i = start; i <= stop; i++)
	{
		cout << "\n" << i << ": " << num[i];
	}
	cout << "\n\nPress <Enter> to exit the program...";
	getch();
	getch();
	return 0;
}
