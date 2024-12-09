#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int a;
	scanf("%d",&a);
	for(int i=0;i<a;i++){
		long long b,c;
		scanf("%lld%lld",&b,&c);
		if((b+1)/2<c){
			printf("-1\n");continue;
		}
		long long left=0;
		long long right=b+1;
		while(left+1<right){
			long long M=(left+right)/2;
			long long mul=1;
			long long now=b;
			long long num=0;
			while(now>0){
				if(now%2==0)now--;
				long long tmp=now/3;
				if(tmp%2==0)tmp--;
				tmp=(tmp+1)/2;
				long long t=min((M/mul+1)/2,(now+1)/2);
				if(tmp<t)num+=t-tmp;
				now=tmp*2-1;
				mul*=2;
			}
			if(num>=c){
				right=M;
			}else left=M;
		}
		printf("%lld\n",right);
	}
}