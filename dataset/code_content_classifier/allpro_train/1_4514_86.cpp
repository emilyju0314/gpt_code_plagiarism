#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;
inline int min(int a, int b) { return a < b ? a : b; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string str;
  cin >> str;
  int ans = 0;
  int marki = 0, markj = 0;
  for (int i = 0; i < str.size(); i++) {
    for (int j = i; j < str.size(); j++) {
      swap(str[i], str[j]);
      int cnt = 0;
      int minn = 0;
      for (int k = 0; k < str.size(); k++) {
        if (str[k] == '(')
          cnt++;
        else
          cnt--;
        minn = min(minn, cnt);
      }
      int now1 = 0;
      if (cnt == 0) {
        for (int k = 0; k < str.size(); k++) {
          if (str[k] == '(')
            cnt++;
          else
            cnt--;
          if (cnt == minn) now1++;
        }
      }
      if (now1 > ans) {
        ans = now1;
        marki = i;
        markj = j;
      }
      swap(str[i], str[j]);
    }
  }
  cout << ans << endl << marki + 1 << " " << markj + 1 << endl;
  return 0;
}
