#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define T int
#define V char

// first task
#pragma region Task1

int HashF(char* str)
{
	int i = 0;
	int sum=0;
	while (str[i] != '\0') sum += str[i++];
	return sum;
}

#pragma endregion

// second task - with recursion (my own variant)
#pragma region task2

#pragma region MyVariant

int found = 1;

typedef struct Node
{
	T data;
	V name; // additional data for more interesting searching
	struct Node* left;
	struct Node* right;
} Node;

Node* PushNode(Node* tree, int value)
{
	Node* newNode;
	if (tree == NULL)
	{
		newNode = (Node*)malloc(sizeof(Node));
		tree = newNode;
		tree->data = value;
		tree->name = 'a'+value;
		tree->left = tree->right = NULL;
	}
	else
	{
		if (value < tree->data)
		{
			tree->left = PushNode(tree->left, value);
		}
		if (value > tree->data)
		{
			tree->right = PushNode(tree->right, value);
		}
	}
	return tree;
}

//printing the tree
void WriteTree(Node* tree) // Rt-L-R
{
	if (tree)
	{
		printf("%d{%c}", tree->data, tree->name);
		if (tree->left || tree->right)
		{
			printf("(");
			if (tree->left)
			{
				WriteTree(tree->left);
			}
			else
			{
				printf("NULL");
			}

			printf(",");

			if (tree->right)
			{
				WriteTree(tree->right);
			}
			else
			{
				printf("NULL");
			}

			printf(")");
		}
	}
}

//search in tree
char FindNode(Node* tree, int value) 
{
	if (tree != NULL)
	{
		if (value < tree->data) tree->left = FindNode(tree->left, value);
		else if (value > tree->data) tree->right = FindNode(tree->right, value);
		else if (value == tree->data) return tree->name;
	}
	else
	{
		found = 0;
		return;
	}
}

#pragma endregion

//From methodic book - realization with cycle

#pragma region BookVariant

typedef struct NodeB
{
	T data;
	struct NodeB* left;
	struct NodeB* right;
	struct NodeB* parent;
} NodeB;

NodeB* getFreeNode(T value, NodeB* parent)
{
	NodeB* tmp = (NodeB*)malloc(sizeof(NodeB));
	tmp->left = tmp->right = NULL;
	tmp->data = value;
	tmp->parent = parent;
	return tmp;
}

void Insert(NodeB** head, int value)
{
	NodeB* tmp = NULL;
	if (*head == NULL)
	{
		*head = getFreeNode(value, NULL);
		return;
	}

	tmp = *head;
	while (tmp)
	{
		if (value > tmp->data)
		{
			if (tmp->right)
			{
				tmp = tmp->right;
				continue;
			}
			else
			{
				tmp->right = getFreeNode(value, tmp);
				return;
			}
		}
		else if (value < tmp->data)
		{
			if (tmp->left)
			{
				tmp = tmp->left;
				continue;
				;
			}
			else
			{
				tmp->left = getFreeNode(value, tmp);
				return;
			}
		}
		else
		{
			exit(2);
		}
	}
}

void WriteTreeB(NodeB* tree) // Rt-L-R
{
	if (tree)
	{
		printf("%d", tree->data);
		if (tree->left || tree->right)
		{
			printf("(");
			if (tree->left)
			{
				WriteTreeB(tree->left);
			}
			else
			{
				printf("NULL");
			}

			printf(",");

			if (tree->right)
			{
				WriteTreeB(tree->right);
			}
			else
			{
				printf("NULL");
			}

			printf(")");
		}
	}
}



#pragma endregion

#pragma endregion


int main()
{

#pragma region Task1

	char MyString[100];
	scanf("%s", MyString);
	printf("%d",HashF(MyString));

	printf("\n\n");

#pragma endregion


#pragma region Task2
	Node* Mytree1 = NULL;
	NodeB* Mytree2 = NULL;

	//MyVariant
	Mytree1 = PushNode(Mytree1, 5);
	Mytree1 = PushNode(Mytree1, 1);
	Mytree1 = PushNode(Mytree1, 3);
	Mytree1 = PushNode(Mytree1, 4);
	Mytree1 = PushNode(Mytree1, 7);
	Mytree1 = PushNode(Mytree1, 6);
	Mytree1 = PushNode(Mytree1, 15);
	Mytree1 = PushNode(Mytree1, 12);
	Mytree1 = PushNode(Mytree1, 32);
	Mytree1 = PushNode(Mytree1, 9);
	Mytree1 = PushNode(Mytree1, 10);
	Mytree1 = PushNode(Mytree1, 61);

	//From book
	Insert(&Mytree2, 5);
	Insert(&Mytree2, 1);
	Insert(&Mytree2, 3);
	Insert(&Mytree2, 4);
	Insert(&Mytree2, 7);
	Insert(&Mytree2, 6);
	Insert(&Mytree2, 15);
	Insert(&Mytree2, 12);
	Insert(&Mytree2, 32);
	Insert(&Mytree2, 9);
	Insert(&Mytree2, 10);
	Insert(&Mytree2, 61);


	WriteTree(Mytree1);

	printf("\n\n");

	WriteTreeB(Mytree2);

	printf("\n\n");

	//searching the node and data in 

	int numNode = 61;
	char S = FindNode(Mytree1, numNode);

	if (found)	printf("In Node number %d - %c\n\n", numNode, S);
	else printf("There is number %d Node\n\n", numNode);

#pragma endregion

	return 0;
}
