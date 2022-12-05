#include <locale.h>
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>

void clrscr()
{
	system("@cls||clear");
}

void main() {

	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	setlocale(LC_ALL, "RUS");

	int i = 0, r = 0;

	FILE *file;
	file = fopen("fscanf.txt", "r"); //открытие файла
	fscanf(file, "%i", &r);

	struct player {
		char name[20];
		unsigned qty[20]; //максимум 20 игроков
	};
	struct player igrok[20];
	
	//чтение списка данных из файла
	while (fscanf(file, "%s", igrok[i].name) != EOF) {
		for (int x = 0; x < r; x++) { fscanf(file, "%u", &(igrok[i].qty[x])); }
		i++;
	}
	fclose(file); //закрытие файла


	//счёт количества побед
	int *pobed = (int*)malloc(i * sizeof(int));
	for (int q = 0; q < i; q++)  // цикл по строкам
	{
		int sm_pobed = 0;
		for (int x = 0; x < i; x++)  // цикл по столбцам
		{
			if (igrok[q].qty[x] > igrok[x].qty[q]) sm_pobed += 1;
		}
		pobed[q] = sm_pobed;
	}


	//вычисление занятого места
	int *mesto = (int*)malloc(i * sizeof(int));
	for (int x = 0; x < i; x++) {
		mesto[x] = 0;
		for (int s = 0; s < i; s++) {
			if (pobed[x] > pobed[s]) { mesto[x] += 1; }
		}
		mesto[x] = i - mesto[x];
	}


	int sortirovka = 0; //переменная для вывода по умолчанию
	int last_choose = 1; //переменная последнего выбранного пункта

	while (1) {
		printf("Пункты меню \n1. Вывод таблицы \n2. Вывод списка \n3. Способ вывода (обычный/в обратном порядке)\n4. Выход\n");

		int menu = 0;
		printf("Выбор пункта: ");
		scanf("%i", &menu);
		if (menu == 1 | menu == 2) { last_choose = menu; }
		switch (menu) {
		case 1:
			//
		case1:
			clrscr();
			if (sortirovka == 0) {
				printf("Вывести таблицу (Вывод обычный)\n");
				printf("Номер | Имя участника |");

				for (int q = 0; q < i; q++) {
					printf(" %3i%2s |", q + 1, "");
				}
				printf(" Побед |"); printf(" Место |"); printf("\n"); //шапка


				for (int x = 0; x < i; x++) { //уникальные строки
					printf("%5i | %13s |", x + 1, igrok[x].name);

					//счёт
					for (int q = 0; q < i; q++) {
						//в случае, если столбец игрока пересекается с своей же строкой
						if (igrok[x].qty[q] == 0 & igrok[q].qty[x] == 0) { printf("       |"); continue; }
						printf(" %2i:%-2i |", igrok[x].qty[q], igrok[q].qty[x]);
					}

					printf("   %i   |   %i   |\n", pobed[x], mesto[x]);
				}
			}
			//
			//
			//
			else {
				printf("Вывести таблицу (Вывод в обратном порядке)\n");
				printf("Номер | Имя участника |");

				for (int q = i - 1; q >= 0; q--) {
					printf(" %3i%2s |", q + 1, "");
				}
				printf(" Побед |"); printf(" Место |"); printf("\n"); //шапка


				for (int x = i - 1; x >= 0; x--) { //уникальные строки
					printf("%5i | %13s |", x + 1, igrok[x].name);

					//счёт
					for (int q = i - 1; q >= 0; q--) {
						//в случае, если столбец игрока пересекается с своей же строкой
						if (igrok[x].qty[q] == 0 & igrok[q].qty[x] == 0) { printf("       |"); continue; }
						printf(" %2i:%-2i |", igrok[x].qty[q], igrok[q].qty[x]);
					}

					printf("   %i   |   %i   |\n", pobed[x], mesto[x]);
				}
			}
			break;
		case 2:
		case2:
			clrscr();

			int *sumpobed = (int*)malloc(i * sizeof(int));
			int *sumporaj = (int*)malloc(i * sizeof(int));

			for (int q = 0; q < i; q++) {
				sumpobed[q] = 0;
				sumporaj[q] = 0;
				for (int x = 0; x < i; x++) {
					sumpobed[q] += igrok[q].qty[x];
					sumporaj[q] += igrok[x].qty[q];
				}
			}

			if (sortirovka == 0) {
				printf("Вывести список (Вывод обычный)\n"); //общее количество очков, поражения

				printf("Имя участника ");

				printf("| И | В | П | %9s%6s ", "+/-", ""); //выравнивание 1 столбца
				printf("| Место |"); printf("\n"); //шапка
				for (int x = 0; x < i; x++) { //уникальные строки
					printf("%13s |", igrok[x].name);
					//счёт
					printf(" %i | %i | %i |", i - 1, pobed[x], i - pobed[x] - 1); // И | В | П
					printf(" %+2i - -%2i = %-3i ", sumpobed[x], sumporaj[x], sumpobed[x] - sumporaj[x]); // +/- |

					printf("|   %1i   |\n", mesto[x]);
				}
			}

			//
			//
			else {
				printf("Вывести список (Вывод в обратном порядке)\n"); //общее количество очков, поражения

				printf("Имя участника ");

				printf("| И | В | П | %9s%6s ", "+/-", ""); //выравнивание 1 столбца
				printf("| Место |"); printf("\n"); //шапка
				for (int x = i-1; x >= 0; x--) { //уникальные строки
					printf("%13s |", igrok[x].name);
					//счёт
					printf(" %i | %i | %i |", i - 1, pobed[x], i - pobed[x] - 1); // И | В | П
					printf(" %+2i - -%2i = %-3i ", sumpobed[x], sumporaj[x], sumpobed[x] - sumporaj[x]); // +/- |

					printf("|   %1i   |\n", mesto[x]);
				}
			}
			//
			//

			break;
		case 3:
			if (sortirovka == 0) { sortirovka = 1; printf("Вывод в обратном порядке\n"); }
			else { sortirovka = 0; printf("Вывод обычный\n"); }

			if (last_choose == 1) { goto case1; }
			else { goto case2; }
			break;
		case 4:
			clrscr();
			printf("Выход\n");
			exit(EXIT_SUCCESS);
		default:
			clrscr();
			printf("Неправильный ввод\n");
		}
	}


	free(pobed);
	free(mesto);
}
