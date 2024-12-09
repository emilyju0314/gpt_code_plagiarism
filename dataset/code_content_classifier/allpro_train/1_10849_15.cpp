#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define ull unsigned long long
#define sz(a) ((int) (a).size())
#define vi vector<int>
using namespace std;
const int N = 233;
int n, tot;
set < int > S[N];
void merge(int x, int y) {
	for(int k : S[y]) S[x].insert(k);
	S[y].clear();
}
void del(int x) {
	L(i, x, tot) S[i] = S[i + 1];
	S[tot].clear(), --tot;
}
void kp(int x) {
	R(i, tot, x) S[i + 1] = S[i];
	++tot, S[x].clear();
}
int get(int x) {
	return * S[x].begin();
}
int getin() {
	int k;
	cin >> k;
	if(k == -1) assert(0);
	return k;
}
bool check(int x, int y) {
	cout << 1 << " " << x << " " << y << endl, fflush(stdout);
	return getin();
}
bool all[N][N], vis[N];
int rmain() {
	memset(all, 0, sizeof(all));
	memset(vis, 0, sizeof(vis));
	L(i, 1, tot) S[i].clear();
	tot = 0;
	cin >> n;
	L(i, 0, n - 1) {
		int l = 1, r = tot + 1;
		while(l < r) {
			int mid = (l + r) >> 1;
			if(mid == tot + 1 || check(i, get(mid))) r = mid;
			else l = mid + 1;
		}
		kp(l), S[l].insert(i);
	}
	int now = tot;
	while(now > 1) {
		for(int v : S[now]) if(!vis[v]) {
			cout << 2 << " " << v << " ";
			int cnt = 0;
			L(i, 1, now - 1) cnt += sz(S[i]);
			cout << cnt << " ";
			L(i, 1, now - 1) for(int u : S[i]) cout << u << " ";
			cout << endl, fflush(stdout);
			if(getin()) {
				merge(now - 1, now), del(now);
				break;	
			}
			vis[v] = true;
		}
		--now;
	}
	L(i, 1, tot) L(j, i, tot) for(int u : S[i]) for(int v : S[j]) all[u][v] = true;
	cout << 3 << endl;
	L(i, 0, n - 1) {
		L(j, 0, n - 1) cout << all[i][j];
		cout << endl;	
	} 
	fflush(stdout);
	getin();
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) rmain();
	return 0;
} // ??