#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long ans = 0;
  string ch;
  cin >> ch;
  for (int i = 0; i < ch.size() - 1; i++) {
    if (ch[i] == 'N') ans++;
  }
  char b = ch[ch.size() - 1];
  if (ans == 1) {
    if (b == 'N') {
      cout << "YES" << endl;
      return;
    }
    cout << "NO" << endl;
    return;
  }
  if (ans == 0) {
    if (b == 'E') {
      cout << "YES" << endl;
      return;
    }
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long test;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
