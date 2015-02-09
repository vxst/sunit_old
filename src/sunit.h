/*
 * Copyright (C) 2015  Shan Ting <vxst@vxst.org>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __VXST_SUNIT_H
#define __VXST_SUNIT_H
#include <stdio.h>

struct sunit_raw_t{
	char* title;
	int success_count, fail_count;
	FILE* output;
	FILE* error;
};

typedef struct sunit_raw_t* sunit_t;

/* Assert a condition */
void sassert(int success, sunit_t test_case);

/* Assert double equal(relative error: 1e-8) */
void sassert_equal(double a, double b, sunit_t test_case);

/* Assert double not equal */
void sassert_not_equal(double a, double b, sunit_t test_case);

/* Assert float equal(relative error: 1e-4) */
void sassert_equal_f(float a, float b, sunit_t test_case);

/* Assert float not equal */
void sassert_not_equal_f(float a, float b, sunit_t test_case);

/* Init a testcase: to stderr and stdout */
void sinit_std(const char* title, sunit_t* test_case_ptr);

/* Init a testcase */
void sinit(const char* title, sunit_t* test_case_ptr, FILE* output, FILE* error);

/* Print result and delete a testcase */
void sfinal(sunit_t* test_case_ptr);

#endif
