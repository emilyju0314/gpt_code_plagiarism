#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
const int maxn = 1e7 + 9;
const long long mod = 1e9 + 7;
const long long INF = 1e18 + 9;
const int minn = 1e5 + 9;
const long long N = 2e2;
int a, i, n;
bool ok = false;
string s;
string t[111][2];
string q;
int main() {
  cin >> a >> s;
  n = a;
  if (a % 2 != 0) {
    cout << "contest";
    return 0;
  }
  while (a--) {
    cin >> q;
    t[i][0] = q[0] + q[1] + q[2];
    t[i][1] = q[5] + q[6] + q[7];
    i++;
  }
  for (int i = 0; i < n; i++) {
    bool ok = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (t[i][0] == t[j][1] && t[i][1] == t[j][0]) {
        ok = 1;
      }
    }
    if (!ok) {
      cout << "constest";
      return 0;
    }
  }
  cout << "home";
}
