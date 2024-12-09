#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long inf = 1e9 + 10;
const int maxc = 1e5 + 10;
const long long mod = 1e9 + 7;
struct ss {
  int ans;
  int k;
} a[maxc];
int cmp(ss x, ss y) { return x.ans > y.ans; }
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].ans;
    a[i].k = i;
  }
  sort(a + 1, a + 1 + n, cmp);
  long long sum = 0;
  long long l = 0;
  for (int i = 1; i <= n; i++) sum += (i - 1) * a[i].ans + 1;
  cout << sum << endl;
  for (int i = 1; i <= n; i++) cout << a[i].k << " ";
  return 0;
}
