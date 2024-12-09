#include<cstdio>
int main(){
	int n,i,t;
	scanf("%d",&n);
	if(n<3||n==(n&-n)){
		puts("No");
		return 0;
	}
	puts("Yes");
	printf("%d %d\n%d %d\n%d 1\n1 2\n2 3\n",1+n,2+n,2+n,3+n,3+n);
	for(i=4;i<n;i+=2)printf("1 %d\n%d %d\n1 %d\n%d %d\n",i,i,i+1,i+1+n,i+1+n,i+n);
	if(!(n&1)){
		t=n&-n;
		printf("%d %d\n%d %d\n",t,n,(n^t^1)+n,n<<1);
	}
	return 0;
}