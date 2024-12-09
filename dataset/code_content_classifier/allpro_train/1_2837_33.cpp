#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min; using std::max;
using std::swap; using std::sort;
typedef long long ll;

template<typename T>
void read(T &x) {
	int flag = 1; x = 0; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') flag = -flag; ch = getchar(); }
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar(); x *= flag;
}

const int _ = 4e5 + 10;
int n, q, d[_], cnt, fa[_];
struct Edge { int u, v, w; } e[_];
inline bool operator < (const Edge &a, const Edge &b) { return a.w < b.w; }
inline void ChkMin(int &a, int b) { if(a > b) a = b; }
inline void addEdge(int u, int v, int w) { e[++cnt] = (Edge){u, v, w}; }
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
bool unionn(int x, int y) {
	int fx = find(x), fy = find(y);
	if(fx == fy) return 0;
	fa[fx] = fy; return 1;
}

int main () {
#ifdef OFFLINE_JUDGE
	freopen("233.in", "r", stdin);
	freopen("233.out", "w", stdout);
#endif
	read(n), read(q);
	memset(d, 127, sizeof d);
	for(int i = 1, a, b, c; i <= q; ++i) {
		read(a), read(b), read(c), addEdge(a, b, c);
		ChkMin(d[a], c + 1), ChkMin(d[b], c + 2);
	}
	for(int i = 0; i < n; ++i) ChkMin(d[i], d[(i - 1 + n) % n] + 2);
	for(int i = 0; i < n; ++i) ChkMin(d[i], d[(i - 1 + n) % n] + 2);
	for(int i = 0; i <= n; ++i) addEdge(i, (i + 1) % n, d[i]);
	sort(e + 1, e + cnt + 1);
	for(int i = 1; i < n; ++i) fa[i] = i;
	int blo = n; ll ans = 0;
	for(int i = 1; i <= cnt && blo > 1; ++i)
		if(unionn(e[i].u, e[i].v)) ans += e[i].w, --blo;
	printf("%lld\n", ans);
	return 0;
} 
