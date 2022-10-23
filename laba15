#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <stdbool.h>
#include <stdlib.h>


#include <ctype.h>

#define ROW 3
#define COL 5

void zadan1() {
	//Задание 1.  Создать и заполнить статический двухмерный массив, размерность которого задается пользователем
/*int *msv, size1 = 5, size2 = 3;

printf("Введите размер массива (строк)> ");
scanf("%d", &size1);
printf("Введите размер массива (столбцов)> ");
scanf("%d", &size2);


msv = (int*)malloc((size1 * size2) * sizeof(int));


for (int q = 0; q < (size1 * size2); q++) {
	msv[q] = q+1;
}

int c = 0;
for (int q = 0; q < (size1 * size2); q++){
	int s = 0;
	int strk = 0;
	int stlb = q;
	while (strk < size2) {
		printf("msv[%i][%i] = %i ", q, strk, msv[stlb+c]);
		stlb++;
		strk++;
	}	printf("\n");
	if (msv[stlb + c] == msv[size1*size2]) break;
	s++;
	c+= size2-1;
}*/


int a[50][50]; int i, j, n, m; printf("Введите количество строк: ");
scanf("%d", &n);
printf("Введите количество столбцов: ");
scanf("%d", &m);
if (!(n < 50) || !(m < 50)) return;

//1. Составьте программу, которая создает двумерный массив, каждый элемент которого определяется по заданному принципу:
//1) сумма индексов элемента;

for(i=0; i<n; i++)
	for(j=0; j<m; j++)
		a[i][j] = i+j;

//2. Вывести на экран результат в виде таблицы, столбцы и строки которой обозначены соответствующими индексами массива.

for(int i=0; i<n; i++) // цикл по строкам
{ for(int j=0; j<m; j++) // цикл по столбцам
	{ printf("a[%d][%d] = %d ", i,j,a[i][j]); //
} printf("\n"); }

//3. Отдельно вывести на печать элемент, расположенный:
//1) в правом верхнем углу массива.

printf("элемент, расположенный в правом верхнем углу массива [0][%i] == %d \n",m-1, a[0][m-1]);

//4. Найти элемент массива:
//а) минимальный в заданной строке;

int stroka = 0;
printf("строка ");
scanf("%d", &stroka);

int minstr = a[stroka][0];
for (int i = 0; i < m; i++)
{
	if (a[stroka][i] < minstr)
		minstr = a[stroka][i];
}

printf("минимальный элемент массива в строке %i\n", minstr);
}

void zadan2(){	//Задание 2. Составьте программу, которая формирует двумерный массив целых чисел от -10 до 10 (размерностью 7 на 7) 
	//и транспонирует его (заменяет строки на столбцы).

	//2.1 Организуйте вывод на экран исходного и транспонированного массива.
	srand(time(0));

	int A_nt[7][7];

	for (int q = 0; q < 6; q++) {
		for (int i = 0; i < 6; i++) {
			A_nt[q][i] = (rand() % 10 - 10);
		}
	}

	printf("исходный массив \n");
	for (int q = 0; q < 6; q++) {
		for (int i = 0; i < 6; i++) {
			printf("A[%i][%i] = %i ", q, i, A_nt[q][i]);
		}puts("");
	}


	puts("\n");
	int A_t[7][7];

	printf("транспонированный массив \n");

	for (int q = 0; q < 6; q++) {
		for (int i = 0; i < 6; i++) {
			A_t[q][i] = A_nt[i][q];
		}
	}

	for (int q = 0; q < 6; q++) {
		for (int i = 0; i < 6; i++) {
			printf("A[%i][%i] = %i ", q, i, A_t[q][i]);
		}puts("");
	}	puts("\n");


	//2.2. Вычислите:
	//1. сумму элементов второго столбца массива, больших 10;

	int sumStlb2 = 0;

	for (int q = 0; q < 6; q++) {
		printf("A[%i][%i] = %i \n", q, 1, A_t[q][1]);
		sumStlb2 += A_t[q][1];
	}puts("");
	printf("Сумма элементов второго столбца %i\n", sumStlb2);

	//2.3. Найдите число пар одинаковых соседних элементов. В качестве соседних рассматривать:
	//только элементы, расположенные в одной строке;

	int kolvo_odinakovih = 0;

	int stroka = 0;
	printf("строка ");
	scanf("%d", &stroka);

	for (int i = 0; i < 5; i++)
	{
		if (A_t[stroka][i] == A_t[stroka][i + 1])
			kolvo_odinakovih++;
	}

	printf("odinakh %i\n", kolvo_odinakovih);

	//2.4 Определите координаты максимального элемента. Если элементов с максимальным значением в столбце несколько, 
	//то должны быть найдены координаты самого нижнего из них.

	int maxel = A_t[0][0];

	int x = 0, y = 0;
	for (int q = 0; q < 6; q++)
		for (int i = 0; i < 6; i++)
		{
			if (A_t[q][i] >= maxel) {
				maxel = A_t[q][i]; x = q; y = i;
			}
		}

	printf("maxel[%i][%i] = %i", x, y, maxel);
}

void zadan3() {

	/*10. В двумерном массиве хранится информация о количестве
учеников в каждом классе каждой параллели школы с первой по
одиннадцатую (в первом столбце — информация о классах первой
параллели, во втором — второй параллели и т. д.). В каждой параллели
школы учатся 5 классов. Составить программу для расчета общего числа
учеников в любой параллели.*/

	int cl[11][5];
	for (int q = 0; q < 11; q++) {
		for (int i = 0; i < 5; i++) {
			cl[q][i] = (rand() % 30 + 10);
		}
	}

	for (int q = 0; q < 11; q++) {
		int obsh = 0;
		for (int i = 0; i < 5; i++) {
			printf("Класс %i, %i параллель = %i \n", q + 1, i + 1, cl[q][i]);
			obsh += cl[q][i];
		}printf("Общее число учеников в %i параллели = %i\n\n", q + 1, obsh);
	}
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	zadan1();
}





	
