#include <bits/stdc++.h>
using namespace std;
int n, c;
long long c2, c3;
string s;
bool a[100005];
int main() {
  cin >> n >> c;
  for (int l = 0; l < n; ++l) {
    cin >> s;
    a[l] = (s == "halfplus");
  }
  for (int l = n - 1; l >= 0; --l) {
    c2 *= 2;
    if (a[l]) c2++;
    c3 += c2 * c / 2;
  }
  cout << c3;
  return 0;
}
