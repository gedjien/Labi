#include <locale.h>
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>

int clrscr();
int poisk_pobed(int, int, int *, int *, int *);
int poisk_mesto(int, int, int *, int *, int *, int *);
int poisk_max_ball(int, int, int *, int *);
int poisk_sred_ball(int, int, int *, int *);
int poisk_min_ball(int, int, int *, int *, int *);
int transponir(int, int *, int*);
int ishod_tablica(int, int, int, int *, int *, int **);
int result_tablica(int, int, int, int *, int *, int **, int *, int *, int *, int *, int *);
int show_menu(int, int, int *, int *, int **);


void main() {

	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	setlocale(LC_ALL, "RUS");

	int i = 0, r = 0;

	FILE *file;

	char file_name[] = "fscanf.txt";
	puts("Введите название .txt файла (Без расширения): "); scanf("%s", &file_name); strcat(file_name, ".txt");
	file = fopen(file_name, "r"); //открытие файла с данными
	if (!file) { //проверка на существование файла
		puts("Файл не обнаружен.");
		system("pause");
		exit(EXIT_SUCCESS);
	}
	
	//определение количества строк в файле
	while (!feof(file)) { 
		if (fgetc(file) == '\n')
			r++;
	}


	fseek(file, 0, SEEK_SET); //возвращение в 0 строку файла

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

	fclose(file); //закрытие файла

	//транспонирование массива
	transponir(r, a, b);

	//вызов таблицы
	show_menu(i ,r, a, b, name);

	// освобождение памяти
	for (int i = 0; i < r; i++)
	{
		free(name[i]);
	}
	free(name);
	free(a);
	free(b);
}

int clrscr()
{
	system("@cls||clear");
	return 1;
}

int poisk_pobed(int i, int r, int *a, int *b, int *pobed) {
	for (int q = 0; q < i; q++)  // цикл по строкам
	{
		int sm_pobed = 0;
		for (int x = 0; x < i; x++)  // цикл по столбцам
		{
			if (*(a + q * r + x) > *(b + q * r + x)) sm_pobed += 1;
		}
		pobed[q] = sm_pobed;
	}
	return 1;
}

int poisk_mesto(int i, int r, int *a, int *b, int *mesto, int *pobed) {
	for (int x = 0; x < i; x++) {
		mesto[x] = 0;
		for (int s = 0; s < i; s++) {
			if (pobed[x] > pobed[s]) { mesto[x] += 1; }
		}
		mesto[x] = i - mesto[x];
	}
	return 1;
}

int poisk_max_ball(int i, int r, int *a, int *maxkolvo) {
	for (int q = 0; q < i; q++)  // цикл по строкам
	{
		int max_ochkov = 0;
		for (int x = 0; x < i; x++)  // цикл по столбцам
		{
			if (max_ochkov < *(a + q * r + x)) max_ochkov = *(a + q * r + x);
		}
		maxkolvo[q] = max_ochkov;
	}
	return 1;
}

int poisk_sred_ball(int i, int r, int *a, int *sredkolvo) {
	for (int q = 0; q < i; q++)  // цикл по строкам
	{
		int sred_ochkov = 0;
		for (int x = 0; x < i; x++)  // цикл по столбцам
		{
			sred_ochkov += *(a + q * r + x);
		}
		sredkolvo[q] = sred_ochkov / (i - 1);
	}
	return 1;
}

int poisk_min_ball(int i, int r, int *a, int *maxkolvo, int *minkolvo) {
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
	return 1;
}

int transponir(int r, int *a, int*b) {
	// Транспонируем значения во массив
	for (int q = 0; q < r; q++) {
		for (int j = 0; j < r; j++) {
			*(b + j * r + q) = *(a + q * r + j);
		}
	}
	return 1;
}

int ishod_tablica(int i, int r, int sortirovka, int *a, int *b, int **name) {
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
				if (*(a + x * r + q) == 0 & *(b + x * r + q) == 0) { printf("       |"); continue; }
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
	return 1;
}

int result_tablica(int i, int r, int sortirovka, int *a, int *b, int **name, int *pobed, int *mesto, int *sredkolvo, int *minkolvo, int *maxkolvo) {
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
	return 1;
}

int show_menu(int i, int r, int *a, int *b, int **name) {
	int *pobed = (int*)malloc(i * sizeof(int));
	int *mesto = (int*)malloc(i * sizeof(int));
	int *maxkolvo = (int*)malloc(i * sizeof(int));
	int *minkolvo = (int*)malloc(i * sizeof(int));
	int *sredkolvo = (int*)malloc(i * sizeof(int));

	//счёт количества побед
	poisk_pobed(i, r, a, b, pobed);

	//вычисление занятого места
	poisk_mesto(i, r, a, b, mesto, pobed);

	//поиск макс/мин/сред знач
	poisk_max_ball(i, r, a, maxkolvo);
	poisk_min_ball(i, r, a, maxkolvo, minkolvo);
	poisk_sred_ball(i, r, a, sredkolvo);

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
			ishod_tablica(i, r, sortirovka, a, b, name);
			break;
		case 2:
		case2:
			clrscr();
			result_tablica(i, r, sortirovka, a, b, name, pobed, mesto, sredkolvo, minkolvo, maxkolvo);
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
	free(minkolvo);
	free(maxkolvo);
	free(sredkolvo);
	return 1;
}
