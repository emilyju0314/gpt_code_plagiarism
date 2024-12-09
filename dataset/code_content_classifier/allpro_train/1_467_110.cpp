#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int mn = 1e9;
  int n;
  cin >> n;
  string s;
  cin >> s;
  int tigers = count(s.begin(), s.end(), 'T');
  s += s;
  int cnt = count(s.begin(), s.begin() + tigers, 'H');
  for (int i = 1; i + tigers - 1 < s.size(); ++i)
    cnt += (s[i + tigers - 1] == 'H') - (s[i - 1] == 'H'), mn = min(mn, cnt);
  cout << mn;
  return 0;
}
