#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <iomanip>

using namespace std;

int main() {
	int n, tens, ten, ones, i, x, final;
	int first[3], second[3];
	
	do 
	{
		cout << "Input any number from 0 to 99: ";
    	cin >> n;
	} while (n > 99 || n < 0);
	
	ten = n / 10;
	tens = ten;
	ones = n % 10;
	x = 3;
	
	for (i = 8; i >= 1; i/=2)
	{
		first[x] = tens/i;
		second[x] = ones/i;
		if (first[x] == 1)
		{
			tens -= i;
		}
		if (second[x] == 1)
		{
			ones -= i;
		}
		x--;
	}
	i = 1;
	final = 0;
	for(x=0; x<=3; x++)
	{
		final += second[x] * i * 16;
		i *= 2;
	}
	final += ten;
    return final;   
}
