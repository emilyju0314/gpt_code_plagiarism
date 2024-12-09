#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long x, y, n;
  cin >> n >> x >> y;
  long long a[n + 5], i, c = 0;
  string s;
  cin >> s;
  for (i = n - 1; i > (n - x - 1); i--) {
    if (s[i] == '1') {
      c++;
    }
  }
  if (s[n - y - 1] == '0') {
    c++;
  } else {
    c = c - 1;
  }
  cout << c;
  return 0;
}
