#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  string s;
  cin >> s;
  long long k, c = 0, g = 0;
  cin >> k;
  vector<char> a;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == '?')
      c++;
    else if (s[i] == '*')
      g++;
  }
  long long n = s.size() - c - g;
  if (g == 0 && k > n) {
    cout << "Impossible";
    return 0;
  }
  if (k < n) {
    if ((c + g) < (n - k)) {
      cout << "Impossible";
      return 0;
    }
  }
  if (k > n) {
    for (long long i = 0; i < s.size(); i++) {
      if (s[i] != '?' && s[i] != '*')
        cout << s[i];
      else if (s[i] == '*') {
        if (k > n) {
          long long h = k - n;
          for (long long j = 0; j < h; j++) {
            cout << s[i - 1];
            n++;
          }
        }
      }
    }
  } else if (k < n) {
    for (long long i = 1; i < s.size(); i++) {
      if (s[i] == '?' || s[i] == '*') {
        if (k < n) {
          n--;
        } else if (s[i - 1] != '?' && s[i - 1] != '*')
          cout << s[i - 1];
      } else if (s[i - 1] != '?' && s[i - 1] != '*')
        cout << s[i - 1];
    }
    if (s[s.size() - 1] != '?' && s[s.size() - 1] != '*')
      cout << s[s.size() - 1];
  } else {
    for (long long i = 0; i < s.size(); i++) {
      if (s[i] != '?' && s[i] != '*') cout << s[i];
    }
  }
}
