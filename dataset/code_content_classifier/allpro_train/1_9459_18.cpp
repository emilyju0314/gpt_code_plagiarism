#include <bits/stdc++.h>
using namespace std;
long long int btd(vector<int> v) {
  long long int i, j, ans = 0, x = 0;
  for (i = v.size() - 1; i >= 0; i--) {
    ans += pow(2, x) * v[i];
    x++;
  }
  return ans;
}
vector<int> dtb(long long int num) {
  vector<int> v(64);
  long long int i = 0, j, x = 1;
  while (num > 0) {
    v[i] = num % 2;
    num = num / 2;
    i++;
  }
  reverse(v.begin(), v.end());
  return (v);
}
int main() {
  long long int n, m, i, j, k, cnt = 0, sum = 0, mn = INT_MAX, mx = INT_MIN,
                               ans, num, diff;
  int flag = 0, t = 1;
  string s, st, str, s1, s2, s3;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while (t--) {
    long long int u, v;
    cin >> u >> v;
    if (u > v || (v - u) % 2 == 1) {
      cout << -1;
      return 0;
    }
    if (v == 0) {
      cout << 0;
      return 0;
    }
    if (u == v) {
      cout << 1 << endl << u;
      return 0;
    }
    vector<int> v1, v2(64), v3(64);
    v1 = dtb(u);
    diff = v - u;
    vector<int> d = dtb(diff);
    for (i = 62; i >= 0; i--) {
      if (d[i] == 1) {
        v2[i + 1] = 1;
        if (v1[i + 1] == 0) {
          v1[i + 1] = 1;
        } else {
          v3[i + 1] = 1;
        }
      }
    }
    if (btd(v3) == 0) {
      cout << 2 << endl << btd(v1) << " " << btd(v2);
    } else {
      cout << 3 << endl << btd(v1) << " " << btd(v2) << " " << btd(v3);
    }
  }
}
