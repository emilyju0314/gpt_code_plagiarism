#include<stdio.h>
int main() {
	int H, W, X, Y;
	scanf("%d %d %d %d", &H, &W, &X, &Y);
	if (H*W%2==1 && (X + Y) % 2 == 1) {
		printf("No\n");
	}
	if (H*W%2 == 0 || (X + Y) % 2 == 0) {
		printf("Yes\n");
	}
	return 0;
}
