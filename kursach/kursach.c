#include <locale.h>
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>

int clrscr();



void main() {

	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	setlocale(LC_ALL, "RUS");

	int i = 0, r = 0;

	FILE *file;
	file = fopen("fscanf.txt", "r"); //открытие файла
	while (!feof(file)) {
		if (fgetc(file) == '\n')
			r++;
	}

	printf("%i", r);

	fseek(file, 0, SEEK_SET);

	char **name = (char**)calloc(r, sizeof(char*));// указатель на массив имён

	for (int q = 0; q < r; q++) {
		name[q] = (char*)calloc(70, sizeof(char)); //двумерный массив имён
		strcpy(name[q], "undefined"); //заполнение значениями
	}

	int *a = (int*)malloc(pow(r, 2) * sizeof(int));// указатель на массив значений
	int *b = (int*)malloc(pow(r, 2) * sizeof(int));// указатель на транспонированный массив значений

	//определение динамического массива данными из файла

	//чтение/заполнение значений
	while (fscanf(file, "%s", name[i]) != EOF) { //чтение имён
		for (int x = 0; x < r; x++) { fscanf(file, "%u", &(*(a + i * r + x))); } //чтение чисел
		i++;
	}

	// Транспонируем значения во массив
	for (int q = 0; q < r; q++) {
		for (int j = 0; j < r; j++) {
			*(b + j * r + q) = *(a + q * r + j);
		}
	}

	fclose(file); //закрытие файла


	//счёт количества побед
	int *pobed = (int*)malloc(i * sizeof(int));
	for (int q = 0; q < i; q++)  // цикл по строкам
	{
		int sm_pobed = 0;
		for (int x = 0; x < i; x++)  // цикл по столбцам
		{
			if (*(a + q * r + x) > *(b + q * r + x)) sm_pobed += 1;
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

	//поиск макс/мин/сред знач
	int *maxkolvo = (int*)malloc(i * sizeof(int));
	for (int q = 0; q < i; q++)  // цикл по строкам
	{
		int max_ochkov = 0;
		for (int x = 0; x < i; x++)  // цикл по столбцам
		{
			if (max_ochkov < *(a + q * r + x)) max_ochkov = *(a + q * r + x);
		}
		maxkolvo[q] = max_ochkov;
	}

	int *minkolvo = (int*)malloc(i * sizeof(int));
	for (int q = 0; q < i; q++)  // цикл по строкам
	{
		minkolvo[q] = maxkolvo[q];
		for (int x = 0; x < i; x++)  // цикл по столбцам
		{
			if (*(a + q * r + x) == 0) { continue; }
			if (*(a + q * r + x) < maxkolvo[q])
				minkolvo[q] = *(a + q * r + x);
		}
	}

	int *sredkolvo = (int*)malloc(i * sizeof(int));
	for (int q = 0; q < i; q++)  // цикл по строкам
	{
		int sred_ochkov = 0;
		for (int x = 0; x < i; x++)  // цикл по столбцам
		{
			sred_ochkov += *(a + q * r + x);
		}
		sredkolvo[q] = sred_ochkov / (i-1);
	}
	

	int sortirovka = 0; //переменная для вывода по умолчанию
	int last_choose = 1; //переменная последнего выбранного пункта

	while (1) {
		printf("Пункты меню \n1. Вывод исходной таблицы \n2. Вывод результирующей таблицы \n3. Способ вывода (обычный/в обратном порядке)\n4. Выход\n");

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
				printf("Вывести исходную таблицу (Вывод обычный)\n");
				printf("Номер | Имя участника |");

				for (int q = 0; q < i; q++) {
					printf(" %3i%2s |", q + 1, "");
				}
				printf("\n"); //шапка


				for (int x = 0; x < i; x++) { //уникальные строки
					printf("%5i | %13s |", x + 1, name[x]);

					//счёт
					for (int q = 0; q < i; q++) {
						//в случае, если столбец игрока пересекается с своей же строкой
						if (*(a + x* r + q) == 0 & *(b + x * r + q) == 0) { printf("       |"); continue; }
						printf(" %2i:%-2i |", *(a + x * r + q), *(b + x * r + q));
					}

					printf("\n");
				}
			}
			//
			//
			//
			else {
				printf("Вывести исходную таблицу (Вывод в обратном порядке)\n");
				printf("Номер | Имя участника |");

				for (int q = i - 1; q >= 0; q--) {
					printf(" %3i%2s |", q + 1, "");
				}
				printf("\n"); //шапка

				for (int x = i - 1; x >= 0; x--) { //уникальные строки
					printf("%5i | %13s |", x + 1, name[x]);

					//счёт
					for (int q = i - 1; q >= 0; q--) {
						//в случае, если столбец игрока пересекается с своей же строкой
						if (*(a + x * r + q) == 0 & *(b + x * r + q) == 0) { printf("       |"); continue; }
						printf(" %2i:%-2i |", *(a + x * r + q), *(b + x * r + q));
					}

					printf("\n");
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
					sumpobed[q] += *(a + q * r + x);
					sumporaj[q] += *(b + q * r + x);
				}
			}

			if (sortirovka == 0) {
				printf("Вывести результирующую таблицу (Вывод обычный)\n"); //общее количество очков, поражения

				printf("Имя участника ");
				// игр | выиграно | проиграно | КОЭФФИЦИНЕНТ РАСЧЕТА СУММЫ ОЧКОВ ( ОТНОШЕНИЕ ВЫИГРЫШ/ПРОИГРЫШ )
				// ОБЩ, СРЕД, МИН, МАКС КОЛИЧЕСТВО ОЧКОВ
				printf("| И | В | П | %9s | %9s ", "Отношение выигрыш/проигыш", "Общ/Сред/Мин/Макс количество очков"); //выравнивание 1 столбца
				printf("| Место |"); printf("\n"); //шапка
				for (int x = 0; x < i; x++) { //уникальные строки
					printf("%13s |", name[x]);
					//счёт
					printf(" %i | %i | %i |", i - 1, pobed[x], i - pobed[x] - 1); // И | В | П
					printf(" %+11i / -%-10i |", sumpobed[x], sumporaj[x]); // +/- |

					printf(" %3i/%4i/%3i/%3i %18s", sumpobed[x] - sumporaj[x], sredkolvo[x], minkolvo[x], maxkolvo[x], ""); // +/- |

					printf("|   %1i   |\n", mesto[x]);
				}
			}

			//
			//
			else {
				printf("Вывести результирующую таблицу (Вывод в обратном порядке)\n"); //общее количество очков, поражения


				printf("Имя участника ");
				// игр | выиграно | проиграно | КОЭФФИЦИНЕНТ РАСЧЕТА СУММЫ ОЧКОВ ( ОТНОШЕНИЕ ВЫИГРЫШ/ПРОИГРЫШ )
				// ОБЩ, СРЕД, МИН, МАКС КОЛИЧЕСТВО ОЧКОВ
				printf("| И | В | П | %9s | %9s ", "Отношение выигрыш/проигыш", "Общ/Сред/Мин/Макс количество очков"); //выравнивание 1 столбца
				printf("| Место |"); printf("\n"); //шапка
				for (int x = i - 1; x >= 0; x--) { //уникальные строки
					printf("%13s |", name[x]);
					//счёт
					printf(" %i | %i | %i |", i - 1, pobed[x], i - pobed[x] - 1); // И | В | П
					printf(" %+11i / -%-10i |", sumpobed[x], sumporaj[x]); // +/- |

					printf(" %3i/%4i/%3i/%3i %18s", sumpobed[x] - sumporaj[x], sredkolvo[x], minkolvo[x], maxkolvo[x], ""); // +/- |

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


		// освобождение памяти
	for (int i = 0; i < 4; i++) 
	{
		free(name[i]);
	}
	free(name);
	free(pobed);
	free(mesto);
	free(minkolvo);
	free(maxkolvo);
	free(sredkolvo);
}

int clrscr()
{
	system("@cls||clear");
	return 1;
}

// ПОИСК ПО КРИТЕРИЮ 
// СОЗДАТЬ СПИСОК ИЛИ ПОДМАССИВ, УДОВЛЕТВОРЯЮЩИЙ КРИТЕРИЯМ ПОЛЬЗОВАТЕЛЯ
// ЗАПОЛНЕНИЕ НОВЫМИ ЗНАЧЕНИЯМИ

// ФУНКЦИИ ПЕРЕД MAIN
