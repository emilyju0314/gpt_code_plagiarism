#include <iostream>
#include <cstdio>
#define MAX_N 21
#define INF 1e+9
using namespace std;
int main(void){
	int n,m;cin>>n>>m;
	int g[MAX_N][MAX_N];
	for(int i=0;i<MAX_N;++i)for(int j=0;j<MAX_N;++j)g[i][j]=INF;
	for(int i=0,a,b,c,d;i<m;++i){
		scanf("%d,%d,%d,%d",&a,&b,&c,&d);
		g[a][b]=c;
		g[b][a]=d;
	}
	int d[MAX_N][MAX_N];
	for(int i=0;i<MAX_N;++i)for(int j=0;j<MAX_N;++j)d[i][j]=(i==j)?0:INF;
	for(int i=1;i<=n;++i){
		bool f=false;
		for(;;){
			for(int j=1;j<=n;++j){//from
				for(int k=1;k<=n;++k){//to
					if(d[i][j]!=INF && d[i][j] + g[j][k] < d[i][k]){
						d[i][k] = d[i][j] + g[j][k];
						f=true;
					}
				}
			}
			if(f==false) break;
			f=false;
		}
	}
	int x1,x2,y1,y2;
	scanf("%d,%d,%d,%d",&x1,&x2,&y1,&y2);
	cout<<y1-y2-d[x1][x2]-d[x2][x1]<<endl;
}