#include <bits/stdc++.h>
using namespace std;
typedef struct {
  long long a, b, c;
} line;
int main() {
  int x1, y1, x2, y2, n;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> n;
  vector<line> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i].a >> arr[i].b >> arr[i].c;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    long long t1 = arr[i].a * x1 + arr[i].b * y1 + arr[i].c;
    long long t2 = arr[i].a * x2 + arr[i].b * y2 + arr[i].c;
    if ((t1 > 0 && t2 < 0) or (t1 < 0 && t2 > 0)) ans += 1;
  }
  cout << ans << "\n";
  return 0;
}
