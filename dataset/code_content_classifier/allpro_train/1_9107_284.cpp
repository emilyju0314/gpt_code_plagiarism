#include <bits/stdc++.h>
using namespace std;
int main() {
  map<long long int, long long int> a;
  int n, b[200001];
  long long int ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    a[b[i] - i] += b[i];
  }
  map<long long int, long long int>::iterator it;
  for (it = a.begin(); it != a.end(); it++) ans = max(ans, it->second);
  cout << ans << endl;
  return 0;
}
