#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  cin >> n >> m;
  vector<int> v(101, 0);
  for (int i = 0; i < m; i++) {
    int temp;
    cin >> temp;
    v[i] = temp;
  }
  vector<int> l(101, 1e9);
  for (int i = 0; i < m; i++) {
    for (int j = v[i]; j <= n; j++)
      if (l[j] == 1e9) l[j] = v[i];
  }
  for (int i = 0; i < n; i++) {
    if (!i)
      cout << l[i + 1];
    else
      cout << " " << l[i + 1];
  }
  cout << " " << endl;
}
