#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

struct way{
	ll a,b,d;
	way(ll x,ll y, ll z){a = x, b = y, d = z;}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N, M, C; cin >> N >> M >> C;
	ll sum = 0;

	vector<way> w;

	vector<P> G[100005]; // (to, dist)

	for (int i = 0;i < M;i++){
		ll A, B, D; cin >> A >> B >> D;
		G[A].push_back(P(B,D));
		G[B].push_back(P(A,D));
		w.push_back(way(A,B,D));
		sum += D;
	}

	ll d[100005]; fill(d, d+N+5, INT_MAX);
	d[1] = 0;

	priority_queue<P, vector<P>, greater<P> > que; // (dist, node)
	que.push(P(0,1));

	while(que.size()){
		P p = que.top(); que.pop();
		ll now = p.second;
		if(d[now] < p.first) continue;
		for (int i = 0;i < G[now].size();i++){
			ll to = G[now][i].first;
			ll len = G[now][i].second;
			if(d[to] > d[now]+len){
				d[to] = d[now]+len;
				que.push(P(d[to], to));
			}
		}
	}

	vector<P> lis;
	map<ll, ll> mp;
	for (int i = 1;i <= N;i++){
		lis.push_back(P(d[i],i));
	}

	sort(lis.begin(),lis.end());

	for (int i = 0;i < N;i++){
		mp[lis[i].second] = i;
	}

	ll minus[100005]; fill(minus,minus+N+5, 0);

	for (int i = 0;i < M;i++){
		way tmp = w[i];
		minus[max(mp[tmp.a], mp[tmp.b])] += tmp.d;
	}

	ll ans = sum;

	for (int i = 0;i < N;i++){
		sum -= minus[i];
		ans = min(ans, sum+lis[i].first*C);
	}

	cout << ans << endl;

	return 0;

}

