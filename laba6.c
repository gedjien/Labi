#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <stdbool.h>

void zadanie1() {
	int years;
	puts("Vvedite god");
	scanf("%i", &years);
	if (((years % 4 == 0) && (years % 100 != 0)) || (years % 400 == 0))
		printf("Год %i високосный\n", years);
	else
		printf("Год %i не високосный\n", years);
}

void zadanie2() {
	double x = 8;
	printf("%lf", x >= 8 ? (pow(-x, 2) + x - 9) : (1 / (pow(x, 4) - 6)));
}


void zadanie3() {
	/*10. Написать программу, которая по введенным датам рождения
	определяет старшего по возрасту(формат ввода : Mila 12 06 2001 / n Nasty 11
		12 2000 вывод : Nasty*/
	char n1[] = "Mila", n2[] = "Nasty";
	int d1=12, d2=11, m1 = 06, m2 = 12, y1 = 2001, y2 = 2000;

	if (y1 != y2) {
		switch (y1 > y2)
		{
		case (1):
			printf("%s старше\n", n2);
			break;
		case (0):
			printf("%s старше\n", n1);
			break;
		default:
			printf("\n");
		}
	}
	else
		if (m1 != m2) {
			switch (m1 > m2)
			{
			case (1):
				printf("%s старше\n", n2);
				break;
			case (0):
				printf("%s старше\n", n1);
				break;
			default:
				printf("\n");
			}
		}
		else
			if (d1 != d2) {
				switch (d1 > d2)
				{
				case (1):
					printf("%s старше\n", n2);
					break;
				case (0):
					printf("%s старше\n", n1);
					break;
				default:
					printf("\n");
				}
			}
			else
				printf("Родились в один день");
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	zadanie3();
}
