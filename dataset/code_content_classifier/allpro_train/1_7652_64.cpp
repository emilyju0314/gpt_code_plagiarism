#include <bits/stdc++.h>
using namespace std;
long long m[1000000], i, k, n, p, x, y, m1[1000000], a, b, m2[1000000];
struct {
  long long n;
  long long a;
  long long b;
  long long d;
} st[300000];
int main() {
  cin >> n >> x >> y;
  for (i = 1; i <= n; i++) {
    cin >> m[i];
  }
  for (i = 0; i < x; i++) {
    cin >> st[i].a >> st[i].b >> st[i].d;
  }
  for (i = 0; i < y; i++) {
    cin >> a >> b;
    m1[a - 1]++;
    m1[b]--;
  }
  for (i = 1; i < x + 1; i++) {
    m1[i] += m1[i - 1];
  }
  for (i = 0; i < x; i++) {
    st[i].n = m1[i];
    m2[st[i].a] += st[i].d * st[i].n;
    m2[st[i].b + 1] -= st[i].d * st[i].n;
  }
  for (i = 1; i <= n; i++) {
    m2[i] += m2[i - 1];
    m[i] += m2[i];
    cout << m[i] << " ";
  }
}
