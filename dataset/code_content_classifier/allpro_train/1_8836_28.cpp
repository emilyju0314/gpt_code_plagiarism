#include <bits/stdc++.h>
using namespace std;
int a[2003];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, i;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  cout << n + 1 << "\n"
       << "1 " << n << " 100000\n";
  for (i = 0; i < n; i++)
    cout << "2 " << i + 1 << " " << a[i] - i - 1 + 100000 << '\n';
}
