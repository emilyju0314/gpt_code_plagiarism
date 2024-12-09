#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld=long double;
ld eps=1e-9;

vector<vector<int>>pres;
vector<long long int>dfs(const vector<vector<pair<int, long long int>>>&edges, const int start,bool flag=false) {
	vector<long long int>dp(edges.size(),1e18);
	if (flag) {
		pres.resize(edges.size());
	}
	dp[start]=0;

	priority_queue<pair<long long int,int>>que;
	que.emplace(0,start);
	while (!que.empty()) {
		auto p(que.top());
		que.pop();
		const int now(p.second);
		const long long int now_cost(-p.first);
		if(now_cost!=dp[now])continue;
		
		for (auto e : edges[now]) {
			const int next(e.first);
			const long long int next_cost(now_cost+e.second);
			if (dp[next] > next_cost) {
				dp[next]=next_cost;
				que.emplace(-next_cost,next);
				if(flag)pres[next] = vector<int>{ now };
			}
			else if (dp[next] == next_cost) {
				if(flag)pres[next].push_back(now);
			}
		}
	}
	return dp;
}

long long int solve(int N, int M, int S,int T ,int U, int V,
	const vector<vector<pair<int ,long long int>>>&edges) {

	vector<long long int>from_Us(N);
	vector<long long int>from_Vs(N);
	vector<long long int>from_Ss(N);

	


	from_Us = dfs(edges, U);
	from_Vs = dfs(edges, V);

	pres.clear();
	from_Ss = dfs(edges, S, true);

	long long int ans = from_Us[V];
	priority_queue<pair<long long int, int>>que;
	que.emplace(make_pair(from_Ss[T], T));
	vector<int>flags(N);
	vector<long long int>mins(N, 1e18);
	for (int i = 0; i < N; ++i) {
		mins[i] = from_Vs[i];
	}
	while (!que.empty()) {
		auto atop(que.top());
		que.pop();
		const int now = atop.second;
		long long int amin = mins[now];

		long long int nans = amin + from_Us[now];
		ans = min(ans, nans);

		for (auto e : pres[now]) {
			mins[e] = min(mins[e], amin);
			if (!flags[e]) {
				flags[e] = true;
				que.emplace(make_pair(from_Ss[e], e));

			}
		}

	}
	return ans;
}

int main() {
	
	int N,M,S,T,U,V;cin>>N>>M>>S>>T>>U>>V;
	S--;T--;U--;V--;
	vector<vector<pair<int, long long int>>>edges(N);
	for (int i = 0; i < M; ++i) {
		int a, b, c; cin >> a >> b >> c; a--; b--;
		edges[a].push_back(make_pair(b, c));
		edges[b].push_back(make_pair(a, c));
	}
	long long int ans=solve(N,M,S,T,U,V,edges);
	ans=min(ans,solve(N,M,S,T,V,U,edges));
	cout<<ans<<endl;
	return 0;
} 
