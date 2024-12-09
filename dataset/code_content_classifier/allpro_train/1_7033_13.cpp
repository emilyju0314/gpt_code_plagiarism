/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-12-06 16:56:59
* @description: 
* /Users/jackbai/Desktop/CGR12/f.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv f.cpp
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
const int MOD = 1000000007; 
const ll INF = 1e18;
const ld eps = 1e-8;
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define F0R(i,a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= a; i --)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

int n;
int a[100010];
int bar[100010];

pii cand[100010];
int cst = 0;

int main() {
	int t;
	cin >> t;
	while (t --) {
		int seg = 1;
		cst = 0;
		cin >> n;
		for (int i = 1; i <= n; i ++)
			bar[i] = 0;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
			if (i == 1)
				continue ;
			if (a[i] == a[i - 1]) {
				seg += 1;
				bar[a[i]] += 2;
			}
			else
				cand[++ cst] = MP(a[i], a[i - 1]);
		}
		bar[a[1]] ++;
		bar[a[n]] ++;
		int mx = 0, id = -1;
		for (int i = 1; i <= n; i ++)
			if (bar[i] > mx) {
				mx = bar[i];
				id = i;
			}
		// cerr << mx << " " << id << endl;
		if (mx <= seg + 1) {
			cout << seg - 1 << '\n';
			continue ;
		}
		for (int i = 1; i <= cst && mx > seg + 1; i ++) {
			int x = cand[i].F, y = cand[i].S;
			if (x == id || y == id)
				continue ;
			seg ++;
			bar[x] ++;
			bar[y] ++;
		}
		if (mx > seg + 1) {
			cout << -1 << '\n';
			continue ;
		}
		else {
			cout << seg - 1 << '\n';
			continue ;
		}
	}

    return 0;
}