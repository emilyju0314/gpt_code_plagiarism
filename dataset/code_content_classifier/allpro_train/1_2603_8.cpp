#include <bits/stdc++.h>
using namespace std;
void use_cio() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
template <typename... Args>
void dbg(Args... args) {
  ((cout << args << " "), ...);
  cout << "\n";
}
int n, m;
int main() {
  use_cio();
  cin >> n >> m;
  if (n > m) swap(n, m);
  if (n == 1) {
    if (m % 6 < 4)
      cout << (m / 6) * 6;
    else
      cout << (m / 6) * 6 + ((m % 6) - 3) * 2;
  } else if (n == 2) {
    if (m == 2)
      cout << 0;
    else if (m == 3)
      cout << 4;
    else if (m == 7)
      cout << 12;
    else
      cout << 1LL * n * m;
  } else {
    cout << (1LL * n * m / 2) * 2;
  }
}
