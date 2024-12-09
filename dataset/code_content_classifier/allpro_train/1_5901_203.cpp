#include <bits/stdc++.h>
using namespace std;
string s;
int k;
set<pair<string, int> > ms;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> s >> k;
  for (int i = 0; i < s.size(); i++) ms.insert({s.substr(i, 1), i + 1});
  for (int i = 0; i < k - 1; i++) {
    if (ms.empty()) {
      cout << "No such line.";
      return 0;
    }
    auto u = *ms.begin();
    ms.erase(ms.begin());
    if (u.second == s.size()) continue;
    ms.insert({u.first + s[u.second], u.second + 1});
  }
  cout << ms.begin()->first;
}
