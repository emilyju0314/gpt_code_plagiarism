#include <bits/stdc++.h>
using namespace std;
int dp[5005][5005];
int a[5005];
void solve() {
  int n, k, v;
  scanf("%d %d %d ", &n, &k, &v);
  long long sum = 0;
  for (int i = 1; i <= n; ++i) {
    scanf(" %d ", &a[i]);
    sum += a[i];
  }
  if (sum < v) {
    printf("NO\n");
    return;
  }
  if (v % k == 0) {
    printf("YES\n");
    for (int i = 2; i <= n; ++i) {
      int cnt = a[i] / k;
      int mod = a[i] % k;
      if (mod > 0) {
        ++cnt;
      }
      if (cnt > 0) printf("%d %d %d\n", cnt, i, 1);
    }
    if (v / k > 0) printf("%d %d %d ", v / k, 1, 2);
    return;
  }
  for (int j = 0; j < k; ++j) {
    dp[0][j] = -1;
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < k; ++j) {
      dp[i][j] = -1;
    }
    int rem = a[i] / k;
    int mod = a[i] % k;
    for (int j = 0; j < k; ++j) {
      if (dp[i - 1][j] != -1) {
        dp[i][j] = dp[i - 1][j] + rem;
      }
    }
    for (int j = 0; j < k; ++j) {
      if (dp[i - 1][j] != -1) {
        dp[i][(j + mod) % k] =
            max(dp[i][(j + mod) % k],
                dp[i - 1][j] + rem + ((j + mod) >= k ? 1 : 0));
      }
    }
  }
  int g = (sum - v) % k;
  if (dp[n][v % k] >= v / k) {
    int curMod = v % k;
    int curRem = v / k;
    int lastRem = v / k;
    curRem = dp[n][curMod];
    printf("YES\n");
    vector<int> vertex;
    vector<int> nv;
    for (int i = n; i >= 1; --i) {
      int rem = a[i] / k;
      int mod = a[i] % k;
      if (dp[i - 1][curMod] + rem == curRem) {
        curRem -= rem;
        nv.push_back(i);
      } else {
        int cnt = rem;
        if (curMod - mod < 0) {
          --curRem;
          ++cnt;
        }
        curMod = (curMod - mod + k) % k;
        vertex.push_back(i);
        curRem -= rem;
      }
    }
    assert(vertex.size() > 0);
    for (int i = 1; i < vertex.size(); ++i) {
      int node = vertex[i];
      int rem = a[node] / k;
      int mod = a[node] % k;
      int cnt = rem;
      if (mod > 0) {
        ++cnt;
      }
      printf("%d %d %d\n", cnt, node, vertex[0]);
    }
    for (int node : nv) {
      if (a[node] / k > 0) printf("%d %d %d\n", a[node] / k, node, vertex[0]);
    }
    int un = 1;
    if (un == vertex[1]) {
      un = 2;
    }
    int cnt = dp[n][v % k] - lastRem;
    assert(cnt >= 0);
    if (cnt > 0) printf("%d %d %d\n", cnt, vertex[0], un);
  } else if (dp[n][g] != -1) {
    printf("YES\n");
    vector<int> vertex;
    vector<int> nv;
    int curMod = g;
    int curRem = dp[n][g];
    long long tsum = 0;
    for (int i = n; i >= 1; --i) {
      int rem = a[i] / k;
      int mod = a[i] % k;
      if (dp[i - 1][curMod] + rem == curRem) {
        curRem -= rem;
        nv.push_back(i);
      } else {
        int cnt = rem;
        if (curMod - mod < 0) {
          --curRem;
          ++cnt;
        }
        tsum += a[i];
        curMod = (curMod - mod + k) % k;
        vertex.push_back(i);
        curRem -= rem;
      }
    }
    int un = 1;
    if (un == vertex[0]) {
      un = 2;
    }
    for (int i = 1; i < vertex.size(); ++i) {
      int node = vertex[i];
      printf("%d %d %d\n", (a[node] + k - 1) / k, node, vertex[0]);
    }
    for (int node : nv) {
      if ((a[node] + k - 1) / k > 0 && un != node) {
        printf("%d %d %d\n", (a[node] + k - 1) / k, node, un);
      }
    }
    if (tsum / k > 0) {
      printf("%lld %d %d\n", tsum / k, vertex[0], un);
    }
    tsum = sum - (sum - v) % k;
    assert((tsum - v) % k == 0);
    if ((tsum - v) / k > 0)
      printf("%lld %d %d\n", (tsum - v) / k, un, vertex[0]);
  } else {
    printf("NO\n");
  }
}
int main() {
  solve();
  return 0;
}
