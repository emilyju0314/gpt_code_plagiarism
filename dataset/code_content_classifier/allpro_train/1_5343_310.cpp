#include <bits/stdc++.h>
using namespace std;
int solve(int a, int b, int c, int d) {
  if (a == c && b == d) return -1;
  if (a == c || a == d) return a;
  if (b == c || b == d) return b;
  return -1;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int> > a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i].first >> b[i].second;
    if (b[i].first > b[i].second) swap(b[i].first, b[i].second);
  }
  vector<int> canBe(10);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int first = solve(a[i].first, a[i].second, b[j].first, b[j].second);
      if (first != -1) canBe[first] = 1;
    }
  int cnt = 0;
  for (int i : canBe) cnt += i;
  if (cnt == 1) {
    for (int i = 0; i < 10; i++)
      if (canBe[i]) cout << i << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    int ans = -1;
    for (int j = 0; j < m; j++) {
      int first = solve(a[i].first, a[i].second, b[j].first, b[j].second);
      if (first == -1) continue;
      if (ans == -1) ans = first;
      if (ans != first) ans = -2;
    }
    if (ans == -2) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (int j = 0; j < m; j++) {
    int ans = -1;
    for (int i = 0; i < n; i++) {
      int first = solve(a[i].first, a[i].second, b[j].first, b[j].second);
      if (first == -1) continue;
      if (ans == -1) ans = first;
      if (ans != first) ans = -2;
    }
    if (ans == -2) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}
