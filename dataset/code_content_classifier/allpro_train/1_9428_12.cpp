#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int go[110];
int c[110];
int d[110];
int e[110];
int ret[110];
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b),a){
		for(int i=0;i<b;i++)scanf("%d",c+i);
		for(int i=0;i<a;i++)d[i]=e[i]=-1;
		int t=0;
		int sz=0;
		int num=0;
		while(sz<b){
			for(int i=0;i<a;i++){
				if(~d[i]){
					if(go[d[i]]<=t){
						ret[sz++]=d[i];
						d[i]=-1;
						if(~e[i]&&go[e[i]]<=t){
							ret[sz++]=e[i];
							e[i]=-1;
						}else {d[i]=e[i];e[i]=-1;}
					}
				}
			}
			for(int i=num;i<=min(t/10,b-1);i++){
				bool ok=false;
				for(int j=0;j<a;j++){
					if(!~d[j]){
						go[i]=t+c[i];
						d[j]=i;
						num++;
						ok=true;break;
					}
				}
				if(ok)continue;
				int at=-1;
				int sc=88888888;
				for(int j=0;j<a;j++){
					if(!~e[j]&&go[d[j]]>=t+c[i]&&sc>go[d[j]]-(t+c[i])){
						at=j;sc=go[d[j]]-(t+c[i]);
					}
				}
				if(~at){
					go[i]=t+c[i];
					e[at]=d[at];
					d[at]=i;
					num++;
					continue;
				}
				for(int j=0;j<a;j++){
					if(!~e[j]&&sc>t+c[i]-go[d[j]]){
						at=j;sc=t+c[i]-go[d[j]];
					}
				}
				if(~at){
					go[i]=t+c[i];e[at]=d[at];d[at]=i;num++;continue;
				}
				
				break;
			}
			t++;
		}
		for(int i=0;i<b;i++){
			if(i)printf(" ");
			printf("%d",ret[i]+1);
		}
		printf("\n");
	}
}