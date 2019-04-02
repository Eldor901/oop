#pragma once

#include <set>
#include <string>
#include <optional>
#include <vector>
#include <iostream>

const unsigned int MaxNumBourn = 100000000;

using namespace std;

string ConvertArgumentToNumber(unsigned int &number, const string &str, string & error);
set<int> VectorToSet(vector <bool> & boolVector);
vector<bool> GetPrimeNumbersInVector(int upperBound);
set<int> GeneratePrimeNumbersSet(int upperBound);
