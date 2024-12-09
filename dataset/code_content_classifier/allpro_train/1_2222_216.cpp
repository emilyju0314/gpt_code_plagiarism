#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int maximum = 0;
  int count = 0;
  char s[n + 1];
  char a[1];
  cin.getline(a, 0);
  cin.getline(s, n + 1);
  for (int i = 0; i < n; i++) {
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == ' ') {
      count = 0;
    } else if ('A' <= s[i] and s[i] <= 'Z') {
      count++;
      maximum = max(maximum, count);
    }
  }
  cout << maximum << endl;
}
