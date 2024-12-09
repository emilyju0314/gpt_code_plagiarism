#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int first = a[2];
  sort(a, a + n);
  int second = a[0];
  cout << 2 + (first ^ second);
  return 0;
}
