
#include "pch.h"
#include<iostream> 
#include<string> 
using namespace std;

const int ARGUMENTNUM = 2;

bool chechForBinary(string BinNum)
{
	int len = BinNum.length();
	int num = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		if (BinNum[i] == '0' || BinNum[i] == '1')
		{
			return true;
		}
		else
		{
			return false;
			break;
		}
	}
}

int BinaryToDecimal(string BinNum)
{
	int Decimal = 0;
	int Power = 1;

	int len = BinNum.length();
	for (int i = len - 1; i >= 0; i--)
	{
		if (BinNum[i] == '1')
		{
			Decimal += Power;
		}

		Power = Power * 2;
	}

	return Decimal;
}


int main(int argc, char *argv[])
{
	if (argc != ARGUMENTNUM)
	{
		cout << "Please check your arguments" << endl;
		return 1;
	}

	string BinNum = argv[1];


	if (chechForBinary(BinNum) == false)
	{
		cout << "You argument is not binary number" << endl;
	}

	else
	{
		cout << BinaryToDecimal(BinNum) << endl;
	}

	return 0;

}
