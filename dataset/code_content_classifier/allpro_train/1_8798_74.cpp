#include <bits/stdc++.h>
using namespace std;
int id[10][10], cnt;
int fw[400][100005];
int n;
map<int, int> mp;
void upd(int t, int pos, int val) {
  for (; pos <= n; pos += pos & -pos) fw[t][pos] += val;
}
int get(int t, int pos) {
  int res = 0;
  for (; pos; pos -= pos & -pos) res += fw[t][pos];
  return res;
}
string s;
int main() {
  iostream::sync_with_stdio(0);
  cin >> s;
  n = s.size();
  s = '0' + s;
  mp['A'] = 0;
  mp['T'] = 100;
  mp['G'] = 200;
  mp['C'] = 300;
  for (int j = 1; j <= 10; j++)
    for (int i = 0; i < j; i++) id[i][j] = ++cnt;
  for (int i = 1; i <= n; i++) {
    for (int mod = 1; mod <= 10; mod++) {
      upd(mp[s[i]] + id[i % mod][mod], i, 1);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    int l, r;
    if (type == 2) {
      cin >> l >> r;
      string t;
      cin >> t;
      int m = t.size();
      int res = 0;
      for (int i = 0; i < t.size(); i++)
        res += get(mp[t[i]] + id[(i + l) % m][m], r) -
               get(mp[t[i]] + id[(i + l) % m][m], l - 1);
      cout << res << endl;
    } else {
      int pos;
      cin >> pos;
      char mjk;
      cin >> mjk;
      for (int mod = 1; mod <= 10; mod++) {
        upd(mp[s[pos]] + id[pos % mod][mod], pos, -1);
      }
      s[pos] = mjk;
      for (int mod = 1; mod <= 10; mod++) {
        upd(mp[s[pos]] + id[pos % mod][mod], pos, 1);
      }
    }
  }
}
