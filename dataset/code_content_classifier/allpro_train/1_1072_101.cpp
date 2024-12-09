#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-9;
const int MAXN = 102400;
int n, x;
int a[MAXN];
int b[MAXN];
int main() {
  cin >> n >> x;
  for (long long i = 0; i < n; ++i) cin >> a[i];
  for (long long i = 0; i < n; ++i) cin >> b[i];
  sort(a, a + n);
  sort(b, b + n);
  reverse(b, b + n);
  int cnt = 1;
  int pa = 0;
  while (a[pa] + b[0] < x) ++pa;
  int push_back = 0;
  while (true) {
    ++push_back;
    ++pa;
    if (push_back >= n || pa >= n) break;
    while (pa < n && a[pa] + b[push_back] < x) ++pa;
    if (push_back >= n || pa >= n) break;
    ++cnt;
  }
  cout << 1 << " " << cnt << endl;
}
