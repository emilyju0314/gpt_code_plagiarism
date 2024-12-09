#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, m;
  map<int, bool> mp;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    mp[a] = 1;
  }
  i = 1;
  vector<int> v;
  while (m - i >= 0) {
    if (mp[i] == 0) {
      m = m - i;
      v.push_back(i);
    }
    i++;
  }
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  return 0;
}
