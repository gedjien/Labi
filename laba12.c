#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <stdbool.h>
#include <stdlib.h>

void i_btprnt(int a) {
	puts("int");
	for(int i = 0; i<= (sizeof(a) - 1); i++) {
		printf("Byte %d: ", i+1);
		printf("%02x\n", *((char*)&a + i));
	} puts("");
}

void f_btprnt(float a) {
	puts("float");
	for (int i = 0; i <= (sizeof(a) - 1); i++) {
		printf("Byte %d: ", i + 1);
		printf("%02x\n", *((char*)&a + i));
	} puts("");
}

void d_btprnt(double a) {
	puts("double");
	for (int i = 0; i <= (sizeof(a) - 1); i++) {
		printf("Byte %d: ", i + 1);
		printf("%02x\n", *((char*)&a + i));
	} puts("");
}


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	//Задание 1.  Определите объем памяти, выделяемой под указатель на переменные типа char, int, double.
	puts("Задание 1");

	int *pi, i = 5;
	float *pf, f = 2.1f;

	double *pd, d = 2.1f;
	char *pc, c = 2.1f;

	printf("%lu\n", sizeof(pi));
	printf("%lu\n", sizeof(pf));
	printf("%lu\n", sizeof(pd));
	printf("%lu\n", sizeof(pc));

	//Задание 2. Проанализируйте приведенный ниже код. Объясните результат.
	puts("\nЗадание 2");

	float PI = 3.14159, *p1, *p2;
	p1 = p2 = &PI;
	printf("По адресу p1=%p хранится *p1=%g\n", p1, *p1);
	printf("По адресу p2=%p хранится *p2=%g\n", p2, *p2);

	//Задание 3.Выполните приведенный ниже код и определите, на сколько увеличится значение, на которое указывает ра. Полученные результаты поясните. 
	puts("\nЗадание 3");

	_Bool *pa, x = 5;
	pa = &x;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);
	pa++;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);
	pa--;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);

	//Задание 4. Исследуйте перемещение по массиву с помощью указателя. Объявите и инициализируйте массив на 10 элементов.
	puts("\nЗадание 4");

	float array[10] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1 };
	float *ptr_a = &array[0];

	printf("По адресу %p хранится *ptr_a %g, по адресу %p хранится array %g\n", &ptr_a, *ptr_a, &array[0], *&array[0]);
	ptr_a++;
	printf("По адресу %p хранится *ptr_a %g, по адресу %p хранится array %g\n", &ptr_a, *ptr_a, &array[1], *&array[1]);
	ptr_a += 4;
	printf("По адресу %p хранится *ptr_a %g, по адресу %p хранится array %g\n", &ptr_a, *ptr_a, &array[5], *&array[5]);
	ptr_a -= 2;
	printf("По адресу %p хранится *ptr_a %g, по адресу %p хранится array %g\n\n", &ptr_a, *ptr_a, &array[3], *&array[3]);

	//4.3 Напишите цикл прохода по массиву с помощью указателя с прямом порядке с увеличением указателя на 2 

	for (int q = 0; q <= 9; q += 2) {
		float *ptr_a = &array[0];
		ptr_a += q;
		printf("[%i](%i) По адресу %p хранится *ptr_a %g, по адресу %p хранится array %g\n", q, q+1, &ptr_a, *ptr_a, &array[q], *&array[q]);
	} puts("");

	//4.4 Выполните проход по массиву в обратном порядке, предварительно установив указатель на конец массива с использованием операции декремента

	for (int q = 9; q >= 0; q--) {
		float *ptr_a = &array[0];
		ptr_a += q;
		printf("[%i](%i) По адресу %p хранится *ptr_a %g, по адресу %p хранится array %g\n", q, q+1, &ptr_a, *ptr_a, &array[q], *&array[q]);
	} //puts("\n");

	//Задание 5. Запустите и исследуйте программу с использованием указателей
	puts("\nЗадание 5");

	//free(x);

	int s = 0x12345678;
	int *prt;
	unsigned char *a1, *a2, *a3, *a4;
	unsigned char *a;

	prt = &s;
	a = (unsigned char*)prt;
	
	a1 = a;
	a2 = a + 1;
	a3 = a + 2;
	a4 = a + 3;
	printf("%.2x %p \n%.2x %p \n%.2x %p \n%.2x %p \n\n", *a1, &a1, *a2, &a2, *a3, &a3, *a4, &a4); 
	// 1. Сделайте вывод о порядке размещения байтов в текущей системе. 
	// B)  с наибольшего адреса ("little-end" - прямое размещение байтов))

	// 2. Усовершенствуйте программу так, чтобы она могла побайтно выводить переменные любого типа.

	/*i_btprnt(0x12345678);
	i_btprnt(s);*/

	int	i5 = 12345.0;
	float f5 = 12345.0;
	double d5 = 12345.0;

	i_btprnt(i5); f_btprnt(f5); d_btprnt(d5);
}
