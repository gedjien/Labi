#include <stdio.h>
#include <locale.h>
#define D 2.54

void zadanie1() {
	int num, num2;
	puts("������� �����:");
	scanf("%d", &num);
	printf("������� ����� %d\n", num);
	puts("������� ������ �����:");
	scanf("%d", &num2);
	printf("%d �����\n", num2+num);             // �����
	printf("%d �������� �� ��������� ������� ����� �� �������\n", num2 - num);           // ��������
	printf("%d ������������\n", num2*num);             // ������������ 
	printf("%d ������� �� ������� ������� ����� �� ������\n", num2 / num); // �������
	printf("%d ������� �� ������� ������� ����� �� ������\n", num2 % num); // �������
}

void zadanie2() {
	int dym;
	float result;
	puts("������� �����:");
	scanf("%d" , &dym);
	result = D * dym;
	printf("%d ������ � ��� %.1f �� \n", dym, result);
}

void zadanie3() {
	int nm1 = 3, nm2 = 5;
	printf("| a * b | a + b | a - b |\n");
		printf("| %d * %d | %d + %d | %d - %d |\n", nm1, nm2, nm1, nm2, nm1, nm2);
		printf("| %d | %d | %d |", nm1 * nm2, nm1 + nm2, nm1 - nm2);
}

void main()
{
	setlocale(LC_ALL, "ru-RU");
	//zadanie1();
	//zadanie2();
	zadanie3();
}
