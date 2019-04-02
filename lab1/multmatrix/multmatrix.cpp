// multmatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
const int ARGUMENTSNUM = 3;
const int MATRIXSIZE = 3;

void fillMatrix(ifstream &fileIn, float Matrix[MATRIXSIZE][MATRIXSIZE])
{
	for (int i = 0; i < MATRIXSIZE; i++)
	{
		for (int j = 0; j < MATRIXSIZE; j++)
		{
			float num;
			fileIn >> num;
			Matrix[i][j] = num;
		}
	}
}

void PrintMatrix(float multMatrix[MATRIXSIZE][MATRIXSIZE])
{
	for (int i = 0; i < MATRIXSIZE; i++)
	{
		for (int j = 0; j < MATRIXSIZE; j++)
		{
			float num;
			num = multMatrix[i][j];
			cout << fixed << setprecision(3) << num << ' ';
		}
		cout << endl;
	}
}

void multiplyTwoMatrix(float firstMatrix[MATRIXSIZE][MATRIXSIZE], float secondMatrix[MATRIXSIZE][MATRIXSIZE],
	float multMatrix[MATRIXSIZE][MATRIXSIZE])
{
	for (int i = 0; i < MATRIXSIZE; i++)
	{
		for (int j = 0; j < MATRIXSIZE; j++)
		{
			for (int k = 0; k < MATRIXSIZE; k++)
			{
				multMatrix[i][j] = multMatrix[i][j] + firstMatrix[i][k] * secondMatrix[k][j];
			}
		}
	}
}

void mulMatrix(ifstream &fileFirst, ifstream &fileSecond)
{

	float firstMatrix[MATRIXSIZE][MATRIXSIZE];
	float secondMatrix[MATRIXSIZE][MATRIXSIZE];
	float ResultMatrix[MATRIXSIZE][MATRIXSIZE] = { 0 };

	fillMatrix(fileFirst, firstMatrix);
	fillMatrix(fileSecond, secondMatrix);

	multiplyTwoMatrix(firstMatrix, secondMatrix, ResultMatrix);
	PrintMatrix(ResultMatrix);

}


void openFile(ifstream &fileFirst, ifstream &fileSecond)
{
	if (!fileFirst.is_open() || !fileSecond.is_open())
	{
		cout << "file is not opened" << endl;
		cout << "please check for its existence" << endl;
	}
}

int main(int argc, char *argv[])
{
	if (argc != ARGUMENTSNUM)
	{
		cout << " check for exsitence of all arguments" << endl;
		cout << " Name of program input1.txt input2.txt" << endl;
		return 1;
	}

	ifstream fileFirst;
	ifstream fileSecond;
	fileFirst.open(argv[1]);
	fileSecond.open(argv[2]);
	openFile(fileFirst, fileSecond);

	mulMatrix(fileFirst, fileSecond);

}
