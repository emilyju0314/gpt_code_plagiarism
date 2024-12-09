#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100005;
int t;
int main() {
  scanf("%d", &t);
  while (t--) {
    ll x;
    scanf("%lld", &x);
    bool can = false;
    for (int i = 1; i <= 6; i++) {
      if (x < (21 - i)) continue;
      can |= (x - (21 - i)) % 14 == 0;
    }
    printf("%s\n", can ? "YES" : "NO");
  }
}
