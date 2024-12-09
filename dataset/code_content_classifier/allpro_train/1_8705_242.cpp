#include <bits/stdc++.h>
using namespace std;
int main() {
  string snum;
  cin >> snum;
  for (int i = snum.size() - 1; i >= 0; --i) snum += snum[i];
  cout << snum << endl;
  return 0;
}
