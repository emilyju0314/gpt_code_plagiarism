#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
  int n;
  string s;
  cin >> n >> s;

  int ans = 0;
  int cnt = 0;
  for (int i = 0; i < n; i ++) {
    if (s[i] == 'x' && cnt == 1) break;
    else if (s[i] == 'x') cnt = 1;
    else cnt = 0;
    
    ans ++;
  }

  cout << ans << endl;
}

