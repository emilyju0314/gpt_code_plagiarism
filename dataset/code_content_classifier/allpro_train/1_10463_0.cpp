#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int mod = 1000000007;
int prev_[100009], dp[100009], dpr[100009];
int mulr[100009];

long long Q;
long long N[1 << 18], C[1 << 18], Base[1 << 18];
long long Answer[1 << 18];

void init(int pos) {
	int lims = (pos - 2) * (pos - 1) / 2;
	int lim2 = max(1, lims);
	if (pos == 1) {
		for (int i = lims; i <= 100000; i++) dp[i] = 1;
	}
	else {
		for (int i = lims; i <= 100000; i++) prev_[i] = dp[i];
		for (int i = lims; i <= 100000; i++) dp[i] = 0;
		for (int i = lims; i <= 100000 - pos; i++) dp[i + pos - 1] = prev_[i];
		for (int i = lims; i <= 100000 - pos; i++) {
			dp[i + pos] += dp[i];
			if (dp[i + pos] >= mod) dp[i + pos] -= mod;
		}
		for (int i = 0; i < lims; i++) dp[i] = 0;
	}
	for (int i = lims; i <= 100000; i++) dpr[i] = dp[i];
	for (int i = lim2; i <= 100000; i++) {
		dpr[i] += dpr[i - 1];
		if (dpr[i] >= mod) dpr[i] -= mod;
	}
	for (int i = lims; i <= 100000; i++) mulr[i] = (1LL * i * dp[i]) % mod;
	for (int i = lim2; i <= 100000; i++) {
		mulr[i] += mulr[i - 1];
		if (mulr[i] >= mod) mulr[i] -= mod;
	}
}

int main() {
	scanf("%lld", &Q);
	for (int i = 1; i <= Q; i++) scanf("%lld%lld", &N[i], &C[i]);
	for (int i = 1; i <= Q; i++) Base[i] = N[i] / C[i];
	for (int i = 1; i <= Q; i++) {
		if (Base[i] == 0) Answer[i] = N[i];
	}
	
	for (int gen = 1; gen <= 450; gen++) {
		init(gen); int lims = gen * (gen - 1) / 2;
		for (int i = 1; i <= Q; i++) {
			if (Base[i] <= lims) continue;
			int cl = Base[i] - 2 * gen + 1;
			int cr = Base[i] - gen; if (cr < 0) continue;
			
			// 1 個目の計算
			long long V1 = 0;
			if (cr >= 0) V1 = dpr[cr];
			if (cl >= 1) V1 -= dpr[cl - 1];
			if (V1 < 0) V1 += mod;
			
			long long S1 = 0;
			if (cr >= 0) S1 = mulr[cr];
			if (cl >= 1) S1 -= mulr[cl - 1];
			if (S1 < 0) S1 += mod;
			
			// 2 個目の計算
			long long V2 = 0;
			if (cl >= 1) V2 = dp[cl - 1];
			
			long long S2 = 0;
			if (cl >= 1) S2 = 1LL * (cl - 1 + gen) * dp[cl - 1] % mod;
			
			// 答えに加算
			Answer[i] += (1LL * V1 * N[i] - 1LL * S1 * C[i] + 1LL * mod * mod);
			Answer[i] += (1LL * V2 * N[i] - 1LL * S2 * C[i] + 1LL * mod * mod);
			Answer[i] %= mod; //cout << gen << ": " << V1 << " " << S1 << " " << V2 << " " << S2 << " " << Answer[i] << endl;
		}
	}
	
	for (int i = 1; i <= Q; i++) printf("%lld\n", Answer[i]);
	return 0;
}