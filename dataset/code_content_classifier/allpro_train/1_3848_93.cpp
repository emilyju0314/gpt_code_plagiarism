#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100;
string s[MAX_N];
int div(int n) {
  int ans = 0;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) ans += 2;
  }
  int u = sqrt(n);
  if (u * u == n) ans--;
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int a[100] = {0};
  int n;
  cin >> n;
  int l, r;
  cin >> l >> r;
  n--;
  while (n--) {
    int x, y;
    cin >> x >> y;
    for (int i = x; i < y; i++) {
      a[i]++;
    }
  }
  int c = 0;
  for (int i = l; i < r; i++) {
    if (a[i] <= 0) c++;
  }
  cout << c << endl;
  return 0;
}
