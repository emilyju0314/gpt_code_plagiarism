#include <bits/stdc++.h>
using namespace std;
int n;
string s;
vector<int> pi;
void pref_fun() {
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[j] != s[i]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
}
int main() {
  cin >> s;
  n = s.size();
  pi.resize(n);
  pref_fun();
  int ans = pi.back();
  if (ans == 0) {
    cout << "Just a legend";
    return 0;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (ans == pi[i]) {
      cnt++;
    }
  }
  if (cnt > 1) {
    for (int i = 0; i < ans; i++) {
      cout << s[i];
    }
    return 0;
  } else {
    ans = pi[pi[n - 1] - 1];
    if (ans == 0) {
      cout << "Just a legend";
      return 0;
    } else {
      for (int i = 0; i < ans; i++) {
        cout << s[i];
      }
    }
  }
}
