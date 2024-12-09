#include<stdio.h>
int main(){
	int n,i = 1,s = 0,a;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		if(i%2==1 && a%2==1)
			s = s + 1;
			i = i + 1;
	}
	printf("%d",s);
} 