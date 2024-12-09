#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

#define MOD @
#define ADD(X,Y) ((X) = ((X) + (Y)) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

i64 dp[1010][9];
int cnt[1010];

int main()
{
	for (int i = 0; i <= 8; ++i) dp[0][i] = 0;
	dp[0][0] = 1;
	for (int i = 1; i <= 500; ++i) {
		dp[i][0] = 1;
		for (int j = 1; j <= 7; ++j) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
	}
	i64 L;
	scanf("%lld", &L);
	for (int i = 500; i >= 7; --i) {
		int n = (int)(L / dp[i][7]);
		cnt[i] = n;
		L %= dp[i][7];
	}
	for (int i = 0; i <= 500; ++i) {
		printf("AVITSEF");
		for (int j = 0; j < cnt[i + 1]; ++j) printf("L");
	}
	puts("");

	return 0;
}
