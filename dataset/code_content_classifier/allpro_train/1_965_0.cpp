#include <bits/stdc++.h>
using namespace std;
int main() {
  ifstream ifile("input.txt");
  if (ifile) freopen("input.txt", "rt", stdin);
  if (ifile) freopen("output.txt", "wt", stdout);
  string s;
  cin >> s;
  int r;
  cin >> r;
  if (s == "front") {
    if (r == 1)
      cout << "L";
    else
      cout << "R";
  } else {
    if (r == 1)
      cout << "R";
    else
      cout << "L";
  }
  return 0;
}
