#include <bits/stdc++.h>
using namespace std;
int N, m[400000], t[400000], a[200000], n[400000], o[200000];
int f(int x, int p) {
  int r = 1;
  for (int i = a[x]; i; i = n[i]) {
    if (m[i] == p) continue;
    int u = f(m[i], x);
    if (t[i] == 2 || u == 2) r = 2;
    if (u == 1 && t[i] == 2) o[++o[0]] = m[i];
  }
  return r;
}
int main() {
  cin >> N;
  for (int i = 1; i < N; ++i) {
    cin >> m[i] >> m[i + N] >> t[i];
    n[i + N] = a[m[i]];
    a[m[i]] = i + N;
    n[i] = a[m[i + N]];
    a[m[i + N]] = i;
    t[i + N] = t[i];
  }
  f(1, 0);
  cout << o[0] << endl;
  for (int i = 1; i <= o[0]; ++i) {
    if (i) cout << ' ';
    cout << o[i];
  }
  cout << endl;
}