#include <bits/stdc++.h>
using namespace std;
int main() {
  map<string, int> mp;
  vector<string> vec;
  string s;
  int n, m, v;
  double k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> s >> v;
    if (v >= 100) {
      mp[s] = k * v + 1e-9;
      if (mp[s] >= 100)
        vec.push_back(s);
      else
        mp[s] = 0;
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> s;
    if (!mp[s]) vec.push_back(s);
  }
  sort(vec.begin(), vec.end());
  cout << vec.size() << "\n";
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " " << mp[vec[i]] << "\n";
  }
}
