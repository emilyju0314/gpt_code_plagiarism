#include<cstdio>
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int time = (a + b) % 24;
	printf("%d\n",time);
	return 0;
}
