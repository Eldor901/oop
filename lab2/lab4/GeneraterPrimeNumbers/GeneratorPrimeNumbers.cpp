#include "pch.h"
#include "GeneratorPrimeNumbers.h"


string ConvertArgumentToNumber(unsigned int &number, const string &str, string & error)
{

	if (number >= 1 && number <= MaxNumBourn)
	{
		error = "Number should be: 1<= Number <= 1000000000";
	}


	try
	{
		number = stoi(str);
	}
	catch (invalid_argument & err)
	{
		error = "invalid argument: num should be int";
	}
	catch (out_of_range &err)
	{
		error = "Out of range";
	}

	return error;

}

set<int> VectorToSet(vector <bool> & boolVector)
{
	set<int> Set;

	for (size_t i = 0; i < boolVector.size(); i++)
	{
		if (boolVector[i])
		{
			Set.insert((int)i);
		}
	}
	return Set;
}

vector<bool> GetPrimeNumbersInVector(int upperBound)
{
	vector<bool> PrimeNumbers(upperBound + 1, true);
	PrimeNumbers[0] = false; // zero
	PrimeNumbers[1] = false; // one both are not prime numbers

	unsigned int MaxElemt = (int)sqrt(PrimeNumbers.size());

	for (size_t i = 2; i <= MaxElemt; i++)
	{
		if (PrimeNumbers[i])
		{
			for (size_t j = 2; i * j < PrimeNumbers.size(); j++)
			{
				PrimeNumbers[i * j] = false;
			}
		}
	}
	return PrimeNumbers;
}

set<int> GeneratePrimeNumbersSet(int upperBound)
{
	vector<bool> PrimeNumbers = GetPrimeNumbersInVector(upperBound);
	return VectorToSet(PrimeNumbers);
}
