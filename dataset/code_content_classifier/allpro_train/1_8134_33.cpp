#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

int n;
int child[500010][2];
ll depth[500010];
ll cnt[500010];
ll dp[500010];
int order[500010];

int main() {
  while (scanf("%d", &n) > 0) {
    MEMSET(depth, 0);
    MEMSET(cnt, 0);
    MEMSET(dp, 0);
    REP(i, n - 1) {
      int a, b;
      scanf("%d %d", &a, &b);
      a--; b--;
      child[i][0] = a; child[i][1] = b;
    }
    queue<pair<int, int> > que;
    que.push(make_pair(0, 0));
    ll ans = 0;
    int m = 0;
    dp[n - 1] = 0;
    cnt[n - 1] = 1;
    while (!que.empty()) {
      int from = que.front().first;
      int d = que.front().second;
      que.pop();
      if (from == n - 1) { ans += d; continue; }
      depth[from] = d;
      order[m++] = from;
      que.push(make_pair(child[from][0], d + 1));
      que.push(make_pair(child[from][1], d + 1));
    }
    assert(m == n - 1);
    reverse(order, order + m);
    REP(i, m) {
      int node = order[i];
      int lc = child[node][0];
      int rc = child[node][1];
      ll d = depth[node];
      cnt[node] = cnt[lc] + cnt[rc];
      dp[node] = max(dp[lc] + dp[rc], max(cnt[lc] * d + dp[rc], cnt[rc] * d + dp[lc]));
    }
    printf("%lld\n", ans - dp[0]);
  }
}