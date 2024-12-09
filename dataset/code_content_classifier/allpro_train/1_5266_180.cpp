#include <stdio.h>
int a, b, h;
int main(){
	scanf("%d %d %d", &a, &b, &h);
	printf("%d", (a + b)*h / 2);
	return 0;
}