#include <bits/stdc++.h>
using namespace std;
void hehe() {
  int n;
  cin >> n;
  if (n < 6) {
    cout << -1 << "\n";
  } else {
    for (int i = 2; i <= n - 2; i++) {
      cout << 1 << " " << i << "\n";
    }
    cout << 2 << " " << n - 1 << "\n" << 2 << " " << n << "\n";
  }
  for (int i = 2; i <= n; i++) {
    cout << 1 << " " << i << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    hehe();
  }
  return 0;
}
