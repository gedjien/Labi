#include <locale.h>
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <string.h>


int clrscr();
int ishod_tablica(int i, int r, int sortirovka, int* a, char** name);
int result_tablica(int i, int r, int sortirovka, int* a, char** name, int* pobed, int* mesto, int* sredkolvo, int* minkolvo, int* maxkolvo, int *sumporaj, int *sumpobed);
int find_filter(int r, int *sumpobed, int *sumporaj, char **name);
int sort_buble(int *ptrarr, int n, char **name);
int sort_place(int i, int r, int *mesto, char **name, int sortirovka);
int result_tab_var_full(int i, int r, int *a, int* pobed, int* mesto, int* maxkolvo, int* sredkolvo, int* minkolvo, int* sumpobed, int* sumporaj);
int add_new_player(int i, int r, int *a, char **name, int *temp_msv, char **temp_name);
int show_menu(int i, int r, int* a, char** name);
int read_file(FILE* file, int i, int r, int *a, char **name);

int main() {

	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	setlocale(LC_ALL, "RUS");

	int i = 0, r = 1; //колонки, строки

	FILE* file;

	char file_name[] = "fscanf.txt";
	//puts("Введите название .txt файла (Без расширения): "); scanf("%s", &file_name); strcat(file_name, ".txt");
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

	char** name = (char**)calloc(r, sizeof(char*));// указатель на массив имён
	for (int q = 0; q < r; q++) {
		name[q] = (char*)calloc(70, sizeof(char)); //двумерный массив имён
		strcpy(name[q], "undefined"); //заполнение значениями
	}

	int* massiv_znach = (int*)malloc(pow(r, 2) * sizeof(int));// указатель на массив значений

	i = read_file(file, i, r, massiv_znach, name); //определение динамического массива данными из файла

	fclose(file); //закрытие файла

	//вызов меню
	show_menu(i, r, massiv_znach, name);

	// освобождение памяти
	free(name);
	free(massiv_znach);

	return 1;
}

int clrscr()
{
	system("@cls||clear");
	return 1;
}

int ishod_tablica(int i, int r, int sortirovka, int* a, char** name) {
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
				if (*(a + x * r + q) == 0 & *(a + q * r + x) == 0) { printf("       |"); continue; }
				printf(" %2i:%-2i |", *(a + x * r + q), *(a + q * r + x));
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
				if (*(a + x * r + q) == 0 & *(a + q * r + x) == 0) { printf("       |"); continue; }
				printf(" %2i:%-2i |", *(a + x * r + q), *(a + q * r + x));
			}

			printf("\n");
		}
	}
	return 1;
}

int result_tablica(int i, int r, int sortirovka, int* a, char** name, int* pobed, int* mesto, int* sredkolvo, int* minkolvo, int* maxkolvo, int *sumporaj, int *sumpobed) {

	if (sortirovka == 0) {
		printf("Вывести результирующую таблицу (Вывод обычный)\n"); //общее количество очков, поражения

		printf("Имя участника ");
		// игр | выиграно | проиграно | КОЭФФИЦИНЕНТ РАСЧЕТА СУММЫ ОЧКОВ ( ОТНОШЕНИЕ ВЫИГРЫШ/ПРОИГРЫШ )
		// ОБЩ, СРЕД, МИН, МАКС КОЛИЧЕСТВО ОЧКОВ
		printf("| И | В | П | %9s | %9s ", "Отношение очков", "Общ/Сред/Мин/Макс очков"); //выравнивание 1 столбца 
		printf("| Место |"); printf("\n"); //шапка
		for (int x = 0; x < i; x++) { //уникальные строки
			printf("%13s |", name[x]);
			//счёт
			printf(" %i | %i | %i |", i - 1, pobed[x], i - pobed[x] - 1); // И | В | П
			printf(" %+6i / -%-5i |", sumpobed[x], sumporaj[x]); // +/- |

			printf(" %3i/%4i/%3i/%3i %7s", sumpobed[x] - sumporaj[x], sredkolvo[x], minkolvo[x], maxkolvo[x], ""); // +/- |

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
		printf("| И | В | П | %9s | %9s ", "Отношение очков", "Общ/Сред/Мин/Макс очков"); //выравнивание 1 столбца 
		printf("| Место |"); printf("\n"); //шапка
		for (int x = i - 1; x >= 0; x--) { //уникальные строки
			printf("%13s |", name[x]);
			//счёт
			printf(" %i | %i | %i |", i - 1, pobed[x], i - pobed[x] - 1); // И | В | П
			printf(" %+6i / -%-5i |", sumpobed[x], sumporaj[x]); // +/- |

			printf(" %3i/%4i/%3i/%3i %7s", sumpobed[x] - sumporaj[x], sredkolvo[x], minkolvo[x], maxkolvo[x], ""); // +/- |

			printf("|   %1i   |\n", mesto[x]);
		}
	}
	//
	//
	return 1;
}

int find_filter(int r, int *sumpobed, int *sumporaj, char **name) {
	int sub_menu;
	printf("1. Найти игрока с максимальным количеством очков\n2. Найти игрока с минимальным количеством очков\n3. Найти игрока с количеством очков больше введённого значения\n4. Найти игрока с количеством очков меньше введённого значения\nВыберите необходимый фильтр: ");
	scanf("%i", &sub_menu);
	int max = INT_MIN;
	int min = INT_MAX;

	switch (sub_menu)
	{
	case 1:
		// Найти команду с максимальным количеством очков
		for (int i = 0; i < r; i++)
		{
			if (sumpobed[i] - sumporaj[i] >= max)
			{
				max = sumpobed[i] - sumporaj[i];
			}
		}
		for (int i = 0; i < r; i++)
		{
			if (sumpobed[i] - sumporaj[i] >= max)
			{
				printf("\nИгрок %s - кол-во очков %i\n", name[i], sumpobed[i] - sumporaj[i]);
			}
		}

		break;
	case 2:
		// Найти команду с минимальным количеством очков
		for (int i = 0; i < r; i++)
		{
			if (sumpobed[i] - sumporaj[i] <= min)
			{
				min = sumpobed[i] - sumporaj[i];
			}
		}
		for (int i = 0; i < r; i++)
		{
			if (sumpobed[i] - sumporaj[i] <= min)
			{
				printf("\nИгрок %s - кол-во очков %i\n", name[i], sumpobed[i] - sumporaj[i]);
			}
		}

		break;
	case 3:
		// Найти команды с количеством очков больше ввденного значения
		printf("\rНайти игрока с количеством очков больше введённого значени \nВведите значение для поиска: ");
		int biggest;
		scanf("%i", &biggest);
		int exist_for_big = 0;
		for (int i = 0; i < r; i++)
		{
			if (sumpobed[i] - sumporaj[i] > biggest)
			{
				exist_for_big = 1;
				printf("Игрок %s - %i кол-во очков\n", name[i], sumpobed[i] - sumporaj[i]);
			}
		}
		if (exist_for_big == 0)
		{
			printf("Таких игроков не существует");
		}
		break;
	case 4:
		// Найти команды с количеством очков меньше ввденного значения
		printf("\rНайти игрока с количеством очков меньше введённого значения \nВведите значение для поиска: ");
		int smallest;
		scanf("%i", &smallest);
		int exist_for_small = 0;
		for (int i = 0; i < r; i++)
		{
			if (sumpobed[i] - sumporaj[i] < smallest)
			{
				exist_for_small = 1;
				printf("Игрок %s - %i кол-во очков\n", name[i], sumpobed[i] - sumporaj[i]);
			}
		}
		if (exist_for_small == 0)
		{
			printf("Таких игроков не существует");
		}
		break;
	default:
		printf("Неправильный ввод\n");
		break;
	}

	return 1;
}

int sort_buble(int *ptrarr, int n, char **name) {
	for (int j = 1; j < n; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (ptrarr[i] > ptrarr[i + 1]) {
				int temp_x = ptrarr[i];
				ptrarr[i] = ptrarr[i + 1];
				ptrarr[i + 1] = temp_x;

				char temp_name[70];
				strcpy(temp_name, name[i]);
				strcpy(name[i], name[i + 1]);
				strcpy(name[i + 1], temp_name);

			}
		}
	}

	return 1;
}

int sort_place(int i, int r, int *mesto, char **name, int sortirovka) {

	char** temp_name = (char**)calloc(r, sizeof(char*));// указатель на массив имён

	for (int q = 0; q < r; q++) {
		temp_name[q] = (char*)calloc(70, sizeof(char)); //двумерный массив имён
		strcpy(temp_name[q], name[q]); //заполнение значениями
	}

	int* mesto_sorted = (int*)malloc(i * sizeof(int));
	for (int q = 0; q < r; q++) {
		mesto_sorted[q] = mesto[q];
	}
	/*printf("До сортировки\n");
	printf("Имя игрока | Занятое место\n");
	for (int q = 0; q < r; q++) {
		printf("%10s | %i \n", name[q], mesto_sorted[q]);
	}	printf("После сортировки\n");
*/

	sort_buble(mesto_sorted, r, temp_name);

	if (sortirovka == 0) {
		printf("Имя игрока | Занятое место (Вывод обычный)\n");
		for (int q = 0; q < r; q++) {
			printf("%10s | %i \n", temp_name[q], mesto_sorted[q]);
		}
	}

	else {
		printf("Имя игрока | Занятое место (Вывод в обратном порядке)\n");

		for (int q = r - 1; q >= 0; q--) {
			printf("%10s | %i \n", name[q], mesto_sorted[q]);
		}
	}

	return 1;
}

int result_tab_var_full(int i, int r, int *a, int* pobed, int* mesto, int* maxkolvo, int* sredkolvo, int* minkolvo, int* sumpobed, int* sumporaj) {

	//вычисление и заполнение массива побед через условие 	//счёт количества побед
	for (int q = 0; q < i; q++)  // цикл по строкам
	{
		int sm_pobed = 0;
		for (int x = 0; x < i; x++)  // цикл по столбцам
		{
			if (*(a + q * r + x) > *(a + x * r + q)) sm_pobed += 1;
		}
		pobed[q] = sm_pobed;
	}
	//

	//вычисление и заполнение массива место //вычисление занятого места
	for (int x = 0; x < i; x++) {
		mesto[x] = 0;
		for (int s = 0; s < i; s++) {
			if (pobed[x] > pobed[s]) { mesto[x] += 1; }
		}
		mesto[x] = i - mesto[x];
	}
	int odinak = 0;
	for (int x = 0; x < i; x++) {
		mesto[x] = 0;
		for (int s = 0; s < i; s++) {
			if (pobed[x] > pobed[s]) { mesto[x] += 1; }
		}
		mesto[x] = i - mesto[x];
	}
	//

	//поиск макс/сред/мин знач
	//вычисление и заполнение массива максимального количества очков
	for (int q = 0; q < i; q++)  // цикл по строкам
	{
		int max_ochkov = 0;
		for (int x = 0; x < i; x++)  // цикл по столбцам
		{
			if (max_ochkov < *(a + q * r + x)) max_ochkov = *(a + q * r + x);
		}
		maxkolvo[q] = max_ochkov;
	}
	//

	//вычисление и заполнение массива среднего количества очков
	for (int q = 0; q < i; q++)  // цикл по строкам
	{
		int sred_ochkov = 0;
		for (int x = 0; x < i; x++)  // цикл по столбцам
		{
			sred_ochkov += *(a + q * r + x);
		}
		sredkolvo[q] = sred_ochkov / (i - 1);
	}
	//

	//вычисление и заполнение массива минимального количества очков
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
	//

	//вычисление и заполнение массивы сумма побед/сумма поражений
	for (int q = 0; q < i; q++) {
		sumpobed[q] = 0;
		sumporaj[q] = 0;
		for (int x = 0; x < i; x++) {
			sumpobed[q] += *(a + q * r + x);
			sumporaj[q] += *(a + x * r + q);
		}
	}

	//проверка на одинаковое место
	for (int x = 0; x < i - 1; x++) {
		//for (int s = 0; s < i; s++) {
		if (pobed[x] == pobed[x + 1]) { if (sumpobed[x] > sumpobed[x + 1]) mesto[x] = mesto[x] - 1; else mesto[x + 1] = mesto[x + 1] - 1; x = 0; break; }
		//}
	}


	return 1;
}

int add_new_player(int i, int r, int *a, char **name, int *temp_msv, char **temp_name) {
	int counter = 0;

	for (int q = 0; q < r; q++) {
		for (int x = 0; x < r; x++) {
			if (q == r - 1 & x == r - 1) { *(a + q * r + x) = 0; continue; }
			if (q == r - 1) {
				printf("Введите количество очков против игрока %i (%s): ", x, temp_name[x]);
				scanf("%i", &(*(a + q * r + x)));
				continue;
			}
			if (x == r - 1) {
				printf("Введите количество очков игрока %i (%s) против нового игрока: ", q, temp_name[q]);
				scanf("%i", &(*(a + q * r + x)));
				counter++;
				continue;
			}
			*(a + q * r + x) = *(temp_msv + q * r + x - counter);
		}
	}

	for (int q = 0; q < r; q++) {
		name[q] = (char*)calloc(70, sizeof(char)); //двумерный массив имён
		if (q == r - 1) { puts("Введите имя нового игрока"); scanf("%s", name[q]); continue; };
		strcpy(name[q], temp_name[q]); //заполнение значениями
	}

	return 1;
}

int show_menu(int i, int r, int* a, char** name) {
newplayer:

	//переменные для результирубщей таблицы/сортировки
	int* pobed = (int*)malloc(i * sizeof(int));
	int* mesto = (int*)malloc(i * sizeof(int));
	int* maxkolvo = (int*)malloc(i * sizeof(int));
	int* minkolvo = (int*)malloc(i * sizeof(int));
	int* sredkolvo = (int*)malloc(i * sizeof(int));
	int* sumpobed = (int*)malloc(i * sizeof(int));
	int* sumporaj = (int*)malloc(i * sizeof(int));

	result_tab_var_full(i, r, a, pobed, mesto, maxkolvo, sredkolvo, minkolvo, sumpobed, sumporaj);

	int spos_vivoda = 0; //переменная для способа вывода по умолчанию
	int last_choose = 1; //переменная последнего выбранного пункта

	while (1) {
		printf("Пункты меню \n1. Вывод исходной таблицы \n2. Вывод результирующей таблицы \n3. Отсортировать игроков по месту\n4. Изменить имя игрока\n5. Найти команду по фильтру\n6. Способ вывода (обычный/в обратном порядке)\n7. Добавить нового игрока в конец списка \n0. Выход\n");

		int menu = 0;
		printf("Выбор пункта: ");
		scanf("%i", &menu);
		if (menu == 1 | menu == 2 | menu == 3) { last_choose = menu; }
		switch (menu) {
		case 1:
			//
		case1:
			clrscr();
			ishod_tablica(i, r, spos_vivoda, a, name);
			break;
		case 2:
		case2:
			clrscr();
			result_tablica(i, r, spos_vivoda, a, name, pobed, mesto, sredkolvo, minkolvo, maxkolvo, sumporaj, sumpobed);
			break;
		case 3:
		case3:
			clrscr();
			//
			sort_place(i, r, mesto, name, spos_vivoda);
			//
			printf("\n\n");
			break;
		case 4:
			clrscr();

			printf("\nЗамена существующих имен\n");
			printf("Выберите имя для замены: \n");
			for (int k = 0; k < r; k++)
			{
				printf("%i) %s\n", k, name[k]);
			}
			int select_name;
			scanf("%i", &select_name);
			printf("Введите новое название: ");
			char new_name[70];
			scanf("%s", &new_name);
			name[select_name] = new_name;
			printf("\n\n");
			break;
		case 5:
			clrscr();
			find_filter(r, sumpobed, sumporaj, name);
			printf("\n\n");
			break;
		case 6:
			if (spos_vivoda == 0) { spos_vivoda = 1; printf("Вывод в обратном порядке\n"); }
			else { spos_vivoda = 0; printf("Вывод обычный\n"); }

			switch (last_choose) {
			case 1: goto case1; break;
			case 2: goto case2; break;
			case 3: goto case3; break;
			}
			break;
		case 7:
			clrscr();
			r += 1;
			i += 1;
			int *temp_msv = (int*)malloc(pow((r - 1), 2) * sizeof(int));
			for (int q = 0; q < r - 1; q++) {
				for (int x = 0; x < r - 1; x++) {
					*(temp_msv + q * (r - 1) + x) = *(a + q * (r - 1) + x);
				}
			}

			char** temp_name = (char**)calloc(r - 1, sizeof(char*));// указатель на массив имён
			for (int q = 0; q < r - 1; q++) {
				temp_name[q] = (char*)calloc(70, sizeof(char)); //двумерный массив имён
				strcpy(temp_name[q], name[q]); //заполнение значениями
			}

			a = (int*)realloc(a, pow(r, 2) * sizeof(int));
			free(name);
			name = (char**)calloc(r, sizeof(char*));// указатель на массив имён

			add_new_player(i, r, a, name, temp_msv, temp_name); //заполнение нового массива

			// освобождение памяти
			free(temp_name);
			free(temp_msv);

			goto newplayer;
			break;
		case 0:
			clrscr();
			printf("Выход\n");
			exit(EXIT_SUCCESS);
			break;
		default:
			clrscr();
			printf("Неправильный ввод\n");
		}
	}

	// освобождение памяти
	free(pobed);
	free(mesto);
	free(minkolvo);
	free(maxkolvo);
	free(sredkolvo);
	free(sumpobed);
	free(sumporaj);
	return 1;
}

int read_file(FILE* file, int i, int r, int *a, char **name) {
	printf("Чтение файла\n");
	//чтение/заполнение значений
	while (!feof(file))
	{ // чтение имён
		fscanf(file, "%s", name[i]);
		//printf("%s ", name[i]);
		for (int x = 0; x < r; x++)
		{
			fscanf(file, "%i", &(*(a + i * r + x)));
			//printf("%i ", *(a + i * r + x));
		} // чтение чисел
		i++;
		//printf("\n");
	}

	return i;
}

