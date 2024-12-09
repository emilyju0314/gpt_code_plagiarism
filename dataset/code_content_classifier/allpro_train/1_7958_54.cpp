#include <bits/stdc++.h>
using namespace std;

#define lp(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) lp(i, 0, n)
#define fi first
#define se second

const int INF = 1 << 28;

typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

int a_, b_, C_ = ~(1<<31), M_ = (1<<16)-1;
int r_() {
  a_ = 36969 * (a_ & M_) + (a_ >> 16);
  b_ = 18000 * (b_ & M_) + (b_ >> 16);
  return (C_ & ((a_ << 16) + b_)) % 1000000;
}

vector<tp> ps;

int solve()
{
	rep(i, ps.size()) get<1>(ps[i]) *= -1;
	sort(begin(ps), end(ps));
	rep(i, ps.size()) get<1>(ps[i]) *= -1;
	
	vector<set<pr>> sts(ps.size() + 10);
	for (auto &st : sts){
		st.insert(pr(-INF, INF));
		st.insert(pr(INF, -INF));
	}
	
	int res = 0;
	rep(i, ps.size()){
		int x, y, z;
		tie(x, y, z) = ps[i];
		int l = 0, r = ps.size();
		while (l + 1 < r){
			int m = (l + r) / 2;
			auto it = --sts[m].lower_bound(pr(y, -INF));
			if (it->se < z) l = m;
			else r = m;
		}
		if (z <= (--sts[r].lower_bound(pr(y, z)))->se){
			while (true){
				auto it = sts[r].lower_bound(pr(y, z));
				if (it->se < z) break;
				sts[r].erase(it);
			}
			sts[r].insert(pr(y, z));
		}
		res = max(res, r);
	}

	return res;
}

int main()
{
	int m, n;
	while (cin >> m >> n >> a_ >> b_, m + n){
		ps.clear();
		rep(i, m){
			int x, y, z;
			cin >> x >> y >> z;
			ps.emplace_back(x, y, z);
		}
		rep(i, n){
			int x = r_();
			int y = r_();
			int z = r_();
			ps.emplace_back(x, y, z);
		}
		cout << solve() << endl;
	}
}