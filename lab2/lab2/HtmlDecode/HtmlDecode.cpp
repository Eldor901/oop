#include "pch.h"
#include <iostream>
#include <string>
#include "FuncToHtmlDecode.h"

using namespace std;

int main()
{
	string htmlString;
	while (getline(cin, htmlString))
	{
		cout << HtmlDecode(htmlString) << endl;

		if (htmlString == "")
		{
			return 0;
		}
	}
}
