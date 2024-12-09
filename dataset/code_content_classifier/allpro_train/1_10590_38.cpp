#include<bits/stdc++.h>
using namespace std;

void domain_expansion_() {
  int n, k;
  cin >> n >> k;
  string ans = "";
  int c = 0;
  while (ans.size() < n) {
    ans += c + 'a';
    for (int i = c + 1; i < k; i++) {
      ans += c + 'a';
      ans += i + 'a';
    }
    c++;
    c %= k;
  }
  for (int i = 0; i < n; i++) cout << ans[i];
  cout << '\n';
  return;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  // cin >> tt;
  while (tt--) 
    domain_expansion_();
  return 0; 
}