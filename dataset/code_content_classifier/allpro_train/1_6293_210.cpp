#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      string tmp = s.substr(0, i);
      s = s.substr(i, n);
      reverse(tmp.begin(), tmp.end());
      s = tmp + s;
    }
  }
  cout << s << endl;
}
