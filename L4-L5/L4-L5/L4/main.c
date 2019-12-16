#include "main.h"
#include <stdio.h>

#define N 8
#define M 8

//Lesson 4 Horse
#pragma region Horse
int steps = 0;
int board[N][M];
void InitBoards();
void ShowBoard();
void ShowBoard2();


//From Weblesson - 3242065 iterations to solution

int steps1[][2] = {
{-2, 1},//               8       1
{-1, 2},//            7             2                     
{1, 2},//                    X
{2, 1},//             6             3
{2, -1}, //              5       4
{1, -2},
{-1, -2},
{-2, -1}
};

//MyVersion 1 - impossible
int steps2[][2] = {
		{2, 1},//                4       3
		{2, -1},//            8             6
		{-2, 1},//                   X
		{-2, -1},//           7             5
		{1, 2},//                2       1   
		{-1, 2},
		{1, -2},
		{-1, -2}
};

//MyVersion 2 - 251825408 iterations to solution
int steps3[][2] = {
		{-2, -1},//              1       8
		{-1, -2},//           2             7
		{1, -2},//                   X
		{2, -1},//            3             6
		{2, 1},//                4       5   
		{1, 2},
		{-1, 2},
		{-2, 1}
};

//Myversion3 - Version from Web has been mixed (first half of array was replaced to the end) - 27241113 iterations
int steps4[][2] = {
		{2, -1},
		{1, -2},
		{-1, -2},
		{-2, -1},
		{-2, 1},
		{-1, 2},
		{1, 2},
		{2, 1}
};

#pragma region FromWebLesson
//int ispossible(int row, int col)
//{
//	if ((row >= 0) && (col >= 0) && (row < N) && (col < M) && (board[row][col] == 0)) return 1;
//	else return 0;
//}
#pragma endregion

int Horse(int row, int col, int count)
{
	int nextrow;
	int nextcol;

#pragma region MyVersion
	if ((row < 0) | (col < 0) | (row >= N) | (col >= M)) return 0;
	if (board[row][col] > 0) return 0;
#pragma endregion

	board[row][col] = count;
	steps++;

	if (count == 64)
		return 1;

	//for (int i = 0;i < 8;i++)
	//	{
	//		nextrow = row + steps1[i][0];
	//		nextcol = col + steps1[i][1];
	//		//if (ispossible(nextrow, nextcol) && Horse(nextrow, nextcol, count + 1))
	//		if (Horse(nextrow, nextcol, count + 1))
	//			{
	//				return 1;
	//			}
	//	}

#pragma region Garbage - My version, which I manually try to use with incorrect array of steps (now here are correct ones)

	if (Horse(row - 2, col + 1, count + 1))
	{
		return 1;
	}
	if (Horse(row - 1, col + 2, count + 1))
	{
		return 1;
	}
	if (Horse(row + 1, col + 2, count + 1))
	{
		return 1;
	}
	if (Horse(row + 2, col + 1, count + 1))
	{
		return 1;
	}
	if (Horse(row + 2, col - 1, count + 1))
	{
		return 1;
	}
	if (Horse(row + 1, col - 2, count + 1))
	{
		return 1;
	}
	if (Horse(row - 1, col - 2, count + 1))
	{
		return 1;
	}
	if (Horse(row - 2, col - 1, count + 1))
	{
		return 1;
	}
#pragma endregion

	board[row][col] = 0;
	return 0;
}
#pragma endregion

//Lesson 4 King

#pragma region King
int map[N][M];
int board2[N][M];

int King(int row, int col)
{
	if ((row == 0) || (col == 0)) return 1;
	else if (map[row][col] == 0) return King(row - 1, col) + King(row, col - 1);
	else return 0;
}
#pragma endregion

void InitBoards()
{
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			board[i][j] = 0;
			map[i][j] = 0;
			board2[i][j] = 0;
		}
	}

	map[1][2] = -1;
	map[5][3] = -1;
	map[0][5] = -1;
	map[5][5] = -1;
	map[5][6] = -1;
	map[4][5] = -1;
	map[3][5] = -1;
	map[2][5] = -1;
}

void ShowBoard()
{
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			printf("%.2d ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void ShowBoard2()
{
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			printf("%.3d ", board2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//Lesson 5 
#pragma region BinToStack
#define T int
#define MaxK 1000

T Stack[MaxK];
int K = -1;

void Push(T obj)
{
	if (K < MaxK)
	{
		Stack[++K] = obj;
	}
	else printf("Stack overflow");
}

T Pop()
{
	if (K != -1)
	{
		return Stack[K--];
	}
	else printf("Stack is empty");
}

void ToBin(int num)
{
	if (num == 0) return;
	Push((num % 2) ? 1 : 0);
	ToBin(num / 2);
}

#pragma endregion

//task 3
#pragma region DinamicStack
//#include <malloc.h>
//#define T int
//
//struct TNode
//{
//	T value;
//	struct TNode* next;
//};
//typedef struct TNode Node;
//
//struct StackD
//{
//	Node* head;
//	int size;
//	int maxSize;
//};
//
//struct StackD StackD;
//
//void PushD(T value)
//{
//	if (StackD.size >= StackD.maxSize) {
//		printf("Error stack size");
//		return;
//	}
//	Node* tmp = (Node*)malloc(sizeof(Node));
//	tmp->value = value;
//	tmp->next = StackD.head;
//	StackD.head = tmp;
//	StackD.size++;
//}
//
//T PopD() {
//	if (StackD.size == 0)
//	{
//		printf("Stack is empty");
//		return;
//	}
//	Node* next = NULL;
//	T value;
//	value = StackD.head->value;
//	next = StackD.head;
//	StackD.head = StackD.head->next;
//	free(next);
//	StackD.size--;
//	return value;
//}  
#pragma endregion


int main()
{
	//lesson 4
	InitBoards();
	//task horse
	ShowBoard(board);
	Horse(0,0,1);
	ShowBoard(board);
	printf("Iterations to solution: %d\n\n King task:\n\n", steps);

	//task king
	ShowBoard2();
	for (int i = 0;i < N;i++) 
	{
		for (int j = 0; j < M; j++)
		{
			board2[i][j] = King(i, j);
		}
	}
	ShowBoard2();

	//lesson5
	//task1
	int num = 14;
	ToBin(num);
	printf("%d to bin = ", num);
	while (K >= 0) printf("%d", Pop());
	printf("\n");

	return 0;
}

