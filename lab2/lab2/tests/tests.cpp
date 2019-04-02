// tests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp" 
#include "../HtmlDecode/FuncToHtmlDecode.h"

TEST_CASE("Testing function HtmlSearchEntity")
{
	WHEN("Nothing to Search")
	{
		CHECK(HtmlSearchEntity("", "SomeText", 'G') == "");
	}

	WHEN("String is not empty but nothing to replace")
	{

		CHECK(HtmlSearchEntity("Eldor", "", 'E') == "Eldor");
	}

	WHEN("String is not empty and we have text to search and replace")
	{

		CHECK(HtmlSearchEntity("Eldor", "El", 'Be') == "BeDor");
	}

}


TEST_CASE("Testing Funtionc Decode")
{
	WHEN("When all elemnts of decoding")
	{
		CHECK(HtmlDecode("Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s") == "Cat <says> ""Meow"". M&M’s ");
	}

	WHEN("Some Elemtns of Decoding")
	{
		CHECK(HtmlDecode("Cat &lt;says&gt;") == "Cat <says>");
	}

	WHEN("Thereis no Elements of decoding")
	{
		CHECK(HtmlDecode("Hello world") == "Hello world");
	}

}
