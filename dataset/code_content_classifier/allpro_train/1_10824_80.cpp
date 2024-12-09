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














int N, P[4], T[4];
//---------------------------------------------------------------------------------------------------
int ans = inf;
int cnt[4];
void dfs(int cu) {
	if (cu == 4) {
		int prize = 0;
		rep(i, 0, 4) prize += P[i] * cnt[i];
		int cha = 0;
		rep(i, 0, 4) cha += T[i] * cnt[i];

		if (N <= cha) chmin(ans, prize);

		return;
	}

	rep(i, 0, N + 1) {
		cnt[cu] = i;
		dfs(cu + 1);
	}
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, 4) cin >> P[i];
	rep(i, 0, 4) cin >> T[i];

	dfs(0);
	cout << ans << endl;
}



