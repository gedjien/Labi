#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <stdbool.h>

#define M_PI 3.14159265358979323846

void zadanie1() {

}

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
	long float w = 0;
	/*for (int q = 1; q <= k; q += 2) {
		w += (pow(x, q) / factorial(q)) * pow((-1), (k - 1));
	}*/
	float t, s;
	int i, n = k;


	t = x;
	s = t;
	for (i = 1; i <= n; i++)
	{
		t *= (-x * x / ((2 * i) * (2 * i + 1)));
		s += t;
	}

	printf("%lf %lf", t, s);

	//printf("%lf", w * (pow(x, ((2 * k) - 1)) / factorial(((2 * k) - 1))));

	return 0;
}



double sin_eps(double x, double eps) {

}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	zadanie1();

	/*float x = 3;
	printf("%lf %lf\n", fa(x), fb(x));

	printf("fa(x)=%lf , fb(x)=%lf \n", fa(x), fb(x));

	printf("произведение %lf разность квадратов %lf удвоенная сумма %lf \n", fa(x) * fb(x), pow(fa(x), 2) - pow(fb(x), 2), 2 * (fa(x) + fb(x)));
	*/

	printf("%lf %lf \n", sin(30), sin((30 * M_PI) / 180));
	printf("%lf %lf \n", sin_n(30, 30), sin((30 * M_PI) / 180));

}
