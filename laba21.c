#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define N 10

typedef struct poezd {
	int numb;
	char* punkt_otbit[3];
	int hour_otbit;
	int min_otbit;
	char* punkt_pribit[3];
	int hour_pribit;
	int min_pribit;
} poezd;

void input_club(poezd* aPoezd, int n) {
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		aPoezd[i].numb = i + 1;
		strcpy(aPoezd[i].punkt_otbit, (i % 2 == 0) ? "msc" : "vrn");
		aPoezd[i].hour_otbit = 0 + rand() % 23;
		aPoezd[i].min_otbit = 0 + rand() % 59;
		strcpy(aPoezd[i].punkt_pribit, (i % 2 != 0) ? "usm" : "rmn");
		aPoezd[i].hour_pribit = 0 + rand() % 23;
		aPoezd[i].min_pribit = 0 + rand() % 59;
	}
}

void print_club(poezd* aPoezd, int n) {
	printf("Номер | Пункт отбытия | Время отбытия | Пункт прибытия | Время прибытия |\n");
	for (int i = 0; i < N; i++) {
		//if ((aPoezd[i].hour_pribit * 60 + aPoezd[i].min_pribit) - (aPoezd[i].hour_otbit * 60 + aPoezd[i].min_otbit) > 440) {
			printf("%5i | %13s | %5i:%-7i | %14s | %5i:%-8i |  \n", aPoezd[i].numb, aPoezd[i].punkt_otbit, aPoezd[i].hour_otbit, aPoezd[i].min_otbit, aPoezd[i].punkt_pribit, aPoezd[i].hour_pribit, aPoezd[i].min_pribit);
		//}
	}
}

void print_struct(poezd str) {

	printf("%5i | %13s | %5i:%-7i | %14s | %5i:%-8i |  \n", str.numb, str.punkt_otbit, str.hour_otbit, str.min_otbit, str.punkt_pribit, str.hour_pribit, str.min_pribit);
}

int compare_punkt_otbit(const void* av, const void* bv) {

	const struct poezd* a = av, * b = bv;

	return -strcmp(a->punkt_otbit, b->punkt_otbit);

}

int compare_punkt_pribit(const void* av, const void* bv) {

	const struct poezd* a = av, * b = bv;

	return -strcmp(a->punkt_otbit, b->punkt_otbit);

}

int compare_hour_pribit(const void* av, const void* bv) { //время прибытия

	const struct poezd* a = av, * b = bv;

	if (a->hour_pribit < b->hour_pribit) return -1;

	if (a->hour_pribit > b->hour_pribit) return 1;

	return -strcmp(a->punkt_otbit, b->punkt_otbit);

}

int compare_hour_otbit(const void* av, const void* bv) { //время отбытия

	const struct poezd* a = av, * b = bv;

	if (a->hour_otbit < b->hour_otbit) return -1;

	if (a->hour_otbit > b->hour_otbit) return 1;

	return -strcmp(a->punkt_otbit, b->punkt_otbit);
}

int f_input_file(FILE* f, poezd* aPoezd) {
	printf("Чтение файла\n");
	int i = 0;

	while (!feof(f)) {
		fscanf(f, "%i%s%i%i%s%i%i", &aPoezd[i].numb, aPoezd[i].punkt_otbit, &aPoezd[i].hour_otbit, &aPoezd[i].min_otbit, aPoezd[i].punkt_pribit, &aPoezd[i].hour_pribit, &aPoezd[i].min_pribit);
		printf("%i %s %i %i %s %i %i\n", aPoezd[i].numb, aPoezd[i].punkt_otbit, aPoezd[i].hour_otbit, aPoezd[i].min_otbit, aPoezd[i].punkt_pribit, aPoezd[i].hour_pribit, aPoezd[i].min_pribit);
		i++;
	}

}

int f_output_file(FILE *f, poezd* aPoezd, int n) {
	printf("Сохранение файла");
	for (int i = 0; i < n; i++) {
		fprintf(f, "%i %s %i %i %s %i %i\n", aPoezd[i].numb, aPoezd[i].punkt_otbit, aPoezd[i].hour_otbit, aPoezd[i].min_otbit, aPoezd[i].punkt_pribit, aPoezd[i].hour_pribit, aPoezd[i].min_pribit);
	}
}

void main()
{
	setlocale(LC_ALL, "RUS");

	FILE* input_file;
	char fname_in[20] = "input_file.txt";
	if ((input_file = fopen(fname_in, "rt")) == NULL) {
		printf("oshibka otkr faila dlya chtenya");
		return 0;
	}

	FILE* output_file;
	char fname_out[20] = "output_file.txt";
	if ((output_file = fopen(fname_out, "wt")) == NULL) {
		printf("oshibka otkr faila dlya zapisi");
		return 0;
	}

	//Задание 1. Реализуйте создание, инициализацию и вывод значений полей массива структур (инд. задания работы 18)
	/*Вариант 2. Запись «Поезд»:
	No поезда
	Пункт и время прибытия
	Пункт и время отбытия
	Вывести все сведения о поездах, время пребывания в пути
	которых превышает 7 часов 20 минут.*/
	//Задание 2. Включите функцию поиска и сортировки для заданных полей структуры
	//Задание 3. Реализуйте запись и чтение массива структур в/из файла 

	struct poezd aPoezd[N];
	input_club(aPoezd, N);
	print_club(aPoezd, N);
	print_struct(aPoezd[3]);

	int menu;
	int sub_menu = -1;
	do
	{
		printf("\n1. Чтение данных из файла\n2. Изменение выбранной пользователем записи\n3. Поиск записи в массиве по одному полю, значение которого задал пользователь\n4. Сортировка массива по выбранному пользователем полю\n5. Сохранение измененного массива записей в новый файл\n6. print\n0. Выход из программы\nВыберите нужный пункт: ");
		scanf("%i", &menu);
		switch (menu)
		{
		case 1:
			//chtenie
			f_input_file(input_file, aPoezd);
			break;
		case 2:
			//izm
			int stroka;
			int pole;
			int tmp_int;
			char tmp_name[3];
			printf("Изменить значение строки 0-%i\n Выберите пункт: ", N-1);
			scanf("%i", &stroka);
			printf("Изменить значение ячейки (0-Номер | 1-Пункт отбытия | 2-Час отбытия | 3-Минута отбытия | 4-Пункт прибытия | 5-Час прибытия | 6-Минута прибытия)\n Выберите пункт: ");
			scanf("%i", &pole);
			switch (pole) {
				case 0: 
					scanf("%i", &tmp_int);
					aPoezd[pole].numb = tmp_int;
					break;
				case 1:
					scanf("%s", &tmp_name);
					strcpy(aPoezd[pole].punkt_otbit, tmp_name);
					break;
				case 2:
					scanf("%i", &tmp_int);
					aPoezd[pole].hour_otbit = tmp_int;
					break;
				case 3:
					scanf("%i", &tmp_int);
					aPoezd[pole].min_otbit = tmp_int;
					break;
				case 4:
					scanf("%s", &tmp_name);
					strcpy(aPoezd[pole].punkt_pribit, tmp_name);
					break;
				case 5:
					scanf("%i", &tmp_int);
					aPoezd[pole].hour_pribit = tmp_int;
					break;
				case 6:
					scanf("%i", &tmp_int);
					aPoezd[pole].min_pribit = tmp_int;
					break;
			}
			break;
		case 3:
			//poisk
			//3. Поиск записи в массиве по одному полю, значение которого задал пользователь
			//номер больше/меньше
			int subb_menu;
			int znach;
			printf("Найти строки, номер которых: \n1. Больше значение\n2. Меньше значения\nВыберите пункт: ");
			scanf("%i", &subb_menu);
			printf("Введите значение: \n");
			scanf("%i", &znach);

			switch (subb_menu){
			case 1://bols
				for (int q = 0; q < N; q++) {
					if (aPoezd[q].numb > znach) { print_struct(aPoezd[q]); }
				}
				break;
			case 2://mensh
				for (int q = 0; q < N; q++) {
					if (aPoezd[q].numb < znach) { print_struct(aPoezd[q]); }
				}
				break;
			}

			break;
		case 4:
			//sort
			printf("1. Сортировка по пункту отбытия \n2. Сортировка по пункту прибытия\n3. Сортировка по часу отбытия\n4. Сортировка по часу прибытия\n0. Выход\nВыберите необходимый фильтр: ");
			scanf("%i", &sub_menu);
			switch (sub_menu)
			{
			case 1:
				printf("1. Сортировка по пункту отбытия \n");
				qsort(aPoezd, N, sizeof(struct poezd), compare_punkt_otbit);
				print_club(aPoezd, N);
				system("pause");

				break;
			case 2:
				printf("2. Сортировка по пункту прибытия\n");
				qsort(aPoezd, N, sizeof(struct poezd), compare_punkt_pribit);
				print_club(aPoezd, N);
				system("pause");

				break;
			case 3:
				printf("3. Сортировка по часу отбытия\n ");
				qsort(aPoezd, N, sizeof(struct poezd), compare_hour_otbit);
				print_club(aPoezd, N);
				system("pause");

				break;
			case 4:
				printf("4. Сортировка по часу прибытия\n ");
				qsort(aPoezd, N, sizeof(struct poezd), compare_hour_pribit);
				print_club(aPoezd, N);
				system("pause");

				break;
			case 0:
				break;

			default:
				printf("Неправильный ввод\n");
				break;
			}
		case 5:
			//sohran
			f_output_file(output_file, aPoezd, N);
			break;
		case 6:
			//print
			print_club(aPoezd, N);
			break;
		} 
	} while (menu != 0);

	fclose(input_file);
	fclose(output_file);

	system("pause");
}
