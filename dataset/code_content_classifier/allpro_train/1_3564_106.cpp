#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v;
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ara[n];
  for (int i = 0; i < n; i++) {
    if (s[i] == 'W')
      ara[i] = 1;
    else
      ara[i] = 0;
  }
  for (int i = 1; (i + 1) < n; i++) {
    if (ara[i] != ara[i - 1]) {
      ara[i] ^= 1;
      ara[i + 1] ^= 1;
      v.push_back(i + 1);
    }
  }
  if (ara[n - 1] == ara[n - 2]) {
    cout << v.size() << endl;
    for (auto x : v) {
      cout << x << " ";
    }
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == 'W')
      ara[i] = 1;
    else
      ara[i] = 0;
  }
  v.clear();
  v.push_back(1);
  ara[0] ^= 1;
  ara[1] ^= 1;
  for (int i = 1; (i + 1) < n; i++) {
    if (ara[i] != ara[i - 1]) {
      ara[i] ^= 1;
      ara[i + 1] ^= 1;
      v.push_back(i + 1);
    }
  }
  if (ara[n - 1] == ara[n - 2]) {
    cout << v.size() << endl;
    for (auto x : v) {
      cout << x << " ";
    }
    return 0;
  }
  cout << -1 << endl;
}
