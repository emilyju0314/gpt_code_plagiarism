#include<stdio.h>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int c[12][1100];
char in[50];
int h[20];
int dp[1<<12][12];
int g[20][20];
int hv[20];
int main(){
	int a;
	while(scanf("%d",&a),a){
		int sz=0;
		map<string,int>m;
		for(int i=0;i<a;i++){
			for(int j=0;j<1100;j++)c[i][j]=9999999;
		}
		for(int i=0;i<a;i++){
			int p;scanf("%d",&p);
			for(int j=0;j<p;j++){
				int t;
				scanf("%s%d",in,&t);
				string tmp=in;
				int at=0;
				if(!m.count(tmp)){
					at=sz;
					m[tmp]=sz++;
				}else at=m[tmp];
				c[i][at]=min(c[i][at],t);
			}
		}
		int b;scanf("%d",&b);
		bool dame=false;
		for(int i=0;i<b;i++){
			scanf("%s",in);
			string tmp=in;
			if(!m.count(tmp)){dame=true;continue;}
			h[i]=m[tmp];
		}
		int e;scanf("%d",&e);
		for(int i=0;i<=a;i++)for(int j=0;j<=a;j++)g[i][j]=9999999;
		for(int i=0;i<=a;i++)g[i][i]=0;
		for(int i=0;i<e;i++){
			int p,q,r;scanf("%d%d%d",&p,&q,&r);
		//	printf("%d %d %d\n",p,q,r);
			g[p][q]=g[q][p]=min(g[p][q],r);
		}
		if(dame){
			printf("impossible\n");continue;
		}
		for(int k=0;k<=a;k++)for(int i=0;i<=a;i++)for(int j=0;j<=a;j++)
			g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
		int ret=0;
		for(int i=0;i<b;i++){
			hv[i]=9999999;
			for(int j=0;j<a;j++){
				hv[i]=min(hv[i],c[j][h[i]]);
			}
			ret+=hv[i];
			if(hv[i]>9888888)dame=true;
		}
		if(dame){printf("impossible\n");continue;}
		for(int i=0;i<(1<<a);i++)for(int j=0;j<=a;j++)
			dp[i][j]=9999999;
		for(int i=0;i<a;i++)dp[1<<i][i+1]=g[0][i+1];
		for(int i=0;i<(1<<a);i++){
			for(int j=0;j<=a;j++){
				dp[i][0]=min(dp[i][0],dp[i][j]+g[j][0]);
				for(int k=1;k<=a;k++){
					dp[i|(1<<(k-1))][k]=min(dp[i|(1<<(k-1))][k],dp[i][j]+g[j][k]);
				}
			}
		}
		int dist=9999999;
		for(int i=0;i<(1<<a);i++){
			bool ok=true;
			for(int j=0;j<b;j++){
				bool OK=false;
				for(int k=0;k<a;k++)if(hv[j]==c[k][h[j]]&&(i&(1<<k)))OK=true;
				if(!OK)ok=false;
			}
			if(ok){
				dist=min(dist,dp[i][0]);
			}
		}
		if(b==0)ret=dist=0;
		if(dist>9999988)printf("impossible\n");
		else printf("%d %d\n",ret,dist);
	}
}