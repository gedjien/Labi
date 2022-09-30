#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <stdbool.h>

void zadanie1() {
	int n = 1, m = 10;
	//scanf("%d %d", &n &m);
	int s = 0, r = 0;

	for (int i = m; i >= n; i--) {
		s += i;
		r += 1;
	}
	printf("выполнено %d раз \n", r);
	printf("результат %d \n", s);

}

void zadanie2() {
	//10. [0.1;2.5]

	double y, M_PI = 3.14;
	float a = 0.1, b = 2.5;
	char z1 = '[', z2 = ']';
	//scanf("%c%f ;%f%c", &z1, &a, &b, &z2);

	/*switch (z1) { //включение или исключение границы интервала
	case ('['):
		break;
	case ('('):
		a += a; // (0.1;1] == [0.2;1]
		break;
	default:
		puts("err\n");
	}
	switch (z2) {
	case (']'):
		break;
	case (')'):
		b -= a; // [0.1;1) == [0.1;0.9]
		break;
	default:
		puts("err\n");
	}
	*/
	for (float i = a; i < b; i += a) {
		y = pow(i, 2) + 2 * M_PI * cos(M_PI) * i;
		printf("%.1f %lf \n", i, y);
	}
}


void zadanie3() {
	float x = 2.06, y = 0;
	// esli x == 63 ili 64 to == 0
	long double sum1 = 1, sum2 = 1;

	for (int i = 1; i < 64; i+=2){
		y = x - i;
		sum1 *= y;
		printf("x - %i | %.2f - %i = %f | %llf\n", i, x, i, y, sum1);
		y = 0;
	}
	for (int i = 2; i < 65; i += 2) {
		y = x - i;
		sum2 *= y;
		printf("x - %i | %.2f - %i = %f | %llf\n", i, x, i, y, sum2);
		y = 0;
	}
	printf("%llf", sum1 / sum2);
}


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	zadanie3();

}
