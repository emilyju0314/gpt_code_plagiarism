#include <bits/stdc++.h>
using namespace std;
string alpha = "abcdefghijklmnopqrstuvwxyz";
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    unordered_map<char, int> freq;
    for (auto &i : s) freq[i]++;
    int m;
    cin >> m;
    vector<int> b(m);
    for (auto &i : b) cin >> i;
    vector<int> I(m);
    for (int i = 0; i < m; i++) I[i] = i;
    vector<char> ans(m, '.');
    int z = 0;
    while (I.size()) {
      sort(I.begin(), I.end(), [&](int i, int j) { return b[i] < b[j]; });
      int z = 0;
      while (z < I.size() && !b[I[z]]) z++;
      for (int i = 26 - 1; i >= 0; i--) {
        char c = alpha[i];
        if (freq[c] < z)
          freq[c] = 0;
        else {
          for (int j = 0; j < z; j++) ans[I[j]] = c;
          freq[c] = 0;
          break;
        }
      }
      vector<int> temp;
      for (int i = 0; i < m; i++) {
        if (ans[i] != '.') continue;
        for (int j = 0; j < z; j++) b[i] -= abs(i - I[j]);
      }
      for (int i = z; i < I.size(); i++) temp.push_back(I[i]);
      I = temp;
    }
    for (auto &i : ans) cout << i;
    cout << "\n";
  }
}
