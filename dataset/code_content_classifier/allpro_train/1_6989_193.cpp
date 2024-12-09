#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
#define per(i, a, b) for (int i = (a); i >= int(b); i--)
#define fir first
#define sec second
#define tct template<class type>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int maxn = 1e5, mod = 1e9 + 7;
int n, m, u[maxn + 5], v[maxn + 5], d[maxn + 5], fa[maxn + 5];

inline void red(int &x) { x += x >> 31 & mod; }
tct inline void cmax(type &x, type y) { x < y ? x = y : 0; }
tct inline void cmin(type &x, type y) { x > y ? x = y : 0; }

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
	scanf("%d %d", &n, &m);
	rep(i, 1, m) {
		scanf("%d %d", &u[i], &v[i]);
		d[u[i]]++, d[v[i]]++;
	}
	rep(i, 1, n) if (d[i] & 1) puts("No"), exit(0);
	rep(i, 1, n) if (d[i] >= 6) puts("Yes"), exit(0);
	int c = 0;
	rep(i, 1, n) c += d[i] == 4;
	if (c != 2) puts(c >= 3 ? "Yes" : "No"), exit(0);
	int x = 0;
	rep(i, 1, n) if (d[i] == 4) { x = i; break; }
	rep(i, 1, n) fa[i] = i;
	rep(i, 1, m) if (u[i] != x && v[i] != x) fa[find(u[i])] = find(v[i]);
	int y = 0;
	rep(i, 1, n) y += find(i) == i;
	puts(y == 3 ? "Yes" : "No");
	return 0;
}