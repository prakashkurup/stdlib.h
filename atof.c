/*
 * =====================================================================================
 *
 *       Filename:  atof.c
 *
 *    Description:  atof implementation.
 *
 *        Version:  1.0
 *        Created:  11/24/2016 02:36:38 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Prakash Kurup (), prakashkurup7@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

double Atof(const char *str)
{
	double res = 0;
	int decimalCnt = 0;
	bool decimalPt = false;
	int sign = 1;
	int i = 0;

	/* If space occurs, move to the next character */
	while (str[i] == ' ') {
		i++;
	}

	/* Check for + and - sign */
	if (str[i] == '-' || str[i] == '+') {
		sign = 1 - 2 * (str[i] == '-');
		i++;
	}

	/* Storing result for number characters */
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') {
		/* Check for decimal point */
		if (str[i] == '.') {
			decimalPt = true;
			i++;
		}

		if (decimalPt)
			decimalCnt++;

		res = res * 10 + (str[i] - '0');
		i++;
	}

	/* Divide result by 10 based on counter */
	if (decimalPt) {
		for (i = 0; i < decimalCnt; i++) {
			res = res / 10;
		}
	}
	return res * sign; 
}

bool testCases(const char *str)
{
	if (atof(str) == Atof(str))
		return true;
	else 
		return false;
	
}

int main(void)
{
	const char *str[10] = {"123.45", "  123.45", "decimal 123.45", "123.45 decimal", "-123.45", "- 123.45", "+123.45", "+-123.45", "-+123.45", ".12"};

	int test_case = 0;
	int count = sizeof(str) / sizeof(str[0]);

	while (test_case < count) {
		printf("Running test case %d:'%s'\n", test_case, str[test_case]);
		testCases(str[test_case]) ? puts("PASSED!") : puts("FAILED :(");
		puts("\r");
		test_case++;
	}

	return 0;
}

