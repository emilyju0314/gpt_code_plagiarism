#include <bits/stdc++.h>
using namespace std;
template <typename T>
T next_int() {
  T x = 0, p = 1;
  char ch;
  do {
    ch = getchar();
  } while (ch <= ' ');
  if (ch == '-') {
    p = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return p * x;
}
string next_token() {
  char ch;
  string ans = "";
  do {
    ch = getchar();
  } while (ch <= ' ');
  while (ch > ' ') {
    ans += ch;
    ch = getchar();
  }
  return ans;
}
const long long INF = (long long)1e18;
const int INFINT = (int)1e9 + 227 + 1;
const int MAXN = (int)1e6 + 227 + 1;
const int MOD = (int)1e9 + 7;
const long double EPS = 1e-9;
long long bin_pow(long long a, long long b) {
  if (!b) return 1;
  long long ans = bin_pow(a, b / 2);
  ans = ans * ans % MOD;
  if (b % 2) ans = ans * a % MOD;
  return ans;
}
bool used[MAXN];
void build_prime() {
  for (int i = 2; i < MAXN; i++) {
    if (used[i]) continue;
    for (int j = i + i; j < MAXN; j += i) {
      used[j] = 1;
    }
  }
}
bool check(int a) {
  if (!a) return 1;
  for (int i = 2; i * i <= a; i++)
    if (a % i == 0) return 1;
  return 0;
}
int dp[MAXN];
int full(int n) {
  int ans = n / 4;
  while (ans >= 0 && !check(n - ans * 4)) ans--;
  if (ans != -1 && ans * 4 != n) ans += dp[n - ans * 4];
  return ans;
}
int main() {
  build_prime();
  for (int i = 0; i * i <= MAXN; i++) dp[i] = -INFINT;
  dp[0] = 0;
  for (int j = 2; j * j <= MAXN; j++) {
    if (!used[j]) continue;
    for (int i = 0; i * i <= MAXN; i++) {
      dp[i + j] = max(dp[i + j], dp[i] + 1);
    }
  }
  int test;
  cin >> test;
  while (test--) {
    int n = next_int<int>();
    cout << full(n) << "\n";
  }
}
