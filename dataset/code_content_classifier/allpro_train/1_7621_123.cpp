#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long inf = 1e18;
void FastInputOutput() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  int n;
  cin >> n;
  int a[n], b[101];
  memset(b, 0, sizeof(b));
  for (int i = 0; i < (int)(n); ++i) {
    cin >> a[i];
    b[a[i]]++;
  }
  sort(b, b + 101, greater<int>());
  cout << b[0];
  return 0;
}
