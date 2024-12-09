#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long INF = 1e12;
const int MOD = 1e9 + 7;
const unsigned long long BIT_FLAG_0 = (1 << 0);
const unsigned long long BIT_FLAG_1 = (1 << 1);
const unsigned long long BIT_FLAG_2 = (1 << 2);
const unsigned long long BIT_FLAG_3 = (1 << 3);
const unsigned long long BIT_FLAG_4 = (1 << 4);
const unsigned long long BIT_FLAG_5 = (1 << 5);
const unsigned long long BIT_FLAG_6 = (1 << 6);
const unsigned long long BIT_FLAG_7 = (1 << 7);
const long long dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const long long Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1},
                Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
void print() { cout << "\n"; }
template <class Head, class... Tail>
void print(Head &&head, Tail &&...tail) {
  cout << head;
  if (sizeof...(tail) != 0) cout << " ";
  print(forward<Tail>(tail)...);
}
template <class T>
void print(vector<T> &vec) {
  for (auto &a : vec) {
    cout << a;
    if (&a != &vec.back()) cout << " ";
  }
  cout << "\n";
}
template <class T>
void print(vector<vector<T>> &df) {
  for (auto &vec : df) {
    print(vec);
  }
}
long long power(long long a, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a;
    a *= a;
    n >>= 1;
  }
  return res;
}
long long comb(long long n, long long k) {
  vector<vector<long long>> v(n + 1, vector<long long>(n + 1, 0));
  for (long long i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (long long k = 1; k < v.size(); k++) {
    for (long long j = 1; j < k; j++) {
      v[k][j] = (v[k - 1][j - 1] + v[k - 1][j]);
    }
  }
  return v[n][k];
}
void add(long long &a, long long b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
__attribute__((constructor)) void faster_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}
vector<vector<long long>> calcNext(const string &S) {
  long long n = (long long)S.size();
  vector<vector<long long>> res(n + 1, vector<long long>(26, n));
  for (long long i = n - 1; i >= 0; --i) {
    for (long long j = 0; j < 26; ++j) res[i][j] = res[i + 1][j];
    res[i][S[i] - 'a'] = i;
  }
  return res;
}
long long n, k;
signed main() {
  cin >> n >> k;
  string S;
  cin >> S;
  long long n = (long long)S.size();
  vector<vector<long long>> next = calcNext(S);
  vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
  dp[0][0] = 1;
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < 26; ++j) {
      if (next[i][j] >= n) continue;
      for (long long k = 0; k < n; ++k) {
        dp[next[i][j] + 1][k + 1] += dp[i][k];
      }
    }
  }
  vector<long long> dp_after(n + 1);
  for (long long kj = 0; kj < (long long)(n + 1); kj++) {
    long long temp = 0;
    for (long long ni = 0; ni < (long long)(n + 1); ni++) {
      temp += dp[ni][kj];
    }
    dp_after[kj] = temp;
  }
  long long cnt = 0, ans = 0;
  bool ok = false;
  for (long long ki = (long long)(n + 1) - 1; ki >= 0; ki--) {
    if (cnt + dp_after[ki] <= k) {
      if (cnt + dp_after[ki] == k) ok = true;
      cnt += dp_after[ki];
      ans += (n - ki) * dp_after[ki];
    } else {
      ans += (n - ki) * (k - cnt);
      ok = true;
    }
    if (ok) break;
  }
  if (!ok)
    print(-1);
  else
    print(ans);
}
