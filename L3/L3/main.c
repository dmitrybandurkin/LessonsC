#include "main.h"
#include <stdio.h>

#define SIZE 10 //have a problem with "const int N" to use in in array - see below
#define SIZE2 15

void ShowArray(int* a, int N);

void BubbleSort(int *a, int N)
{
	int count = 0;
	int countMainCycle = 0;
	int countNestCycle = 0;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N-1;j++)
		{
			count++;
			countNestCycle++;
			if (a[j] > a[j + 1])
			{
				count++;
				a[j] = a[j] ^ a[j + 1];
				count++;
				a[j + 1] = a[j] ^ a[j + 1];
				count++;
				a[j] = a[j] ^ a[j + 1];
			}
		}
		countMainCycle++;
	}
	printf("Bubble action count = %d\n", count);
	printf("Bubble Main cycle iteration count = %d\n", countMainCycle);
	printf("Bubble nested cycles iteration count = %d\n", countNestCycle);
	ShowArray(a, N);
}

void BubbleSortUpgrade(int* a, int N)
{
	int count = 0;
	int countMainCycle = 0;
	int countNestCycle = 0;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N - 1 - i;j++) //no need to check already checked last numbers;
		{
			count++;
			countNestCycle++;
			if (a[j] > a[j + 1])
			{
				count++;
				a[j] = a[j] ^ a[j + 1];
				count++;
				a[j + 1] = a[j] ^ a[j + 1];
				count++;
				a[j] = a[j] ^ a[j + 1];
			}
		}
		countMainCycle++;
	}
	printf("BubbleUpgrade action count = %d\n", count);
	printf("BubbleUpgrade Main cycle iteration count = %d\n", countMainCycle);
	printf("BubbleUpgrade nested cycles iteration count = %d\n", countNestCycle);
	ShowArray(a, N);
}

void SheikerSort(int* a, int N)
{
	int count = 0;
	int countMainCycle = 0;
	int countNestCycle = 0;
	for (int i = 0;i < N;i++)
	{
		for (int j = i;j < N - i - 1;j++)
		{
			count++;
			countNestCycle++;
			if (a[j] > a[j + 1])
			{
				count++;
				a[j] = a[j] ^ a[j + 1];
				count++;
				a[j + 1] = a[j] ^ a[j + 1];
				count++;
				a[j] = a[j] ^ a[j + 1];
			}
		}

		for (int j = N - i - 2;j >= i;j--)
		{
			count++;
			countNestCycle++;
			if (a[j] < a[j - 1])
			{
				count++;
				a[j] = a[j] ^ a[j - 1];
				count++;
				a[j - 1] = a[j] ^ a[j - 1];
				count++;
				a[j] = a[j] ^ a[j - 1];
			}
		}
		countMainCycle++;
	}
	printf("Sheiker count = %d\n", count);
	printf("Bubble Main cycle iteration count = %d\n", countMainCycle);
	printf("Bubble nested cycles iteration count = %d\n", countNestCycle);
	ShowArray(a, N);
}

void RecursiveSearch(int *a, int N, int num)
{
	if (N<0) printf("nothing to search\n");
	else if (a[N - 1] == num)
	{
		printf("in array:\n");
		ShowArray(a,10);
		printf("Index of %d = %d\n", num, N - 1);
	}		
	else RecursiveSearch(a, N - 1, num);

}

void PPG(int *a, int N)
{
	ShowArray(a,N);
	int temp[SIZE];
	for (int i = 0;i < SIZE;i++) temp[i] = 0;

	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < SIZE;j++)
		{
			if (a[i] == j) temp[j]++;
		}
	}

	int k = 0;

	for (int i = 0;i < SIZE;i++)
	{
		for (int j = 0;j < temp[i];j++) 
		{
			a[k] = i;
			k++;
		}
	}
	ShowArray(a, SIZE2);
}

void ShowArray(int* a, int N)
{
	for (int i = 0;i < N;i++)
	{
		printf("%d, ", a[i]);
	}
	printf("\n");
}

int main() //sorry, i'm flooded too much, so have no time for refactoring. I think, that i've got the main idea
{	
	//task 1
	int initarray1[SIZE] = { 15,51,32,24,78,66,94,0,46,83 };

	//for some reason can't use next code:
	// const int N = 10;
	// int initarray[N]; - Compiler writes, that N must be a constant; 

	printf("Initial array (it's always the same array in the next tasks):\n"); 
	ShowArray(initarray1, SIZE);
	printf("\n");
	BubbleSort(initarray1, SIZE);
	printf("\n");

	//task 2
	int initarray2[] = { 15,51,32,24,78,66,94,0,46,83 };
	BubbleSortUpgrade(initarray2, SIZE);
	printf("\n");

	//task 3
	int initarray3[] = { 15,51,32,24,78,66,94,0,46,83 };
	SheikerSort(initarray3, SIZE);
	printf("\n");

	//task 4
	RecursiveSearch(initarray3, SIZE, 46);
	printf("\n");

	//task 5
	int initarray4[SIZE2] = { 1,2,3,2,1,2,3,2,1,2,1,2,3,0,4 };
	PPG(initarray4,SIZE2);

	return 0;
}