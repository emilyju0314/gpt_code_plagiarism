#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int boy, girl, n;
  cin >> boy >> girl >> n;
  if (boy + girl == n) {
    cout << 1 << "\n";
    return 0;
  }
  if (boy >= n)
    cout << min(n, girl) + 1 << '\n';
  else if (girl >= n)
    cout << min(n, boy) + 1 << '\n';
  else {
    int maxx = max(boy, girl);
    int minn = min(boy, girl);
    cout << maxx - (n - minn) + 1 << '\n';
  }
}
