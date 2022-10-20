#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <stdbool.h>
#include <stdlib.h>


#include <ctype.h>

void prntstr(char *str, int dlina) {
	for (int q = 0; q < dlina; q++){
		if (str[q] == '\0') break;

		if ((str[q] == 'a') | (str[q] == 'а')) printf("@"); //zadanie 2
		else printf("%c", str[q]);}
	printf("\n");
}

int dlinastr(char *str) {
	int count = 0;
	int q = 0;
	while (1){
		if (str[q] != '\0') {
			q++;  
			count++;
		}
		else break;
	}

	return count;
}

int slvcount(char* slv, char* str, int dlslv, int dlina) {
	int scount = 0, count = 0;

	for (int q = 0; q < dlina; q++) {
		if (slv[count] == str[q]) {
			count++;
			if (count == dlslv) {
				scount += 1; count = 0;
			}
		}
		else
			count = 0;
	}


	return scount;
};


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	
	char S1[10] = "123456789";
	char S2[10] = { 'y','e','s','\0' };
	char S3[] = "12345";

	printf(" %c \n %c \n %c \n", *S1, *S2, *S3);
	printf("%i %i %i \n", sizeof(S1), sizeof(S2), sizeof(S3));

	prntstr(S1, sizeof(S1));
	prntstr(S2, sizeof(S2));
	prntstr(S3, sizeof(S3));

	//Задание 1.  Напишите программу, которая запрашивает имя пользователя и здоровается с ним, используя введённое имя.
	
	puts("Приглашение к вводу имени"); 
	char Name[20];
	gets(Name);
	printf("*приветствие*, %s\n", Name);
	

	// Задание 2. Измените первоначальный вариант программы, выводящий строку типа «Привет, Вася!» так, чтобы
	// 10) вместо буквы ‘а’ вставлялся символ @;

	printf("*приветствие*, "); prntstr(Name, sizeof(Name));

	// Задание 3. См. индивидуальный вариант
	// 10. определяет сколько раз в введенной строке встречается слово, заданное пользователем.

	puts("Приглашение к вводу слова");
	char slovo[20];
	gets(slovo);
	puts("Приглашение к вводу строки");
	char stroka[20];
	gets(stroka);


	printf("*совпадений*, %i", slvcount(slovo, stroka, dlinastr(slovo), dlinastr(stroka)));

}



	
