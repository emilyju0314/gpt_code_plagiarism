#include <bits/stdc++.h>
using namespace std;
int T;
string s;
int N, K;
int p[500010], e[500010];
map<long long, int> mp[20];
long long power(long long x, long long n) {
  if (n == 0) return 1;
  long long y = power(x, n / 2);
  y = y * y % 1000000007ll;
  if (n % 2 == 1) y = y * x % 1000000007ll;
  return y;
}
void update_mp(void) {
  int i, j;
  mp[0][0]++;
  for ((i) = 0; (i) < (int)(K); (i)++) {
    int pr = p[i];
    vector<long long> masks(pr);
    for ((j) = 0; (j) < (int)(T); (j)++) masks[j % pr] |= (1ll << j);
    for (__typeof((mp[i]).begin()) itr = (mp[i]).begin(); itr != (mp[i]).end();
         itr++) {
      long long mask = (itr->first);
      int cnt = (itr->second);
      for ((j) = 0; (j) < (int)(pr); (j)++) {
        long long mask2 = (mask | masks[j]);
        mp[i + 1][mask2] = (mp[i + 1][mask2] + cnt) % 1000000007ll;
      }
    }
  }
}
long long dp[500010][50];
long long func(void) {
  int i, j;
  for (__typeof((mp[K]).begin()) itr = (mp[K]).begin(); itr != (mp[K]).end();
       itr++) {
    long long mask = (itr->first);
    long long cnt = (itr->second);
    bool good = true;
    int covered = 0;
    for ((i) = 0; (i) < (int)(T); (i)++) {
      if (mask & (1ll << i)) {
        if (s[i] == '0') good = false;
        if (s[i] == '1') covered++;
      }
    }
    if (good) dp[K][covered] = (dp[K][covered] + cnt) % 1000000007ll;
  }
  int ones = 0;
  for ((i) = 0; (i) < (int)(T); (i)++)
    if (s[i] == '1') ones++;
  for (i = K; i < N; i++) {
    long long pr = p[i];
    for ((j) = 0; (j) < (int)(ones + 1); (j)++) {
      dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * (pr - T)) % 1000000007ll;
      dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * j) % 1000000007ll;
      if (j < ones)
        dp[i + 1][j + 1] =
            (dp[i + 1][j + 1] + dp[i][j] * (ones - j)) % 1000000007ll;
    }
  }
  return dp[N][ones];
}
int main(void) {
  int i;
  cin >> s >> N;
  for ((i) = 0; (i) < (int)(N); (i)++) scanf("%d%d", &p[i], &e[i]);
  T = s.length();
  for ((i) = 0; (i) < (int)(T); (i)++) s[i] = ((s[i] == '0') ? '1' : '0');
  long long prod = 1;
  for ((i) = 0; (i) < (int)(N); (i)++)
    prod = prod * power(p[i], e[i] - 1) % 1000000007ll;
  sort(p, p + N);
  while (K < N && p[K] < 40) K++;
  update_mp();
  long long ans = func();
  ans = ans * prod % 1000000007ll;
  cout << ans << endl;
  return 0;
}
