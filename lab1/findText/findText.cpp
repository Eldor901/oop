
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool OpenFile(ifstream& fileIn)
{
	if (!fileIn.is_open())
	{
		cout << "file is not opened" << endl;;
		cout << "please check for its existence" << endl;
		return false;
	}
	return true;
}

void FindText(ifstream& fileIn, string& searchText)
{
	string line;
	int num;
	int counter = 0;
	while (!fileIn.eof())
	{
		counter = counter + 1;
		getline(fileIn, line);
		if ((num = line.find(searchText, 0)) != string::npos)
		{
			cout << counter << endl;
		}
	}
}


int main(int argc, char *argv[])
{
	ifstream fileIn;
	string searchText;


	fileIn.open(argv[1]);
	searchText = argv[2];

	if (!OpenFile(fileIn))
	{
		return 1;
	}
	FindText(fileIn, searchText);
	return 0;
}
