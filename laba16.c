#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <stdbool.h>
#include <stdlib.h>


int* insert(int* ptr_arr, int *size, int index, int num) {
	/*
	   ptr_arr - адрес массива
	   size - число элементов
	   k : индекс элемента
	   num - вставляемое значение
	   */
	ptr_arr[index] = num;

	return ptr_arr;
}

int delete_k(double* ptr_arr, int size, int k) {

	/* ptr_arr - адрес массива

	size - число элементов

	k - индекс удаляемого элемента */

	int n = size - 1;

	for (int i = k; i < (size - 1); i++) ptr_arr[i] = ptr_arr[i + 1];

	return n;//возвращает число элементов массива

}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Задание 1.  Напишите программу, которая работает с динамическим массивом

	srand((unsigned int)time(NULL));

	float * ptr_array;

	int size = 5;

	ptr_array = (int*)malloc(size * sizeof(int));

	if (ptr_array == NULL) {
		puts("error");
		return -1;
	}

	for (int q = 0; q < size; q++) {
		ptr_array[q] = (-100 + rand() % (100 + 100)) + ((200 / ((float)rand(1, 4)) * size));
	}
//
//
//
	//округлить в большую сторону все элементы массива;

	float * ptr_array2 = ptr_array2 = (int*)malloc(size * sizeof(int));

	for (int q = 0; q < size; q++) {
		ptr_array2[q] = round(ptr_array[q]);
	}

	printf("  Первый | Второй массив\n");
	for (int q = 0; q < size; q++) {
		printf("%+.4f | ", ptr_array[q]);
		printf("%+.1f \n", ptr_array2[q]);
	}

	free(ptr_array);
	free(ptr_array2);

	//Задание 2. Перепишите программу так, чтобы массив хранил значения типа double, заполните его случайными числами от -1 до 1.

	double * ptr_array3 = (int*)malloc(size * sizeof(int));

	for (int q = 0; q < size; q++) {
		ptr_array3[q] = (-1 + rand() % (1 + 1)) + ((200 / ((float)rand(1, 4)) * size));
	}

	for (int q = 0; q < size; q++) {
		printf("%+.4lf \n", ptr_array3[q]);
	}

	//2.1 Выполните удаление заданного элемента массива (по варианту), и напечатайте изменненный массив с помощью функций работы 14.
	//1. Удаление элемента с заданным номером.
	printf("\n");
	delete_k(ptr_array3, size, 1);

	for (int q = 0; q < size - 1; q++) {
		printf("%+.4lf \n", ptr_array3[q]);
	}

	//2.2 Выполните вставку -999 после заданного элемента массива (по варианту), и напечатайте изменненный массив
	//1. Вставка в случайную позицию.*/
	printf("\n");

	int* ptr_array4 = (int*)malloc(size * sizeof(int));
	for (int w = 0; w < size; w++) {
		ptr_array4[w] = w;
	}
	for (int w = 0; w < size; w++) {
		printf("%i \n", ptr_array4[w]);
	}printf("\n");

	int a = (0 + rand() % (0 - 5));
	printf("rand %i\n\n", a);

	insert(ptr_array4, size, a, -999);

	for (int w = 0; w < size; w++) {
		printf("%i \n", ptr_array4[w]);
	}

	free(ptr_array3);
	free(ptr_array4);

  	/*Массив d0, d1, d2, ..., dh, приняв в качестве первых его элементов все
	положительные элементы массива а0, а1, а2, ..., an с сохранением порядка их
		следования, а в качестве остальных элементов все отрицательные элементы
		b0, b1, b2 ..., bm в обратном порядке.*/
	printf("\n");

	int* msv_a = (int*)malloc(size * sizeof(int));
	int* msv_b = (int*)malloc(size * sizeof(int));
	for (int w = 0; w < size; w++) {
		msv_a[w] = w;
		printf("a[%i] %i \n", w, msv_a[w]);
	}printf("\n");
	for (int w = 0; w < size; w++) {
		msv_b[w] = w;
		printf("b[%i] %i \n", w, msv_b[w]);
	}printf("\n");

	int* d = (int*)malloc((size * 2) * sizeof(int));

	for (int w = 0; w < size; w++) {
		d[w] = msv_a[w];
	}

	for (int w = size - 1; w >= 0; w--) {
		d[size + w] = msv_b[size - w - 1];
	}
	for (int w = 0; w < size * 2; w++) {
		msv_b[w] = w;
		printf("d[%i] %i \n", w, d[w]);
	}
  
	system("pause");
  return 0;
}
