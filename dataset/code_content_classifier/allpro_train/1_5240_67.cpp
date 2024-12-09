#include <bits/stdc++.h>
using namespace std;
int n, a[200];
double q[200], bas[200];
struct node {
  double v;
  int x;
  bool operator<(const node &t) const { return v < t.v; }
};
priority_queue<node> que;
double update(int x) { return (1 - bas[x] * q[x]) / (1 - bas[x]); }
int main() {
  cin >> n;
  double ans = n, p = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    q[i] = double(100 - a[i]) / 100;
    bas[i] = q[i];
    que.push({update(i), i});
    p *= double(a[i]) / 100;
  }
  for (int i = n; i <= 300000; i++) {
    ans += 1 - p;
    node now = que.top();
    que.pop();
    p *= now.v;
    bas[now.x] *= q[now.x];
    que.push({update(now.x), now.x});
  }
  cout << setiosflags(ios::fixed) << setprecision(15) << ans << endl;
  return 0;
}
