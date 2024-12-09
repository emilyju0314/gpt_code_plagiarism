#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string st;
  cin >> st;
  sort(st.begin(), st.end());
  string ans;
  for (int i = 0; i < 100; i++) ans.push_back('z');
  if (k == 1) {
    cout << int(st[0]) - 96;
    return 0;
  }
  int ok = 1;
  for (int i = 0; i < n && ok; i++) {
    string t;
    t.push_back(st[i]);
    int lt = i;
    int r = 0;
    for (int j = i + 1; j < n && ok; j++) {
      if (int(st[lt]) + 2 <= int(st[j])) {
        t = t + st[j];
        if (t.size() == k) {
          ans = t;
          ok = 0;
        }
        lt = j;
        r++;
      }
    }
  }
  if (ans.size() == 100)
    cout << -1;
  else {
    int r = 0;
    for (int i = 0; i < k; i++) r += (int(ans[i]) - 96);
    cout << r << endl;
  }
  return 0;
}
