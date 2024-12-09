#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int deg[110000];
int UF[110000];
int FIND(int a){
	if(UF[a]<0)return a;
	return UF[a]=FIND(UF[a]);
}
void UNION(int a,int b){
	a=FIND(a);b=FIND(b);if(a==b)return;
	UF[a]+=UF[b];UF[b]=a;
}
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b),a){
		for(int i=0;i<a;i++)UF[i]=-1;
		for(int i=0;i<a;i++)deg[i]=0;
		for(int i=0;i<b;i++){
			int p,q;
			scanf("%d%d",&p,&q);
			p--;q--;
			UNION(p,q);
			deg[p]++;
			deg[q]++;
		}
		bool ok=true;
		for(int i=0;i<a;i++)if(deg[i]>2)ok=false;
		
		int rk=0;
		for(int i=0;i<a;i++)if(UF[i]<0)rk++;
		if(rk!=a-b)ok=false;
		if(ok)printf("yes\n");
		else printf("no\n");
	}
}