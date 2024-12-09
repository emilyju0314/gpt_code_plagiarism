#include <bits/stdc++.h>
using namespace std;
string s;
int coos;
map<char, int> cnt;
string getcoos(int nos) {
  string p = "";
  for (auto y : cnt) {
    int t = (y.second + nos - 1) / nos;
    for (int j = 0; j < t; j++) p += (char)(y.first);
  }
  return p;
}
int main() {
  cin >> s;
  cin >> coos;
  int n = s.size();
  for (int i = 0; i < n; i++) cnt[s[i]]++;
  int lo = 1, hi = 1e6;
  int ans = -1;
  while (lo <= hi) {
    int nos = lo + (hi - lo) / 2;
    if (getcoos(nos).size() > coos) {
      lo = nos + 1;
    } else {
      ans = nos;
      hi = nos - 1;
    }
  }
  cout << ans << endl;
  if (ans != -1) {
    string p = getcoos(ans);
    cout << p;
    for (int i = p.size(); i < coos; i++) cout << 'a';
  }
}
