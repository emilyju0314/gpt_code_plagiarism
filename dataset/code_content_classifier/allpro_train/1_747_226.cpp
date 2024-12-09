#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int INF = 1000 * 1000 * 1000 + 21;
const long long int LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;
const int MAX_N = 100 * 1000 + 228;
int n;
long long int arr[MAX_N];
long long int at[MAX_N];
vector<long long int> now;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
  long long int cnt = 0;
  for (int i = 0; i < n; ++i) {
    now.push_back(i);
    while (cnt <= arr[i]) {
      ++cnt;
      ++at[now.back()];
      now.pop_back();
    }
  }
  for (int i = 1; i < n; ++i) at[i] += at[i - 1];
  long long int ans = 0;
  for (int i = 0; i < n; ++i) ans += at[i] - arr[i] - 1;
  printf("%lld\n", ans);
  return 0;
}
