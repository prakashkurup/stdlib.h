/*
 * =====================================================================================
 *
 *       Filename:  atoi.c
 *
 *    Description:  atoi implementation.
 *
 *        Version:  1.0
 *        Created:  11/24/2016 12:38:28 AM
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

/* Function to implement atoi */
int Atoi(const char *str)
{
	int res = 0;
	int sign = 1;
	bool negative = false;

	/* Check for negative sign */
	char *ptr = (char *)str;
	while (*ptr) {
		if (*ptr == '-') {
			/* Check for a number after negative sign */
			ptr++;
			if (*ptr >= '0' && *ptr <= '9') {
				sign = -1;
				negative = true;
				break;
			} else {
				break;
			}
		}
		ptr++;
	}

	while (*str) {
		/* If character is a number between 0 to 9 */
		if (*str >= '0' && *str <= '9') {
			/* Stores the result as integer */
			res = (res * 10) + (*str - '0');
			str++;

		/* If there are spaces, move on to the next */	
		} else if (*str == ' ') {
			str++;

		/* If negative sign occurred */
		} else if (*str == '-') {
			/* check if negative value */
			if (negative)
				str++;
			else
				return res; // return 0

		} else {
			return res * sign; 
		}
	}

	return res * sign;
}

int main(void)
{
	char *str1 = "12345";
	char *str2 = "      12345 number";
	char *str3 = "number 12345";
	char *str4 = "-12345";
	char *str5 = "      -12345 number";
	char *str6 = "  -  12345";

	printf("Actual atoi results: \n");

	int res1 = atoi(str1);
	int res2 = atoi(str2);
	int res3 = atoi(str3);
	int res4 = atoi(str4);
	int res5 = atoi(str5);
	int res6 = atoi(str6);

	printf("%d\n%d\n%d\n%d\n%d\n%d\n", res1, res2, res3, res4, res5, res6);

	printf("\nMy atoi implementation results: \n");

	res1 = Atoi(str1);
	res2 = Atoi(str2);
	res3 = Atoi(str3);
	res4 = Atoi(str4);
	res5 = Atoi(str5);
	res6 = Atoi(str6);

	printf("%d\n%d\n%d\n%d\n%d\n%d\n", res1, res2, res3, res4, res5, res6);
	
	return 0;
}
