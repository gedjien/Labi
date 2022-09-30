#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <stdbool.h>

void zadanie1() {
	char c;
	printf("Введите символ: ");
	scanf("%c", &c);
	switch (c >= '0' && c <= '9')
	{
	case 1:
		puts("Введено число.\n");
		break;
	case 0:
		puts("Введен символ.\n");
		break;
	default:
		printf("Неизвестный символ - %c\n", c);
	}
}


void zadanie2() {
	float x, y;
	char c;

	scanf("%f%c%f", &x, &c, &y);
	switch (c)
	{
	case ('+'):
		printf("%f", x + y);
		break;
	case ('-'):
		printf("%f", x - y);
		break;
	case ('/'):
		printf("%f", x / y);
		break;
	case ('*'):
		printf("%f", x * y);
		break;
	case ('^'): // vozvedenie v stepen'
		printf("%lf", pow(x, y));
		break;
	default:
		printf("err");
	}
}


void zadanie3() {
	/* Составить программу, которая для заданного римскими цифрами года
выводит его обычное значение (XX = 2020)*/
	/* XI   = 2011
	   VII  = 2007
	   XVII = 2017 i t.d */

	char ye[] = "XVII";
	printf("%i", sizeof(ye));


	int god = 2000;
	for (int io = 0; io < sizeof(ye)-1; io++) {
		printf("%c \n", ye[io]);
		switch (ye[io])
		{
		case 'I':
			god += 1;
			break;
		case 'V':
			god += 5;
			break;
		case 'X':
			god += 10;
			break;
		case 'L':
			god += 50;
			break;
		default:
			printf("err \n");
		}
		printf("%i \n", god);
	}

}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	zadanie3();

}
