#include <locale.h>
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>

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

	file = fopen("Text.txt", "r"); //открытие файла

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

	fclose(file);

	int a[5][5];

	for (int q = 0; q < n; q++) {
		for (int s = 0; s < n; s++) {
			if (igrok[q].qty[n - s -1] == 0) {

				a[q][0] = n-s-1;
				a[q][1] = n - s - 1;

			}
		}
	}

	int temp = -1;
	char temp_name[20];

		for (int q = 0; q < n; q++) {
			for (int s = 0; s < n; s++) {
				if (a[s][0] == q) {

					temp = a[q][0];

					a[q][0] = a[s][0];

					a[s][0] = temp;

					for (int w = 0; w > n; w++) {

					}

					strcpy(temp_name, igrok[q].name);
					strcpy(igrok[q].name, igrok[s].name);
					strcpy(igrok[s].name, temp_name);
					
					printf("%s",igrok[q].name);
					for (int w = 0; w < n; w++) {
						printf(" %i", a[q][w]);
					}
					printf("\n");
					break;
				}
			}


	}	
		

		int temp_msv[5][5];
		int temp_mmsv[5][2];

		for (int x = 0; x < n; x++) {
			for (int w = 0; w < n; w++) {
				temp_msv[x][w] = igrok[a[x][1]].qty[w];
				temp_mmsv[x][0] = a[x][0];
				temp_mmsv[x][1] = a[x][1];
			}
		}

		for (int q = 0; q < n; q++) {

				for (int s = 0; s < 2; s++) {
					printf("%i ", temp_mmsv[q][s]);


			}
			printf("\n");

		}
		printf("\n");
		
		for (int x = 0; x < n; x++) {
			for (int w = 0; w < n; w++) {
				a[temp_mmsv[x][1]][w] = igrok[temp_mmsv[x][0]].qty[w];
				//a[temp_mmsv[x][0]][w] = temp_msv[x][w];
			}
		}
		printf("\n");

		for (int q = 0; q < n; q++) {
			for (int s = 0; s < n; s++) {
			//	printf("%s", igrok[q].name);

				for (int w = 0; s < n; s++) {
					printf("%i ", temp_msv[q][s]);
				}

				break;
			}
			printf("\n");

		}
		printf("\n");

		for (int q = 0; q < n; q++) {
			for (int s = 0; s < n; s++) {
					printf("%s", igrok[q].name);

				for (int w = 0; s < n; s++) {
					printf(" %i", a[q][s]);
				}

				break;
			}
			printf("\n");

		}

		file = fopen("Text_Sorted.txt", "w");
		fprintf(file, "%d\n", n);

		for (int q = 0; q < n; q++) {
			fprintf(file, "%s ", igrok[q].name);
			for (int w = 0; w < n; w++) {
				fprintf(file, "%d ", a[q][w]);
			}
			fprintf(file, "\n");
		}

		fclose(file);


		getchar();

}