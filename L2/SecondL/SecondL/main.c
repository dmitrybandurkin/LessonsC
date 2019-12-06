#include "main.h"
#include <stdio.h>

//1 –еализовать функцию перевода из 10 системы в двоичную использу€ рекурсию.
void DecToBin()
{
	//всЄ, € сдалс€ и хочу спать. без строк, не могу ничего толком написать в этом задании
}

//2. –еализовать функцию возведени€ числа a в степень b :
int Pow(int a, int b, int depth)
{
	printf("depth: %d\n", depth);
	if (b == 0) return 1;
	if (b == 1) return a;
	return Pow(a, b - 1,depth+1) * a;
}

//*рекурсивно, использу€ свойство чЄтности степени.
int Superpow(int a, int b, int depth)
{
	printf("depth: %d\n", depth);
	if (b == 0) return 1;
	if (b == 1) return a;
	if (b % 2 == 0) return Superpow(a * a, b / 2,depth+1);
	return Superpow(a, b - 1,depth+1) * a;
}

// –ешить на листочке задачу ≈√Ё из урока с G(6) страница 7 ћетодички, на 8й странице решение, не подсматривайте, пожалуйста))

//int F(int n) {
//	if (n > 2)
//		return F(n - 1) + G(n - 2);
//	else
//		return n;
//}
//int G(int n) {
//	if (n > 2)
//		return G(n - 1) + F(n - 2);
//	else
//		return 3 - n;
//}
//
//G(6) =
//G(5) + F(4) =
//G(4) + F(3) + F(3) + G(2) =
//G(3) + F(2) + F(2) + G(1) + F(2) + G(1) + 1 =
//G(2) + F(1) + 2 + 2 + 2 + 2 + 2 + 1 = G(2) + F(1) + 11 =
//1 + 1 + 11 = 13;

void Multi(int n,int num, int *wpointer)
{
	if (n < num)
	{
		Multi(2 * n,num,wpointer);
		Multi(n + 1,num,wpointer);
	}
	if (n == num) (*wpointer)++;
}

int main()
{
	printf("pow: %d\n\n",Pow(2,17,1));
	printf("superpow: %d\n\n", Superpow(2, 17,1));
	int ways = 0;
	Multi(3, 20, &ways);
	printf("steps: %d\n\n", ways);
	return 0;
}