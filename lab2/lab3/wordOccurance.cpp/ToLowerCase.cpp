#include "pch.h"
#include "ToLowerCase.h"


string ToLowerCase(string word)
{
	for (int i = 0; i < word.length(); i++)
	{
		word[i] = tolower(word[i]);
	}

	return word;
}
