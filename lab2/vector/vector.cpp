#include "pch.h"


#include "FuncToVect.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

void PrintVector(vector<float> &nums, int numQuan)
{
	for (int i = 0; i < numQuan; i++)
	{
		cout << fixed << setprecision(3) << nums[i] << ' ';
	}
}


void ReadAndWriteToVector(vector<float> &nums)
{
	int numQuan = 0;
	float arifAvrage = 0;


	float num;
	while (cin >> num)
	{
		nums.push_back(num);
		numQuan = numQuan + 1;
	}

	ArifmeticAvrageOfPositiveNums(nums, numQuan, arifAvrage);
	MultToArifAvrage(nums, arifAvrage, numQuan);

	sort(nums.begin(), nums.end());
	PrintVector(nums, numQuan);
}

int main()
{
	vector<float> nums;
	ReadAndWriteToVector(nums);
}
