#include <stdio.h>
#include <stdlib.h>

#include <2021/solutions.h>
#include <aoc/common.h>
#include <unity.h>

const char *INPUT = "0,9 -> 5,9\n"
					"8,0 -> 0,8\n"
					"9,4 -> 3,4\n"
					"2,2 -> 2,1\n"
					"7,0 -> 7,4\n"
					"6,4 -> 2,0\n"
					"0,9 -> 2,9\n"
					"3,4 -> 1,4\n"
					"0,0 -> 8,8\n"
					"5,5 -> 8,2";

FILE *input;

void setUp()
{
	input = fmemopen_str(INPUT, "r");
	if (!input)
	{
		perror("setUp");
		exit(1);
	}
}

void tearDown()
{
	fclose(input);
}

void test_part1()
{
	TEST_ASSERT_EQUAL_INT64(5, aoc2021_5_1(input));
}

void test_part2()
{
	TEST_ASSERT_EQUAL_INT64(12, aoc2021_5_2(input));
}

int main()
{
	UNITY_BEGIN();
	RUN_TEST(test_part1);
	RUN_TEST(test_part2);
	return UNITY_END();
}
