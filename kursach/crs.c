#include <locale.h>
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <string.h>

int clrscr();
int ishod_tablica(int i, int r, int* b, char** name);
int result_tablica(int i, int r, int** res_tab_var, char** name);
int result_tab_var_full(int i, int r, int* b, int** res_tab_var);
int find_diapaz(int r, int* ball, char** name, int znach);
int sort_buble(int* ptrarr, int n, char** name);
int sort_place(int i, int r, char** name, int* mesto_sorted);
int add_new_player(int i, int r, int* b, char** name);
int show_menu(int i, int r, int** b, char** name);
int write_new_file(int r, int* b, char* new_file_name, char** name);
int read_file(int i, int r, int* a, char* file_name, char** name);

int main() {

	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	setlocale(LC_ALL, "RUS");

	int i = 0, r = 1; //колонки, строки

	FILE* file;
	char file_name[70] = "fscanf.txt";
	puts("Введите название .txt файла (Без расширения): ");
	scanf("%s", &file_name);
	strcat(file_name, ".txt");
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
	//fseek(file, 0, SEEK_SET); //возвращение в 0 строку файла


	char** name = (char**)calloc(r, sizeof(char*));// указатель на массив имён
	for (int q = 0; q < r; q++) {
		name[q] = (char*)calloc(70, sizeof(char)); //двумерный массив имён
		strcpy(name[q], "undefined"); //заполнение значениями
	}

	int** massiv_znach = (int*)malloc(r * sizeof(int));// указатель на массив значений
	for (int q = 0; q < r; q++) {
		massiv_znach[q] = (int*)malloc(r * sizeof(int)); //двумерный массив имён
	}


	fclose(file); //закрытие файла

	i = read_file(i, r, massiv_znach, file_name, name); //чтение данных из файла

	show_menu(i, r, massiv_znach, name);

	// освобождение памяти
	//free(name);
	//free(massiv_znach);

	return 1;
}

int clrscr()
{
	system("@cls||clear");
	return 1;
}

int ishod_tablica(int i, int r, int* b, char** name) {
	printf("Вывести исходную таблицу\n");
	printf("Номер | Имя участника |");

	for (int q = 0; q < i; q++) {
		printf(" %3i%2s |", q + 1, "");
	}
	printf("\n"); //шапка


	for (int x = 0; x < i; x++) { //уникальные строки
		printf("%5i | %13s |", x + 1, name[x]);

		////счёт
		for (int q = 0; q < i; q++) {
			//	//в случае, если столбец игрока пересекается с своей же строкой
			if (*(b + x * r + q) == 0 & *(b + q * r + x) == 0) { printf("       |"); continue; }
			printf(" %2i:%-2i |", *(b + x * r + q), *(b + q * r + x));
		}
		printf("\n");
	}
}

int result_tablica(int i, int r, int** res_tab_var, char** name) {

	printf("Вывести результирующую таблицу\n"); //общее количество очков, поражения

	printf("Имя участника ");
	printf("| И | В | П | %9s | %9s ", "Отношение очков", "Общ/Сред/Мин/Макс очков"); //выравнивание 1 столбца 
	printf("| Место |"); printf("\n"); //шапка
	for (int x = 0; x < i; x++) { //уникальные строки
		printf("%13s |", name[x]);
		//счёт
		printf(" %i | %i | %i |", i - 1, res_tab_var[0][x], i - res_tab_var[0][x] - 1); // И | В | П
		printf(" %+6i / -%-5i |", res_tab_var[5][x], res_tab_var[6][x]); // +/- |

		printf(" %3i/%4i/%3i/%3i %7s", res_tab_var[5][x] - res_tab_var[6][x], res_tab_var[4][x], res_tab_var[3][x], res_tab_var[2][x], ""); // +/- |

		printf("|   %1i   |\n", res_tab_var[1][x]);
	}

};

int result_tab_var_full(int i, int r, int* b, int** res_tab_var) {

	int* a = (int*)malloc(pow(r, 2) * sizeof(int));// указатель на массив значений

	//переменные для результирубщей таблицы
	for (int q = 0; q < i; q++) {
		for (int w = 0; w < i; w++) {
			*(a + q * r + w) = *(b + q * r + w);
		}
	}

	////переменные для результирубщей таблицы
	//for (int q = 0; q < i; q++) {
	//	for (int w = 0; w < i; w++) {
	//		printf(" %2i:%-2i |", *(a + q * r + w), *(a + w * r + q));
	//	}
	//	printf("\n");
	//}

	//переменные для результирубщей таблицы/сортировки
	int* pobed = (int*)malloc(i * sizeof(int));
	int* mesto = (int*)malloc(i * sizeof(int));
	int* maxkolvo = (int*)malloc(i * sizeof(int));
	int* minkolvo = (int*)malloc(i * sizeof(int));
	int* sredkolvo = (int*)malloc(i * sizeof(int));
	int* sumpobed = (int*)malloc(i * sizeof(int));
	int* sumporaj = (int*)malloc(i * sizeof(int));

	//вычисление и заполнение массива побед через условие 	//счёт количества побед
	for (int q = 0; q < i; q++)  // цикл по строкам
	{
		int sm_pobed = 0;
		for (int x = 0; x < i; x++)  // цикл по столбцам
		{
			if (*(a + q * r + x) > *(a + x * r + q)) sm_pobed += 1;
		}
		pobed[q] = sm_pobed;
		res_tab_var[0][q] = pobed[q];
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
		res_tab_var[1][x] = mesto[x];
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
		res_tab_var[2][q] = maxkolvo[q];
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
		res_tab_var[4][q] = sredkolvo[q];
	}
	//

	//вычисление и заполнение массива минимального количества очков
	for (int q = 0; q < i; q++)  // цикл по строкам
	{
		minkolvo[q] = INT_MAX;
		for (int x = 0; x < i; x++)  // цикл по столбцам
		{
			if (*(a + q * r + x) == 0) { continue; }
			if (*(a + q * r + x) < minkolvo[q]) {
				minkolvo[q] = *(a + q * r + x);
				res_tab_var[3][q] = minkolvo[q];
			}
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
			res_tab_var[5][q] = sumpobed[q];
			res_tab_var[6][q] = sumporaj[q];
		}
	}

	//проверка на одинаковое место
	for (int x = 0; x < i - 1; x++) {
		//for (int s = 0; s < i; s++) {
		if (pobed[x] == pobed[x + 1]) { if (sumpobed[x] > sumpobed[x + 1]) mesto[x] = mesto[x] - 1; else mesto[x + 1] = mesto[x + 1] - 1; x = 0; break; }
		//}
	}

	//for (int q = 0; q < r; q++) {
	//	printf("%i", mesto[q]);
	//}
	int* mesto_sorted = (int*)malloc(i * sizeof(int));	for (int q = 0; q < r; q++) { mesto_sorted[q] = mesto[q]; }

	int min = 0;
	int buf = 0;
	for (int i = 0; i < r; i++) {
		min = i;
		for (int j = i + 1; j < r; j++)
			min = (mesto_sorted[j] < mesto_sorted[min]) ? j : min;
		if (i != min) {
			buf = mesto_sorted[i];
			mesto_sorted[i] = mesto_sorted[min];
			mesto_sorted[min] = buf;
		}
	}


	for (int q = 0; q < i; q++) {
		res_tab_var[7][q] = mesto_sorted[q];
		//		printf("%i", mesto_sorted[q]);
	}

	int* fnd_msv = (int*)malloc(r * sizeof(int));

	for (int q = 0; q < i; q++) {
		fnd_msv[q] = res_tab_var[5][q] - res_tab_var[6][q];
		res_tab_var[8][q] = fnd_msv[q];
		//	printf("%i", res_tab_var[8][q]);
	}



	// освобождение памяти
	//free(pobed);
	//free(mesto);
	//free(maxkolvo);
	//free(minkolvo);
	//free(sredkolvo);
	//free(sumpobed);
	//free(sumporaj);
}

int find_diapaz(int r, int* ball, char** name, int znach) {
	// Найти команды с количеством очков больше ввденного значения
	int exist = 0;
	
	for (int i = 0; i < r; i++)
	{
		if (ball[i] > znach)
		{
			exist = 1;
			printf("Игрок %s - %i кол-во очков\n", name[i], ball[i]);
		}
	}
	if (exist == 0)
	{
		printf("Таких игроков не существует");
	}
	//// Найти команды с количеством очков меньше ввденного значения
	//printf("\nНайти игрока с количеством очков меньше введённого значения \nВведите значение для поиска: ");
	//exist = 0;
	//for (int i = 0; i < r; i++)
	//{
	//	if (sumpobed[i] - sumporaj[i] < znach)
	//	{
	//		exist = 1;
	//		printf("Игрок %s - %i кол-во очков\n", name[i], sumpobed[i] - sumporaj[i]);
	//	}
	//}
	//if (exist == 0)
	//{
	//	printf("Таких игроков не существует");
	//}
}

int sort_buble(int* ptrarr, int n, char** name) {
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

int sort_place(int i, int r, char** name, int* mesto_sorted) {
	char** temp_name2 = (char**)calloc(r, sizeof(char*));// указатель на массив имён
	for (int q = 0; q < r; q++) {
		temp_name2[q] = (char*)calloc(70, sizeof(char)); //двумерный массив имён
		strcpy(temp_name2[q], name[q]); //заполнение значениями 
	}

	sort_buble(mesto_sorted, r, temp_name2);

	printf("Имя игрока | Занятое место\n");
	for (int q = 0; q < r; q++) {
		printf("%10s | %i \n", temp_name2[q], mesto_sorted[q]);
	}

}

int add_new_player(int i, int r, int* b, char** name) {
	
	//printf("%i\n", r);
	
	char** temp_name = (char**)calloc((r + 1), sizeof(char*));// указатель на новый массив имён
	for (int q = 0; q < r+1; q++) {
		temp_name[q] = (char*)calloc(70, sizeof(char)); //двумерный массив имён
	}

	for (int q = 0; q < r; q++) {
		strcpy(temp_name[q], name[q]); //заполнение значениями
	}

	puts("Введите имя нового игрока"); scanf("%s", temp_name[r]);

	int** tmp_massiv_znach = (int*)malloc((r + 1) * sizeof(int));// указатель на массив значений
	for (int q = 0; q < r+1; q++) {
		tmp_massiv_znach[q] = (int*)malloc((r + 1) * sizeof(int)); //двумерный массив имён
	}

	//for (int q = 0; q < r+1; q++) {
	//	printf("%s\n", temp_name[q]);
	//}

	int counter = 0;

	for (int q = 0; q < r+1; q++) {
		for (int x = 0; x < r+1; x++) {
			if (q == r & x == r) { tmp_massiv_znach[q][x] = 0; continue; }
			if (q == r) {
				printf("Введите количество очков против игрока %i (%s): ", x, temp_name[x]);
				scanf("%i", &(tmp_massiv_znach[q][x]));

				continue;
			}
			if (x == r) {
				printf("Введите количество очков игрока %i (%s) против нового игрока: ", q, temp_name[q]);
				scanf("%i", &(tmp_massiv_znach[q][x]));
				counter++;
				continue;
			}
			tmp_massiv_znach[q][x] = *(b + q * (r+1) + x - counter);
		}
	}

	char file_name[] = "fscanf.txt";
	puts("Введите название .txt файла (Без расширения): ");
	scanf("%s", &file_name);
	strcat(file_name, ".txt");
	FILE* new_file = fopen(file_name, "w");

	for (int q = 0; q < r + 1; q++) {
		fprintf(new_file, "%s ", temp_name[q]);
		for (int x = 0; x < r + 1; x++)
		{
			if (x < r) {
				fprintf(new_file, "%i ", tmp_massiv_znach[q][x]);
			}
			else {
				fprintf(new_file, "%i", tmp_massiv_znach[q][x]);
			}
		}
	
		if (q == r) {
			continue;
		}
		else {
			fprintf(new_file, "\n");
		}
	}
	fclose(new_file);
	//exit(EXIT_SUCCESS);

	return 1;
}

int show_menu(int i, int r, int** b, char** name) {
	while (1) {
		//массив переменных для результирующей таблицы
		int** res_tab_var = (int*)malloc(9 * sizeof(int)); // 0 побед; 1 место; 2 максколво; 3 минколво; 4 средколво; 5 сумпобед; 6 сумпораж; 7 отсортированное место; 8 баллы
		for (int q = 0; q < 9; q++) {
			res_tab_var[q] = (int*)malloc(r * sizeof(int)); //двумерный массив
		}

		result_tab_var_full(i, r, b, res_tab_var); //вычисление и заполнение массива
		printf("Пункты меню \n1. Вывод исходной таблицы \n2. Вывод результирующей таблицы \n3. Отсортировать игроков по месту\n4. Изменить имя игрока\n5. Найти игрока по фильтру\n6. Добавить нового игрока в конец списка \n7. Запись в файл \n0. Выход\n");

		int menu = 0;
		printf("Выбор пункта: ");
		scanf("%i", &menu);
		switch (menu) {
		case 1:
			//
			clrscr();
			ishod_tablica(i, r, b, name);
			break;

		case 2:
			clrscr();
			result_tablica(i, r, res_tab_var, name);
			break;

		case 3:
			clrscr();

			sort_place(i, r, name, res_tab_var[7]);

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
			int select_name; scanf("%i", &select_name);
			printf("Введите новое название: "); char new_name[70]; scanf("%s", &new_name);
			name[select_name] = new_name;

			printf("\n\n");
			break;
		case 5:
			clrscr();
			int sub_menu;
			printf("1. Найти игроков с максимальным/минимальным/средним количеством очков\n2. Найти игрока с количеством очков больше введённого значения\nВыберите необходимый фильтр: ");
			scanf("%i", &sub_menu);

			if (sub_menu == 1) {
				char** name_ind_srt = (char**)calloc(r, sizeof(char*));// указатель на массив имён
				for (int q = 0; q < r; q++) {
					name_ind_srt[q] = (char*)calloc(70, sizeof(char)); //двумерный массив имён
					strcpy(name_ind_srt[q], name[q]); //заполнение значениями
				}

				sort_buble(res_tab_var[8], r, name_ind_srt);

				//for (int q = 0; q < r; q++) {
				//	printf("%s %i\n", name_ind_srt[q], res_tab_var[8][q]);
				//}

				printf("Игрок c максимальным количеством очков: %s - кол-во очков %i\n", name_ind_srt[r - 1], res_tab_var[8][r - 1]);
				printf("Игрок c минимальным количеством очков: %s - кол-во очков %i\n", name_ind_srt[0], res_tab_var[8][0]);
				printf("Игрок с количеством очков приближенным к среднему: %s - кол-во очков %i\n", name_ind_srt[r / 2], res_tab_var[8][r / 2]);
			}
			else {
				printf("\nНайти игрока с количеством очков больше введённого значени \nВведите значение для поиска: ");
				int znach;
				scanf("%i", &znach);
				find_diapaz(sub_menu, r, res_tab_var[8], name, znach);
			}


			printf("\n\n");
			break;
		case 6:
			clrscr();

			add_new_player(i, r, b, name);

			break;
		case 7:
			clrscr();

			puts("Запись в новый файл");
			char new_file_name[] = "new.txt";
			puts("Введите название нового .txt файла (Без расширения): "); scanf("%s", &new_file_name); strcat(new_file_name, ".txt");

			write_new_file(r, b, new_file_name, name);
			puts("Файл записан");


			printf("\n\n");
			break;
		case 0:
			clrscr();
			printf("Выход\n");
			//		exit(EXIT_SUCCESS);
			break;

		default:
			clrscr();
			printf("Неправильный ввод\n");
		}

		// освобождение памяти
		//free(res_tab_var);
	}

	return 1;
}

int write_new_file(int r, int* b, char* new_file_name, char** name) {
	FILE* new_file = fopen(new_file_name, "w");

	for (int q = 0; q < r; q++) {
		fprintf(new_file, "%s ", name[q]);
		for (int x = 0; x < r; x++)
		{
			if (x < r-1) {
				fprintf(new_file, "%i ", *(b + q * r + x));
			}
			else {
				fprintf(new_file, "%i", *(b + q * r + x));
			}
		}

		if (q == r-1) {
			continue;
		}
		else {
			fprintf(new_file, "\n");
		}
	}
	fclose(new_file);

	return 1;
}

int read_file(int i, int r, int* a, char* file_name, char** name) {
	FILE* file = fopen(file_name, "r");
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

	fclose(file); //закрытие файла

	return i;
}
