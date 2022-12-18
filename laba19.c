#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define N 10

struct poezd {
	int numb;
	char *punkt_otbit;
	int hour_otbit;
	int min_otbit;
	char *punkt_pribit;
	int hour_pribit;
	int min_pribit;
};

int main()
{
	setlocale(LC_ALL, "RUS");

	//Задание 1.  Напишите программу, которая создает новый файл number.txt в текущей папке и записывает в него произвольную цифру и закрывает файл. 

	char fname[20] = "number.txt";
	FILE *out;
	puts("sozd faila");
	if ((out = fopen(fname, "wt")) == NULL) {
		printf("oshibka otkr faila dlya zapisi");
			return 0;
	}

	fprintf(out, "%d\n12,56", 5);
	fclose(out);

	//Задание 2. Разработайте программу, которая записывает в файл temp.txt, содержащих результат табулирования функции (работа 8 зад.2) вводом из stdin интервала и шага табуляции

	char fname2[20] = "temp.txt";
	FILE *out2;

	double y, M_PI = 3.14;
	float a = 0.1, b = 2.5;
	char z1 = '[', z2 = ']';

	if ((out2 = fopen(fname2, "wt")) == NULL) {
		printf("oshibka otkr faila dlya zapisi");
		return 0;
	}

	for (float i = a; i < b; i += a) {
		y = pow(i, 2) + 2 * M_PI * cos(M_PI) * i;
		fprintf(out2, "%.1f %lf \n", i, y);
		printf("%.1f %lf \n", i, y);
	}


	//Предусмотрите возможность выбора пользователем действий - 1) запись в новый файл 2) дозапись в существующий
	//Задание 3. Разработайте программу, которая записывает в файл поля структуры задания 3 работы 18

	struct poezd aPoezd[N];
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		aPoezd[i].numb = i + 1;
		aPoezd[i].punkt_otbit = "msc";
		aPoezd[i].hour_otbit = 0 + rand() % 23;
		aPoezd[i].min_otbit = 0 + rand() % 59;
		aPoezd[i].punkt_pribit = "rmn";
		aPoezd[i].hour_pribit = 0 + rand() % 23;
		aPoezd[i].min_pribit = 0 + rand() % 59;
	}

	int vibor = 1;
	printf("1 - v nov\n2 - v sush\n");
	scanf("%i", &vibor);
	if (vibor == 1) {
		fclose(out2);

		char fname3[20] = "temp2.txt";
		FILE *out3;

		if ((out3 = fopen(fname3, "wt")) == NULL) {
			printf("oshibka otkr faila dlya zapisi");
			return 0;
		}

		for (int i = 0; i < N; i++) {
				fprintf(out3, "Номер: %5i | Пункт отбытия: %13s | Время отбытия: %5i:%-7i | Пункт прибытия: %14s | Время прибытия: %5i:%-8i |  \n", aPoezd[i].numb, aPoezd[i].punkt_otbit, aPoezd[i].hour_otbit, aPoezd[i].min_otbit, aPoezd[i].punkt_pribit, aPoezd[i].hour_pribit, aPoezd[i].min_pribit);
		}
		fclose(out3);
	}
	else {
		for (int i = 0; i < N; i++) {
			fprintf(out2, "Номер: %5i | Пункт отбытия: %13s | Время отбытия: %5i:%-7i | Пункт прибытия: %14s | Время прибытия: %5i:%-8i |  \n", aPoezd[i].numb, aPoezd[i].punkt_otbit, aPoezd[i].hour_otbit, aPoezd[i].min_otbit, aPoezd[i].punkt_pribit, aPoezd[i].hour_pribit, aPoezd[i].min_pribit);
		}
		fclose(out2);
	}

	system("pause");
	return 1;
}

