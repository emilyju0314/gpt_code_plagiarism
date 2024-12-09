#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger &operator,(const T &v) {
    cerr << v << "\t";
    return *this;
  }
} dbg;
template <class T>
void setmax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
void setmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
T Abs(T x) {
  return x > 0 ? x : -x;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline T Mod(T n, T m) {
  return (n % m + m) % m;
}
template <class T>
string toString(T n) {
  ostringstream oss;
  oss << n;
  oss.flush();
  return oss.str();
}
int toInt(string s) {
  int r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
bool isVowel(char ch) {
  ch = tolower(ch);
  if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    return true;
  return false;
}
bool isUpper(char c) { return c >= 'A' && c <= 'Z'; }
bool isLower(char c) { return c >= 'a' && c <= 'z'; }
long long Pow(long long B, long long P) {
  long long R = 1;
  while (P > 0) {
    if (P % 2 == 1) R = (R * B);
    P /= 2;
    B = (B * B);
  }
  return R;
}
long long BigMod(long long B, long long P, long long M) {
  long long R = 1;
  while (P > 0) {
    if (P % 2 == 1) {
      R = (R * B) % M;
    }
    P /= 2;
    B = (B * B) % M;
  }
  return (int)R;
}
void binprint(long long mask, long long n) {
  long long i;
  string s = "";
  do {
    s += (mask % 2 + '0');
    mask /= 2;
  } while (mask);
  reverse(s.begin(), s.end());
  s = string(max(n - (int)s.size(), 0LL), '0') + s;
  for (i = (int)s.size() - n; i < (int)s.size(); i++) printf("%c", s[i]);
  printf("\n");
}
void ASCII_Chart() {
  int i, j, k;
  printf("ASCII Chart:(30-129)\n");
  for (i = 30; i < 50; i++) {
    for (j = 0; j < 5; j++) {
      k = i + j * 20;
      printf("%3d---> '%c'   ", k, k);
    }
    printf("\n");
  }
}
long long memo[105][105];
long long dp[105][10010];
long long N, M;
long long nCr(long long n, long long r) {
  if (n == 0) return !r;
  long long &ret = memo[n][r];
  if (ret != -1) return ret;
  ret = nCr(n - 1, r);
  if (r) ret += nCr(n - 1, r - 1);
  ret %= 1000000007;
  return ret;
}
long long memo2[105][105];
long long recBigMod(int i, int pos) {
  if (nCr(N, i) == 1) return 1;
  long long &ret = memo2[i][pos];
  if (ret != -1) return ret;
  long long p = (M - pos + N - 1) / N;
  ret = BigMod(nCr(N, i), p, 1000000007);
  return ret;
}
long long rec(long long pos, long long rem) {
  if (pos >= N) return !rem;
  if (rem == 0) return 1;
  long long &ret = dp[pos][rem];
  if (ret != -1) return ret;
  ret = 0;
  for (int i = 0; i <= N && i <= rem; i++) {
    long long val = recBigMod(i, pos);
    val = (val * rec(pos + 1, rem - i)) % 1000000007;
    ret += val;
  }
  ret %= 1000000007;
  return ret;
}
int main() {
  int i, j, test, Case = 1;
  long long K;
  while (scanf("%I64d %I64d %I64d", &N, &M, &K) == 3) {
    memset(dp, -1, sizeof(dp));
    memset(memo, -1, sizeof(memo));
    memset(memo2, -1, sizeof(memo2));
    long long ans = rec(0, K);
    cout << ans << endl;
  }
  return 0;
}
