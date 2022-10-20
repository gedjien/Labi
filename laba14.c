#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <stdbool.h>
#include <stdlib.h>


#include <ctype.h>

double* full_elements(double *ptr_array, int n) //-заполнение массива случайными значениями
{
	for (int i = 0; i < n; i++)
	{
		ptr_array[i] = ((double)rand() / RAND_MAX) * (12 - 1) ;
	}
}

int put_elements(double *ptr_array, int n) //-печать элементов массива
{
	for (int i = 0; i < n; i++)
	{
		printf("a[%d] = %.3lf\n", i, ptr_array[i]);
	}
}


double* calc_elements(double *ptr_array, int n) { //-обработка элементов массива(см.инд.вариант  зад. 1.3 в работе 11)
//10. округлить в большую сторону все элементы массива;

	for (int i = 0; i < n; i++)
	{
		ptr_array[i] = round(ptr_array[i]);
	}

}

double sum_elements(double *ptr_array, int begin, int end) { //1. Добавьте функцию вычисления суммы элементов массива от индекса begin до индекса end включительно:
	
	double summa = 0;

	for (int i = begin; i < end+1; i++)
	{
		printf("a[%d] = %.3lf\n", i, ptr_array[i]);
		summa = summa + (double)ptr_array[i];	
	}

	return summa;
}

int find_element(double *ptr_array, int n, double element)//2. Добавьте функцию поиска элемента равного а:
{
	int isk = 0;

	for (int i = 0; i < n; i++)
	{
		printf("a[%d] = %.1lf\n", i, ptr_array[i]);

		if (ptr_array[i] == element) { 
			isk = i;
			break;
		}
	}

	return isk;
}

int max_ch_nch(double *ptr_array, int n) {
	double max_ch = 0;
	double max_nch = 0;

	for (int i = 0; i < n; i+=2)
	{
		printf("a[%d] = %.1lf\n", i, ptr_array[i]);

		if (ptr_array[i] > max_ch) {
			max_ch = ptr_array[i];
		}
	}

	printf("Максимальное четное %lf\n", max_ch); //max четное

	for (int i = 1; i < n; i += 2)
	{
		printf("a[%d] = %.1lf\n", i, ptr_array[i]);

		if (ptr_array[i] > max_nch) {
			max_nch = ptr_array[i];
		}
	}

	printf("Максимальное нечетное %lf\n", max_nch); //max нечетное

}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Задание 1.  Напишите программу работы с массивом, где все операции (создание, обработка, поиск, печать) вынесены в отдельные функции.

	double *a; int size;

	printf("Введите размер массива > ");
	scanf("%d", &size);

    a = (double*)malloc(size * sizeof(double));
	full_elements(a, size);
	put_elements(a, size);

	calc_elements(a, size);
	put_elements(a, size);


	//Задание 2. Разработайте дополнительные собственные функции обработки массива

		//1. Добавьте функцию вычисления суммы элементов массива от индекса begin до индекса end включительно:
	printf("суммы элементов массива от индекса begin до индекса end %.0lf\n", sum_elements(a, 1, 3));

		//2. Добавьте функцию поиска элемента равного а:
	printf("элемента равного а(6) = a[%i]\n", find_element(a, size, 6));


	//Задание 3. Реализуйте в виде отдельной функции <type> function (double *ptr_array, int n, ... ) один из следующих вариантов обработки созданного массива:

		//10. Определение максимального значения элемента находящегося на четных/нечетных позициях (параметр функции int type).

	max_ch_nch(a, size);
}



	
