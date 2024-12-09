#include <bits/stdc++.h>
using namespace std;
string days[] = {"sunday",   "monday", "tuesday", "wednesday",
                 "thursday", "friday", "saturday"};
int getIdx(string day) {
  for (int i = 0; i < 7; i++) {
    if (days[i] == day) return i;
  }
  return -1;
}
int main() {
  string a, b;
  cin >> a >> b;
  int idx1 = getIdx(a);
  if (a == b)
    cout << "YES\n";
  else {
    int idx2 = getIdx(b);
    if ((idx1 + 31) % 7 == idx2)
      cout << "YES\n";
    else if ((idx1 + 30) % 7 == idx2)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
