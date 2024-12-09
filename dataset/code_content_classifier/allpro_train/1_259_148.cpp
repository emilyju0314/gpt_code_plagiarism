#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  int temp;
  vector<int> ch;
  vector<int> nec;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    if (temp % 2 == 0) {
      ch.push_back(temp);
    } else {
      nec.push_back(temp);
    }
  }
  if (abs((int)ch.size() - (int)nec.size()) < 2) {
    cout << 0;
  } else {
    if (ch.size() > nec.size()) {
      sort(ch.begin(), ch.end());
      int i = 0;
      int ans = 0;
      while (ch.size() - i - nec.size() > 1) {
        ans += ch[i];
        i++;
      }
      cout << ans;
    } else {
      sort(nec.begin(), nec.end());
      int i = 0;
      int ans = 0;
      while (nec.size() - i - ch.size() > 1) {
        ans += nec[i];
        i++;
      }
      cout << ans;
    }
  }
}
