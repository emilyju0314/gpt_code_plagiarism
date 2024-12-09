#include <bits/stdc++.h>
using namespace std;
long long run(long long n) {
  if (n % 2LL == 0LL) {
    if ((n / 2LL) % 2LL == 0LL && n != 4LL) {
      n--;
    } else {
      n >>= 1LL;
    }
  } else {
    n--;
  }
  return n;
}
long long cal_ans(long long n) {
  long long ans = 0LL;
  while (n > 0LL) {
    long long update = run(n);
    ans += n - update;
    n = run(update);
  }
  return ans;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    cout << cal_ans(n) << endl;
  }
}
