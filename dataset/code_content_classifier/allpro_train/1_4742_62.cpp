#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a,b) a=max(a,b)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> jcat(k);
	rep(i, n) {
		int c, v;
		cin >> c >> v;
		jcat[c - 1].push_back(v);
	}
	for(auto& c: jcat) {
		if (c.size() <= 1) continue;
		sort(c.rbegin(), c.rend());
	}
	sort(jcat.begin(), jcat.end(), [](vector<int>& c1, vector<int>& c2) {
			return c1[0] + c1[1] > c2[0] + c2[1];
			});

	queue<ll> trimax;
	{
		vector<ll> tm(jcat.size());
		ll mx = -1;
		for(int i = jcat.size() - 1; i >= 0; i--) {
			auto& c = jcat[i];
			if (c.size() >= 3) chmax(mx, (ll)c[0] + c[1] + c[2]);
			tm[i] = mx;
		}
		for(ll val: tm) trimax.push(val);
	}
	multiset<int, greater<int>> singles;
	queue<vector<int>> unseen;
	for(auto& c: jcat) unseen.push(c);

	ll acc = 0, last_single = -1, last_double = -1;
	int flag = 0;
	rep(i, n) {
		if (flag) {
			flag = 0;
			vector<int>& c = unseen.front();
			auto it = c.begin();
			ll inc = *(it++) + *(it++);
			acc += inc;
			last_double = inc;
			singles.insert(it, c.end());
			unseen.pop();
			trimax.pop();
			cout << acc << endl;
		} else {
			auto take_single = [&](){
				auto it = singles.begin();
				acc += *it;
				last_single = *it;
				singles.erase(it);
				cout << acc << endl;
			};
			if (unseen.empty()) {
				if (singles.empty()) cout << -1 << endl;
				else take_single();
				continue;
			}
			vector<int>& c = unseen.front();
			ll m = trimax.front();
			auto nxt = singles.begin();
			if (!singles.empty() && *nxt * 2 >= c[0] + c[1]) {
				take_single();
				continue;
			}
			flag = 1;
			ll ans = -1;
			if (!singles.empty()) chmax(ans, acc + *nxt);
			if (last_single != -1) chmax(ans, acc - last_single + c[0] + c[1]);
			if (last_double != -1 && m != -1) chmax(ans, acc - last_double + m);
			cout << ans << endl;
		}
	}
}