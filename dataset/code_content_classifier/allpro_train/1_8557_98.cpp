#include<stdio.h>
int main(void)
{
	int i,j,n,x=-1000,y=1000000,z[100],a,b,c=0,d=2100000000;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&z[i]);
		if(x<z[i]){
			x=z[i];
		}
		if(y>z[i]){
			y=z[i];
		}
	}
	for(i=y;i<=x;i++){
		c=0;
		for(j=1;j<=n;j++){
			c+=(i-z[j])*(i-z[j]);
		}
		if(d>c){
			d=c;
		}
	}
	printf("%d\n",d);
	return 0;
}