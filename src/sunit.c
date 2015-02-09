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

#include "sunit.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

void sassert(int success, sunit_t test_case){
	if(!success){
		fprintf(test_case->error, "SASSERT ERROR %s, %d case", test_case->title,
				test_case->success_count + test_case->fail_count + 1);
		test_case->fail_count++;
	}else{
		test_case->success_count++;
	}
}

void sassert_equal(double a, double b, sunit_t test_case){
	/* So that the maxiumn relative error is bigger than 1e-8 */
	if(fabs(a-b)/fmin(a,b) > 1e-8){
		fprintf(test_case->error, "SASSERT ERROR %s, %d case", test_case->title,
				test_case->success_count + test_case->fail_count + 1);
		test_case->fail_count++;
	}else{
		test_case->success_count++;
	}
}

void sassert_not_equal(double a, double b, sunit_t test_case){
	if(fabs(a-b)/fmin(a,b) < 1e-8){
		fprintf(test_case->error, "SASSERT ERROR %s, %d case", test_case->title,
				test_case->success_count + test_case->fail_count + 1);
		test_case->fail_count++;
	}else{
		test_case->success_count++;
	}
}

void sassert_equal_f(float a, float b, sunit_t test_case){
	if(fabsf(a-b)/fminf(a,b) > 1e-4f){
		fprintf(test_case->error, "SASSERT ERROR %s, %d case", test_case->title,
				test_case->success_count + test_case->fail_count + 1);
		test_case->fail_count++;
	}else{
		test_case->success_count++;
	}
}

void sassert_not_equal_f(float a, float b, sunit_t test_case){
	if(fabsf(a-b)/fminf(a,b) < 1e-4f){
		fprintf(test_case->error, "SASSERT ERROR %s, %d case", test_case->title,
				test_case->success_count + test_case->fail_count + 1);
		test_case->fail_count++;
	}else{
		test_case->success_count++;
	}
}

void sinit_std(const char* title, sunit_t* test_case_ptr){
	*test_case_ptr = malloc(sizeof(struct sunit_raw_t));
	(*test_case_ptr)->title = calloc(strlen(title)+1, sizeof(char));
	(*test_case_ptr)->success_count = 0;
	(*test_case_ptr)->fail_count = 0;
	(*test_case_ptr)->output = stdout;
	(*test_case_ptr)->error = stderr;
}

void sinit(const char* title, sunit_t* test_case_ptr, FILE* output, FILE* error){
	*test_case_ptr = malloc(sizeof(struct sunit_raw_t));
	(*test_case_ptr)->title = calloc(strlen(title)+1, sizeof(char));
	(*test_case_ptr)->success_count = 0;
	(*test_case_ptr)->fail_count = 0;
	(*test_case_ptr)->output = output;
	(*test_case_ptr)->error = error;
}

void sfinal(sunit_t* test_case_ptr){
	fprintf( (*test_case_ptr)->output, "Testcase %s finished: ",
			 (*test_case_ptr)->title );
	fprintf( (*test_case_ptr)->output, "Success:%d ",
			 (*test_case_ptr)->success_count );
	fprintf( (*test_case_ptr)->output, "Fail:%d ",
			 (*test_case_ptr)->fail_count );
	fprintf( (*test_case_ptr)->output, "Total:%d\n",
			 (*test_case_ptr)->success_count + (*test_case_ptr)->fail_count );
	free( (*test_case_ptr)->title );
	free( (*test_case_ptr) );
}
