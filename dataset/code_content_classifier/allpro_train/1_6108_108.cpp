#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long int n, sum = 0;
  vector<long long int> my;
  cin >> n;
  for (int i = 1; i <= n; i++)
    (i + 1 <= n - i ? my.push_back(i) : my.push_back(n)), n -= i;
  cout << my.size() << '\n';
  for (auto i : my) cout << i << ' ';
  return 0;
}
