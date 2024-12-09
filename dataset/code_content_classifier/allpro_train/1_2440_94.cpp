#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  string s, a;
  cin >> s;
  a = s;
  int minb = 0;
  int n = s.size();
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '1' && minb >= 0) a[i] = '0';
    int cur = s[i] == '1' ? 1 : -1;
    minb = min(minb + cur, cur);
  }
  cout << a;
}
