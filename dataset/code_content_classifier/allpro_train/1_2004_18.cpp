#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long a = 0, b = 0, c, d, e, f = 0, l, g, m, n, k, i, j, t, p, q;
  string s, ss, st;
  cin >> n >> s;
  l = s.size();
  if (l % n) {
    d = l / n + 1;
    for (i = 0; i < d; i++) {
      cout << 1;
      for (j = 1; j < n; j++) cout << 0;
    }
    return 0;
  }
  ss = s.substr(0, n);
  st = "";
  d = l / n;
  for (i = 0; i < d; i++) {
    for (j = 0; j < n; j++) st.push_back(ss[j]);
  }
  if (st > s) {
    cout << st;
    return 0;
  }
  f = 0;
  for (i = 0; !f && i < n; i++) {
    if (ss[i] != '9') f = 1;
  }
  if (!f) {
    d++;
    for (i = 0; i < d; i++) {
      cout << 1;
      for (j = 1; j < n; j++) cout << 0;
    }
    return 0;
  }
  a = 1;
  for (i = n - 1; a && i >= 0; i--) {
    ss[i]++;
    if (ss[i] > '9') {
      ss[i] = '0';
      a = 1;
    } else
      break;
  }
  for (i = 0; i < d; i++) {
    cout << ss;
  }
  return 0;
}
