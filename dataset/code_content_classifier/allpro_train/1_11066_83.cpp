#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<double, double> pd;
typedef pair<int, int> pi; typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;  typedef pair<ll, pi> plp;
typedef pair<int, pi> pip; typedef tuple<int, int, int> ti;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

int A, B, C;

int main() {
	cin >> A >> B >> C;
	multiset<string> S;
	for(int i=0; i<A; i++) S.insert("a");
	for(int i=0; i<B; i++) S.insert("b");
	for(int i=0; i<C; i++) S.insert("c");

	for(int k=0; k<A+B+C-1; k++) {
		string l = *S.begin();
		auto it = S.end(); it--;
		string r = *it;
		S.erase(S.begin());
		S.erase(it);
		S.insert(l+r);
	}
	cout << *S.begin() << endl;
	return 0;
}
