#include<queue>
#include<cstdio>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n,a,b; scanf("%d%d%d",&n,&a,&b);
		int x[1001],y[1001];
		rep(i,n+1) scanf("%d%d",x+i,y+i);

		vector<int> G[1000];
		rep(i,n) rep(j,n) {
			if((x[i+1]-x[j+1])*(x[i+1]-x[j+1])+(y[i+1]-y[j+1])*(y[i+1]-y[j+1])<=50*50){
				G[i].push_back(j);
			}
		}

		int last[1000]; // 最後に発声を終えた時刻
		int cnt=0;
		rep(i,n) last[i]=-INF;
		queue< pair<int,int> > Q;
		rep(i,n) if((x[i+1]-x[0])*(x[i+1]-x[0])+(y[i+1]-y[0])*(y[i+1]-y[0])<=10*10) {
			last[i]=a;
			Q.push(make_pair(a,i));
		}
		while(!Q.empty()){
			int t=Q.front().first,u=Q.front().second; Q.pop();

			cnt++;
			if(cnt>2*n*n){ cnt=-1; break; } // 十分多く回ったら無限に続いていると判断する

			rep(i,G[u].size()){
				int v=G[u][i];
				if(t-last[v]>b){
					last[v]=t+a;
					Q.push(make_pair(t+a,v));
				}
			}
		}

		if(cnt==-1) puts("You're always welcome!");
		else        printf("%d\n",max(*max_element(last,last+n),0));
	}

	return 0;
}