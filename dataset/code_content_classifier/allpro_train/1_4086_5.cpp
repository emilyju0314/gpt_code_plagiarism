#include <bits/stdc++.h>
using namespace std;
char s[2020];
int main() {
  int n, a, b, t;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b;
    int m = 0;
    int p = min(26, b);
    for (int i = 1; i <= n; i++) {
      s[i] = 'a' + m;
      m++;
      m %= p;
      cout << s[i];
    }
    cout << endl;
  }
  return 0;
}
