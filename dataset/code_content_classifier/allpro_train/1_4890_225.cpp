#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s1;
  string s2;
  int sum = 0;
  cin >> n;
  cin >> s1;
  cin >> s2;
  for (int i = 0; i < n; i++) {
    int cha1;
    cha1 = abs(s1[i] - s2[i]);
    if (cha1 < 5)
      sum += cha1;
    else
      sum += 10 - cha1;
  }
  cout << sum << endl;
  return 0;
}
