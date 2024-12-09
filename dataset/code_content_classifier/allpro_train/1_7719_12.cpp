#include <bits/stdc++.h>
using namespace std;
const int max_n = 300022, inf = 1000111222;
int k, n, a, b;
char s[max_n];
int main() {
  cin >> k;
  while (k--) {
    cin >> a >> b;
    scanf("%s", s);
    n = strlen(s);
    vector<int> v;
    int cntt = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '.') {
        ++cntt;
      } else {
        if (cntt && cntt >= b) {
          v.push_back(cntt);
        }
        cntt = 0;
      }
    }
    if (cntt && cntt >= b) {
      v.push_back(cntt);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    if (v.empty() || v.size() >= 2 && v[1] >= 2 * b || v.back() < a) {
      cout << "NO\n";
      continue;
    }
    if (v[0] < 2 * b) {
      cout << (v.size() % 2 == 0 ? "NO\n" : "YES\n");
      continue;
    }
    bool good = false;
    int cnt = v.size() - 1;
    for (int i = 0; i + a <= v[0]; ++i) {
      int x = i, y = v[0] - a - i;
      if (x >= 2 * b || y >= 2 * b || x >= b && x < a || y >= b && y < a)
        continue;
      if ((cnt + (x >= a) + (y >= a)) % 2 == 0) {
        good = true;
      }
    }
    cout << (good ? "YES\n" : "NO\n");
  }
  return 0;
}
