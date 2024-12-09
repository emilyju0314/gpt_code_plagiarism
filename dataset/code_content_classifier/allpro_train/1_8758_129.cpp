#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-16;
const int MOD = (int)1e9 + 9;
const long long INF = (int)1e9 + 10;
const int p = 31;
template <typename T>
vector<T> readVector0(int n) {
  vector<T> res(n);
  for (int i = 0; i < n; i++) cin >> res[i];
  return res;
}
template <typename T>
vector<T> readVector1(int n) {
  vector<T> res(n + 1);
  for (int i = 1; i <= n; i++) cin >> res[i];
  return res;
}
inline int mod(int first, int m = MOD) {
  if (first < 0) first += m;
  return (first % m);
}
template <typename T>
bool sortBy2(const pair<T, T> &a, const pair<T, T> &b) {
  return (a.second < b.second);
}
int main() {
  int T;
  cin >> T;
  for (int q = 0; q < T; ++q) {
    string s, t;
    cin >> t >> s;
    int szt = t.size();
    vector<vector<int> > fl(26, vector<int>(szt, -1));
    fl[t[szt - 1] - 'a'][szt - 1] = szt - 1;
    for (int i = szt - 2; i >= 0; i--) {
      for (int j = 0; j < 26; ++j) fl[j][i] = fl[j][i + 1];
      fl[t[i] - 'a'][i] = i;
    }
    int nops = 1;
    int szs = s.size();
    int cur = 0;
    for (int i = 0; i < szs; ++i) {
      if (cur >= szt) {
        cur = 0;
        nops++;
      }
      int c = fl[s[i] - 'a'][cur];
      if (c == -1) {
        if (cur == 0) {
          nops = -1;
          break;
        }
        nops++;
        i--;
        cur = 0;
      } else
        cur = c + 1;
    }
    cout << nops << "\n";
  }
  return 0;
}
