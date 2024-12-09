#include <bits/stdc++.h>
using namespace std;
const int maxn = 200001;
struct node {
  long long x, y;
};
bool cmp(node a, node b) { return a.x < b.x; }
node a[maxn];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> a[i].x >> a[i].y;
  long long ans = max(a[0].x + a[0].y - 1, n - a[m - 1].x + a[m - 1].y);
  for (int i = 0; i < m - 1; i++) {
    if (abs(a[i].y - a[i + 1].y) > abs(a[i].x - a[i + 1].x)) {
      printf("IMPOSSIBLE");
      return 0;
    }
    int data = abs(a[i].x - a[i + 1].x) - abs(a[i].y - a[i + 1].y);
    ans = max(ans, max(a[i].y, a[i + 1].y) + data / 2);
  }
  cout << ans << endl;
}
