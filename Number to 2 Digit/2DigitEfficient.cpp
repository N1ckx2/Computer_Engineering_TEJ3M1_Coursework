#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <iomanip>

using namespace std;

int main() {
	int n, tens, ones, final;
string t;
	do 
	{
		cout << "Input any number from 0 to 99: ";
    	cin >> n;
	} while (n > 99 || n < 0);
	
	tens = n / 10;
	ones = n % 10;
	final = tens + (ones*16);
	
	return final;
}
