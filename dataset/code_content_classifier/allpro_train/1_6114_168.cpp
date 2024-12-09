#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int n, i, mn = INT_MAX, c = 1, z = 0;
  cin >> n;
  vector<int> v, v1;
  for (i = 0; i < n; i++) {
    cin >> z;
    v.push_back(z);
    v1.push_back(i - v[i]);
  }
  for (i = n - 1; i > 0; i--) {
    if (v1[i] < mn) mn = v1[i];
    if (i - 1 < mn) c++;
  }
  cout << c;
}
