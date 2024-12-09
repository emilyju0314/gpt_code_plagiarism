#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int j = 0; j < n; j++) {
      int p;
      cin >> p;
      mp[p - 1] = j;
    }
    int mx = 0;
    int mi = n + 1;
    string answer = "";
    for (int j = 0; j < n; j++) {
      mx = max(mx, mp[j]);
      mi = min(mi, mp[j]);
      if ((mx - mi) == j) {
        answer += "1";
      } else {
        answer += "0";
      }
    }
    cout << answer << endl;
  }
}
