#include <bits/stdc++.h>
using namespace std;
void setIO(string name) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
}
template <typename T>
void PVecPrint(vector<T>& v) {
  for (int i = 0; i < (int)v.size(); i++)
    cout << v[i].first << "," << v[i].second << ' ';
  cout << '\n';
}
template <class T>
void VecPrint(vector<T>& v) {
  for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
  cout << '\n';
}
long long int func1(int a, int b, int m) {
  int b1 = max(0, b - m);
  int m1 = max(0, m - b);
  a -= m1;
  return a - b1;
}
pair<long long int, long long int> func(int a, int b, int m) {
  long long int v = func1(a, b, m), v1 = -func1(b, a, m);
  return {min(v1, v), max(v1, v)};
}
pair<long long int, long long int> func(
    pair<long long int, long long int> curr,
    pair<long long int, long long int> allowed, long long int needed) {
  if (curr.first + allowed.second <= needed)
    return {needed - allowed.second, allowed.second};
  return {curr.first, needed - curr.first};
}
int main() {
  int te;
  cin >> te;
  while (te--) {
    int n, m;
    cin >> n >> m;
    long long int l = 0, r = 0;
    vector<pair<long long int, long long int> > v, lims, dish;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      dish.push_back({x, y});
      pair<long long int, long long int> limits = func(x, y, m);
      l += limits.first;
      r += limits.second;
      lims.push_back(limits);
      v.push_back({l, r});
    }
    long long int ans = 0;
    if (l >= 0 and r >= 0) {
      cout << l << '\n';
      ans = l;
    } else if (l <= 0 and r <= 0) {
      cout << abs(r) << '\n';
      ans = -r;
    } else {
      if (abs(l) % 2 == 0)
        cout << "0\n";
      else {
        cout << "1\n";
        ans = 1;
      }
    }
    vector<long long int> imp(n);
    for (int i = n - 2; i > -1; i--) {
      pair<long long int, long long int> t = func(v[i], lims[i + 1], ans);
      ans = t.first;
      imp[i + 1] = t.second;
    }
    pair<long long int, long long int> t = func({0, 0}, lims[0], ans);
    imp[0] = t.second;
    for (int i = 0; i < n; i++) {
      long long int x = dish[i].first - dish[i].second + m - imp[i];
      x /= 2;
      cout << x << ' ' << m - x << '\n';
    }
  }
}
