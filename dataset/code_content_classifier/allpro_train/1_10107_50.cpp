#include <bits/stdc++.h>
using namespace std;
void OUT_TST(string s, istream_iterator<string> it) { cout << s; }
template <typename T, typename... Args>
void OUT_TST(string s, istream_iterator<string> it, T a, Args... args) {
  cerr << *it << "=" << a << " ";
  OUT_TST(s, ++it, args...);
}
template <class T>
void rd(T& ret) {
  ret = 0;
  bool ok = 0, u = 0;
  for (;;) {
    int c = getchar();
    if (c >= '0' && c <= '9')
      ret = (ret << 3) + (ret << 1) + c - '0', ok = 1;
    else if (c == '-')
      u = 1;
    else if (ok) {
      if (u) ret *= -1;
      return;
    }
  }
}
long long powmod(long long p, long long n, long long mod) {
  long long ret = 1;
  for (; n; n >>= 1) {
    if (n & 1) ret = ret * p % mod;
    p = p * p % mod;
  }
  return ret;
}
template <class T>
bool chmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool chmax(T& a, const T& b) {
  return b > a ? a = b, 1 : 0;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
const int N = (int)5e5 + 9;
const int MX = 1 << 30;
int sum[N];
int dp[111][111 * 111];
vector<int> pos[111];
int main() {
  int n, K, p;
  cin >> n >> K >> p;
  for (int i = (0); i < (n); i++) {
    int t;
    scanf("%d", &t);
    sum[i] = t;
    if (i) sum[i] += sum[i - 1];
    sum[i] %= p;
    pos[sum[i]].push_back(i);
  }
  int up = K * (p - 1) + 1;
  for (int i = (0); i < (up); i++) dp[1][i] = MX;
  for (int i = (0); i < (n); i++) {
    chmin(dp[1][sum[i]], i);
  }
  for (int i = (2); i < (K + 1); i++) {
    deque<pair<int, int> > q;
    for (int j = (0); j < (up); j++) {
      while (((int)(q).size()) && q.back().second >= dp[i - 1][j]) q.pop_back();
      q.push_back({j, dp[i - 1][j]});
      dp[i][j] = MX;
      int s = j % p;
      auto it = upper_bound((pos[s]).begin(), (pos[s]).end(), q.front().second);
      if (it != pos[s].end()) {
        dp[i][j] = *it;
      }
      while (((int)(q).size()) && q.front().first <= j - p + 1) q.pop_front();
    }
  }
  for (int i = sum[n - 1] % p; i < up; i += p)
    if (dp[K][i] != MX) {
      printf("%d\n", i);
      return 0;
    }
  return 0;
}
