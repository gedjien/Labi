#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define N 10

struct point {
	float x;
	float y;
	char name;
};

typedef struct point Point;

void put_point(Point z) {
	printf("point %c (%.1f, %.1f)\n", z.name, z.x, z.y);
}

float dist(Point z, Point w) {
	return sqrt(pow((w.x - z.x), 2) + pow((w.y - z.y), 2));
}

Point sr_otr(Point z, Point w) {
	Point sr_otrezka;
	sr_otrezka.name = 'M';
	sr_otrezka.x = ((z.x + w.x) / 2);
	sr_otrezka.y = ((z.y + w.y) / 2);

	return sr_otrezka;
}


void main()
{
	setlocale(LC_ALL, "RUS");

	//Задание 1.  Напишите программу, работающую с точками на плоскости
	//1. Реализуйте программу работы со структурой, содержащей запись о координатной точке
	Point b, a;
	a = (Point) { 1.f, 2.f, 'A' };
	b.name = 'B'; b.x = 5; b.y = -3;

	printf("point %c (%.1f, %.1f)\n", b.name, b.x, b.y);
	put_point(a); //2. Реализуйте отображение точки в отдельной функции:

	printf("%f", dist(a, b)); //3. Добавьте функцию вычисления  декартова расстояния между двумя точками.
	put_point(sr_otr(a, b)); //4. Добавьте функцию получения новой точки - середины отрезка между двумя точками. 



	//Задание 2. Напишите программу, которая выводит на экран текущее время.
	struct tm {
		int tm_sec;     /* секунды - [0,59] */
		int tm_min;     /* минуты - [0,59] */
		int tm_hour;    /* часы - [0,23] */
		int tm_mday;    /* день - [1,31] */
		int tm_mon;     /* месяц - [0,11] */
		int tm_year;    /* год от 1900 */
		int tm_wday;    /* день недели с воскресенья - [0,6] */
		int tm_yday;    /* номер дня с 1 января - [0,365] */
		int tm_isdst;   /* флаг летнего времени устанавливается >0, если <=0, то информация недоступна*/
	};

	struct tm *mytime;
	time_t t;
	t = time(NULL);
	mytime = localtime(&t);
	printf("Московское время %02d:%02d:%02d \n",
	mytime->tm_hour, mytime->tm_min, mytime->tm_sec );

	//Задание 2.2 Добавьте вывод следующей информации :
	//1. День недели(словами)

	char dayname[13];
	switch (mytime->tm_wday) {
	case 0:
		printf("Воскресенье");
		strcpy(dayname, "Воскресенье");
		break;
	case 1:
		printf("Понедельник");
		//strcpy(dayname, "Понедельник");
		break;
	case 2:
		printf("Вторник");
		//strcpy(dayname, "Вторник");

		break;
	case 3:
		printf("Среда");	
		//strcpy(dayname, "Среда");
		break;
	case 4:
		printf("Четверг");
		//strcpy(dayname, "Четверг");
		break;
	case 5:
		printf("Пятница");
		//strcpy(dayname, "Пятница");
		break;
	case 6:
		printf("Суббота");
		//strcpy(dayname, "Суббота");
		break;
	default:
		printf("err");
	}printf("\n");

	//Задание 2.3 Организуйте вывод на экран так, чтобы сообщения размещались точно в центре строки экрана (80 символов). 
	//Для подготовки строки используйте функцию sprintf(). 
	//Свободное пространство заполните символами ‘*’ и стилизуйте  вывод в виде прямоугольного окна (10 символов).

	for (int x = 0; x < 10 / 2; x++) {
		for (int q = 0; q < 80; q++) {
			printf("*");
		}
		printf("\n");
	}

	for (int q = 0; q < (80 / 2 - (int)ceil((float)strlen(dayname)/2)); q++)
		printf("*");
	printf("%s", dayname);
	for (int q = 0; q < (80 / 2 - (int)floor((float)strlen(dayname)/2)); q++)
		printf("*");
	printf("\n");

	for (int x = 0; x < 10 / 2; x++) {
		for (int q = 0; q < 80; q++) {
			printf("*");
		}
		printf("\n");
	}

	//Задание 3. Реализуйте создание структуры, заполнение полей и вывод на экран. (Создание массива структур в след. работе)

	/*Вариант 2. Запись «Поезд»:
	No поезда
	Пункт и время прибытия
	Пункт и время отбытия
	Вывести все сведения о поездах, время пребывания в пути
	которых превышает 7 часов 20 минут.*/

	struct poezd{
		int numb;
		char *punkt_otbit;
		int hour_otbit;
		int min_otbit;
		char *punkt_pribit;
		int hour_pribit;
		int min_pribit;
	};

	struct poezd aPoezd[N];
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		aPoezd[i].numb = i + 1;
		aPoezd[i].punkt_otbit = "msc";
		aPoezd[i].hour_otbit = 0 + rand()%23;
		aPoezd[i].min_otbit = 0 + rand()%59;
		aPoezd[i].punkt_pribit = "rmn";
		aPoezd[i].hour_pribit = 0 + rand() % 23;
		aPoezd[i].min_pribit = 0 + rand() % 59;
	}


	printf("Номер | Пункт отбытия | Время отбытия | Пункт прибытия | Время прибытия |\n");
	for (int i = 0; i < N; i++) {
		if ((aPoezd[i].hour_pribit * 60 + aPoezd[i].min_pribit) - (aPoezd[i].hour_otbit * 60 + aPoezd[i].min_otbit) > 440){
		printf("%5i | %13s | %5i:%-7i | %14s | %5i:%-8i |  \n", aPoezd[i].numb, aPoezd[i].punkt_otbit, aPoezd[i].hour_otbit, aPoezd[i].min_otbit, aPoezd[i].punkt_pribit, aPoezd[i].hour_pribit, aPoezd[i].min_pribit);
		}
	}

	system("pause");
}

