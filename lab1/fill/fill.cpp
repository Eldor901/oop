// fill.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

#pragma comment(linker, "/STACK:16777216")


using namespace std;

const int MAXARRAY = 100;
const int MAXARGUMENTS = 3;


char field[MAXARRAY][MAXARRAY];
void PaintTillFance(int i, int j) //painting places where we have been  untill stap fances.
{
	if (field[i][j + 1] == ' ')
	{
		field[i][j + 1] = '-';
		PaintTillFance(i, j + 1);
	}
	if (field[i][j - 1] == ' ')
	{
		field[i][j - 1] = '-';
		PaintTillFance(i, j - 1);
	}
	if (field[i + 1][j] == ' ')
	{
		field[i + 1][j] == '-';
		PaintTillFance(i + 1, j);
	}
	if (field[i - 1][j] == ' ')
	{
		field[i - 1][j] = '-';
		PaintTillFance(i - 1, j);
	}
}

void initLabir()
{
	for (int8_t i = 0; i < MAXARRAY; i++)
	{
		for (int8_t j = 0; j < MAXARRAY; j++)
		{
			field[i][j] = ' ';
		}
	}
}

void FillLabir(ifstream & fileIn)
{
	char ch;
	int m_tmp = 0;
	int n = 0, m = 0;
	while (fileIn.get(ch))
	{
		if (ch == ' ')
		{
			field[n][m] = ch;
			m++;
		}
		else if (ch == '\n')
		{
			if (m > m_tmp)
			{
				m_tmp = m;
			}
			n++;
			m = 0;
		}
		else
		{
			field[n][m] = ch;
			m++;
		}
	}
	m = m_tmp;
}

void Paint()
{
	for (int8_t i = 0; i < MAXARRAY; i++)
	{
		for (int8_t j = 0; j < MAXARRAY; j++)
		{
			if (field[i][j] == 'o')
			{
				PaintTillFance(i, j);
			}
		}
	}
}

void Print(ofstream& fileOut)
{
	for (int8_t i = 0; i < MAXARRAY; i++)
	{
		for (int8_t j = 0; j < MAXARRAY; j++)
		{
			fileOut << field[i][j];
			cout << field[i][j];
		}
		fileOut << endl;
		cout << endl;
	}
}

void Fill(ifstream &fileIn, ofstream &fileOut)
{
	initLabir();
	FillLabir(fileIn);
	Paint();
	Print(fileOut);
}

int main(int argc, char *argv[])
{
	if (argc != MAXARGUMENTS)
	{
		cout << "quantaty of arguments Should be 3" << endl;
		cout << "fill.exe input.txt output.txt" << endl;
		return 1;
	}
	ifstream fileIn;
	ofstream fileOut;

	fileIn.open(argv[1]);
	fileOut.open(argv[2]);

	if (!fileIn.is_open() || !fileOut.is_open())
	{
		cout << "file is not opened" << endl;
		cout << "please check for its existence" << endl;
		return 1;
	}

	Fill(fileIn, fileOut);

	return 0;
}
