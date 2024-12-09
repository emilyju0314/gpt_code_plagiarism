#include <bits/stdc++.h>
using namespace std;
int n, a[1000];
string s;
int main() {
  cin >> n >> s;
  if (n == 1) a[s[0]]++;
  for (int i = 0; i < n; i++) a[s[i]]++;
  for (int i = 0; i < 1000; i++) {
    if (a[i] > 1) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}
