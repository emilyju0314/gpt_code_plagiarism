#include <bits/stdc++.h>
using namespace std;
const int len = 4e3 + 5;
const long long mod = 1e9 + 7;
const double pi = acos(-1.0);
struct Node {
  long long v, d, p, vis;
} a[len];
vector<long long> ans;
int main() {
  long long n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i].v >> a[i].d >> a[i].p;
  for (int i = 1; i <= n; ++i) {
    if (a[i].vis) continue;
    a[i].vis = 1;
    ans.push_back(i);
    long long x = a[i].v, y = 0;
    for (int j = i + 1; j <= n; ++j) {
      if (a[j].vis) continue;
      a[j].p -= x + y;
      if (a[j].p < 0) {
        y += a[j].d;
        a[j].vis = 1;
      }
      x -= 1;
      if (x < 0) x = 0;
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
}
