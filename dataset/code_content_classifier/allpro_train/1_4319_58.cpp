#include<stdio.h>
int main(void)
{
	int a,b,i,j,x[7];
	for(i=0;i<7;i++){
		scanf("%d %d",&a,&b);
		x[i]=a-b;
	}
	for(j=0;j<7;j++){
		printf("%d\n",x[j]);
	}
	return 0;
}