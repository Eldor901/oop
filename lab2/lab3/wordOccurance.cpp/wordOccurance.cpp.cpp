
#include "pch.h"
#include "ToLowerCase.h"


void main()
{
	string word;

	WordOccurance occured;

	while (cin >> word)
	{
		if (word == ".")
		{
			break;
		}
		word = ToLowerCase(word);
		occured[word]++;
	}


	for (auto & Info : occured)
	{
		cout << Info.first << ": " << Info.second << endl;
	}

}
