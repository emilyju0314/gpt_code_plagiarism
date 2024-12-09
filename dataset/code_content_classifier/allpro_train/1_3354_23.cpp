#include <cstdio>
#include <set>
#include <queue>
#include <algorithm>

typedef std::set<int>::iterator Iter;
const int Inf = 0x3f3f3f3f;
const int MN = 100005;

int N, M, Q;
char Str1[MN], Str2[MN];
std::set<int> se, sw, ss, sn;

int dx[10], dy[10], cx, cy;
inline void Add(std::set<int> &st, int id, int *dw, int &cw) {
	if (st.empty()) return ;
	Iter It = st.lower_bound(id);
	if (It != st.end()) dw[++cw] = *It;
	if (It != st.begin()) --It, dw[++cw] = *It;
}

int Id[10][10], Cnt, S, T;
int h[40], nxt[65], to[65], w[65], tot;
inline void Ins(int x, int y, int z) { nxt[++tot] = h[x], to[tot] = y, w[tot] = z, h[x] = tot; }

struct nde {
	int d, u;
	nde() {}
	nde(int d, int u) : d(d), u(u) {}
	inline friend bool operator <(nde i, nde j) {
		return i.d == j.d ? i.u < j.u : i.d > j.d;
	}
};

std::priority_queue<nde> pq;
int Vis[40], Dis[40];
inline int Dijkstra() {
	for (int i = 1; i <= Cnt; ++i) Vis[i] = 0, Dis[i] = Inf;
	Dis[S] = 0, pq.push(nde(0, S));
	while (!pq.empty()) {
		nde p = pq.top(); pq.pop();
		int d = p.d, u = p.u;
		if (Vis[u]) continue;
		Vis[u] = 1;
		for (int i = h[u]; i; i = nxt[i])
			if (Dis[to[i]] > d + w[i])
				Dis[to[i]] = d + w[i],
				pq.push(nde(Dis[to[i]], to[i]));
	}
	return Dis[T] == Inf ? -1 : Dis[T];
}

int main() {
	scanf("%d%d%d", &N, &M, &Q);
	scanf("%s%s", Str1 + 1, Str2 + 1);
	for (int i = 1; i <= N; ++i) (Str1[i] == 'E' ? se : sw).insert(i);
	for (int i = 1; i <= M; ++i) (Str2[i] == 'S' ? ss : sn).insert(i);
	while (Q--) {
		int sx, sy, tx, ty;
		scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
		dx[1] = sx, dx[2] = tx;
		dy[1] = sy, dy[2] = ty;
		cx = cy = 2;
		Add(Str1[sx] == 'E' ? sw : se, sx, dx, cx);
		Add(Str1[tx] == 'E' ? sw : se, tx, dx, cx);
		Add(Str2[sy] == 'S' ? sn : ss, sy, dy, cy);
		Add(Str2[ty] == 'S' ? sn : ss, ty, dy, cy);
		std::sort(dx + 1, dx + cx + 1);
		cx = std::unique(dx + 1, dx + cx + 1) - dx - 1;
		std::sort(dy + 1, dy + cy + 1);
		cy = std::unique(dy + 1, dy + cy + 1) - dy - 1;
		Cnt = tot = 0;
		for (int i = 1; i <= cx; ++i)
			for (int j = 1; j <= cy; ++j) {
				Id[i][j] = ++Cnt;
				if (dx[i] == sx && dy[j] == sy) S = Cnt;
				if (dx[i] == tx && dy[j] == ty) T = Cnt;
			}
		for (int i = 1; i <= Cnt; ++i) h[i] = 0;
		for (int i = 1; i <= cx; ++i) {
			int dir = Str1[dx[i]] == 'E';
			for (int j = 1; j < cy; ++j)
				Ins(Id[i][j + !dir], Id[i][j + dir], dy[j + 1] - dy[j]);
		}
		for (int j = 1; j <= cy; ++j) {
			int dir = Str2[dy[j]] == 'S';
			for (int i = 1; i < cx; ++i)
				Ins(Id[i + !dir][j], Id[i + dir][j], dx[i + 1] - dx[i]);
		}
		printf("%d\n", Dijkstra());
	}
	return 0;
}

// Source : AtCoder ExaWizards 2019 F