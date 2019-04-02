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
	bool found = false;
	while (!fileIn.eof())
	{
		getline(fileIn, line);
		counter = counter + 1;
		if ((num = line.find(searchText, 0)) != string::npos)
		{
			cout << counter << endl;
			found = true;
		}
	}

	if (found == false)
	{
		cout << "Text not found" << endl;
	}
}


int main(int argc, char *argv[])
{
	ifstream fileIn;
	string searchText;


	fileIn.open(argv[1]);
	searchText = argv[2];

	if (argc != 3)
	{
		cout << "Please check your amount of arguments" << endl;
		cout << "findtext.exe filename.txt texttosearch" << endl;
		return 1;
	}

	if (!OpenFile(fileIn))
	{
		return 1;
	}

	FindText(fileIn, searchText);
	return 0;
}
