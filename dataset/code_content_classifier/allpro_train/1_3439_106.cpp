#include <stdio.h>

/* 特にコメントはありません */
int main(void){
	long long H, i, s = 0;
	
	scanf("%lld", &H);
	
	for (i = 2; H /= 2; i <<= 1);
	
	printf("%lld\n", i - 1);
}
