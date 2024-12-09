#include <bits/stdc++.h>

using namespace std;

bitset <4000010> bs;

int main() {
  int n;
  scanf("%d", &n);
  bs.reset();
  bs.set(0);
  int ans = 0;
  while (n--) {
    int foo;
    scanf("%d", &foo);
    bs |= bs << foo;
    ans += foo;
  }
  ++ans;
  ans /= 2;
  while (bs[ans] == 0) {
    ++ans;
  }
  printf("%d\n", ans);
}
