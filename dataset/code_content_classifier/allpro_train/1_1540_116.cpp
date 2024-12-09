#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <bitset>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int MAXN = 2005;
const int MOD = 998244353;

int n,cnt[3];
int MAXr[MAXN << 1];
int MAXb[MAXN << 1];
int f[MAXN << 1][MAXN << 1];

char s[MAXN];

int main()
{
//	freopen("ball.in","r",stdin);
//	freopen("ball.out","w",stdout);
	scanf("%s",s + 1);
	n = strlen(s + 1);
	for (int i = 1;i <= n;i++)
	{
		cnt[s[i] - '0']++;
		for (int j = i;j <= 2 * i;j++)
		{
			MAXr[j] = max(MAXr[j],min(j,cnt[1] + cnt[0] * 2));
			MAXb[j] = max(MAXb[j],min(j,cnt[1] + cnt[2] * 2));
		}
	}
	f[0][0] = 1;
	for (int i = 1;i <= 2 * n;i++)
		for (int j = i - MAXb[i];j <= MAXr[i];j++)
		{
			f[i][j] = f[i - 1][j];
			if (j > 0)
				(f[i][j] += f[i - 1][j - 1]) %= MOD;
		}
	printf("%d\n",f[n * 2][MAXr[n * 2]]);
	return 0;
}