#include <stdio.h>
#include <locale.h>

void zadanie1() {
	char c = '!';
	int i = 2;
	float f = 3.14f;
	double d = 5e-12;

	printf("%c %i %f %d \n", c, i, f, d);

	printf("input char >");
	scanf("%c", &c);
	printf("%c %d %X \n", c, c, c); //Задача 1б.Выведите шестнадцатеричный и десятичный код введенного символа

	printf("input int >");
	scanf("%i", &i);
	printf("%i %f\n", i, (1 / (float)i)); //Задача 1в. Выведите десятичное число, соотвествующее 1/i

	printf("input float >");
	scanf("%f", &f);
	printf("%f %i %f\n", f, (int)f, f - (int)f); //Задача 1а.Выведите отдельно целую и дробную часть введенного вещественного числа.

	printf("input double >");
	scanf("%d", &d);
	printf("%d \n", d);
}

void zadanie2() {
	int a = 11, b = 3;

	printf("%i %f %f \n", ((int)a/(int)b), ((float)a/(float)b), ((double)a/(double)b));

}

void zadanie3() {
	int n; puts("Ваше 3-х знач. число");
	scanf("%i", &n);
	printf("Последняя цифра %d, первая - %d, сумма цифра %d", n % 10, n / 100, 	((n % 10) + (n / 100) + ((n % 100) / 10)));
	printf("\nЧисло наоборот: %d%d%d", n % 10, ((n % 100) / 10), n / 100);
}

void main()
{
	setlocale(LC_ALL, "ru-RU");
	zadanie3();
}
