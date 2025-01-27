#include <inttypes.h>

#include "2021.h"
#include "solutions.h"

static solution_t solutions[] = {
	aoc2021_1_1,
	aoc2021_1_2,
	aoc2021_2_1,
	aoc2021_2_2,
	aoc2021_3_1,
	aoc2021_3_2,
	aoc2021_4_1,
	aoc2021_4_2,
	aoc2021_5_1,
	aoc2021_5_2,
	aoc2021_6_1,
	aoc2021_6_2,
	aoc2021_7_1,
	aoc2021_7_2,
	aoc2021_8_1,
	aoc2021_8_2,
	aoc2021_9_1,
	aoc2021_9_2,
};

void aoc_2021_run_solution(int day, int part, FILE *input)
{
	int index = (day - 1) * 2 + (part - 1);
	if (index >= (int)(sizeof(solutions) / sizeof(solution_t)))
		panicf("solution for day %d part %d not implemented!", day, part);

	int64_t result = solutions[index](input);
	printf("day %d part %d: solution is %" PRIi64 "\n", day, part, result);
}
