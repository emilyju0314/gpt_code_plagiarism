#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
T power(T N, T P) {
  return (P == 0) ? 1 : N * power(N, P - 1);
}
long long toInt64(string s) {
  long long r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
double LOG(long long N, long long B) { return (log10l(N)) / (log10l(B)); }
string itoa(long long a) {
  if (a == 0) return "0";
  string ret;
  for (long long i = a; i > 0; i = i / 10) ret.push_back((i % 10) + 48);
  reverse(ret.begin(), ret.end());
  return ret;
}
vector<string> token(string a, string b) {
  const char *q = a.c_str();
  while (count(b.begin(), b.end(), *q)) q++;
  vector<string> oot;
  while (*q) {
    const char *e = q;
    while (*e && !count(b.begin(), b.end(), *e)) e++;
    oot.push_back(string(q, e));
    q = e;
    while (count(b.begin(), b.end(), *q)) q++;
  }
  return oot;
}
int Set(int N, int pos) { return N = N | (1 << pos); }
int Reset(int N, int pos) { return N = N & ~(1 << pos); }
int check(int N, int pos) { return (N & (1 << pos)); }
int toggle(int N, int pos) {
  if (check(N, pos)) return N = Reset(N, pos);
  return N = Set(N, pos);
}
void PBIT(int N) {
  printf("(");
  for (int i = 10; i >= 0; i--) {
    bool x = check(N, i);
    cout << x;
  }
  puts(")");
}
queue<long long> q[4][100003];
long long k[5], t[5], arr[100003], sav[100003];
int main() {
  for (int i = 0; i < (int)3; i++) cin >> k[i];
  for (int i = 0; i < (int)3; i++) cin >> t[i];
  int n;
  cin >> n;
  for (int i = 0; i < (int)n; i++) {
    cin >> arr[i];
    sav[i] = arr[i];
  }
  for (int i = 0; i < (int)3; i++) k[i] = (k[i] > n) ? n : k[i];
  for (int i = 0; i < (int)3; i++)
    for (int j = 0; j < (int)n; j++) q[i][j % k[i]].push(j);
  for (int i = 0; i < (int)3; i++)
    for (int j = 0; j < (int)k[i]; j++) {
      long long lp = 0;
      while (q[i][j].size()) {
        int p = q[i][j].front();
        q[i][j].pop();
        arr[p] = max(lp, arr[p]) + t[i];
        lp = arr[p];
      }
    }
  long long ans = 0;
  for (int i = 0; i < (int)n; i++) {
    ans = max(ans, arr[i] - sav[i]);
  }
  cout << ans << endl;
  return 0;
}
