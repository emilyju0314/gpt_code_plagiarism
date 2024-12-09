#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<ll,int> P;
typedef pair<int,P> P1;

#define pb push_back
#define fr first
#define sc second
#define mp1(a,b,c) P1(a,P(b,c))

struct MAX_FLOW{
	vector<P1> G[105];
	bool used[105];
	void init(){
		for(int i = 0 ; i < 105 ; i ++)G[i].clear();
	}
	void add_edge(int from, int to, ll flow){
		G[from].pb( mp1( to, flow, G[to].size() ) );
		G[to].pb( mp1( from, 0, G[from].size()-1 ) );
	}
	ll dfs(int v, int t, ll f){
		if(v == t)return f;
		used[v] = true;
		for(int i = 0 ; i < G[v].size() ; i ++){
			if(!used[G[v][i].fr] && G[v][i].sc.fr > 0){
				ll d = dfs(G[v][i].fr,t,min(f,G[v][i].sc.fr));
				if(d > 0){
					G[v][i].sc.fr -= d;
					G[G[v][i].fr][G[v][i].sc.sc].sc.fr += d;
					return d;
				}
			}
		}
		return 0;
	}
	ll flow(ll s,ll t){
		ll ret = 0, d = 1;
		while(d > 0){
			for(int i = 0 ; i < 105 ; i ++)used[i] = false;
			d = dfs(s,t,1000000000);
			ret += d;
		}
		return ret;
	}
}flow;

int main(){
	int N;
	int a[102];
	scanf("%d",&N);
	for(int i = 1 ; i <= N ; i ++){
		scanf("%d",&a[i]);
	}
	
	ll ret = 0;
	flow.init();
	for(int i = 1 ; i <= N ; i ++){
		for(int j = 2*i ; j <= N ; j += i){
			flow.add_edge(i,j,1000000000000000000);
		}
		if(a[i] > 0){
			ret += a[i];
			flow.add_edge(i,N+1,a[i]);
		}
		if(a[i] < 0){
			flow.add_edge(0,i,-a[i]);
		}
	}
	ret -= flow.flow(0,N+1);
	cout << ret << endl;
}

