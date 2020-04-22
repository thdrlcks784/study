#include <stdio.h>
#include <stdlib.h>
int main() {
	int** metrix;
	int raws, cols;
	printf("input raws,cols : ");
	scanf_s("%d %d", &raws, &cols);
	metrix = malloc(sizeof(int) * raws);
	for (int i = 0; i < raws; i++) {
		metrix[i] = malloc(sizeof(int) * cols);
	}
	rand_input_metrix(metrix, raws, cols);
	print_metrix(metrix, raws, cols);
	free_metrix(metrix,raws);
}

int rand_input_metrix(int** metrix, int raws, int cols) {
	for (int i = 0; i < raws; i++) {
		for (int j = 0; j < cols; j++) {
			metrix[i][j] = rand() % 10;
		}
	}
}
int print_metrix(int **metrix, int raws, int cols) {
	for (int i = 0; i < raws; i++) {
		printf("\n|");
		for (int j = 0; j < raws; j++) {
			printf(" %d ", metrix[i][j]);
		}
		printf("|");
	}
}
int free_metrix(int** metrix, int raws) {
	for (int i = 0; i < raws; i++) {
		free(metrix[i]);
	}
	free(metrix);
}
