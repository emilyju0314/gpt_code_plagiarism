#include <bits/stdc++.h>
template <typename T>
T inline SQR(const T& a) {
  return a * a;
}
template <typename T>
T inline ABS(const T& a) {
  return a < 0 ? -a : a;
}
template <typename T>
T inline MIN(const T& a, const T& b) {
  if (a < b) return a;
  return b;
}
template <typename T>
T inline MAX(const T& a, const T& b) {
  if (a > b) return a;
  return b;
}
using namespace std;
int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false);
  int n;
  string curstr, sep;
  int cur, sz = 0;
  cin >> n;
  list<string> wrds[11];
  string a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    cur = (int)a[i].size();
    sz += cur;
  }
  cin >> sep;
  sz = (2 * sz) / n;
  for (int i = 0; i < n; ++i) {
    a[i] += sep;
    wrds[(int)a[i].size() - 1].push_back(a[i]);
  }
  sort(a, a + n);
  for (int i = 0; i < 11; ++i) wrds[i].sort();
  for (int i = 0; i < n; ++i) {
    curstr = a[i];
    cur = (int)curstr.size() - 1;
    if (wrds[cur].empty() || *wrds[cur].begin() != curstr) continue;
    wrds[cur].pop_front();
    string nxt = *wrds[sz - cur].begin();
    wrds[sz - cur].pop_front();
    cout << a[i] << nxt.substr(0, sz - cur) << endl;
  }
  return 0;
}
