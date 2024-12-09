#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧  
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|     
　　　 /　　 /￣￣￣￣/　　|  
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿  
　 　　　＼/＿＿＿＿/　（u　⊃  
---------------------------------------------------------------------------------------------------*/














int N, S, T;
int A[303], B[303];
//---------------------------------------------------------------------------------------------------
map<pair<int, int>, int> memo;
int ask(int u, int v) {
	if (u == v) return 0;
	if (u > v) swap(u, v);

	if (memo.count({ u, v })) return memo[{u, v}];

	printf("? %d %d\n", u, v);
	fflush(stdout);

	int res; cin >> res;

	return memo[{u, v}] = res;
}
void answer(vector<int> v) {
	printf("!");
	fore(x, v) printf(" %d", x);
	printf("\n");
	fflush(stdout);
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> S >> T;

	rep(i, 1, N + 1) A[i] = ask(S, i);
	rep(i, 1, N + 1) B[i] = ask(T, i);

	vector<pair<int, int>> v;
	rep(i, 1, N + 1) if (A[T] == A[i] + B[i]) v.push_back({ A[i], i });
	sort(all(v));

	vector<int> ans;
	fore(p, v) {
		if (ans.size() == 0) ans.push_back(p.second);
		else {
			int pre = ans.back();
			if (A[T] == A[pre] + ask(pre, p.second) + B[p.second]) {
				ans.push_back(p.second);
			}
		}
	}
	answer(ans);
}



