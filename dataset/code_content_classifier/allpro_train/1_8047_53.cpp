#include<stdio.h>
#include<algorithm>
using namespace std;
int e[110];
int f[110];
int main(){
	int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=0;i<d;i++)scanf("%d%d",e+i,f+i);
	int at=0;
	int pr=0;
	while(1){
		if(e[at]==0&&f[at]==0){
			break;
		}
		if(e[at]){
			e[at]--;b++;
			pr+=10;
		}else{
			f[at]--;pr+=100;
		}
		if(b>d)break;
		if(pr>=90){
			pr-=90;
			if(pr/10>b)break;
			e[at]+=pr/10;
			b-=pr/10;
			pr=0;
		}
		at=(at+1)%a;
	}
	printf("%d\n",at+1);
}