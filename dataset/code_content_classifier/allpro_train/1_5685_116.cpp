#include <bits/stdc++.h>
using namespace std;
template <class _T_>
void read(_T_& d) {
  d = 0;
  int f = 1;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f *= -1;
  for (; c >= '0' && c <= '9'; c = getchar()) d = d * 10 + c - '0';
  d *= f;
}
const double eps = 1e-9;
struct Node {
  double x, y;
} p[2205], rt, P;
Node operator+(Node A, Node B) { return (Node){A.x + B.x, A.y + B.y}; }
Node operator-(Node A, Node B) { return (Node){A.x - B.x, A.y - B.y}; }
Node operator*(Node A, double B) { return (Node){A.x * B, A.y * B}; }
Node operator/(Node A, double B) { return (Node){A.x / B, A.y / B}; }
double operator*(Node A, Node B) { return A.x * B.x + A.y * B.y; }
bool operator==(Node A, Node B) { return A.x == B.x && A.y == B.y; }
int res, n, a;
pair<double, int> PP[2205];
bool Doit(int x) {
  P = (p[a] + p[x]) * .5;
  Node var = rt - P;
  var = (Node){var.y, -var.x};
  for (int i = 1; i <= n; ++i) {
    PP[i] = make_pair(var * p[i], i);
  }
  sort(PP + 1, PP + n + 1);
  int G = 0;
  for (int i = 1; i <= n; ++i) {
    if (PP[i].second == x) G += i;
    if (PP[i].second == a) G += i;
  }
  if (G != n + 1) return 0;
  for (int i = 1; i <= n; ++i) {
    if (abs(PP[i].first + PP[n - i + 1].first - PP[1].first - PP[n].first) >
        eps)
      return 0;
  }
  return 1;
}
int main() {
  read(n);
  res = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%lf%lf", &p[i].x, &p[i].y);
    rt = rt + p[i];
  }
  rt = rt / n;
  for (int i = 1; i <= n; ++i) {
    int A = 1;
    for (int j = 1; j <= n; ++j)
      if (p[i] + p[j] == rt + rt) A = 0;
    if (A) {
      a = i;
      goto Turtle;
    }
  }
  return puts("-1"), 0;
Turtle:
  for (int i = 1; i <= n; ++i)
    if (Doit(i)) ++res;
  printf("%d\n", res);
  return 0;
}
