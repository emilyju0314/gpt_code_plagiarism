#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int a[m];
  for (int i = 0; i < m; i++) {
    scanf("%d", &a[i]);
  }
  int c, po = 0;
  for (int i = 0; i < m; i++) {
    mp[a[i]]++;
    c = 0;
    for (int j = 1; j <= n; j++) {
      if (mp[j] > 0) c++;
    }
    if (c == n) {
      po++;
      for (int j = 1; j <= n; j++) {
        mp[j]--;
      }
    }
  }
  cout << po << endl;
}
