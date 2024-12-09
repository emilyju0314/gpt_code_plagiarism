#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    string s, s1 = "", s2 = "";
    cin >> n >> s;
    long long int x = 0;
    for (long long int i = 0; i < n; i++) {
      if (s[i] == '0') {
        s1 += '0';
        s2 += '0';
      } else if (s[i] == '1') {
        if (x == 0) {
          s1 += '1';
          s2 += '0';
          x = 1;
        } else {
          s2 += '1';
          s1 += '0';
        }
      } else {
        if (x == 0) {
          s1 += '1';
          s2 += '1';
        } else {
          s1 += '0';
          s2 += '2';
        }
      }
    }
    cout << s1 << "\n" << s2 << "\n";
  }
  return 0;
}
