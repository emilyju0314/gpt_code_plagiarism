#include "bits/stdc++.h"
using namespace std;
using ll = long long int;
using ha = pair<ll, ll>;
struct RollingHash {
	static const ll mul0 = 100009, mul1 = 1000007;
	static const ll add0 = 10000120007, add1 = 10032333331;
	size_t len;
	vector<ha>hash_;
	static vector<ha>pmo_;
	void init(const vector<ll>& s) {
		len = s.size();
		hash_.resize(len + 1);
		hash_[0] = make_pair(0, 0);

		if (pmo_.empty()) {
			pmo_.push_back(make_pair(1, 1));
		}
		while (pmo_.size() <= len) {
			pmo_.push_back(make_pair(pmo_.back().first*mul0, pmo_.back().second*mul1));
		}
		for (unsigned int i = 0; i < len; ++i) {
			hash_[i + 1] = make_pair((hash_[i].first * mul0 + s[i]), (hash_[i].second*mul1 + s[i]));
		}
		return;
	}
	void init(const string& s) {
		vector<ll>v;
		for (char c : s) {
			v.push_back(c);
		}
		init(v);
	}
	ha hash(const int l, const int r)const { // s[l..r]
		return make_pair(hash_[r + 1].first - hash_[l].first * pmo_[r + 1 - l].first,
			hash_[r + 1].second - hash_[l].second * pmo_[r + 1 - l].second);
	}

	ha get_changed_hash(const int index, const ll from, const ll to, const int l, const int r)const {
		const ha p(hash(l, r));
		if (l > index || r < index)return p;
		return make_pair(
			p.first + (to - from) * pmo_[r + 1 - index - 1].first,
			p.second + (to - from) * pmo_[r + 1 - index - 1].second);
	}
};
vector<ha> RollingHash::pmo_;

RollingHash rh;
int check(const int a, const int b,int len) {
	int al = a, ar = a+ len;
	int bl = b, br = b+len;
	int lans = -1;
	int rans =len;
	while (lans + 1 != rans) {
		int midans = (lans + rans) / 2;
		if (rh.hash(al, al + midans) == rh.hash(bl, bl + midans)) {
			lans = midans;
		}
		else {
			rans = midans;
		}
	}
	if (rh.hash(al + rans + 1, ar) == rh.hash(bl + rans + 1, br))return rans;
	else return -1;
}
string st;
int changeind = -1;
char changeto = 0;
ha getha(const int l, const int r) {
	if (changeind != -1) {
		return rh.get_changed_hash(changeind, st[changeind], changeto, l, r);
	}
	else {
		ha h = rh.hash(l, r);
		return h;
	}
}
int L, R, T;
pair<bool, int> issame(int a, int b, int alen) {
	if (b > R) {
		return make_pair(true, -1);
	}
	else {
		assert(b <= R);
		int len = min(alen, R - b);
		bool same = getha(a, a + len) == getha(b, b + len);
		if (same)return make_pair(true, -1);
		else {

			int acheck = check(a,b,len);
			return make_pair(false, acheck);
		}
	}
}
int main() {
	cin >> st;
	rh.init(st);
	int N; cin >> N;
	int num = -1;
	while (N--) {
		num++;
		changeind = -1;
		changeto = -1; cin >> L >> R >> T;
		L--; R--;
		int asize = R - L + 1;
		int nt = T;
		while (asize  >= nt) {
			nt *= 2;
		}
		bool ok = true;
		while (nt != T) {
			nt /= 2;
			if (nt >= asize)continue;
			auto ap = issame(L, L + nt, nt-1);
			if (ap.first)continue;
			else {
				int p(ap.second);
				if (p == -1) {
					ok = false;
					break;
				}
				else {
					if (changeind != -1) {
						ok = false;
						break;
					}
					else if (nt == T) {
						if (L + nt * 3 + p <= R)ok = false;
						else {
							ok = true;
						}
						break;
					}
					else {
						bool lsame = issame(L,L+nt/2,nt/2-1).first;
						bool rsame= issame( L + nt,L+nt+nt/2, nt / 2 - 1).first;
						
						if (lsame) {
							changeind = L + nt + p;
							changeto = st[L + p];
							assert(issame(L, L + nt / 2, nt / 2 - 1).first);
							assert(issame(L + nt, L + nt + nt / 2, nt / 2 - 1).first);
						}
						else if(rsame){
							changeind = L + p;
							changeto = st[L + nt + p];
							if (!issame(L, L + nt / 2, nt / 2 - 1).first) {
								ok = false;
								break;
							}
							assert(issame(L + nt, L + nt + nt / 2, nt / 2 - 1).first);
						}
						else {
							ok = false;
							break;
						}
					}
				}
				assert(issame(L, L + nt, nt - 1).first);
			}
		}
		if (ok)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}