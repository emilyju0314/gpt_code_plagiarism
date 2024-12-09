#include <bits/stdc++.h>
using namespace std;
const int size = 110000, mod = 1000000009;
const double pi = acos(-1.0);
vector<int> ar;
int main() {
  int n, h, i, a, t1, t2, ans = 1000000000, id;
  cin >> n >> h;
  for (int i = 1; i < n + 1; i++) {
    cin >> a, ar.push_back(a);
    if (ans > a) ans = a, id = i;
  }
  sort(ar.begin(), ar.end());
  t1 = ar[n - 1] + ar[n - 2] - ar[0] - ar[1];
  t2 = max(ar[n - 1] + ar[0] + h, ar[n - 1] + ar[n - 2]) -
       min(ar[0] + ar[1] + h, ar[1] + ar[2]);
  cout << min(t1, t2) << endl;
  ;
  for (int i = 1; i <= n; i++)
    if (i == id && t2 < t1)
      cout << 1 << ' ';
    else
      cout << 2 << ' ';
  cout << endl;
  return 0;
}
