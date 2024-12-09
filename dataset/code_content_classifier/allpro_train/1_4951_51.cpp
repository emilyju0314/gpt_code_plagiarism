#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while ((c < '0' || c > '9') && c ^ '-') c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - 48;
    c = getchar();
  }
  return x * f;
}
int n;
int main() {
  n = read();
  cout << 4 + (n * 3) << "\n";
  cout << "0 0\n";
  for (int i = 0; i <= n; i++) {
    cout << i + 1 << " " << i << "\n";
    cout << i << " " << i + 1 << "\n";
    cout << i + 1 << " " << i + 1 << "\n";
  }
  return 0;
}
