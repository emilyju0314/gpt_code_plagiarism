#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define befv(V) ((V)[(sz(V)-2)])
#define sorv(V) sort(allv(V))
#define revv(V) reverse(allv(V))
#define univ(V) (V).erase(unique(allv(V)),(V).end())
#define clv(V) (V).clear()
#define upmin(a,b) (a)=min((a),(b))
#define upmax(a,b) (a)=max((a),(b))
#define rb(x) ((x)&(-(x)))
#define cb(x) (x)=(!(x))
#define INF (0x3f3f3f3f)
#define INFLL (0x3f3f3f3f3f3f3f3fll)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;
const int MAXN = 55;

int dp[MAXN][MAXN*2][MAXN*2];

int B[MAXN], C[MAXN];

int A[MAXN*2];

int N, Ans;

void add(int &a, ll b) { a = ((b+a) % MOD + MOD) % MOD; }

int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	if(1 == N) {
		puts("1");
		return 0;
	}
	for(int i = 1; i < N*2; i++) cin >> A[i];

	{
		sort(A+1, A+N*2);
		vector<int> V;
		for(int i = 1; i < N*2; i++) V.eb(A[i]);
		univ(V);
		for(int i = 1; i < N*2; i++)
			A[i] = int(lower_bound(allv(V), A[i]) - V.begin()) + 1;
	}

	for(int i = 1; i <= N; i++) {
		B[i] = A[N-i+1];
		C[i] = A[N+i-1];
	}

	B[1] = C[1];
	dp[1][1][1] = 1;
	for(int i = 1; i < N; i++) {
		for(int j = 1; j <= C[i]-B[i]+1; j++) {
			for(int k = 1; k <= j; k++) {
				int ret = dp[i][j][k];
				if(!ret) continue;

				int lc = B[i] - B[i+1], rc = C[i+1] - C[i];
				for(int l = 1; l <= k+lc; l++)
					add(dp[i+1][j+lc+rc - max(0, k+lc-l-1)][l], ret);
				for(int l = k+lc+1; l <= j+lc+rc; l++)
					add(dp[i+1][j+lc+rc - max(0, l-k-lc-1)][k+lc+1], ret);
			}
		}
	}

	for(int i = 1; i <= C[N]-B[N]+1; i++) for(int j = 1; j <= i; j++)
		add(Ans, dp[N][i][j]);
	cout << Ans << endl;
	return 0;
}