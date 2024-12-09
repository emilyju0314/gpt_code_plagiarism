#include <bits/stdc++.h>
using namespace std;
int n, p = 131, out[131 * 131], in[131 * 131];
vector<int> al[131 * 131];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  char c, c1, c2;
  for (int i = 0; i < n; ++i) {
    cin >> c >> c1 >> c2;
    al[c + c1 * 131].push_back(c1 + c2 * 131);
    in[c1 + c2 * 131]++;
    out[c + c1 * 131]++;
  }
  int st = -1, en = -1;
  for (int i = 0; i < 131 * 131; ++i) {
    if (in[i] == out[i]) continue;
    if (abs(in[i] - out[i]) > 1) {
      cout << "NO" << endl;
      exit(0);
    }
    if (in[i] == out[i] - 1) {
      if (st != -1) {
        cout << "NO" << endl;
        exit(0);
      }
      st = i;
    }
    if (in[i] - 1 == out[i]) {
      if (en != -1) {
        cout << "NO" << endl;
        exit(0);
      }
    }
  }
  if (st == -1 && en != -1) {
    cout << "NO" << endl;
    exit(0);
  }
  if (st == -1) {
    for (int i = 0; i < 131 * 131; ++i) {
      if (in[i] != 0) {
        st = i;
        break;
      }
    }
  }
  stack<int> sta;
  vector<int> pa;
  int cur = st;
  while (sta.size() || al[cur].size()) {
    if (al[cur].size() == 0) {
      pa.push_back(cur);
      cur = sta.top();
      sta.pop();
    } else {
      sta.push(cur);
      cur = al[cur].back();
      al[sta.top()].pop_back();
    }
  }
  pa.push_back(cur);
  if (pa.size() - 1 < n) {
    cout << "NO" << endl;
    exit(0);
  }
  reverse((pa).begin(), (pa).end());
  string ans;
  for (int i = 0; i < pa.size(); ++i) {
    char x = pa[i] % 131, y = pa[i] / 131;
    if (ans.size() == 0) {
      ans += x;
      ans += y;
    } else
      ans += y;
  }
  cout << "YES" << endl << ans << endl;
  return (0);
}
