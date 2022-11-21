#include <locale.h>
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>


int find_maxrange(int stat, int range[], int msv_rng)
{
	int max_dl = stat;
	for (int x = 0; x < msv_rng; x++) {
		if (range[x] > max_dl) max_dl = range[x];
	};

	return max_dl;
}

int find_stlb_dln(int x1, int x2) {
	int dlina = 0;
	while (x1 > 0) {
		x1 /= 10;
		dlina += 1;
	}
	while (x2 > 0) {
		x2 /= 10;
		dlina += 1;
	}
	//if (dlina /= 10 !=);
	return dlina;
}

void probeli(int range, int max_dl) {
	for (int x = 0; x <= max_dl - range; x++)
		printf(" ");
}

void main()
{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

	//setlocale(LC_ALL, "RUS");

		int m[5][5] = {
		{0, 4, 7, 4, 3},	//igrok 5 nabral ochkov protiv 1 2 3 4
		{11, 0, 11, 11, 11}, //igrok 2 nabral ochkov protiv 1 3 4 5
		{7, 5, 0, 11, 13}, //igrok 1 nabral ochkov protiv 2 3 4 5 
		{7, 5, 13, 0, 11}, //igrok 3 nabral ochkov protiv 1 2 4 5
		{2, 9, 11, 6, 0} //igrok 4 nabral ochkov protiv 1 2 3 5
		};

	int pobed[5];

	for (int x = 0; x < 5; x++) {
		pobed[x] = 0;
		for (int s = 0; s < 5; s++) {
			if (m[x][s] > m[s][x]) { pobed[x] += 1; }
		}
		//printf("pobed %i ", pobed[x]);
	}

	int mesto[5];

	int pobed_copy[5];
	for (int x = 0; x < 5; x++) {
		pobed_copy[x] = pobed[x];
	}

	for (int x = 0; x < 5; x++) {
		mesto[x] = 0;
		for (int s = 0; s < 5; s++) {
			if (pobed[x] > pobed[s]) { mesto[x] += 1; }
		}
		mesto[x] = 5 - mesto[x];
		//printf("mesto %i ", mesto[x]);
	}
	/*for (int x = 0; x <= 4; x++) {
		for (int q = 0; q <= 4; q++) {
			if (q == x) { m[x][q] = 0; continue; }
			m[x][q] = x + q;
		}
	}*/

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

	char sp[5][25] = { "Nikita\0", "Alex\0", "Grisha\0", "Evgeny\0", "Dm9try\0"};

	//char spis[25] = "testtestetset";
	int range[5] = {0, 0, 0, 0, 0};
	for (int q = 0; q < 5; q++) {
		for (int x = 0; x < 100; x++) {
			if (sp[q][x] == '\0') { break; }
			range[q]++; //printf("%i", range);
		}
	};

	/*for (int x = 0; x < 5; x++) {
		printf("%s = %i symb\n", sp[x], range[x]);
	}
	printf("spis = %s[%zu]\n", spis, sizeof(spis));

	printf("%s %s %s\n", sp[1], sp[2], sp[3]);*/

	int max_range = find_maxrange(10, range, sizeof(range) / sizeof(int));

	int s = 4;
	
	/*for (int x = 0; x < 5; x++) {
		printf("%i ", range[x]);
	}
	printf("\n");*/

	int stlb_rng[5];
	int stlb_str_rng[5][5];
	for (int x = 0; x < 5; x++) {
		int stlbb[5];
		for (int q = 0; q < 5; q++) {
			stlb_str_rng[x][q] = find_stlb_dln(m[x][q], m[q][x]);
		}
		//printf("\n");

	}

	/*for (int x = 0; x < 5; x++) {
		int stlbb[5];
		for (int q = 0; q < 5; q++) {

			printf("%i ", stlb_str_rng[x][q]);
		}
		printf("\n");
	}
	*/
	int max_chs = 0;

	int range_copy[5];
	for (int x = 0; x < 5; x++) {
		range_copy[x] = range[x];
	}

	printf("Участники"); probeli(8, find_maxrange(10, range, sizeof(range) / sizeof(int))); printf("|"); //выравнивание 1 столбца
	for (int q = 0, scht = 0; q <= 4; q++) {
		

		for (int s = 0; s < 5; s++)
		{
			max_chs = max(stlb_str_rng[q][s], max_chs);

		}
	//	printf("%i", range[q]);
		if (max_chs == range[q]) {
			printf(" %s ", sp[q]); //probeli(15, max_range); 
			range[q] += 1;
		}
		else {
			printf(" %s", sp[q]); //probeli(15, max_range); 
		}

		printf(" |");//столбцы с игроками

	}printf(" Побед |"); printf(" Место |"); printf("\n"); //шапка
	for (int x = 0; x <= 4; x++) { //уникальные строки
		printf("%s", sp[x]); 

		probeli(range_copy[x], find_maxrange(10, range_copy, sizeof(range_copy) / sizeof(int))); printf(" |");//имя участника

		//счёт
		for (int q = 0; q <= 4; q++) {
			if (x == q) { 
				probeli(0, range[x]+1); //printf("%i", range[x]); 
				printf("|"); continue; }

			//printf("%i", range[q] - (stlb_str_rng[x][q] + 1));
		/*	if ((range[q] - (stlb_str_rng[x][q] + 1)) >= 2){
				probeli((stlb_str_rng[x][q] + 3)/2, (range[q]/2));
				printf(" %i:%i ", m[x][q], m[q][x]);
				probeli((stlb_str_rng[x][q] + 3)/2, (range[q]/2));

			}
			else {
				printf(" %i:%i ", m[x][q], m[q][x]);
				probeli(stlb_str_rng[x][q] + 2, range[q]);
			}*/

			printf(" %i:%i ", m[x][q], m[q][x]);
			probeli(stlb_str_rng[x][q] + 2, range[q]);


			printf("|");
		}

		printf("   %i   |   %i   |\n", pobed[x], mesto[x]);
	}
	//printf("\n %i", find_maxrange(10, range, sizeof(range) / sizeof(int)));

	/*while (1) {

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
					printf("   %i:%i   |", m[x][q], m[4 - x][4 - q]);
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

	}*/
}
