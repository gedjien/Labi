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
	printf("%c %d %X \n", c, c, c); //������ 1�.�������� ����������������� � ���������� ��� ���������� �������

	printf("input int >");
	scanf("%i", &i);
	printf("%i %f\n", i, (1 / (float)i)); //������ 1�. �������� ���������� �����, �������������� 1/i

	printf("input float >");
	scanf("%f", &f);
	printf("%f %i %f\n", f, (int)f, f - (int)f); //������ 1�.�������� �������� ����� � ������� ����� ���������� ������������� �����.

	printf("input double >");
	scanf("%d", &d);
	printf("%d \n", d);
}

void zadanie2() {
	int a = 11, b = 3;

	printf("%i %f %f \n", ((int)a/(int)b), ((float)a/(float)b), ((double)a/(double)b));

}

void zadanie3() {
	int n; puts("���� 3-� ����. �����");
	scanf("%i", &n);
	printf("��������� ����� %d, ������ - %d, ����� ����� %d", n % 10, n / 100, 	((n % 10) + (n / 100) + ((n % 100) / 10)));
	printf("\n����� ��������: %d%d%d", n % 10, ((n % 100) / 10), n / 100);
}

void main()
{
	setlocale(LC_ALL, "ru-RU");
	zadanie3();
}
