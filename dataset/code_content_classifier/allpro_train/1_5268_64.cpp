#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
typedef long long ll;
int main() {
  while(1) {
    int n;
    cin >> n;
    if(n == 0) break;
    int num, ans = 0;
    int a, b, c;
    rep(i, n) {
      cin >> a >> b >> c;
     if(ans < b + c) {
        num = a;
        ans = b + c;
      }
    }
    cout << num << " " << ans << endl;
  }
  return 0;
}
