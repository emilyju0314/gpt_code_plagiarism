#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  string s;
  cin >> s;
  int l = 0, r = s.size() - 1;
  int cnt = 0;
  while (l < r) {
    if (s[l] == s[r]) {
      l++;
      r--;
      continue;
    } else {
      if (s[l] != 'x' && s[r] != 'x') {
        cout << -1 << endl;
        return 0;
      }
      if (s[l] == 'x') {
        l++;
      } else {
        r--;
      }
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
