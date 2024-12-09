#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
	while(1){
		int n, m;
		cin >> n >> m;
		if(n == 0 && m == 0) break;
		vector<ll> a(n);
		rep(snip_i, n) cin >> a.at(snip_i);
		vector<ll> w(m);
		rep(snip_i, m) cin >> w.at(snip_i);
		sort(w.begin(), w.end());
		map<ll, int> mp;
		mp.clear();
		rep(i, pow(3, m)){
			ll sum = 0;
			int ii = i;
			rep(j, m){
				if(ii % 3 == 0) sum += w.at(j);
				if(ii % 3 == 1) sum -= w.at(j);
				ii /= 3;
			}
			mp[sum] = i;
		}
		vector<ll> nf;
		rep(i, n){
			ll now = a.at(i);
			if(mp.count(now) == 0){
				nf.push_back(now);
			}
		}
		if(nf.size() == 0){
			cout << 0 << endl;
			continue;
		}
		ll fst = nf.at(0);
		ll ans = 1e18;
		for(auto p : mp){
			ll add =fabs(fst - p.first);
			bool flag = true;
			rep2(j, 1, nf.size()){
				ll now = nf.at(j);
				if(mp.count(now-add) == 0 && mp.count(now+add) == 0){
					flag = false;
					break;
				}
			}
			if(flag == true){
				ans = min(ans, add);
			}
		}
		if(ans == 1e18) ans = -1;
		cout << ans << endl;
	}
	return 0;
}
