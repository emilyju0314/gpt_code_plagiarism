#include <bits/stdc++.h>
using namespace std;
int n, k, xb, num;
map<int, int> mp;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= k + 1; ++i) {
    cout << "? ";
    for (int j = 1; j <= k + 1; ++j) {
      if (i != j) cout << j << " ";
    }
    cin >> xb >> num;
    mp[num]++;
  }
  cout << "! ";
  cout << k + 1 - (mp.begin()->second);
  return 0;
}
