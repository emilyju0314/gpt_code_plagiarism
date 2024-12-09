#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	if(n<1200)printf("ABC");
	else if(n<2800)printf("ARC");
	else printf("AGC");
	return 0;
}