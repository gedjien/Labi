#include <locale.h>
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>

void clrscr()
{
	system("@cls||clear");
}

//символов в строке, макс в столбце, с учетом пробелов
void probeli(int probelov, int vstlb)
{
	for (int x = 0; x < vstlb - probelov; x++)
		printf(" ");
}

//
void probeli_2(int probelov) {
	for (int x = 0; x < probelov; x++)
		printf(" ");
}

//максимальное в массиве
int max_range(int i, int msv[]) {
	int max_r = 0;
	for (int q = 0; q < i; q++) {
		if (msv[q] > max_r) max_r = msv[q];
	}

	return max_r;
}

//счет количества цифр в числе
int find_stlb_dln(int x) {
	int dlina = 0;

	if (x < 0) {
		return find_stlb_dln(abs(x)) + 1;		
	}

	if (x == 0) return 1;

	while (x > 0) {
		x /= 10;
		dlina += 1;
	}

	return dlina;
}

void main() {

	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	setlocale(LC_ALL, "RUS");

	FILE *file;
	struct player {
		char name[20];
		unsigned qty[10];
	};
	struct player igrok[10];
	char i = 0;

	file = fopen("fscanf.txt", "r"); //открытие файла

	int n = 1, m = 1;

	fscanf(file, "%i", &n); // чтение размера массива

	m = n;


	while (fscanf(file, "%s%u%u%u%u%u%u%u%u%u%u",
		igrok[i].name, &(igrok[i].qty[0]),
		&(igrok[i].qty[1]), &(igrok[i].qty[2]), &(igrok[i].qty[3]), &(igrok[i].qty[4]),
		&(igrok[i].qty[5]), &(igrok[i].qty[6]), &(igrok[i].qty[7]), &(igrok[i].qty[8]), &(igrok[i].qty[9])) != EOF) {

		printf("%s %u %u %u %u %u %u %u %u %u %u\n", igrok[i].name,
			igrok[i].qty[0], igrok[i].qty[1], igrok[i].qty[2], igrok[i].qty[3], igrok[i].qty[4],
			igrok[i].qty[5], igrok[i].qty[6], igrok[i].qty[7], igrok[i].qty[8], igrok[i].qty[9]);
		i++;
	}

	int *a;  // указатель на массив
	a = (int*)malloc(n*m * sizeof(int));

	//определение динамического массива данными из файла

	for (int i = 0; i < n; i++)  // цикл по строкам
	{
		for (int j = 0; j < m; j++)  // цикл по столбцам
		{
			*(a + i * m + j) = igrok[i].qty[j];
		}
	}

	//вывод динамического массива
	printf("\nВывод значений динамического массива\n");
	for (int i = 0; i < n; i++)  // цикл по строкам
	{
		for (int j = 0; j < m; j++)  // цикл по столбцам
		{
			printf("%2d ", *(a + i * m + j)); // 2 знакмест под элемент массива
		}
		printf("\n");
	}





	int *b;  // указатель на транспонированный массив
	b = (int*)malloc(n*m * sizeof(int));

	for (int i = 0; i < n; i++)// Транспонируем
		for (int j = 0; j < m; j++)
			*(b + j * m + i) = *(a + i * m + j);

	//вывод транспонированного динамического массива
	printf("\nВывод значений транспонированного динамического массива\n");
	for (int i = 0; i < n; i++)  // цикл по строкам
	{
		for (int j = 0; j < m; j++)  // цикл по столбцам
		{
			printf("%2d ", *(b + i * m + j)); // 2 знакмест под элемент массива
		}
		printf("\n");
	}

	int *pobed = (int*)malloc(n*m * sizeof(int));
	//счет количества побед
	printf("\nКоличество побед\n");
	for (int i = 0; i < n; i++)  // цикл по строкам
	{
		int sm_pobed = 0;
		for (int j = 0; j < m; j++)  // цикл по столбцам
		{
			if (*(a + i * m + j) > *(b + i * m + j)) sm_pobed += 1;
		}
		pobed[i] = sm_pobed;
		printf("%i ", pobed[i]); // вывод побед
		printf("\n");
	}



	int *mesto = (int*)malloc(n * sizeof(int));
	//вычисление занятого места
	printf("\nЗанятое место\n");
	for (int x = 0; x < n; x++) {
		mesto[x] = 0;
		for (int s = 0; s < n; s++) {
			if (pobed[x] > pobed[s]) { mesto[x] += 1; }
		}
		mesto[x] = n - mesto[x];
		printf("%i ", mesto[x]); // вывод места
		printf("\n");
	}




	//определенние длинны имён для построения таблицы
	int *range = (int*)malloc(n * sizeof(int));

	for (int q = 0; q < n; q++) {
		range[q] = 0;
		for (int x = 0; x < 100; x++) {
			if (igrok[q].name[x] == '\0') { break; }
			range[q] += 1;
		}
	};

	printf("\n%i\n", max_range(n, range)); //макс символов в числе

	printf("\nКол-во символов в именах\n");
	for (int x = 0; x < n; x++) {
		printf("%s = %i symb\n", igrok[x].name, range[x]);
	}

	int sortirovka = 0;
	int last_choose = 0;

	while (1) {
	printf("Пункты меню \n1. Вывод таблицы \n2. Вывод списка \n3. Сортировка по количеству побед (по возрастанию/убыванию)\n4. Выход\n");
	
	int menu = 0;
	printf("Выбор пункта: ");
	scanf("%i", &menu);
	if (menu == 1 | menu == 2) { last_choose = menu; }
	switch (menu) {
	case 1:
		//
	case1:
		clrscr();
		if (sortirovka == 0) {
			printf("Вывести таблицу (Сорт. по убыванию)\n");
			printf("Участники "); //10 символов в статич слове
			probeli(10, max(10, max_range(n, range)));

			printf("|"); //выравнивание 1 столбца
			for (int q = 0; q < n; q++) {

				printf(" %s", igrok[q].name);

				//исключ, если имя короче 4 символов
				if (range[q] < 4) {
					for (int f = 0; f < 4 - range[q]; f++)
						printf(" ");
				}

				printf(" |");//столбцы с игроками

			}printf(" Побед |"); printf(" Место |"); printf("\n"); //шапка
			for (int x = 0; x < n; x++) { //уникальные строки
				printf("%s", igrok[x].name);
				probeli(range[x], max(10, max_range(range[x], range)));

				printf("|");//имя участника

				//счёт
				for (int q = 0; q < n; q++) {
					int o = find_stlb_dln(*(a + x * m + q));
					int u = find_stlb_dln(*(b + x * m + q));

					//в случае, если столбец игрока пересекается с своей же строкой
					if (*(a + x * m + q) == 0 & *(b + x * m + q) == 0) {
						// если имя короче 4 символов
						if (range[q] < 4) {
							for (int f = 0; f < 4 - range[q]; f++)
								printf(" ");
						}
						probeli_2(range[q] + 2); printf("|"); continue;
					}

					//вывод значений таблицы с исключениями и балансировкой пробелов
					if ((range[q] + 2) - (o + u + 3) == 0) {
						printf(" %i:%i ", *(a + x * m + q), *(b + x * m + q)); printf("|"); continue;
					}
					if ((range[q] + 2) - (o + u + 3) == 1) {
						printf(" %i:%i  ", *(a + x * m + q), *(b + x * m + q)); printf("|"); continue;
					}

					if ((range[q] + 2) - (o + u + 3) == 3) {
						printf("  %i:%i   ", *(a + x * m + q), *(b + x * m + q)); printf("|"); continue;
					}

					if ((range[q] + 2) - (o + u + 3) % 2 != 0) {

						probeli_2(((range[q] + 2) - (o + u + 3)) / 2);
						printf(" %i:%i ", *(a + x * m + q), *(b + x * m + q));
						probeli_2(((range[q] + 2) - (o + u + 3)) / 2);

					}


					printf("|");
				}

				printf("   %i   |   %i   |\n", pobed[x], mesto[x]);
			}
		}
		//
		//
		//
		else {
			printf("Вывести таблицу (Сорт. по возрастанию)\n");
			printf("Участники "); //10 символов в статич слове
			probeli(10, max(10, max_range(n, range)));

			printf("|"); //выравнивание 1 столбца
			for (int q = n - 1; q >= 0; q--) {

				printf(" %s", igrok[q].name);

				//исключ, если имя короче 4 символов
				if (range[q] < 4) {
					for (int f = 0; f < 4 - range[q]; f++)
						printf(" ");
				}

				printf(" |");//столбцы с игроками

			}printf(" Побед |"); printf(" Место |"); printf("\n"); //шапка
			for (int x = n - 1; x >= 0; x--) { //уникальные строки
				printf("%s", igrok[x].name);
				probeli(range[x], max(10, max_range(range[x], range)));

				printf("|");//имя участника

				//счёт
				for (int q = n - 1; q >= 0; q--) {
					int o = find_stlb_dln(*(a + x * m + q));
					int u = find_stlb_dln(*(b + x * m + q));

					//в случае, если столбец игрока пересекается с своей же строкой
					if (*(a + x * m + q) == 0 & *(b + x * m + q) == 0) {
						// если имя короче 4 символов
						if (range[q] < 4) {
							for (int f = 0; f < 4 - range[q]; f++)
								printf(" ");
						}
						probeli_2(range[q] + 2); printf("|"); continue;
					}

					//вывод значений таблицы с исключениями и балансировкой пробелов
					if ((range[q] + 2) - (o + u + 3) == 0) {
						printf(" %i:%i ", *(a + x * m + q), *(b + x * m + q)); printf("|"); continue;
					}
					if ((range[q] + 2) - (o + u + 3) == 1) {
						printf(" %i:%i  ", *(a + x * m + q), *(b + x * m + q)); printf("|"); continue;
					}

					if ((range[q] + 2) - (o + u + 3) == 3) {
						printf("  %i:%i   ", *(a + x * m + q), *(b + x * m + q)); printf("|"); continue;
					}

					if ((range[q] + 2) - (o + u + 3) % 2 != 0) {

						probeli_2(((range[q] + 2) - (o + u + 3)) / 2);
						printf(" %i:%i ", *(a + x * m + q), *(b + x * m + q));
						probeli_2(((range[q] + 2) - (o + u + 3)) / 2);

					}


					printf("|");
				}

				printf("   %i   |   %i   |\n", pobed[x], mesto[x]);
			}
		}
		//
		//
		//

		break;
	case 2:
		case2:
		clrscr();

		int *sumpobed = (int*)malloc(n * sizeof(int));
		int *sumporaj = (int*)malloc(n * sizeof(int));
		int maxssum = 0;

		for (int x = 0; x < n; x++) {
			sumpobed[x] = 0;
			sumporaj[x] = 0;
			for (int q = 0; q < n; q++) {
				sumpobed[x] += *(a + x * m + q);
				sumporaj[x] += *(b + x * m + q);
				if (9 + find_stlb_dln(sumpobed[x] - sumporaj[x]) > maxssum) maxssum = 9 + find_stlb_dln(sumpobed[x] - sumporaj[x]);
			}
		}

		if (sortirovka == 0) {
			printf("Вывести список (Сорт. по убыванию)\n"); //общее количество очков, поражения

			printf("Участники "); //10 символов в статич слове
			probeli(10, max(10, max_range(n, range)));

			printf("| И | В | П |   +/-   "); //выравнивание 1 столбца
			probeli(9, maxssum);
			printf("| Место |"); printf("\n"); //шапка
			for (int x = 0; x < n; x++) { //уникальные строки
				printf("%s", igrok[x].name);
				probeli(range[x], max(10, max_range(range[x], range)));

				printf("|");//имя участника
				//счёт
				printf(" %i | %i | %i |", n - 1, pobed[x], n - pobed[x] - 1); // И | В | П
				printf(" %+i-%i=%i ", sumpobed[x], sumporaj[x], sumpobed[x] - sumporaj[x]); // +/- |
				probeli(9 + find_stlb_dln(sumpobed[x] - sumporaj[x]), maxssum);

				printf("|   %i   |\n", mesto[x]);
			}
		}

		//
		//
		else {
			printf("Вывести список (Сорт. по возрастанию)\n"); //общее количество очков, поражения

			printf("Участники "); //10 символов в статич слове
			probeli(10, max(10, max_range(n, range)));

			printf("| И | В | П |   +/-   "); //выравнивание 1 столбца
			probeli(9, maxssum);
			printf("| Место |"); printf("\n"); //шапка
			for (int x = n - 1; x >= 0; x--) { //уникальные строки
				printf("%s", igrok[x].name);
				probeli(range[x], max(10, max_range(range[x], range)));

				printf("|");//имя участника
				//счёт
				printf(" %i | %i | %i |", n - 1, pobed[x], n - pobed[x] - 1); // И | В | П
				printf(" %+i-%i=%i ", sumpobed[x], sumporaj[x], sumpobed[x] - sumporaj[x]); // +/- |
				probeli(9 + find_stlb_dln(sumpobed[x] - sumporaj[x]), maxssum);

				printf("|   %i   |\n", mesto[x]);
			}
		}
		//
		//

		break;
	case 3:
		if (sortirovka == 0) { sortirovka = 1; printf("Сортировка по убыванию побед\n"); }
		else { sortirovka = 0; printf("Сортировка по возрастанию побед\n"); }

		if (last_choose == 1) { goto case1; }
		else { goto case2; }
		break;
	case 4:
		clrscr();
		printf("Выход\n");
		exit(EXIT_SUCCESS);
	default:
		printf("Неправильный ввод\n");
	}
	//ранжирование поиск по баллам
	}


	free(a);
	free(b);
	free(pobed);
	free(mesto);
	free(range);
}
