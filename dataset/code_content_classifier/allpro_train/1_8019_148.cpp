#include <bits/stdc++.h>
using namespace std;
int a, b, n;
int main() {
  cin >> n >> a >> b;
  pair<int, int> s[n];
  for (int i = 0; i < n; i++) {
    cin >> s[i].first;
    s[i].second = i;
    if (a < b) {
      s[i].first = -s[i].first;
    }
  }
  if (b == a) {
    for (int i = 0; i < a; i++) {
      cout << 1 << " ";
    }
    for (int i = 0; i < b; i++) {
      cout << 2 << " ";
    }
  } else {
    sort(s, s + n);
    int c[n];
    for (int i = 0; i < a; i++) {
      c[s[i].second] = 1;
    }
    for (int i = a; i < n; i++) {
      c[s[i].second] = 2;
    }
    for (int i = 0; i < n; i++) {
      cout << c[i] << " ";
    }
  }
}
