#include <stdio.h>
#include <stdlib.h>
int main() {
	int *list;
	int key,BUF,result;
	printf("insert buffer size : ");
	scanf_s("%d", &BUF);
	list = (int*)malloc(sizeof(int) * BUF);
	seq_create(list, BUF);
	seq_print(list,BUF);
	printf("\ninsert key number : ");
	scanf_s("%d", &key);
	result = seq_search(list, BUF, key) + 1;
	printf("%d", result);
}
int seq_print(int list[], int BUF) {
	for (int i = 0; i < BUF; i++) {
		printf("-----");
	}
	printf("\n| ");
	for (int i = 0; i < BUF; i++) {
		printf("%d | ",list[i]);
	}
	printf("\n");
	for (int i = 0; i < BUF; i++) {
			printf("-----");
	}
}
int seq_create(int list[], int BUF) {
	for (int i = 0; i < BUF; i++) {
		list[i] = rand() % 100;
	}
}
int seq_search(int list[],int n, int key) {
	int i;
	for (i = 0; i < n; i++) {
		if (list[i] == key)
			return i;
	}
	return -1;
}
