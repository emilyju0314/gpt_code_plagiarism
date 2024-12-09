#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define loop for(;;)
#define trace(var) cerr<<">>> "<<#var<<" = "<<var<<endl;
#define inf (1e9)
#define eps (1e-9)

int main() {
  string s;
  int ans = 0;
  while (getline(cin, s)) {
    transform(begin(s), end(s), begin(s), [](char c){ return isdigit(c) ? c : ' '; });
    stringstream ss(s);
    int x;
    while (ss >> x) ans += x;
  }
  cout << ans << endl;

  return 0;
}