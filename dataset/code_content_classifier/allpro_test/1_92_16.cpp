#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  long long ct = 0;
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] == 'a' && s[i + 1] == 'b')
      ct++;
    else if (s[i] == 'b' && s[i + 1] == 'a')
      ct--;
  }
  if (ct == 0) {
    cout << s << endl;
  } else if (ct == 1) {
    for (int i = 0; i < s.size() - 1; i++) {
      cout << s[i];
    }
    cout << "a\n";
  } else {
    for (int i = 0; i < s.size() - 1; i++) {
      cout << s[i];
    }
    cout << "b\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  ;
  cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
