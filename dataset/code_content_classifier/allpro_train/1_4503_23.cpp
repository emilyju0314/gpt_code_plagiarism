#include<stdio.h>

int main() {
	int input;
	scanf("%d", &input);
	printf("%d:%d:%d\n", input/3600, (input%3600)/60, input%60);
}

