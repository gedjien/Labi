#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <stdbool.h>

#define N 100
#define M_PI 3.14

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

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	float A[N];

	/*for (int i = 0; i < N; i++) {
		float temp;
		printf("a[%d] = ", i + 1);	scanf("%f", &temp);
		A[i] = temp;
	}*/

	double y;
	float a = 0.1, b = 2.5;
	char z1 = '[', z2 = ']';

	int cnt = 0;
	for (int q = 0; cnt != N; q++) {
		for (float i = a; i < b; i += a) {
			cnt += 1;
			A[cnt-1] = pow(i, 2) + 2 * M_PI * cos(M_PI) * i;
			//printf("%i %.1f %lf \n", cnt, i, A[cnt-1]);
		}
	}

	printf("| индекс | исходное значение | новое значение \n");

	int count = 0, stlb1_1 = 8, stlb2_1 = 19, stlb1 = 5, stlb2 = 2;

	int sm = 0, smpl = 0, smotrc = 0, countpl = 0, countotrc = 0;
	for (int i = 0; i < N; i++) {
		stlb1 = 5; stlb2 = 2;
		printf("| a[%d] ", i); stlb1 += dlina(i, count); balans(stlb1, stlb1_1);
		printf("| %.1lf ", A[i]); stlb2 += dlina(A[i], count)+2; balans((A[i] < 0 && A[i] > -1) ? stlb2+1 : stlb2, stlb2_1);
		printf("| %.1lf ", round(A[i])); printf("\n");
		A[i] = round(A[i]);
		sm += round(A[i]);
		if (round(A[i]) < 0) {
			countotrc += 1;
			smotrc += round(A[i]);
		}
		else {
			countpl += 1;
			smpl += round(A[i]);
		}

	}

	printf("Среднее арифметическое %.1f\n\nОтрицательных %i \\ Положительных %i \n\nСумма отрицательных %i \\ Сумма положительных %i\n\n", (float)sm / N, countotrc, countpl, smotrc, smpl);

	//zadanie3

	int minI = 0, minZN = A[0], sumPM = 0;
	for (int w = 1; w < N; w++) {
		if (fabs(A[w]) < (float)abs(minZN)) { minZN = (int)fabs(A[w]); minI = w; sumPM = 0; }
		sumPM += A[w];
	}
	printf("%i %i %i", minI, minZN, sumPM);
}
