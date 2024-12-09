#include<cstdio>
#include<algorithm>
#include<vector>
#define M_ 201000
#define N_ 10100
using namespace std;

struct MinimumCostFlow {
	struct Edge {
		int b, e, f;
		long long c;
	}E[M_];
	int EC, source, sink, n, Q[M_*2], InQ[N_], Path[N_], flow;
	vector<int>G[N_];
	long long D[N_], INF = 4e18, res;

	void init(int N, int S, int T) {
		n = N, source = S, sink = T;
		flow = EC = 0;
		res = 0;
		for (int i = 0; i <= n; i++)G[i].clear();
	}

	void Add_Edge(int b, int e, int f, long long c) {
		G[b].push_back(EC);
		G[e].push_back(EC + 1);
		E[EC++] = { b,e,f,c };
		E[EC++] = { e,b,0,-c };
	}

	bool SPFA() {
		int i, head = 0, tail = 0;
		for (i = 0; i <= n; i++)D[i] = -INF, Path[i] = 0, InQ[i] = 0;
		D[source] = 0; Q[++tail] = source, InQ[source] = 1;
		while (head < tail) {
			int x = Q[++head];
			InQ[x] = 0;
			for (auto &t : G[x]) {
				if (E[t].f) {
					if (D[E[t].e] < D[E[t].b] + E[t].c) {
						D[E[t].e] = D[E[t].b] + E[t].c;
						Path[E[t].e] = t;
						if (!InQ[E[t].e]) {
							InQ[E[t].e] = 1;
							Q[++tail] = E[t].e;
						}
					}
				}
			}
		}
		if (D[sink] == -INF)return false;
		int x = sink;
		while (x != source) {
			E[Path[x]].f--;
			E[Path[x] ^ 1].f++;
			x = E[Path[x]].b;
		}
		res += D[sink];
		return true;
	}

	void MCMF() {
		while (SPFA())flow++;
	}

}MCF;

struct point {
	int x, y;
	long long c;
}w[81];
struct Query {
	char ch;
	int a, c;
}U[320];
int n, m, L1[110], R1[110], L2[110], R2[110];

long long Solve(int K) {
	int i, j;
	for (i = 0; i <= K + 1; i++) {
		L1[i] = L2[i] = 0;
		R1[i] = R2[i] = 100;
	}
	for (i = 1; i <= m; i++) {
		if (U[i].c >= K)continue;
		if (U[i].ch == 'L') {
			L1[U[i].c + 1] = max(L1[U[i].c + 1], U[i].a + 1);
		}
		if (U[i].ch == 'R') {
			R1[K - U[i].c] = min(R1[K - U[i].c], U[i].a - 1);
		}
		if (U[i].ch == 'D') {
			L2[U[i].c + 1] = max(L2[U[i].c + 1], U[i].a + 1);
		}
		if (U[i].ch == 'U') {
			R2[K - U[i].c] = min(R2[K - U[i].c], U[i].a - 1);
		}
	}
	for (i = 1; i <= K; i++) {
		L1[i] = max(L1[i - 1], L1[i]);
		L2[i] = max(L2[i - 1], L2[i]);
	}
	for (i = K; i >= 1; i--) {
		R1[i] = min(R1[i + 1], R1[i]);
		R2[i] = min(R2[i + 1], R2[i]);
	}
	MCF.init(2 + K * 2 + 100 * 2, 1 + K * 2 + 100 * 2, 2 + K * 2 + 100 * 2);
	for (i = 1; i <= K; i++) {
		MCF.Add_Edge(MCF.source, i, 1, 0);
		MCF.Add_Edge(i + K, MCF.sink, 1, 0);
		for (j = L1[i]; j <= R1[i]; j++) {
			MCF.Add_Edge(i, K + K + j, 1, 0);
		}
		for (j = L2[i]; j <= R2[i]; j++) {
			MCF.Add_Edge(K + K + 100 + j, K + i, 1, 0);
		}
	}
	for (i = 1; i <= n; i++) {
		MCF.Add_Edge(K + K + w[i].x, K + K + 100 + w[i].y, 1, w[i].c);
	}
	MCF.MCMF();
	if (MCF.flow == K)return MCF.res;
	return 0ll;
}

int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d%d%lld", &w[i].x, &w[i].y, &w[i].c);
	}
	scanf("%d", &m);
	for (i = 1; i <= m; i++) {
		char pp[3];
		int a, b;
		scanf("%s%d%d", pp, &a, &b);
		U[i] = { pp[0],a,b };
	}
	long long res = 0;
	for (i = 1; i <= n; i++)res = max(res,Solve(i));
	printf("%lld\n", res);
}