#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
int main() {
  srand(1373737);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    set<char> ss;
    for (int i = 0; i < (int)s.size(); i++) ss.insert(s[i]);
    if ((int)ss.size() == 1)
      cout << -1 << '\n';
    else {
      sort(s.begin(), s.end());
      cout << s << '\n';
    }
  }
  return 0;
}
