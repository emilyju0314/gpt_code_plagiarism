#include<stdio.h>
long long int t[4000];
int k[4000];
bool sub[4000];
int main(){
	int a;
	while(scanf("%d",&a),a){
		for(int i=0;i<4000;i++){
			t[i]=0;
			k[i]=0;
			sub[i]=false;
		}
		int o=0;
		for(int i=0;i<a;i++){
			int b,c,d;
			
			scanf("%d%d%d",&b,&c,&d);
			t[b-1]+=(long long)c*(long long)d;
			if(!sub[b-1]){
				k[o++]=b-1;
				sub[b-1]=true;
			}
		}
		bool ok=false;
		for(int i=0;i<o;i++){
			if(t[k[i]]>=1000000LL){
				printf("%d\n",k[i]+1);
				ok=true;
			}
		}
		if(!ok)printf("NA\n");
	}
}