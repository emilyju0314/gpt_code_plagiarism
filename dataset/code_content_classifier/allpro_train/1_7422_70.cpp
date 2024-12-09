#include <cstdio>
#include <algorithm>

namespace Dinic {
	typedef long long LL;
	const LL Inf = 0x3f3f3f3f3f3f3f3f;
	const int MN = 200005, MM = 100005;
	
	int N, S, T;
	int h[MN], iter[MN], nxt[MM * 2], to[MM * 2], tot; LL w[MM * 2];
	
	inline void SetST(int, int);
	inline void Init(int _N) {
		N = _N, tot = 1;
		for (int i = 1; i <= N; ++i) h[i] = 0;
		SetST(_N - 1, _N);
	}
	inline void SetST(int _S, int _T) { S = _S, T = _T; }
	
	inline void ins(int u, int v, LL x) { nxt[++tot] = h[u], to[tot] = v, w[tot] = x, h[u] = tot; }
	inline void insw(int u, int v, LL w1 = Inf, LL w2 = 0) {
		if (!u) u = S; if (!v) v = T;
		ins(u, v, w1), ins(v, u, w2);
	}
	
	int lv[MN], que[MN], l, r;
	
	inline bool Lvl() {
		for (int i = 1; i <= N; ++i) lv[i] = 0;
		lv[S] = 1;
		que[l = r = 1] = S;
		while (l <= r) {
			int u = que[l++];
			for (int i = h[u]; i; i = nxt[i])
				if (w[i] && !lv[to[i]]) {
					lv[to[i]] = lv[u] + 1;
					que[++r] = to[i];
				}
		}
		return lv[T] != 0;
	}
	
	LL Flow(int u, LL f) {
		if (u == T) return f;
		LL d = 0, s = 0;
		for (int &i = iter[u]; i; i = nxt[i])
			if (w[i] && lv[to[i]] == lv[u] + 1) {
				d = Flow(to[i], std::min(f, w[i]));
				f -= d, s += d;
				w[i] -= d, w[i ^ 1] += d;
				if (!f) break;
			}
		return s;
	}
	
	inline LL Dinic() {
		LL Ans = 0;
		while (Lvl()) {
			for (int i = 1; i <= N; ++i) iter[i] = h[i];
			Ans += Flow(S, Inf);
		}
		return Ans;
	}
}

const int MN = 100005;
int N, A[MN], B[MN], cA[MN], cB[MN], Sum;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]), ++A[i];
	for (int i = 1; i <= N; ++i) scanf("%d", &B[i]), ++B[i];
	for (int i = 1; i <= N; ++i) cA[i] = cB[i] = i;
	for (int i = 1; i <= N; ++i) {
		if (cA[i] == i) for (int x = A[i]; x != i; x = A[x]) cA[x] = i;
		if (cB[i] == i) for (int x = B[i]; x != i; x = B[x]) cB[x] = i;
	}
	for (int i = 1; i <= N; ++i) cB[i] += N;
	Dinic::Init(N + N + 2);
	for (int i = 1; i <= N; ++i) {
		if (A[i] != i && B[i] != i) {
			if (A[i] != B[i]) Dinic::insw(cB[i], cA[i], 1);
			else Dinic::insw(cB[i], cA[i], 1, 1);
		} else if (A[i] != i || B[i] != i) {
			if (A[i] == i) Dinic::insw(cB[i], 0, 1);
			else Dinic::insw(0, cA[i], 1);
		} else ++Sum;
	}
	printf("%lld\n", N - Dinic::Dinic() - Sum);
	return 0;
}