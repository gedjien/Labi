#include <stdio.h>
#include <locale.h>
#define D 2.54

void zadanie1() {
	int num, num2;
	puts("Введите число:");
	scanf("%d", &num);
	printf("Введено число %d\n", num);
	puts("Введите второе число:");
	scanf("%d", &num2);
	printf("%d Сумма\n", num2+num);             // Сумма
	printf("%d Разность от вычетания первого числа из второго\n", num2 - num);           // Разность
	printf("%d Произведение\n", num2*num);             // Произведение 
	printf("%d Частное от деления второго числа на первое\n", num2 / num); // Частное
	printf("%d Остаток от деления второго числа на первое\n", num2 % num); // Остаток
}

void zadanie2() {
	int dym;
	float result;
	puts("Введите число:");
	scanf("%d" , &dym);
	result = D * dym;
	printf("%d дюймов – это %.1f см \n", dym, result);
}


int dlina(int m, int count) {
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

void zadanie3() {
	int nm1 = 3, nm2 = 5;

	int count = 0;

	int stlb1 = 7, stlb2 = 5, umn3 = 2, pls3 = 2, mns3 = 2;
	stlb2 += dlina(nm1, count) + dlina(nm2, count);
	umn3 += dlina(nm1*nm2, count);	pls3 += dlina(nm1+nm2, count);	mns3 += dlina(nm1-nm2, count);
	int mm = max(stlb1, max(stlb2, max(umn3, max(pls3, mns3))));

	printf("| a * b "); balans(stlb1, mm);
	printf("| a + b "); balans(stlb1, mm);
	printf("| a - b "); balans(stlb1, mm); printf("|\n");

	printf("| %d * %d ", nm1, nm2);	balans(stlb2, mm);
	printf("| %d + %d ", nm1, nm2); balans(stlb2, mm);
	printf("| %d - %d ", nm1, nm2); balans(stlb2, mm); printf("|\n");

	printf("| %d ", nm1 * nm2); balans(umn3, mm);
	printf("| %d ", nm1 + nm2); balans(pls3, mm);
	printf("| %d ", nm1 - nm2); balans(mns3, mm); printf("|\n");
}

void main()
{
	setlocale(LC_ALL, "ru-RU");
	//zadanie1();
	//zadanie2();
	zadanie3();
}
