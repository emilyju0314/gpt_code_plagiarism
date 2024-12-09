#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;



int main() {
	while (true) {
		int N,M;cin>>N>>M;
		if(!N)break;
		map<string,int>stmp;
		string S,P,G;cin>>S>>P>>G;
		stmp[S]=0;
		stmp[P]=1;
		stmp[G]=2;
		int id=3;
		vector<vector<pair<int,int>>>edges(N);
		for (int i = 0; i < M; ++i) {
			string s,t;cin>>s>>t;
			int d,c;cin>>d>>c;
			int cost=d/40+c;
			if (stmp.find(s) == stmp.end()) {
				stmp[s]=id++;
			}
			if (stmp.find(t) == stmp.end()) {
				stmp[t]=id++;
			}
			edges[stmp[s]].push_back(make_pair(stmp[t],cost));
			edges[stmp[t]].push_back(make_pair(stmp[s],cost));
		}
		vector<int>memo(N,1e9);
		memo[stmp[P]]=0;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>que;
		que.push(make_pair(0,stmp[P]));
		while (!que.empty()) {
			auto atop(que.top());
			que.pop();
			int now=atop.second;
			int cost=atop.first;
			for (auto e : edges[now]) {
				const int nextcost=cost+e.second;
				const int next=e.first;
				if (memo[next] > nextcost) {
					memo[next]=nextcost;
					que.push(make_pair(memo[next],next));
				}
			}
		}
		int ans=memo[stmp[S]]+memo[stmp[G]];
		cout<<ans<<endl;

	}
	return 0;
}