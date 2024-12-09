#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t) {
    t--;
    int n;
    cin >> n;
    string s;
    cin >> s;
    string r = "";
    for (int i = 0; i < n; i++) {
      r.push_back(s[2 * i]);
    }
    cout << r << endl;
  }
}
