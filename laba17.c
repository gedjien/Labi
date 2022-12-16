#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define N 50

void sort_buble(int*ptrarr, int n);
void sort_shake(int*ptrarr, int n);
void sort_select(int*ptrarr, int n);
void sort_insert(int*ptrarr, int n);
int* full_array(int*ptrarr, int n);
int put_array(int*ptrarr, int n);

void main()
{
	setlocale(LC_ALL, "RUS");

	int x[N];
	full_array(x, N);
	//put_array(x, N);
	puts("");

	// Задание 1.  Реализовать функции сортировки массива целых чисел по следующему алгоритму
	//sort_buble(x, N);
	//sort_shake(x, N);
	//sort_select(x, N);
	//sort_insert(x, N);


	//Задание 2.  Разработать программный комплекс для проведения вычислительных экспериментов по оценке эффективности алгоритмов
	clock_t fTimeStart, fTimeStop;
	fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;

	sort_insert(x, N);

	fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
	printf("\nVremya sortirovki %i(ms)\n", fTimeStop - fTimeStart);

	//put_array(x, N);

	//Задание 3.  Проведите вычислительный эксперимент по одному из вариантов:
	//1) сравнение простых сортировок(выбором, пузырьковая, коктельная, вставками) для различных размеров выборок  100, 1000, 10000 значений

	int x100[100];
	int x1000[1000];
	int x10000[10000];

	fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;
	full_array(x100, 100);
	sort_buble(x100, 100);
	fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
	printf("\nПузырьковая 100 знач %i(ms)", fTimeStop - fTimeStart);

	fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;
	full_array(x1000, 1000);
	sort_buble(x1000, 1000);
	fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
	printf("\nПузырьковая 1000 знач %i(ms)", fTimeStop - fTimeStart);

	fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;
	full_array(x10000, 10000);
	sort_buble(x10000, 10000);
	fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
	printf("\nПузырьковая 10000 знач %i(ms)\n", fTimeStop - fTimeStart);

	//

	fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;
	full_array(x100, 100);
	sort_shake(x100, 100);
	fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
	printf("\nШейкером 100 знач %i(ms)", fTimeStop - fTimeStart);

	fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;
	full_array(x1000, 1000);
	sort_shake(x1000, 1000);
	fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
	printf("\nШейкером 1000 знач %i(ms)", fTimeStop - fTimeStart);

	fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;
	full_array(x10000, 10000);
	sort_shake(x10000, 10000);
	fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
	printf("\nШейкером 10000 знач %i(ms)\n", fTimeStop - fTimeStart);

	//

	fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;
	full_array(x100, 100);
	sort_select(x100, 100);
	fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
	printf("\nВыбором 100 знач %i(ms)", fTimeStop - fTimeStart);

	fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;
	full_array(x1000, 1000);
	sort_select(x1000, 1000);
	fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
	printf("\nВыбором 1000 знач %i(ms)", fTimeStop - fTimeStart);

	fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;
	full_array(x10000, 10000);
	sort_select(x10000, 10000);
	fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
	printf("\nВыбором 10000 знач %i(ms)\n", fTimeStop - fTimeStart);

	//


	fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;
	full_array(x100, 100);
	sort_insert(x100, 100);
	fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
	printf("\nВставкой 100 знач %i(ms)", fTimeStop - fTimeStart);

	fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;
	full_array(x1000, 1000);
	sort_insert(x1000, 1000);
	fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
	printf("\nВставкой 1000 знач %i(ms)", fTimeStop - fTimeStart);

	fTimeStart = clock() * 1000 / CLOCKS_PER_SEC;
	full_array(x10000, 10000);
	sort_insert(x10000, 10000);
	fTimeStop = clock() * 1000 / CLOCKS_PER_SEC;
	printf("\nВставкой 10000 знач %i(ms)\n", fTimeStop - fTimeStart);




	getchar();	getchar();
	getchar();

}

void sort_buble(int*ptrarr, int n) {
	for (int j = 1; j < n; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (ptrarr[i] > ptrarr[i + 1]) {
				int temp_x = ptrarr[i];
				ptrarr[i] = ptrarr[i + 1];
				ptrarr[i + 1] = temp_x;
			}
		}
	}
}

void sort_shake(int*ptrarr, int n) {
	int left = 0, right = n - 1; // левая и правая границы сортируемой области массива
	int flag = 1;  // флаг наличия перемещений
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)  //двигаемся слева направо
		{
			if (ptrarr[i] > ptrarr[i + 1]) // если следующий элемент меньше текущего,
			{             // меняем их местами
				double t = ptrarr[i];
				ptrarr[i] = ptrarr[i + 1];
				ptrarr[i + 1] = t;
				flag = 1;      // перемещения в этом цикле были
			}
		}
		right--; // сдвигаем правую границу на предыдущий элемент

		for (int i = right; i > left; i--)  //двигаемся справа налево
		{
			if (ptrarr[i - 1] > ptrarr[i]) // если предыдущий элемент больше текущего,
			{            // меняем их местами
				double t = ptrarr[i];
				ptrarr[i] = ptrarr[i - 1];
				ptrarr[i - 1] = t;
				flag = 1;    // перемещения в этом цикле были
			}
		}
		left++; // сдвигаем левую границу на следующий элемент
	}
}

void sort_select(int*ptrarr, int n) {
	int min = 0; // для записи минимального значения
	int buf = 0; // для обмена значениями 

	/*********** Начало сортировки **************/
	for (int i = 0; i < n; i++)
	{
		min = i; // запомним номер текущей ячейки, как ячейки с минимальным значением
		// в цикле найдем реальный номер ячейки с минимальным значением
		for (int j = i + 1; j < n; j++)
			min = (ptrarr[j] < ptrarr[min]) ? j : min;
		// cделаем перестановку этого элемента, поменяв его местами с текущим
		if (i != min)
		{
			buf = ptrarr[i];
			ptrarr[i] = ptrarr[min];
			ptrarr[min] = buf;
		}
	}
}

void sort_insert(int*ptrarr, int n) {

	int temp, // временная переменная для хранения значения элемента сортируемого массива
		item; // индекс предыдущего элемента
	for (int counter = 1; counter < n; counter++)
	{
		temp = ptrarr[counter]; // инициализируем временную переменную текущим значением элемента массива
		item = counter - 1; // запоминаем индекс предыдущего элемента массива
		while (item >= 0 && ptrarr[item] > temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
		{
			ptrarr[item + 1] = ptrarr[item]; // перестановка элементов массива
			ptrarr[item] = temp;
			item--;
		}
	}
}

int* full_array(int*ptrarr, int n) {
	for (int q = 0; q < n; q++) {
		ptrarr[q] = n-q;
	}
}

int put_array(int*ptrarr, int n) {
	for (int q = 0; q < n; q++) {
		printf("%i ", ptrarr[q]);
	}
}
