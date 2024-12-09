#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:268435456")
using namespace std;
const double PI = 3.1415926535897932384626433832795;
template <class T>
T min(T &a, T &b) {
  return (a < b) ? a : b;
}
template <class T>
T max(T &a, T &b) {
  return (a > b) ? a : b;
}
template <class T>
T sqr(T &a) {
  return a * a;
}
template <class T>
T abs(T &a) {
  return (a < 0) ? (-a) : a;
}
inline void read(int &x) { scanf("%d", &x); }
inline void readln(int &x) { scanf("%d\n", &x); }
inline void write(int x) { printf("%d", x); }
inline void writeln(int x) { printf("%d\n", x); }
inline void read(long long &x) { scanf("%lld", &x); }
inline void readln(long long &x) { scanf("%lld\n", &x); }
inline void write(long long x) { printf("%lld", x); }
inline void writeln(long long x) { printf("%lld\n", x); }
inline void read(double &x) { scanf("%lf", &x); }
inline void readln(double &x) { scanf("%lf\n", &x); }
inline void write(double x) { printf("%.15lf", x); }
inline void writeln(double x) { printf("%.15lf\n", x); }
inline void read(char *s) { scanf("%s", s); }
inline void readln(char *s) { scanf("%s\n", s); }
inline void write(char *s) { printf("%s", s); }
inline void writeln(char *s) { printf("%s\n", s); }
inline int readInt() {
  int x;
  read(x);
  return x;
}
inline long long readLong() {
  long long x;
  read(x);
  return x;
}
inline double readDouble() {
  double x;
  read(x);
  return x;
}
long long hl, hr, n;
char buf[100];
long long sc[104];
long long a[104];
long long b[104];
bool top[104];
string s;
long long best = 0;
void solve() {
  for (int i = 0; i < ((int)(n + 1)); i++) {
    long long yl = 100 - hl;
    long long yr = (i % 2 == 0) ? (100 + 100 * i - hr) : (100 * i + hr);
    long long score = 0;
    long long cnt = 0;
    for (int j = 0; j < ((int)(n)); j++) {
      long long xa = a[j];
      long long xb = b[j];
      long long koe = (top[j] ? 0 : 100);
      long long leftcount =
          (yl * 100000 + (yr - yl) * xa + koe * 100000) / (200 * 100000);
      long long rightcount =
          (yl * 100000 + (yr - yl) * xb + koe * 100000) / (200 * 100000);
      if ((yl * 100000 + (yr - yl) * xa + koe * 100000) % (200 * 100000) == 0)
        --leftcount;
      long long count = rightcount - leftcount;
      if (count > 1) score -= 1000000000;
      if (count == 1) {
        ++cnt;
        score += sc[j];
      }
    }
    if (cnt != i) score -= 1000000000;
    best = max(score, best);
  }
}
int main() {
  cin >> hl >> hr >> n;
  for (int i = 0; i < ((int)(n)); i++) {
    cin >> sc[i] >> s >> a[i] >> b[i];
    if (s[0] == 'T') top[i] = true;
  }
  solve();
  for (int i = 0; i < ((int)(n)); i++) top[i] = !top[i];
  hl = 100 - hl;
  hr = 100 - hr;
  solve();
  cout << best;
}
