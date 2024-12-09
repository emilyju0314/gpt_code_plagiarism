#pragma GCC optimize("O3","Ofast","no-stack-protector","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
// #pragma GCC target("avx2") //Enable AVX

#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MOD = 1e9 + 7;

const int MAXN = 110;

int C[MAXN];

int B[MAXN];

int T[MAXN];

int dp[MAXN][MAXN*MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int N;
	cin >> N;

	for(int i = 1 ; i <= N ; i++)
	{
		cin >> C[i];
	}    

	for(int i = 2 ; i <= N ; i++)
	{
		cin >> B[i];
		T[i] = T[i-1]+B[i];
	}

	for(int i = 1 ; i <= N ; i++)
	{
		T[i] += T[i-1];
	}

	int Q;
	cin >> Q;

	int X;
	cin >> X;

	///Ta-Tb >= X*i

	dp[0][0] = 1;

	for(int j = 1 ; j <= 10000 ; j++)
	{
		dp[0][j] += dp[0][j-1];
		dp[0][j] %= MOD;
	}

	for(int i = 1 ; i <= N ; i++)
	{
		for(int j = 0 ; j <= 10000 ; j++)
		{
			if(j-T[i] >= X*i)
			{
				int val = 0;
				if(j-C[i]-1 >= 0)val = dp[i-1][j-C[i]-1];

				dp[i][j] += (dp[i-1][j]+MOD-val);
				dp[i][j] %= MOD;
			}
		}

		for(int j = 1 ; j <= 10000 ; j++)
		{
			dp[i][j] += dp[i][j-1];
			dp[i][j] %= MOD;
		}
	}

	cout << dp[N][10000] << '\n';

    return 0;
}