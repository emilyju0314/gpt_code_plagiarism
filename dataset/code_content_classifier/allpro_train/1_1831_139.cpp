#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a == 0) {
    return b;
  } else {
    return gcd(b % a, a);
  }
}
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    string s;
    string t;
    cin >> s;
    cin >> t;
    bool good = true;
    int c_s[26] = {0};
    int c_t[26] = {0};
    for (int i = 0; i < n; i++) {
      c_s[s[i] - 'a']++;
    }
    for (int i = 0; i < n; i++) {
      c_t[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      if (c_s[i] != c_t[i]) {
        good = false;
        break;
      }
    }
    if (!good) {
      cout << -1 << endl;
      continue;
    }
    int answer = 1;
    for (int i = 0; i < n; i++) {
      int counter = 0;
      int k = 0;
      for (int j = i; j < n; j++) {
        for (int l = k; l < n; l++) {
          if (l == n - 1) {
            k = n;
          }
          if (s[l] == t[j]) {
            counter++;
            k = l + 1;
            break;
          }
        }
        if (k >= n) {
          break;
        }
      }
      answer = max(answer, counter);
    }
    cout << n - answer << endl;
  }
}
