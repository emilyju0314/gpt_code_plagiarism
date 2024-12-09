#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  long long ans = 0;
  int x;
  for (int i = 1; i <= N; i++) {
    cin >> x;
    ans += x * i;
  }
  cout << ans;
}
