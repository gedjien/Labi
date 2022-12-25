#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define _USE_MATH_DEFINES

typedef double(*TFun)(double);

double fun1(double);
double fun2(double);
double fun3(double);
void Out_Rez(TFun, double, double, double);
int f_output_file(FILE *file, TFun f, double xn, double xk, double h);
void calculate(double *x, int n);

void main()
{
	setlocale(LC_ALL, "RUS");

	//Задание 1. Разработайте программу табуляции трех заданных функций, состоящую из трех отдельных математических функций и 
	//функции печати таблицы значений, которая принимает в качестве параметра - указатель на выбранную математическую функцию.
	//Задание 2. Дополните программу меню, позволяющее выбирать функции и действия с ними
	//Варианты операций: записать значение выбранной функции в  файл dat.txt с разделителем запятая;
	//Задание 3 (индивидуальное) //Реализовать функцию calculate (TFun prtf, double *x, int n), которая по
	//заданной указателем prtf функции для значений массива х, размера n
	//2. Вычисляет сумму максимального и минимального значений функции.

	int menu;
	double a, b, h; // ниж граница, верх граница, шаг
	printf("1. вычислить значение\n2. табулировать\n3. выполнить операцию(записать значение выбранной функции в файл dat.txt с разделителем запятая;)\n4. выход");
	scanf("%i", &menu);
	
	switch (menu) {
	case 1: {
		int sub_menu;
		printf("Выберите функцию (1-3): ");
		scanf("%i", &sub_menu);
		switch (sub_menu) {
		case 1: {
			puts("Input x:");
			scanf("%lf", &a);
			printf("|x = %5.2lf| y = %8.4lf|\n", a, fun1(a));
			break;
		}
		case 2: {
			puts("Input x:");
			scanf("%lf", &a);
			printf("|x = %5.2lf| y = %8.4lf|\n", a, fun2(a));
			break;
		}
		case 3: {
			puts("Input x:");
			scanf("%lf", &a);
			printf("|x = %5.2lf| y = %8.4lf|\n", a, fun3(a));
			break;
		}
		}
		break;
	}
	case 2: {
		int sub_menu;
		printf("Выберите функцию (1-3): ");
		scanf("%i", &sub_menu);
		switch (sub_menu) {
		case 1: {
			puts("Input a,b,h");
			scanf("%lf%lf%lf", &a, &b, &h);
			Out_Rez(fun1, a, b, h);
			//Out_Rez(fun2, a, b, h);
			//Out_Rez(fun3, a, b, h);
			break;
		}
		case 2: {
			puts("Input a,b,h");
			scanf("%lf%lf%lf", &a, &b, &h);
			//Out_Rez(fun1, a, b, h);
			Out_Rez(fun2, a, b, h);
			//Out_Rez(fun3, a, b, h);
			break;
		}
		case 3: {
			puts("Input a,b,h");
			scanf("%lf%lf%lf", &a, &b, &h);
			//Out_Rez(fun1, a, b, h);
			//Out_Rez(fun2, a, b, h);
			Out_Rez(fun3, a, b, h);
			break;
		}
		}
		break;
	}
	case 3: {
		FILE* output_file;
		char fname_out[20] = "dat.txt";
		if ((output_file = fopen(fname_out, "wt")) == NULL) {
			printf("oshibka otkr faila dlya zapisi");
			return 0;
		}
		int sub_menu;
		printf("Выберите функцию (1-3): ");
		scanf("%i", &sub_menu);
		switch (sub_menu) {
		case 1: {
			puts("Input a,b,h");
			scanf("%lf%lf%lf", &a, &b, &h);
			f_output_file(output_file, fun1, a, b, h);
			break;
		}
		case 2: {
			puts("Input a,b,h");
			scanf("%lf%lf%lf", &a, &b, &h);
			f_output_file(output_file, fun2, a, b, h);
			break;
		}
		case 3: {
			puts("Input a,b,h");
			scanf("%lf%lf%lf", &a, &b, &h);
			f_output_file(output_file, fun3, a, b, h);
			break;
		}
		}
		break;
	}
	case 4: {
		exit(EXIT_SUCCESS);
		break;
	}
	case 5:
		break;
	}
	//getch();

	puts("Input a,b,h");
	scanf("%lf%lf%lf", &a, &b, &h);
	double* msv = (double*)malloc(b * sizeof(double));

	int i = 0;

	for (double x = a; x <= b; x += h) {
		msv[i] = fun1(x);
		printf("|x = %5.2lf| y = %8.4lf|\n", x, fun1(x));
		i++;
	}
	
	for (int q = 0; q < i; q++) {
		printf("%lf\n", msv[q]);
	}

	calculate(msv, i);

	system("pause");
	//return 1;
}

/*----Описание пользовательских функций -----*/

double fun1(double r)
	{
		if (r > 0) {
			puts("\n\t Function - log(fabs(sqrt(x, 3)))");
			return log(fabs(sqrt(r, 3)));
		}
		else
			return 0;
	}

double fun2(double r)
{
	if (r > 1) {
		puts("\n\t Function - sqrt(tan(pow(r,2)-1))");
		return sqrt(fabs(tan(fabs(pow(r, 2) - 1))));
	}
	if (r < 0) {
		puts("\n\t Function - exp(cos(x))");
		return exp(cos(r));
	}
	if (0 <= r <= 1) {
		puts("\n\t Function - -2 * x");
		return -2 * r;
	}
}

double fun3(double r)
{
	puts("\n\t Function - ((r-1)/(r+1)) + ((r/3) * pow(((r - 1) / (r + 1)),3)) + ((r / 5) * pow(((r - 1) / (r + 1)),5)) + ((r / 7) * pow(((r - 1) / (r + 1)),7))");
	return ((r-1)/(r+1)) + ((r/3) * pow(((r - 1) / (r + 1)),3)) + ((r / 5) * pow(((r - 1) / (r + 1)),5)) + ((r / 7) * pow(((r - 1) / (r + 1)),7));
}

/*----Функций вывода результата-------------*/
void Out_Rez(TFun f, double xn, double xk, double h)
{
	for (double x = xn; x <= xk; x += h)
		printf("|x = %5.2lf| y = %8.4lf|\n", x, f(x));
}

int f_output_file(FILE *file, TFun f, double xn, double xk, double h) {
	printf("Сохранение файла");
	for (double x = xn; x <= xk; x += h){
		fprintf(file, "%5.2lf,%8.4lf\n", x, f(x));
		//fprintf(file, "%i %s %i %i %s %i %i\n", aPoezd[i].numb, aPoezd[i].punkt_otbit, aPoezd[i].hour_otbit, aPoezd[i].min_otbit, aPoezd[i].punkt_pribit, aPoezd[i].hour_pribit, aPoezd[i].min_pribit);
	}
}

void calculate(double *x, int n) {
	double min_x = INT_MAX;
	double max_x = INT_MIN;
	for (int w = 0; w <= n; w += 1)
		if (min_x > x[w]) min_x = x[w];
	for (int w = 0; w <= n; w += 1)
		if (max_x < x[w]) max_x = x[w];
	printf("min = %lf max = %lf", min_x, max_x);
}

