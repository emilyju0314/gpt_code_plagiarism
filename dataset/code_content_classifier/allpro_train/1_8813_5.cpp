#include<cstdio>
int main(){
	int n,k=1;
	scanf("%d",&n);
	while(2*k<=n){
		k*=2;
	}
	printf("%d",k);
}
