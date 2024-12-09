#include <bits/stdc++.h>
using namespace std;
set<char> s;
map<char, int> mp;
int main() {
  int q;
  cin >> q;
  while (q--) {
    long long int n, k, m, i, c = 0, x, y, z;
    string p;
    cin >> p;
    mp.clear();
    for (i = 0; i < p.size(); i++) {
      s.insert(p[i]);
      mp[p[i]]++;
    }
    x = max(mp['P'], max(mp['R'], mp['S']));
    if (mp['R'] == x) {
      for (i = 0; i < p.size(); i++) {
        cout << "P";
      }
    } else if (mp['P'] == x) {
      for (i = 0; i < p.size(); i++) {
        cout << "S";
      }
    } else {
      for (i = 0; i < p.size(); i++) {
        cout << "R";
      }
    }
    cout << endl;
  }
  return 0;
}
