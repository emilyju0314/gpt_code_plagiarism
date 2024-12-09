#include <bits/stdc++.h>
using namespace std;
int f(string s1, string s2) {
  int posa, posc;
  swap(s2[0], s2[1]);
  string ns = s1 + s2;
  int a = 0;
  for (int i = 0; i < 4; i++) {
    if (ns[i] == 'X') continue;
    if (ns[i] == 'A') posa = a;
    if (ns[i] == 'C') posc = a;
    a++;
  }
  if (posc == posa + 1 || posa == 2 && posc == 0) return 1;
  return 0;
}
int main(void) {
  string a1, a2, b1, b2;
  cin >> a1 >> a2 >> b1 >> b2;
  if (f(a1, a2) == f(b1, b2))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
