#include <stdio.h>
int N, Q, T[100000], V[100000], marked[100000], par[100000]; char W[100001];
int root(int x) {
	return par[x] == x ? x : par[x] = root(par[x]);
}
void unite(int x, int y) {
	x = root(x), y = root(y); if (x != y) par[x] = y;
}
int main() {
	while (true) {
		scanf("%d%d", &N, &Q);
		if (N == 0 && Q == 0) break; T[0] = -1;
		for (int i = 1; i < N; i++) scanf("%d", &T[i]), T[i]--; getchar();
		for (int i = 0; i < Q; i++) scanf("%c%d", &W[i], &V[i]), V[i]--, getchar();
		for (int i = 0; i < N; i++) par[i] = i, marked[i] = -1;
		for (int i = 0; i < Q; i++) if (W[i] == 'M') marked[V[i]] = (marked[V[i]] == -1 ? i : marked[V[i]]);
		for (int i = 1; i < N; i++) if (marked[i] == -1) unite(i, T[i]);
		long long ret = 0;
		for (int i = Q - 1; i >= 0; i--) {
			if (W[i] == 'Q') ret += root(V[i]) + 1;
			else if(marked[V[i]] == i && V[i] != 0) unite(V[i], T[V[i]]);
		}
		printf("%lld\n", ret);
	}
	return 0;
}