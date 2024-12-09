#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdio>

using namespace std;

#define REP(i,n) for(int i=0;i<int(n);i++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
typedef long long ll;
typedef pair<int,int>P;

int N,K;
vector<int> G[5010];
int D[5010][5010];
int d[5010];
int C[10010];
int R[5010];
const int INF=100000000;

void bfs(int x){
	queue<int>q;
	q.push(x);
	while(R[x]>0){
		queue<int>q1;
	while(!q.empty()){
		int p=q.front(); q.pop();
		int n=G[p].size();
		for(int i=0;i<n;i++){
			if(D[x][G[p][i]]==INF){
				D[x][G[p][i]]=C[x];
				q1.push(G[p][i]);
			}
		}
	}
	  R[x]--;
	  q=q1;
	}
}

int main(void){

	cin >> N >> K;
	int i,j;
	for(i=1;i<=N;i++) cin >> C[i] >> R[i];
	int a,b;
	REP(i,K){
		cin >> a >> b;
		G[a].push_back(b); G[b].push_back(a);
	}

	for(i=1;i<=N;i++) for(j=1;j<=N;j++) D[i][j]=INF;

	for(i=1;i<=N;i++) bfs(i);

	priority_queue<P,vector<P>,greater<P> >Q;
	for(i=1;i<=N;i++) d[i]=INF;
	d[1]=0;
	Q.push(P(d[1],1));

	while(!Q.empty()){
		P p=Q.top(); Q.pop();
		int a=p.first,b=p.second;
		if(d[b]<a) continue;
		d[b]=a;
		for(i=1;i<=N;i++){
			if(d[i]>d[b]+D[b][i]){
			   d[i]=d[b]+D[b][i];
			   Q.push(P(d[i],i));
			}
		}
	}

	cout << d[N] << endl;

	return 0;
}