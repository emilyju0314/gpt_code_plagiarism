#include <bits/stdc++.h>
using namespace std;
int main() {
  string second;
  cin >> second;
  string t = second;
  reverse(t.begin(), t.end());
  cout << second + t << "\n";
}
