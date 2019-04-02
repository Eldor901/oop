// GeneraterPrimeNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "GeneratorPrimeNumbers.h"

void PrintSet(set<int> Set)
{
	int elements = 0;
	for (auto i : Set)
	{
		cout << i << ' ';
		if (elements == 20)
		{
			cout << endl;
		}
		elements++;
	}
}

int main(int argc, char *argv[])
{
	unsigned int upperBound;
	string error = "Ok";

	if (argc < 2)
	{
		cout << "Please check for number of arguments: program.exe number";
		return 1;
	}

	ConvertArgumentToNumber(upperBound, argv[1], error);
	if (error != "Ok")
	{
		cout << error << endl;
		return 1;
	}

	set<int> primeNums = GeneratePrimeNumbersSet(upperBound);
	//PrintSet(PrimeNums);
	cout << endl;
	cout << primeNums.size();
}
