#include <bits/stdc++.h>
using namespace std;
long long n, m, t, a, k, x, w;
long long ans, ind;
string s;
int main() {
  cin >> n;
  cin >> s;
  if (n == 1) {
    cout << s << endl;
    return 0;
  }
  for (int i = 0; i < n; i++)
    if (s[i] == '0') k++;
  s = "1";
  for (int i = 0; i < k; i++) s += '0';
  cout << s << endl;
}
