#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    int d;
    cin >> d;
    mp[d]++;
  }
  
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int t;
    cin >> t;
    if (mp[t] == 0) {
      puts("NO");
      return 0;
    }
    mp[t]--;
  }
  puts("YES");
  return 0;
}