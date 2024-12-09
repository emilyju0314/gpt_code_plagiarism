#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    bool flag = true;
    string p, h;
    cin >> p >> h;
    sort(p.begin(), p.end());
    for (int i = 0; i < h.size(); i++) {
      string temp = h.substr(i, p.size());
      sort(temp.begin(), temp.end());
      if (p == temp) {
        cout << "Yes" << endl;
        flag = !flag;
        break;
      }
    }
    if (flag) cout << "NO" << endl;
  }
  return 0;
}
