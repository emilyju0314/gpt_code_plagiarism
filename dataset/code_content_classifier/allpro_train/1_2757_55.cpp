#include<stdio.h>
int n,i,a[300001],b[300001],c[300001],j,max;
int main(void)
{
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<300000;i++) b[i]=0,c[i]=0;
	max=1;
	//printf("%d\n",n);
	for(i=0;i<n;i++){
		max--;
		b[i]=1;
		if(max<=a[i]/10) max=a[i]/10;
		if(max==0) break;
	}
	//printf("BB\n");
	if(b[n-1]==1){
		for(i=n-1;i>=0;i--){
			max--;
			c[i]=1;
			if(max<=a[i]/10) max=a[i]/10;
			if(max==0) break;
		}
	}
	//printf("cc\n");
	if(c[0]==1) printf("yes\n");
	else printf("no\n");
	return 0;
}
