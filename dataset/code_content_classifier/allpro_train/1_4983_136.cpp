#include <bits/stdc++.h>
using namespace std;
string s;
int L, N;
int main() {
  int a, koks = 0;
  cin >> a >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '_' or s[i] == '(') {
      if (koks != 0) L = max(L, koks);
      koks = 0;
    } else
      koks++;
    if (s[i] == '(') {
      i++;
      int lel = 0;
      while (s[i] != ')') {
        if (s[i] == '_') {
          if (lel != 0) N++;
          lel = 0;
        } else
          lel++;
        i++;
      }
      if (lel != 0) N++;
    }
  }
  if (koks != 0) L = max(L, koks);
  cout << L << " " << N;
}
