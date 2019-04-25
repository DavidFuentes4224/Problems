/*
When given a number, will produce and report the sum of all
the multiples of 3 and 5 below given number. Main function has
been renamed to "main1" for easier debugging in other problems.
*/
#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;
int findsum(int n);

int main1()
{
	cout << "Enter a number: ";
	unsigned int n;
	cin >> n;
	cout << endl << "The sum of all the multiples of 3 and 5 below " << n << " is " << findsum(n) << endl;


	return 0;
}

int findsum(int num)
{
	int sum = 0;
	int div3 = floor(num / 3);
	int div5 = floor(num / 5);

	//if num is evenly divisible by 5 or 3, decrease the number of multiples of that number by 1
	//the report must show the sum of multiples BELOW the given number
	if ((num % 3 == 0) || (num % 5 == 0))
	{
		(num % 3 == 0) ? div3-- : div5--;
	}

	/*
	computes the sum of the multiples.
	This process can be sped up using two hash table tables.
	*/
	for (int i = 1; i <= fmax(div3, div5); i++)
	{
		if (i <= div5)
		{
			sum = sum + (i * 5);
		}
	}

	return sum;
}
