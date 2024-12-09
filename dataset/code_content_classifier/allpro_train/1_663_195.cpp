#include<stdio.h>
int main(void){
	int n,i;
	long long ans=0;
	int a[200000];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++){
		if(a[i+1]<a[i]){
			ans+=a[i]-a[i+1];
			a[i+1]=a[i];
		}
	}
	printf("%lld",ans);
	return 0;
}