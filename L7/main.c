#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define N 9

int matrix[N*N] =
{
	0,1,1,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,1,
	1,0,0,1,0,0,0,0,0,
	1,0,0,0,0,1,0,0,0,
	0,0,0,1,0,0,0,1,0,
	0,0,0,0,1,0,0,1,0,
	0,0,0,0,0,1,0,0,0,
	0,0,0,0,0,0,1,0,0,
	0,0,0,0,0,1,0,0,0
};

int NUM = 1;

typedef struct Node
{
	int data;
	struct Node* prev;
	struct Node* next;
} Node;

typedef struct Queue
{
	int size;
	Node* head;
	Node* tail;
}Queue;

Queue* ConstructQ()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->next = tmp->prev = NULL;
	q->size = 0;
	q->head = q->tail = tmp;
	return q;
}

void Enqueue(Queue* q, int value)
{
	q->head->data = value;
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->next = NULL;
	tmp->prev = q->head;
	q->head->next = tmp;
	q->head = tmp;
	q->size++;
}

int Dequeue(Queue* q)
{
	int value;
	value = q->tail->data;
	q->tail = q->tail->next;
	q->size--;
	return value;
}

void RecW(Queue* q,int* matr, int* nodes, int* steps, int start)
{
	nodes[start] = NUM;
	steps[NUM] = start;
	for (int i = 0;i < N;i++)
	{
		if (matr[9*start + i] == 1 && nodes[i] == 0)
		{
			nodes[i] = -1;
			Enqueue(q, i);
		}
	}
	while (q->size != 0)
	{
		++NUM;
		RecW(q,matr,nodes,steps,Dequeue(q));
	}
}

void RecH(Queue* q, int* matr, int* nodes, int* steps, int start)
{
	nodes[start] = NUM;
	steps[NUM] = start;
	for (int i = 0;i < N;i++)
	{
		if (matr[9 * start + i] == 1 && nodes[i] == 0)
		{
			++NUM;
			RecH(q, matr, nodes, steps, i);
		}
	}
}

int main() 
{
	Queue* q = ConstructQ();
	int nodesW[N] = { 0,0,0,0,0,0,0,0,0 };
	int stepsW[N+1] = { 0,0,0,0,0,0,0,0,0,0 };
	
	RecW(q, matrix, nodesW, stepsW, 4);

	for (int i = 1;i <= N;i++) printf("step %d: %d\n",i,stepsW[i]);
	printf("\n");
	NUM = 1;

	int nodesH[N] = { 0,0,0,0,0,0,0,0,0 };
	int stepsH[N + 1] = { 0,0,0,0,0,0,0,0,0,0 };

	RecH(q, matrix, nodesH, stepsH, 4);

	for (int i = 1;i <= N;i++) printf("step %d: %d\n", i, stepsH[i]);

	return 0;
}