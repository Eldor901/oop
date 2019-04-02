#include "pch.h"
#include "FuncToVect.h"

void MultToArifAvrage(vector<float> &nums, float arifAvrage, int numQuan)
{
	for (int i = 0; i < numQuan; i++)
	{
		nums[i] = nums[i] + arifAvrage;
	}


}

void ArifmeticAvrageOfPositiveNums(vector<float> &nums, int numQuan, float &arifAvrage)
{
	float sumPosNum = 0;  // suma polojitelnix elementov
	float quanPosNum = 0; // kolichetvo elementov
	for (int i = 0; i < numQuan; i++)
	{
		if (nums[i] > 0)
		{
			sumPosNum += nums[i];
			quanPosNum++;
		}
	}

	if (quanPosNum != 0)
	{
		arifAvrage = sumPosNum / quanPosNum; // srednee arifmiticheskoe znacheniya
	}
}
