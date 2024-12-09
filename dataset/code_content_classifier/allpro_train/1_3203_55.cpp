#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define for0(i, n) for(int i = 0; i < (n); i++)
#define for1(i, n) for(int i = 1; i <= (n);i++)
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
struct S {
	int num = mod;
	vector<S*>list;
};
S top[1234];
S ss[510000]; int sssize = 0;
int n, q;
void ssinsert(S s1) {
	ss[sssize] = s1;
	sssize++;
}

bool dumpb = 0;
void dump(S* s1) {
	if ((*s1).num != mod) {
		if (dumpb) cout << ' ';
		cout << (*s1).num;
		dumpb = 1;
	}
	for (S* s2 : (*s1).list)dump(s2);
}

signed main() {
	cin >> n >> q;
	for1(valsqotch, q) {
		int a, b, c; cin >> a;
		if (a == 0) {
			S s1;
			cin >> b >> s1.num;
			ssinsert(s1);
			top[b].list.push_back(&(ss[sssize - 1]));
		}
		else if (a == 1) {
			cin >> b;
			dump(&(top[b]));
			cout << endl;
			dumpb = 0;
		}
		else {
			cin >> b >> c;
			S s1 = top[b];
			ssinsert(s1);
			top[c].list.push_back(&(ss[sssize - 1]));
			top[b].list.clear();
		}
	}
}
