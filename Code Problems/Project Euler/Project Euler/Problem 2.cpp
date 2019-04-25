/*
Reports the sum of the even-valued fibonnaci numbers from 0 to 4,000,000.
A possible improvment to this code would be to include the Fib numbers in
a hash table. This way, the Fib numbers are only ever calculated once or 
as needed.
*/

#include "pch.h"
#include <iostream>
#include <stdio.h>


using namespace std;

int getFib();

int main2() {
	cout << "The sum of the even-valued terms is: " << getFib() << endl; 
	return 0;
}

int getFib()
{
	int first = 1;
	int second = 2;
	int sum = 0;
	int fnum = 3;

	while (fnum < 4000000)
	{
		if (fnum % 2 == 0)
		{
			
			sum += fnum;
		}
		int temp = fnum;
		first = second;
		second = temp;
		fnum = first + second;	
	}
	return sum;
}