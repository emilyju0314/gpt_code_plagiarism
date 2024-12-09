#include <bits/stdc++.h>
using namespace std;
namespace cqz {
static const int GYN = 2333333;
char SZB[GYN], *S = SZB, *T = SZB;
inline char gc() {
  if (S == T) {
    T = (S = SZB) + fread(SZB, 1, GYN, stdin);
    if (S == T) return '\n';
  }
  return *S++;
}
inline long long read() {
  long long x = 0, g = 1;
  char ch = gc();
  for (; !isdigit(ch); ch = gc())
    if (ch == '-') g = -1;
  for (; isdigit(ch); ch = gc()) x = x * 10 - 48 + ch;
  return x * g;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline char readchar() {
  char ch = gc();
  for (; isspace(ch); ch = gc())
    ;
  return ch;
}
inline long long readstr(char *s) {
  char ch = gc();
  int cur = 0;
  for (; isspace(ch); ch = gc())
    ;
  for (; !isspace(ch); ch = gc()) s[cur++] = ch;
  s[cur] = '\0';
  return cur;
}
void Print(long long *a, int s, int t) {
  for (int i = int(s); i <= int(t); ++i) printf("%lld ", a[i]);
}
void Print(int *a, int s, int t) {
  for (int i = int(s); i <= int(t); ++i) printf("%d ", a[i]);
}
void Print(char *a, int s, int t) {
  for (int i = int(s); i <= int(t); ++i) putchar(a[i]);
}
void writeln(long long x) {
  write(x);
  puts("");
}
}  // namespace cqz
using namespace cqz;
const long long N = 600100;
long long x[N], y[N], n, A, B, ans[N], sum[N], answ, cogito;
bool cmp(long long a, long long b) { return a > b; }
int main() {
  n = read(), A = read(), B = read();
  for (int i = int(1); i <= int(n); ++i) {
    x[i] = read(), y[i] = read();
    if (x[i] - y[i] > 0) ans[++ans[0]] = x[i] - y[i];
    cogito += y[i];
  }
  if (!B) return writeln(cogito), 0;
  sort(ans + 1, ans + ans[0] + 1, cmp);
  for (int i = int(1); i <= int(((B) < (ans[0]) ? (ans[0]) : (B))); ++i)
    sum[i] = sum[i - 1] + ans[i];
  for (int i = int(1); i <= int(n); ++i) {
    long long a = x[i] << A;
    if (ans[B] >= (x[i] - y[i]))
      ((answ) =
           ((answ) < (sum[B] - ans[B] +
                      ((a - y[i]) < (0ll) ? (0ll) : (a - y[i])))
                ? (sum[B] - ans[B] + ((a - y[i]) < (0ll) ? (0ll) : (a - y[i])))
                : (answ)));
    else
      ((answ) =
           ((answ) < (sum[B] - ((x[i] - y[i]) < (0ll) ? (0ll) : (x[i] - y[i])) +
                      ((a - y[i]) < (0ll) ? (0ll) : (a - y[i])))
                ? (sum[B] - ((x[i] - y[i]) < (0ll) ? (0ll) : (x[i] - y[i])) +
                   ((a - y[i]) < (0ll) ? (0ll) : (a - y[i])))
                : (answ)));
  }
  writeln(cogito + answ);
}
