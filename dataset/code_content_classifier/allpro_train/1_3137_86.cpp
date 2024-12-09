#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  getline(cin, a);
  getline(cin, b);
  int w4 = 0, w7 = 0;
  for (int i = 0; i < a.length(); i++)
    if (a[i] != b[i])
      if (a[i] == '7')
        w7++;
      else
        w4++;
  cout << w4 + w7 - min(w7, w4) << endl;
}
