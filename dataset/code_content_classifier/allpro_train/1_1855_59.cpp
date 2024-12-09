#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[4];
  for (int i = 0; i < 4; i++) scanf("%d", &a[i]);
  ;
  string s;
  cin >> s;
  int su = 0;
  for (int i = 0; i < s.length(); i++) su += a[s[i] - '1'];
  cout << su << endl;
}
