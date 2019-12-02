#include "Main.h"
#include <stdio.h>
#include <math.h>
//
//Ввести вес и рост человека.Рассчитать и вывести индекс массы тела по формуле I = m / (h * h);
//где m - масса тела в килограммах, h - рост в метрах.
//

void Mass(float m, float h) 
{
	float I;
	printf("First task: m = %.2f, height = %.2f\n",m,h);
	I= (float)(m / (h * h));
	printf("I = %.2f\n\n", I);
}

//Написать программу обмена значениями двух целочисленных переменных :
//b. * без использования третьей переменной.
//

void Change(int a, int b)
{
	printf("Second task: before: a = %d, b = %d\n", a, b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("after: a = %d, b = %d\n\n", a, b);
}

//Написать программу нахождения корней заданного квадратного уравнения.
//
void Eq(float a, float b, float c)
{
	float D, x1, x2;

	printf("Third task: %.2fx2 %.2fx %.2f\n",a,b,c);

	D = b * b - 4 * a * c;
	if (D < 0) printf("0 roots\n\n");
	if (D == 0)
	{
		x1 = x2 = -b / (2 * a);
		printf("1 root: %.2f\n\n", x1);
	}
	if (D > 0)
	{
		x1 = (-b + sqrt(D)) / (a * 2);
		x2 = (-b - sqrt(D)) / (a * 2);
		printf("2 roots: root #1: %.2f, root #2: %.2f\n\n", x1 ,x2);
	}
}


//Ввести возраст человека(от 1 до 150 лет) и вывести его вместе с последующим
//словом «год», «года» или «лет».
//

void Age(int y) //хотелось бы узнать, про вывод кириллицы в консоль. Спасибо (боюсь, что в данный момент не найду времени разобраться)
{
	printf("Fourth task: y = %d\n", y);
	float a;
	a = y % 10;
	if (((y>9)&(y<21))|((y>109)&(y<121))) printf("%d let\n\n", y);
	else 
	{
		if (a == 1) printf("%d god\n\n", y);
		else if ((a > 1) & (a < 5)) printf("%d goda\n\n", y);
		else if ((a == 0) | (a > 4)) printf("%d let\n\n", y);
	}
}

//* Существуют числовые координаты двух полей шахматной доски(x1, y1, x2, y2).
//Требуется определить, относятся ли к поля к одному цвету или нет.
//

void Chess(int x1, int x2, int x3, int x4) 
{
	printf("Fifth task: x1 = %d, x2 = %d, x3 = %d, x4 = %d\n",x1,x2,x3,x4);
	if ((x1 + x2) % 2 == (x3 + x4) % 2) printf("one color\n\n");
	else printf("different colors\n\n");
}


//Автоморфные числа.Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата
//Например, 25 ^ 2 = 625. Напишите программу, которая вводит натуральное число N и выводит на экран все автоморфные числа, не превосходящие N.

void Automorf(int a)
{
	printf("Sixth task: a = %d\n", a);

	int x, y, z, i;

	for (int j = 0; j <= a; j++)
	{
		x = j;
		y = x * x;
		z = x;
		i = 0;
		
		do // не знаю как более правильно, 
		//в голову пришла идея сравнивать число и остаток от деления квадрата числа на более высокий порядок, чем число: 
		//число 15 - порядок - 10 (десятки) - больший порядок 100 - квадрат 225 -  225%100 = 25 <> 15 - не автоморфное
		{
			z /= 10;
			i++;
		} while (z > 0);

		i = pow(10, i);
		z = y % i;
		if (x == z) printf("%d: %d\n", x, y);
	}
}

void mean() //исправленный код
{
	int counter = 0;
	float sum = 0;
	int in;

	for(;;) //while(true) почему-то не работает
	{
		scanf_s("%d", &in);
		if (in == -1) break;
		sum += in;
		counter++;
	}

	//do {
	//	scanf("%d", &in);
	//	if(in == -1) break; //very bad code
	//	sum += in;
	//	counter++;
	//} while (in != -1);

	if (counter != 0) {
		printf("a = %.2f\n", (float)(sum / counter));
	}
	else {
		printf("No input");
	}
}

int main()
{
	Mass(67, 1.93);
	Change(12,17);
	Eq(12,7,1);
	Age(7);
	Age(21);
	Age(111);
	Chess(2, 3, 5, 7);
	Automorf(100000);
	mean();
	return 0;
}