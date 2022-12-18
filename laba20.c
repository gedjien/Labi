#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	setlocale(LC_ALL, "RUS");


	//Задание 1. Напишите программу, которая вычисляет среднее арифметическое целых чисел, содержащихся в файле (использовать файл созданный в задании 2 работы 19). 

	FILE *out;
	out = fopen("temp.txt", "rt");

	float x[25], y[25];
	int i = 0;

	while (!feof(out)) {
		fscanf(out, "%f %f", &x[i], &y[i]);
		i++;
	}

	float sum1 = 0, sum2 = 0;

	for (int q = 0; q < 25; q++) {
		sum1 += x[q]; sum2 += y[q];
		printf("%.1f %f \n", x[q], y[q]);
	}printf("Ср. арефметич. %.1f %f", sum1 / i, sum2 / i);

	//Задание 2. Напишите программу, которая открывает указанный пользователем файл, содержащий выборку рациональных чисел, 
	//каждое их которых записано с новой строки. Выполняет преобразование над ними согласно варианту. 
	//Записывает результат в файл с прежним название дополненным название выполненного над данными преобразования 
	//(например, было input.dat стало inputparity1.dat)

	//Варианты преобразований:
	//1. Заменить каждое второе число на 0.

	FILE *out2;
	out2 = fopen("tempparity1.txt", "wt");

	for (int q = 0; q < 25; q++) {
		if (q % 2 == 0) {
			fprintf(out2, "%.1f %f \n", x[q], y[q]);
		}
		else {
			fprintf(out2, "%.1f %f \n", 0, 0);
		}
	}

	fclose(out);
	fclose(out2);


	//Задание 3 (индивидуальное)
	//2. Заменить восклицательным знаком все буквы а, если в этой строке
	//нет восклицательного знака, иначе на символ подчеркивания
	printf("\n");

	FILE* file;
	file = fopen("winter.txt", "rt");
	FILE* in;
	char b[100];
	char *a[100];
	int n = 100;
	a[0] = '\0';
	char fname[100] = "winter2.txt";
	if ((in = fopen(fname, "wt")) == NULL) {
		printf("\n\nОшибка открытия файла\n\n");
		return 0;
	}

	char* ptr;

	for (int i = 0; fgets(fname, 100, file) != NULL; ++i)
	{
		if (i % 2 != 0) {}
		else
		{
			printf("%s\n", fname);
			if (strchr(fname, '!') == NULL) {
				ptr = strchr(fname, 'a');
				if (ptr != NULL) {
					*ptr = '!'; strcat(a, ptr);
				}
				else {
					strcat(a, fname);
				}
			}
			else {
				ptr = strchr(fname, 'a');
				if (ptr != NULL) {
					*ptr = '_'; strcat(a, ptr);
				}
				else {
					strcat(a, fname);
				}
			}
		}

		fputs(fname, in);
	}

	fclose(file);
	fclose(in);


	getchar();
	system("pause");
	return 1;
}

