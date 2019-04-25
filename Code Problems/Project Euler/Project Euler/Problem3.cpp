/*
When given a number, produces a list of prime factors of given number.
This code has been modified to include multi-threading with 4 threads
and has been given a timer for performance testing. Testing shows using
4 threads allowed for 4 times quicker execution.
*/

#include"pch.h"
#include <iostream>
#include <stdio.h>
#include <iterator>
#include <vector>
#include <math.h>
#include <thread>
#include <chrono>


using namespace std;

vector<unsigned int> GetFactors(unsigned int num);
bool _isPrime(unsigned int num);
void PrintVector(vector<unsigned int> vect);
void AddFactorsThreaded(vector<unsigned int> *vect, const unsigned int num, const int tID);
void AddFactors(vector<unsigned int> *vect, const unsigned int num);

int main() {
	cout << "::PROBLEM 3::" << endl;
	unsigned int x = 600851475143;

	//get all factors of given number
	vector<unsigned int> myFactors = GetFactors(x);
	vector<unsigned int>::iterator iter;
	vector<unsigned int> myPrimeFactors;


	auto start = chrono::high_resolution_clock::now(); //gets current time in microseconds

	//iterate through factors of given number and determine ones that are prime
	for (iter = myFactors.begin(); iter != myFactors.end(); iter++)
	{
		if (_isPrime(*iter))
		{
			//add prime factor to list of prime factors
			myPrimeFactors.push_back(*iter);
		}
	}
	cout << "The prime factors of: " << x << " is "; PrintVector(myPrimeFactors);


	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

	cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
	return 0;
}

vector<unsigned int> GetFactors(unsigned int num){
	vector<unsigned int> factors;
	//restricting the use of threading to only when needing more than 1000 calculations
	if (num >= 1000)
	{
		std::thread t1(AddFactorsThreaded, &factors, num, 0);
		std::thread t2(AddFactorsThreaded, &factors, num, 1);
		std::thread t3(AddFactorsThreaded, &factors, num, 2);
		std::thread t4(AddFactorsThreaded, &factors, num, 3);

		t1.join();
		t2.join();
		t3.join();
		t4.join();
	}
	else
	{
		AddFactors(&factors, num);
	}
	
	cout << "The factors of " << num << " are ";PrintVector(factors);
	return factors;
}

void AddFactors(vector<unsigned int> *vect, const unsigned int num) {
	for (int i = 1; i <= floor(num / 2); i++)
	{
		if (num % i == 0)
		{
			(*vect).push_back(i);
		}
	}
}

//this could be changed to an overloaded version of AddFactors for easier use
void AddFactorsThreaded(vector<unsigned int> *vect, const unsigned int num, const int tID) {
	for (int i = num / 8 * tID + 1; i < floor(num / 8 * (tID + 1)); i++)
	{
		if (num % i == 0)
		{
			(*vect).push_back(i);
		}
	}
}

bool _isPrime(unsigned int num){
	vector<unsigned int> factors = GetFactors(num);
	return factors.size() > 1 ? false : true;
}

void PrintVector(vector<unsigned int> vect) {
	vector<unsigned int>::iterator iter;

	cout << "Vector: [";
	for (iter = vect.begin(); iter != vect.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << "]" << endl;
}