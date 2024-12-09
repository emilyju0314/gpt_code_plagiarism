#include <bits/stdc++.h>
using namespace std;
int T;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    int X, N;
    string s, t;
    cin >> X >> s;
    N = (int)s.size();
    int p = 0;
    while ((int)s.size() < X) {
      p++;
      int cnt = s[p - 1] - '0' - 1;
      t.clear();
      if (cnt)
        for (int i = p; i < s.size(); i++) t += s[i];
      while (cnt--) s += t;
    }
    long long R = N;
    for (int i = 0; i < X; i++) {
      R--;
      R *= s[i] - '0';
      R %= 1000000007;
    }
    R += X;
    R %= 1000000007;
    R += 1000000007;
    R %= 1000000007;
    cout << R << "\n";
  }
  return 0;
}
