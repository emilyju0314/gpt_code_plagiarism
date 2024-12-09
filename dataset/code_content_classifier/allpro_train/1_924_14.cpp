#include <bits/stdc++.h>
using namespace std;
const int P = 30;
int n, m;
bool us[P], OK;
vector<string> q;
int differents(string a, string b) {
  int num = 0;
  for (int i = 0; i < n; ++i) num += (a[i] != b[i]);
  return num;
}
bool eq(string a, string b) {
  vector<int> v;
  for (int i = 0; i < n; ++i)
    if (a[i] != b[i]) v.push_back(i);
  if (v.size() == 1 || v.size() > 2) return 0;
  if (v.size() == 0) return OK;
  swap(b[v[0]], b[v[1]]);
  return a == b;
}
bool correct(string st) {
  for (auto it : q)
    if (!eq(st, it)) return false;
  return true;
}
string make_string(string s) {
  if (correct(q[0])) return q[0];
  vector<int> v;
  for (int i = 0; i < n; ++i)
    if (q[0][i] != s[i]) v.push_back(i);
  if (v.size() == 2) {
    for (int i = 0; i < n; ++i) {
      if (i != v[0] && s[i] == s[v[0]]) {
        string now = q[0];
        swap(now[i], now[v[0]]);
        if (correct(now)) return now;
      }
      if (i != v[1] && s[i] == s[v[1]]) {
        string now = q[0];
        swap(now[i], now[v[1]]);
        if (correct(now)) return now;
      }
    }
  }
  do {
    string now = q[0];
    swap(now[v[0]], now[v[1]]);
    if (correct(now)) return now;
  } while (next_permutation(v.begin(), v.end()));
  return "-1";
}
int main() {
  cin >> m >> n;
  for (int i = 0; i < m; ++i) {
    string st;
    cin >> st;
    q.push_back(st);
  }
  for (auto it : q[0]) {
    if (us[it - 'a']) OK = true;
    us[it - 'a'] = true;
  }
  for (auto it : q) {
    int key = differents(q[0], it);
    if (key == 1 || key > 4) {
      cout << -1;
      return 0;
    }
    if (key) {
      cout << make_string(it);
      return 0;
    }
  }
  swap(q[0][0], q[0][1]);
  cout << q[0];
  return 0;
}
