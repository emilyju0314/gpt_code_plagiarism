#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld = long double;
ld eps=1e-9;

int answer=-1e9;
vector<int> dfs(const vector<vector<int>>&edges, 
	const vector<int>&scores,
	const int now, const int from) {
	vector<int>ans(3,-1e9);
	ans[0]=scores[now];
	for (auto e : edges[now]) {
		if (e != from) {
			auto v = dfs(edges,scores, e, now);
			vector<int>nextans(ans);
			for (int l = 0; l < 3; ++l) {
				for (int r = 0; r < 3; ++r) {
					if (l + r <= 2) {
						if (r == 0) {
							nextans[l + r] = max(nextans[l + r],
								ans[l] + v[r] - 2);
							if (l + r + 1 <= 2)nextans[l + r + 1] = max(nextans[l + r + 1],
								ans[l] + v[r] - 1);
						}
						else if (r == 1) {
							nextans[l + r] = max(nextans[l + r],
								ans[l] + v[r] - 1);

						}
						else {
							nextans[l + r] = max(nextans[l + r],
								ans[l] + v[r] - 2);
						}
					}
					
				}
			}
			ans=nextans;
		}
	}
	for (auto a : ans) {
		answer=max(answer,a);
	}
	return ans;
}
int main() {
	int N;cin>>N;
	vector<vector<int>>edges(N);
	vector<int>scores(N);
	for (int i = 0; i < N; ++i) {
		int a;cin>>a;
		scores[i]=a;

	}
	for (int i = 0; i < N - 1; ++i) {
		int a,b;cin>>a>>b;a--;b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	auto v=dfs(edges,scores,0,-1);
	cout<<answer<<endl;
	return 0;
}
