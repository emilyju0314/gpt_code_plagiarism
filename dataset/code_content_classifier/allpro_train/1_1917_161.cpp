#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  vector<int> cnt(26, 0);
  for (auto c : s) {
    bool ok = false;
    for (int i = 0; i + 97 < c; i++) {
      if (cnt[i]) ok = true;
    }
    if (ok) {
      cout << "Ann" << endl;
    } else {
      cout << "Mike" << endl;
    }
    cnt[c - 'a']++;
  }
  return 0;
}
