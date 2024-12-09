#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b[100005], i, j;
  cin >> a;
  for (i = 1; i <= a; i++) {
    cin >> b[i];
  }
  vector<int> v;
  int maxn = 0;
  for (i = a; i >= 1; i--) {
    if (maxn < b[i]) {
      v.push_back(0);
    } else if (maxn > b[i]) {
      v.push_back(maxn - b[i] + 1);
    } else if (maxn == b[i]) {
      v.push_back(1);
    }
    if (maxn < b[i]) {
      maxn = b[i];
    }
  }
  reverse(v.begin(), v.end());
  for (i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
}
