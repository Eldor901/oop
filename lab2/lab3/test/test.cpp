

#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "../wordOccurance.cpp/ToLowerCase.h"

TEST_CASE("TO LOWER CASE")
{
	WHEN("STRING IS UPPERCASE")
	{
		CHECK(ToLowerCase("ELDOR") == "eldor");
	}

	WHEN("STRING some letters is upper string")
	{
		CHECK(ToLowerCase("ELdOR") == "eldor");
	}
}
