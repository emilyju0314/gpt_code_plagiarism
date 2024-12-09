#include<stdio.h>
int main(){
	int a,b,k;
	scanf("%d%d%d", &k,&a,&b);
	
	if((b/k)*k >b || (b/k)*k <a){
		printf("NG");
	} else {
		printf("OK");
	}
	
	return 0;
}