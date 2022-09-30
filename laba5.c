#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <stdbool.h>

#define M_PI 3.14159265358979323846


void zadanie1() {
	float gr;
	scanf("%f", &gr);
	printf("%.6f", sin((gr * M_PI) / 180));
}

void zadanie2(double *b, double *a, double *y) {
	double t = 0.3, x = 5.2;
	*b = ((x * pow(t, 2)) + sqrt(x));

	*a = log10(fabs(((t*x) + pow(t, 2))));

	*y = log(((pow(*a, 2)) / (*a + *b)));

	printf("%.2lf\n", *y);
}

void zadanie3(double a, double b, double y) {
	int A = a, B = b, C = y;
	
	/*
	if ((A % 2 == 0 & B % 2 != 0) | (A % 2 != 0 & B % 2 == 0)) {  // только одно из чисел А и В четное
		bool usl = 0;
		if ((A % 3 == 0) & (B % 3 == 0) & (C % 3 == 0)) { // каждое из чисел А,В,С кратно трем
			usl = 1;
		}
	printf("Условие выполнено (1 - да, 0 - нет) %i\n", usl);
	}*/

	printf("Условие выполнено (1 - да, 0 - нет) %i\n", (((A % 2 == 0 & B % 2 != 0) | (A % 2 != 0 & B % 2 == 0)) & ((A % 3 == 0) & (B % 3 == 0) & (C % 3 == 0))));
}

void zadanie4() {
	double x = 3.981 * pow(10, -2);
	double y = -1.625 * pow(10, 3);
	double z = 0.512;
	double a;
	a = pow(2, -x) * sqrt((x + (pow(fabs(y), 1/4.f)))) * pow((exp((x-1) / sin(z))), 1/3.f);
	printf("%.5lf\n", a);
	a = (pow(2, (-x))) * (pow((x + (pow((fabs(y)), 1/4.f))), 1/2.f)) * (pow((exp(((x-1) / sin(z)))), 1/3.f));
	printf("%.5lf\n", a);

}


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//zadanie1();

	//double a, b, y;
	//zadanie2(&b, &a, &y);

	//zadanie3(a, b, y);
	zadanie4();
}
