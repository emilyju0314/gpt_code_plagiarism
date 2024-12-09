#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m;
  cin >> n >> m;
  cout << (long long)max(n, m) - 1 << " " << min(n, m) << "\n";
  return 0;
}
