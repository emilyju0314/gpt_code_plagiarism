#include <bits/stdc++.h>
using namespace std;
int const N = 1000005;
long double pi = 3.14159265359;
long long const mod = 1e9 + 7;
void FAST() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void TXT() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
map<char, int> p;
int main() {
  FAST();
  string s, t;
  cin >> s >> t;
  set<int> x;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != t[i]) {
      if (p[t[i]] == 0 && p[s[i]] == 0) {
        p[t[i]] = s[i];
        p[s[i]] = t[i];
      } else {
        if (p[t[i]] != s[i] || p[s[i]] != t[i]) {
          cout << -1;
          return (0);
        }
      }
    } else {
      if (p[t[i]] == 0 && p[s[i]] == 0) {
        p[t[i]] = s[i];
        p[s[i]] = t[i];
      } else {
        if (p[t[i]] != s[i] || p[s[i]] != t[i]) {
          cout << -1;
          return (0);
        }
      }
    }
  }
  vector<pair<char, char>> ans;
  for (int i = 0; i < 26; i++) {
    if (x.find(i + 'a') == x.end() && p['a' + i] != 0 &&
        p[i + 'a'] != i + 'a') {
      ans.push_back({i + 'a', p[i + 'a']});
      x.insert(i + 'a');
      x.insert(p[i + 'a']);
    }
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << "\n";
  }
}
