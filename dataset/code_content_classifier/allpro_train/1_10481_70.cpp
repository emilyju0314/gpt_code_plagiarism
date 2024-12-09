#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
};
bool compare(node a, node b) { return (a.x - a.y) > (b.x - b.y); }
int main() {
  long long n, m, i, j, p, q, sum = 0, c = 0;
  cin >> n >> m;
  struct node arr[n];
  for (i = 0; i < n; i++) {
    cin >> p >> q;
    arr[i].x = p, arr[i].y = q;
  }
  sort(arr, arr + n, compare);
  for (i = 0; i < n; i++) {
    sum = sum + arr[i].x;
  }
  if (sum <= m) {
    cout << 0 << endl;
    return 0;
  }
  for (i = 0; i < n; i++) {
    sum = sum - arr[i].x + arr[i].y;
    c++;
    if (sum <= m) {
      cout << c << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
