#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <stdbool.h>

#define M_PI 3.14159265358979323846

int dlina(int m, int count) {
	if (m == 0) return 1;

	count = 0;
	if (m < 0) count = 1;
	while (m != 0) {
		count++;
		m /= 10;
	}

	return count;
}

void balans(raz, mm) {

	if (raz < mm) {
		int razn = mm - raz;
		for (int q = 0; q < razn; q++) {
			printf(" ");
		}
	}
};

double fa(double x) {

	double y = (x <= 3 ? (pow(x, 2) - (3 * x) + 9) : (1 / (pow(x, 3) + 3)));
	return y;

}

double fb(double x) {

	double y = x * exp(sin(pow(x, 2)));
	return y;

}

factorial(int n)
{
	return (n < 2) ? 1 : n * factorial(n - 1);
}

double sin_n(double x, int N) {
	int k = N;
	float w;
	w = (pow((-1), (k - 1)) * ((pow(x, ((2 * k) - 1))) / ((float)factorial((2 * k) - 1))));
}

double sin_eps(double x, double eps) {
	float n = eps;
	float w;
	w = (pow((-1), n) * pow(x, n)) / (float)factorial(n);
}

float area_square(float a) {
	a = pow(a, 2); return a;
}

void draw_square() {

	printf("Символ: "); 
	char smb; 
	scanf(" %c", &smb);
	printf("Размер стороны: "); 
	float rzm;
	scanf(" %f", &rzm);

	int r = (int)ceil(rzm);
	printf("\n");
	for (int i = 1; i <= r; ++i) {
		for (int i = 1; i <= r; ++i) {
			printf("%c ", smb);
		}
		printf("\n");
	}
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//zadanie1
	float x = 3;
	printf("%lf %lf\n", fa(x), fb(x));
	printf("fa(x)=%lf , fb(x)=%lf \n", fa(x), fb(x));
	printf("произведение %lf разность квадратов %lf удвоенная сумма %lf \n\n", fa(x) * fb(x), pow(fa(x), 2) - pow(fb(x), 2), 2 * (fa(x) + fb(x)));


	//zadanie2
	int count = 0, stlb1 = 15, stlb2 = 11, stlb3 = 11;

	printf("Угол a, градусы ");
	printf("| sin "); balans(0, 6);
	printf("| sin_n "); balans(0, 4);
	printf("| sin_eps \n");

	int dln = 0;

	for (int qt = 0; qt <= 360; qt += 30) {
		dln = dlina(qt, count); balans(dln, stlb1); printf("%i ", qt);
		printf("| %lf ", sin((qt * M_PI) / 180)); if (sin((qt * M_PI) / 180) >= 0) balans(0, 1);
		printf("| %lf ", sin((sin_n(qt, 1) * M_PI) / 180)); if (sin((sin_n(qt, 1) * M_PI) / 180) >= 0) balans(0, 1);
		printf("| %lf \n", sin((-1) * (sin_eps(qt, 1) * M_PI) / 180));
	}

	//zadanie3
	while(1){
	char a;
	printf("\n(1) Рассчитать площадь \n(2) Вывести определение фигуры \n(3) Нарисовать фигуру \n");
	switch (a = getchar()) {
	case ('1'):
		puts("Площадь квадрата"); float arsq = 0; scanf("%f", &arsq);
		printf("%.1f", area_square(arsq));
		break;
	case ('2'):
		printf("Правильный прямоугольник — это прямоугольник, у которого все четыре стороны равны.\n");
		break;
	case ('3'):
		draw_square();
		break;	}
	break;
	}
}
