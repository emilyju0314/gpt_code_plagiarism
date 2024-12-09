#include <cstdio>
#include <algorithm>

typedef long long LL;
const int Mod = 1000000007;
const int MN = 1 << 16 | 7;

inline int qPow(int b, int e) {
	int a = 1;
	for (; e; e >>= 1, b = (LL)b * b % Mod)
		if (e & 1) a = (LL)a * b % Mod;
	return a;
}

int Fac[MN], iFac[MN];
void Init(int N) {
	Fac[0] = 1;
	for (int i = 1; i <= N; ++i) Fac[i] = (LL)Fac[i - 1] * i % Mod;
	iFac[N] = qPow(Fac[N], Mod - 2);
	for (int i = N; i >= 1; --i) iFac[i - 1] = (LL)iFac[i] * i % Mod;
}
inline int Binom(int N, int M) {
	if (N < 0 || M < 0 || M > N) return 0;
	return (LL)Fac[N] * iFac[M] % Mod * iFac[N - M] % Mod;
}

int N, M, U, A[17];
int f[MN], g[MN], Ans;

int main() {
	scanf("%d%d", &N, &M);
	U = (1 << N) - 1, Init(1 << N);
	for (int i = 1; i <= M; ++i) scanf("%d", &A[i]);
	f[0] = 1;
	for (int i = M; i >= 1; --i) {
		for (int S = 0; S <= U; ++S) g[S] = f[S];
		for (int S = 0; S <= U; ++S)
			for (int j = 0; j < N; ++j) if (~S >> j & 1)
				g[S ^ 1 << j] = (g[S ^ 1 << j] - (LL)f[S] * Binom((1 << N) - A[i] - S, (1 << j) - 1)) % Mod;
		std::swap(f, g);
	}
	for (int S = 0; S <= U; ++S) {
		int num = (LL)f[S] * Fac[S ^ U] % Mod;
		for (int j = 0; j < N; ++j) if (~S >> j & 1)
			num = (LL)num * iFac[1 << j] % Mod;
		Ans = (Ans + num) % Mod;
	}
	for (int j = 0; j < N; ++j) Ans = 2ll * Ans * Fac[1 << j] % Mod;
	printf("%d\n", (Ans + Mod) % Mod);
	return 0;
}