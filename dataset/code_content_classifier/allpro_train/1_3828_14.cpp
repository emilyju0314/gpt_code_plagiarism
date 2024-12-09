#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  scanf("%d", &x);
  bitset<6> bs(x);
  string s = bs.to_string();
  swap(s[1], s[5]);
  swap(s[2], s[3]);
  bitset<6> bs2(s);
  cout << bs2.to_ullong() << endl;
  return 0;
}
