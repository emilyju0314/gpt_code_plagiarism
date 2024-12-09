#include <bits/stdc++.h>
using namespace std;
int main() {
  int drinks = 0, j = 1, p;
  cin >> p;
  string m;
  cin >> m;
  for (int i = p; i < m.length(); i += p) {
    if (m[i - 1] == m[i - 2] && m[i - 2] == m[i - 3]) {
      drinks++;
    }
  }
  cout << drinks;
}
