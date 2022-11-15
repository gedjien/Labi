#include <locale.h>
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

void main()
{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);

	setlocale(LC_ALL, "RUS");

	int m[5][5];

	for (int x = 0; x <= 4; x++) {
		for (int q = 0; q <= 4; q++) {
			if (q == x) { m[x][q] = 0; continue;}
			m[x][q] = x+q;
		}
	}

	printf("Пункты меню \n1. Вывод таблицы \n2. Функция 2 \n3. Функция 3\n4. Функция 4\n");


	/*
	printf("Участники |"); for (int q = 0; q <= 4; q++) {
		printf(" Игрок %i |", q + 1);
	}printf(" Побед |"); printf(" Место |"); printf("\n");
	for (int x = 0; x <= 4; x++) {
		printf("Игрок %i   |", x + 1);
		for (int q = 0; q <= 4; q++) {
			printf(" %i       |", m[x][q]);
		}
		printf("   %i   |   %i   |\n", 5-x, x+1);
	}

	*/

	while (1) {

	int menu = 0;
	printf("Выбор пункта: ");
	scanf("%i", &menu);

		switch (menu) {
		case 1:
			printf("Участники |"); for (int q = 0; q <= 4; q++) {
				printf(" Игрок %i |", q + 1);
			}printf(" Побед |"); printf(" Место |"); printf("\n");
			for (int x = 0; x <= 4; x++) {
				printf("Игрок %i   |", x + 1);
				for (int q = 0; q <= 4; q++) {
					printf("   %i:%i   |", m[x][q], m[4-x][4-q]);
				}
				printf("   %i   |   %i   |\n", 4 - x, x + 1);
			}			
			break;
		case 2:
			printf("Функция 2\n");
			break;
		case 3:
			printf("Функция 3\n");
			break;
		case 4:
			printf("Функция 3\n");
			break;
		default:
			printf("Неправильный ввод\n");
		}
//ранжирование поиск по баллам

	}
}
