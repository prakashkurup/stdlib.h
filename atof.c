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

float Atof(const char *str)
{
	float res = 0;
	int decimalCnt = 0;
	bool decimalPt = false;
	int sign = 1;
	bool negative = false;  

	/* Check for negative value */
	char *ptr = (char *)str;
	while (*ptr) {
		if (*ptr == '-') {
			/* Check for number value in the next character */
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
		/* Check for decimal point */
		if (*str == '.') {
			decimalPt = true;
			str++;
		}
		
		/* Check for number value */
		if (*str >= '0' && *str <= '9') {
			/* Start counter if decimal point is true */
			if (decimalPt == true) {
				decimalCnt++; 
			}
			res = (res * 10) + (*str - '0');
			str++;

		/* If spaces, move on to the next character */	
		} else if (*str == ' ') {
			str++;

		/* If negative sign */
		} else if (*str == '-') {
			if (negative)
				str++;
			else
				return res; // return 0

		} else {
			return res * sign;
		}
	}
	
	/* Divide result by 10 based on counter */
	if (decimalPt == true) {
		int i;
		for (i = 0; i < decimalCnt; i++) {
			res = res / 10;
		}
	}

	return res * sign;
}

int main(void)
{
	char *str1 = "123.45";
	char *str2 = "      123.45";
	char *str3 = "decimal 123.45";
	char *str4 = "-123.45";
	char *str5 = "       -123.45";
	char *str6 = "   -    123.45";

	printf("Actual atof results: \n");

	float res1 = atof(str1);
	float res2 = atof(str2);
	float res3 = atof(str3);
	float res4 = atof(str4);
	float res5 = atof(str5);
	float res6 = atof(str6);

	printf("%f\n%f\n%f\n%f\n%f\n%f\n", res1, res2, res3, res4, res5, res6);

	printf("\nMy atof implementation results: \n");
	
	res1 = Atof(str1);
	res2 = Atof(str2);
	res3 = Atof(str3);
	res4 = Atof(str4);
	res5 = Atof(str5);
	res6 = Atof(str6);
	
	printf("%f\n%f\n%f\n%f\n%f\n%f\n", res1, res2, res3, res4, res5, res6);

	return 0;
}
