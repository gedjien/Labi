#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <stdbool.h>

#define ROW 9
#define COL 9


void zadanie1() {
	int row, col, count = 0;

	printf("\n");
	for (row = 1; row <= ROW; ++row) {
		for (col = 1; col <= COL; col++) {
			printf("%5d", col*row);
		}
		printf("\n");
	}

	printf("\n");
	for (row = 1; row <= ROW; ++row) {
		count = 0;
		for (col = 1; col <= COL; col++) {
			printf("%5d", col*row);
			count += 1;
			if (count == row) break;
		}
		printf("\n");
	}

}

void zadanie2() {

	int row, col, count = 0;
	printf("\n");
	for (row = 1; row <= 5; ++row) {
		count = 0;
		for (col = 1; col <= 5; col++) {
			((col % 2 != 0) && (col != row)) ? printf("%5d", row-1) : printf("%5d", row - col);
			if ((row - col) == 0) break;
		}
		printf("\n");
	}
}

void zadanie3() {
	while (1)

	{

		char a;

		// Решение домашней задачи

		printf("Продолжить ? (Да - y, нет - n)");

		if ((a = getchar()) == 'n') break;
		else{	float x = 2.06, y = 0;


		// esli x == 63 ili 64 to == 0
		long double sum1 = 1, sum2 = 1;

		for (int i = 1; i < 64; i += 2) {
			y = x - i;
			sum1 *= y;
			printf("x - %i | %.2f - %i = %f | %llf\n", i, x, i, y, sum1);
			y = 0;
		}
		for (int i = 2; i < 65; i += 2) {
			y = x - i;
			sum2 *= y;
			printf("x - %i | %.2f - %i = %f | %llf\n", i, x, i, y, sum2);
			y = 0;
		}
		printf("%llf\n", sum1 / sum2);
		}
	}
}

void zadanie4() {
	int r;
  scanf("%i", &r);
	printf("\n");
	for (int i = 1; i <= r; ++i) {
		for (int i = 1; i <= r; ++i) {
			printf("* ");
		}
		printf("\n");
	}

}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	zadanie4();


}
