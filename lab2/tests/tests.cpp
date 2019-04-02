

#define CATCH_CONFIG_MAIN


#include "../../catch.hpp"
#include "../vector/FuncToVect.h"

TEST_CASE("Avrifmatic avrage of positive nums:")
{
	WHEN("random numbers")
	{
		vector<float> nums = { 1.22f, -2.14f, -2.12f, 3.11f, 4.44f };
		int numQuan = 5;
		float arifAvrage = 0;
		THEN("Check int numbers of arifavrage")
		{
			ArifmeticAvrageOfPositiveNums(nums, numQuan, arifAvrage);
			arifAvrage = (int)arifAvrage;
			CHECK(arifAvrage == 2); // comprassinon with int so as we cant compare float numbers
		}
	}

	WHEN("All Numbers Are Negative")
	{
		vector<float> nums = { -1.22f, -2.14f, -2.12f, -3.11f, -4.44f };
		int numQuan = 5;
		float arifAvrage = 0;
		THEN("Check int numbers of arifavrage")
		{
			ArifmeticAvrageOfPositiveNums(nums, numQuan, arifAvrage);
			arifAvrage = (int)arifAvrage;
			CHECK(arifAvrage == 0); // comprassinon with int so as we cant compare float numbers
		}
	}


	WHEN("empty vector")
	{
		vector<float> nums = {};
		int numQuan = 0;
		float arifAvrage = 0;
		THEN("Check int numbers of arifavrage")
		{
			CHECK(arifAvrage == 0); // comprassinon with int so as we cant compare float numbers
		}
	}



}

TEST_CASE("Mult To arifmetic avrage: ")
{
	WHEN("random numbers")
	{
		vector<float> nums = { 1.00f, -2.00f, -2.00f, 3.00f, 5.00f };
		int numQuan = 5;
		float arifAvrage = 3;
		THEN("Check added avragenum to sum of vectors")
		{
			MultToArifAvrage(nums, arifAvrage, numQuan);
			CHECK(nums == vector<float>{4.00, 1.00, 1.00, 6.00, 8.00}); // comprassinon with int so as we cant compare float numbers
		}
	}


	WHEN("All Numbers Are Negative")
	{
		vector<float> nums = { -1.22f, -2.14f, -2.12f, -3.11f, -4.44f };
		int numQuan = 5;
		float arifAvrage = 0;
		THEN("Check added avragenum to sum of vectors")
		{
			MultToArifAvrage(nums, numQuan, arifAvrage);
			CHECK(nums == vector<float>{-1.22f, -2.14f, -2.12f, -3.11f, -4.44f}); // comprassinon with int so as we cant compare float numbers
		}
	}


	WHEN("EMPTY RESULT")
	{
		vector<float> nums = { };
		int numQuan = 5;
		float arifAvrage = 0;
		THEN("Check added avragenum to sum of vectors")
		{
			MultToArifAvrage(nums, numQuan, arifAvrage);
			CHECK(nums == vector<float>{}); // comprassinon with int so as we cant compare float numbers
		}
	}
}
