#include <bits/stdc++.h>
using namespace std;
const int MAX = 501;
int arr[MAX], n, k;
bitset<MAX> mem[MAX][MAX], vis[MAX][MAX];
bool ans[MAX];
bool dp(int idx, int s1, int s2) {
  if (idx == n) return (ans[s2] |= s1 == k), s1 == k;
  bool ret = mem[idx][s1][s2];
  if (vis[idx][s1][s2]) return ret;
  vis[idx][s1][s2] = 1;
  ret = dp(idx + 1, s1, s2);
  if (s1 + arr[idx] <= k) {
    ret |= dp(idx + 1, s1 + arr[idx], s2);
    ret |= dp(idx + 1, s1 + arr[idx], s2 + arr[idx]);
  }
  return (ans[s2] |= ret), mem[idx][s1][s2] = ret;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> arr[i];
  dp(0, 0, 0);
  int cnt = 0;
  for (int i = 0; i <= k; i++) cnt += ans[i];
  cout << cnt << '\n';
  for (int i = 0; i <= k; i++)
    if (ans[i]) cout << i << ' ';
  return 0;
}
