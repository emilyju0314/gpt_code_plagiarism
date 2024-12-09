#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) { return a > b; }
int main() {
  int n, k, s[5] = {0};
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> k;
    s[k]++;
  }
  sort(s + 1, s + 4, cmp);
  cout << n - s[1];
  return 0;
}
