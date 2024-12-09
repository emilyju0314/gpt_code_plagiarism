#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  string s;
  for (int i = 1; i <= 1000; i++) {
    int t = i;
    string ts;
    while (t) {
      ts.push_back((t % 10) + '0');
      t /= 10;
    }
    for (int j = ts.length() - 1; j >= 0; j--) s.push_back(ts[j]);
  }
  cin >> n;
  cout << s[n - 1] << endl;
  cerr << s.length() << endl;
  return 0;
}
