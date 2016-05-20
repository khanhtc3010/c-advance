/*
*	My framework for Alt plus coding contest
*	Author: Pham Duy Hung
*	Take your own risk when using this framework
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAXLENGTH 100
#define MAXSIZE 100 // Could be changed for the specific problem

#define FOR(i, n) for(i = 0; i < n; i++)
#define IFNULL(n) if((n) == NULL)

/*
*	My own string type
*	Author: Pham Duy Hung
*	Take your own risk when using this type
*
*/
typedef struct _String {
	char content[MAXLENGTH];
} String;

/*
*	Functions' prototypes for specific problem
*	Author: Pham Duy Hung
*	Take your own risk when using these functions
*
*/
int* getMultiInteger(int numberOfInt);
int solve(int *listInt, int length);
void displayArray(int *array, int length);
int myIntCompare(const void *a, const void *b);

/*
*	Utility functions' prototypes
*	Author: Pham Duy Hung
*	Take your own risk when using these functions
*
*/
int getInt();
float getFloat();
void getString(char *str);
int getIntBetween(int lower, int upper);
void* myMalloc(size_t size, size_t total);
int split(char *str, char splitChar, String *listString);

/*
*	Main function
*	Author: Pham Duy Hung
*	Take your own risk when using these functions
*
*/
int main() {
	int n;
	int *listInt = NULL;

	printf("Please enter the size of integer array:\n");
	n = getIntBetween(1, MAXSIZE);

	IFNULL(listInt = getMultiInteger(n)) {
		printf("NULL\n");
		return 1;
	}

	// displayArray(listInt, n); // for debugging

	printf("%d\n", solve(listInt, n));
	displayArray(listInt, n); // for debugging

	free(listInt);
    return 0;
}

/*
*	Functions for specific problem
*	Author: Pham Duy Hung
*	Take your own risk when using these functions
*
*/
int* getMultiInteger(int numberOfInt) {
	int *res = NULL;
	char str[MAXLENGTH];
	String output[MAXLENGTH];
	int i;

	IFNULL(res = (int*)myMalloc(sizeof(int), numberOfInt)) {
		return NULL;
	}

	printf("Please enter the input:\n");
	getString(str);

	if((split(str, ' ', output)) < numberOfInt) {
		return NULL;
	}

	FOR(i, numberOfInt) {
		res[i] = atoi(output[i].content);
	}

	return res;
}

int solve(int *listInt, int length) {
	// TODO: process to get the output
	qsort(listInt, length, sizeof(int), myIntCompare); // test

	return 0;
}

void displayArray(int *array, int length) {
	int i;

	FOR(i, length) {
		printf("Element #%d: %d\n", i + 1, array[i]);
	}
}

int myIntCompare(const void *a, const void *b) {
	int *x = (int*)a;
	int *y = (int*)b;

	return *x - *y;
}

/*
*	Utility functions
*	Author: Pham Duy Hung
*	Take your own risk when using these functions
*
*/
void* myMalloc(size_t size, size_t total) {
	char *result;

	IFNULL(result = (char*) malloc((total + 1) * size * sizeof(char))) {
		printf("Cannot allocate memory\n");
		return NULL;
	}

	return result;
}

int getInt() {
	int result;

	while(scanf("%d", &result) != 1) {
		printf("This is not an integer number. Please retype the input: ");
		while(getchar() != '\n');
	}

	while(getchar() != '\n');

	return result;
}

float getFloat() {
	float result;

	while(scanf("%f", &result) != 1) {
		printf("This is not a float number. Please retype the input: ");
		while(getchar() != '\n');
	}

	while(getchar() != '\n');

	return result;
}

void getString(char *str) {
	fgets(str, MAXLENGTH, stdin);
	str[strlen(str) - 1] = '\0';
}

int getIntBetween(int lower, int upper) {
	int res;

	do {
		res = getInt();
		if(res < lower || res > upper) {
		  printf("Invalid integer. Please enter another integer in range [%d, %d] again!\n", lower, upper);
		}
	} while(res < lower || res > upper);

	return res;
}

int split(char *str, char splitChar, String *listString) {
	int counter = 0;
	int i;
	char *ptr, *temp = NULL;

	IFNULL(str) {
		return -1;
	}

	IFNULL(temp = myMalloc(sizeof(String), 1)) {
		return -1;
	}

	strcpy(temp, str);
	ptr = temp;

	FOR(i, strlen(str) + 1) {
		if(temp[i] == splitChar || temp[i] == '\0') {
		  temp[i] = '\0';
		  strcpy(listString[counter++].content, ptr);
		  ptr = temp + i + 1;
		}
	}

	free(temp);

	return counter;
}