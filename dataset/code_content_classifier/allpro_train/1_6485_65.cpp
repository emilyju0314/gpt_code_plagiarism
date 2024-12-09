#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b),a){
		int A=0;
		int last=0;
		for(int i=2;i*i<=a;i++){
			if(a%i==0){
				A-=i;
				last=i;
				while(a%i==0)a/=i;
			}
		}
		if(a!=1){
			A-=a;
			last=a;
		}
		A+=last*2;
		int B=0;
		last=0;
		for(int i=2;i*i<=b;i++){
			if(b%i==0){
				B-=i;last=i;while(b%i==0)b/=i;
			}
		}
		if(b!=1){
			B-=b;last=b;
		}
		B+=last*2;
		if(A>B)printf("a\n");else printf("b\n");
	}
}