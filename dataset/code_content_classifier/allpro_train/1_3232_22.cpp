#include <bits/stdc++.h>
using namespace std;
signed main() {
  string s;
  cin >> s;
  string turn = "First";
  map<char, long long> mp;
  for (long long i = 0; i < s.length(); i++) mp[s[i]]++;
  while (mp.size() > 1) {
    bool flag = true;
    long long odd = 0;
    for (auto x : mp) {
      if (x.second & 1) odd++;
    }
    if (odd == 1) break;
    for (auto it = mp.begin(); it != mp.end(); it++) {
      long long v = it->second;
      if (v & 1) {
        if (turn == "First")
          turn = "Second";
        else
          turn = "First";
        it->second--;
        if (it->second == 0) {
          auto jt = it;
          mp.erase(jt);
        }
        flag = false;
        break;
      }
    }
    if (flag) break;
  }
  cout << turn << endl;
}
