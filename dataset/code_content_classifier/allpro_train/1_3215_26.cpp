#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long double PI = 3.14159265358979323846264338328;
const long long mx64 = 9223372036854775807;
const int mx32 = 2147483647;
const short int mx16 = 32767;
const long long mod1 = 1000000007;
const long long mod2 = 998244353;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(25);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> cnt(26);
    for (int i = 0; i < n; i++) {
      cnt[s[i] - 97]++;
      cnt[t[i] - 97]++;
    }
    bool cont = false;
    for (int i = 0; i < 26; i++) {
      if (cnt[i] % 2 == 1) {
        cont = true;
      }
    }
    if (cont) {
      cout << "No" << endl;
      continue;
    }
    vector<pair<int, int>> ans;
    while (s != t) {
      vector<int> dif;
      for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
          dif.push_back(i);
        }
      }
      if (dif.size() == 2) {
        if (s[dif[0]] == s[dif[1]] && t[dif[0]] == t[dif[1]]) {
          swap(s[dif[0]], t[dif[1]]);
          ans.push_back({dif[0], dif[1]});
        } else {
          swap(s[dif[0]], t[dif[1]]);
          ans.push_back({dif[0], dif[1]});
          swap(s[dif[1]], t[dif[1]]);
          ans.push_back({dif[1], dif[1]});
        }
      } else {
        bool fff = false;
        for (int i = 1; i < dif.size(); i++) {
          if (t[dif[i]] == s[dif[0]]) {
            swap(s[dif[i]], t[dif[i]]);
            ans.push_back({dif[i], dif[i]});
            swap(s[dif[i]], t[dif[0]]);
            ans.push_back({dif[i], dif[0]});
            fff = true;
            break;
          }
        }
        if (!fff) {
          for (int i = 1; i < dif.size(); i++) {
            if (s[dif[i]] == s[dif[0]]) {
              swap(s[dif[i]], t[dif[0]]);
              ans.push_back({dif[i], dif[0]});
              break;
            }
          }
        }
      }
    }
    cout << "Yes" << endl;
    if (ans.size()) {
      cout << ans.size() << endl;
      for (int i = 0; i < ans.size(); i++) {
        cout << (ans[i].first + 1) << " " << (ans[i].second + 1) << endl;
      }
    }
  }
  return 0;
}
