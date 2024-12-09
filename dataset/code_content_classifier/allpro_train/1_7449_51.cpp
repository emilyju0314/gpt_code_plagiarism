#include <bits/stdc++.h>
using namespace std;
long long int p[1000000];
void solve() {
  long long int l = 1, r = 0, a, b;
  char c;
  cin >> a;
  while (a--) {
    cin >> c >> b;
    if (c == 'L')
      p[b] = --l;
    else if (c == 'R')
      p[b] = ++r;
    else {
      cout << min(p[b] - l, r - p[b]) << endl;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
