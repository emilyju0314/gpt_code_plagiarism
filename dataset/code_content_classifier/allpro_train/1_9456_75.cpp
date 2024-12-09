#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long long int INF = 10000000000;
const long long int MAX_N = 1e6 + 2;
void solve() {
  string s;
  cin >> s;
  int space = 0, n = s.size();
  stack<char> stk;
  for (int i = 0; i < n - 3; ++i) {
    if (isalpha(s[i + 1]) != 0) {
      for (int j = 0; j < space; j++) cout << " ";
      cout << s[i] << s[i + 1] << s[i + 2] << "\n";
      space += 2, i += 2;
    } else {
      space -= 2;
      for (int j = 0; j < space; j++) cout << " ";
      cout << s[i] << s[i + 1] << s[i + 2] << s[i + 3] << "\n";
      i += 3;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  t = 1;
  while (t--) solve();
}
