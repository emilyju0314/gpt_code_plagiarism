#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
string s;
bool judge(int a, int b) {
  if (a > b) swap(a, b);
  if (a == 3 && b == 3) return true;
  if (a == 4 && b == 6) return true;
  if (a == 5 && b == 9) return true;
  if (a == 7 && b == 7) return true;
  if (a == 0 && b == 8) return true;
  return false;
}
int main() {
  cin >> s;
  int ok = 1;
  for (int i = 0; i <= (int)s.size() - 1; ++i) {
    if (!judge(s[i] - '0', s[s.size() - i - 1] - '0')) ok = 0;
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
