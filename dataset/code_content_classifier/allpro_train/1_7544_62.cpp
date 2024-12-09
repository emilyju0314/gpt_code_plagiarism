#include <bits/stdc++.h>
using namespace std;
long long mex(long long p, long long n) {
  if (n <= 1) return (long long)pow(p, n);
  long long num = mex(p, n / 2);
  if (n % 2)
    return (((num * num) % 1000000007) * p) % 1000000007;
  else
    return (num * num) % 1000000007;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.length() == 1) {
      cout << s << endl;
      continue;
    }
    set<char> ans;
    char now = s[0];
    int c = 1;
    for (int i = 1; i < s.length(); i++) {
      if (s[i] == now)
        c++;
      else {
        if (c % 2) ans.insert(now);
        now = s[i];
        c = 1;
      }
    }
    if (c % 2) ans.insert(now);
    for (auto p : ans) cout << p;
    cout << endl;
  }
  return 0;
}
