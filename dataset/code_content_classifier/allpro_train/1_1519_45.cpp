#include <bits/stdc++.h>
using namespace std;
int x[1000000], p[1000001];
int main() {
  int n;
  cin >> n;
  vector<int> v(n), t;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    x[v[i]] = 1;
  }
  for (int i = n; i > 0; i--) {
    if (x[i] != 1) t.push_back(i);
  }
  for (int i = 0; i < n; i++) {
    if (v[i] <= n && !p[v[i]]) {
      cout << v[i] << " ";
      p[v[i]] = 1;
    } else {
      cout << t[t.size() - 1] << " ";
      t.pop_back();
    }
  }
  return 0;
}
