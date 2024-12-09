#include<cstdio>
#include<algorithm>

#define	rep(i,n)	for(int i=0;i<n;i++)

using namespace std;

const int INF=1<<29;

int main(){
	for(int n,m,a,b,c;scanf("%d%d%d%d%d",&n,&m,&a,&b,&c),n;){
		a--,b--,c--;
		int wf[100][100];
		rep(u,n)rep(v,n)	wf[u][v]=(u==v?0:INF);
		rep(i,m){
			int s,d,cost;	scanf("%d%d%d",&s,&d,&cost);
			s--,d--;
			wf[s][d]=cost;
		}

		rep(k,n)rep(i,n)rep(j,n)	wf[i][j]=min(wf[i][j],wf[i][k]+wf[k][j]);

		int cmin=INF;
		rep(u,n)	cmin=min(cmin,wf[a][u]+wf[u][b]+wf[u][c]);
		printf("%d\n",cmin);
	}

	return 0;
}