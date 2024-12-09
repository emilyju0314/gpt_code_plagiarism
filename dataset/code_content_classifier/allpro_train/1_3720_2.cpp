#include<stdio.h>
#include<algorithm>
using namespace std;
double last[1120];
int x[110];
int l[110];
int f[110];
int d[110];
int u[110];
int p[1120];
double q[110];
int v[110];
int main(){
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c),a){
		for(int i=0;i<=c+b+2;i++)p[i]=-1;
		for(int i=0;i<a;i++){
			scanf("%d%d%d%d%d",x+i,l+i,f+i,d+i,u+i);
			if(!u[i]){
				swap(f[i],d[i]);
			}
			p[x[i]]=i;
		}
		for(int i=0;i<a;i++)q[i]=-999999999;
		for(int i=0;i<=c+b+2;i++)last[i]=-999999999;
		for(int i=0;i<a;i++){
			if(u[i]==1)q[i]=-(double)l[i]/d[i];
		}
	//	for(int i=0;i<a;i++)printf("%f\n",q[i]);
		for(int i=0;i<b;i++)scanf("%d",v+i);
		for(int i=0;i<b;i++){
		
			double now=0;
			for(int j=0;j<=c+b;j++){
				if(j==0){
					now=(double)i/v[i];
				}else now+=1.0/v[i];
				now=max(now,last[j+1]);
				
				last[j]=now;
				if(~p[j]){
					int at=p[j];
					now=max(now,q[at]+(double)l[at]/f[at]+(double)l[at]/d[at]);
					q[at]=now;
					now+=(double)l[at]/d[at];
				}
			//	printf("%d %d: %f\n",i,j,now);
			}
		}
		printf("%.12f\n",last[c]);
	}
}