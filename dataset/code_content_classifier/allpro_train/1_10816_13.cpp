#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1 << 25;
using S = tuple<int, int, int, ll>;
map<ll, int> dist[50][50];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	std::ifstream in("in");
	std::cin.rdbuf(in.rdbuf());
#endif

	int n, m;
	while(cin >> n >> m, n){
		int G[50][50] = { 0 };
		int h[50] = { 0 };
		int v[50] = { 0 };
		fill((int*)begin(G), (int*)end(G), INF);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				dist[i][j].clear();
			}
		}

		h[n - 1] = 1000;
		for(int i = 1; i < n - 1; i++){
			cin >> v[i] >> h[i];
		}

		for(int i = 0; i < m; i++){
			int a, b, c;
			cin >> a >> b >> c;
			a--, b--;
			G[a][b] = min(G[a][b], c);
		}

		dist[0][0][0] = 0;
		priority_queue<S, vector<S>, greater<S>> q;
		q.emplace(0, 0, 0, 0);
		int ans = INF;
		while(q.size()){
			int a, b, d;
			ll bit;
			tie(d, a, b, bit) = q.top();
			q.pop();
			if(a == n - 1 && b == n - 1){
				ans = d;
				break;
			}
			for(int i = 0; i < n; i++){
				if(h[a] > h[i]) continue;
				if(G[a][i] == INF) continue;
				int nd = d + G[a][i];
				if((bit >> i & 1) == 0) nd += v[i];
				ll nbit = bit;
				if(h[i] > h[b]) nbit = 1LL << i;
				if(h[i] == h[b]) nbit = bit | (1LL << i);

				if(dist[i][b].count(nbit) == 0 || dist[i][b][nbit] > nd){
					dist[i][b][nbit] = nd;
					q.emplace(nd, i, b, nbit);
				}
			}
			for(int i = 0; i < n; i++){
				if(h[b] > h[i]) continue;
				if(G[i][b] == INF) continue;
				int nd = d + G[i][b];
				if((bit >> i & 1) == 0) nd += v[i];
				ll nbit = bit;
				if(h[i] > h[a]) nbit = 1LL << i;
				if(h[i] == h[a]) nbit = bit | (1LL << i);
				if(dist[a][i].count(nbit) == 0 || dist[a][i][nbit] > nd){
					dist[a][i][nbit] = nd;
					q.emplace(nd, a, i, nbit);
				}
			}
		}

		if(ans == INF) ans = -1;
		cout << ans << endl;
	}
}