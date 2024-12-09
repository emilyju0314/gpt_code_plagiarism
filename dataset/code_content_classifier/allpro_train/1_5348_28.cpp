#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
ll dp[10001][101][2];
int D;
string k;

ll solve(int i, int sum, int f)
{
	if (i == k.size())
		return sum % D == 0;

	if (dp[i][sum % D][f] != -1)
		return dp[i][sum % D][f];

	ll ans = 0;
	for (int d = 0; d <= (f ? k[i] - '0' : 9); d++)
		ans = (ans + solve(i + 1, sum + d, f && d == (k[i] - '0'))) % MOD;
	return dp[i][sum % D][f] = ans;
}

int main()
{
	cin >> k >> D;
	memset(dp, -1, sizeof(dp));
	cout << (solve(0, 0, 1) - 1 + MOD) % MOD << endl;
	return 0;
}
