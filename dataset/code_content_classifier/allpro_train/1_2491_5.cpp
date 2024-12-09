#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair <ll, ll>;

ll p1 = 37237, q1 = 3726473, mod1 = 998244353;
ll p2 = 20202039, q2 = 1716162, mod2 = 1000000007;

string S[202020];
vector <pll> V[1010101];
ll C[26];
ll n, ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll i, j, k, s, c;
	ll hs, hs1, hs2;

	cin >> n;

	for(i = 0; i < n; i ++){
		cin >> S[i];
	}

	sort(S, S + n, [&](string &a, string &b){
		return a.size() < b.size();
	});

	for(i = 0; i < n; i ++){
		if(i && S[i].size() != S[i - 1].size()){
			s = S[i - 1].size();
			sort(V[s].begin(), V[s].end());
		}

		for(j = 0; j < S[i].size(); j ++){
			C[S[i][j] - 'a'] ++;
		}
		hs = hs1 = hs2 = 0;	
		for(j --, s = 1; j >= 0; j --, s ++){
			c = S[i][j] - 'a';

			k = lower_bound(V[s].begin(), V[s].end(), pll(hs, 0)) - V[s].begin();
			for(; k < V[s].size() && V[s][k].first == hs; k ++){
				if(C[V[s][k].second]) ans ++;
			}
			C[c] --;

			if(j == 0) break;
			hs1 = (hs1 * p1 + c * q1) % mod1;
			hs2 = (hs2 * p2 + c * q2) % mod2;
			hs = hs1 * mod2 + hs2;
		}
		V[S[i].size()].emplace_back(hs, c);
	}

	cout << ans << "\n";

	return 0;
}