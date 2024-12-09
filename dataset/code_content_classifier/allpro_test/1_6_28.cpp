#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
int n;
unordered_map<int, int> mp;
int phi[maxn];
vector<int> num1[maxn];
vector<int> num2;
int mul(int a, int b, int p) {
  int ans = 0;
  for (; b; b >>= 1, a = (a + a) % p)
    if (b & 1) ans = (ans + a) % p;
  return ans;
}
void phi_table(int n) {
  phi[1] = 1;
  for (int i = 2; i <= n; i++)
    if (!phi[i]) {
      for (int j = i; j <= n; j += i) {
        if (!phi[j]) phi[j] = j;
        phi[j] = phi[j] / i * (i - 1);
      }
    }
}
void init() {
  phi_table(maxn - 1);
  for (int i = 1; i < maxn; i++) {
    for (int j = i; j < maxn; j += i) {
      num1[j].push_back(i);
    }
  }
  int temp;
  num2.push_back(0);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &temp);
    num2.push_back(temp);
  }
}
void solve() {
  int ans = 0;
  for (int d = 1; d <= n; d++) {
    int tmp = 0;
    mp.clear();
    for (int i = 1; i <= n / d; i++) {
      for (auto it : num1[num2[i * d]]) {
        mp[it]++;
      }
    }
    for (auto it : mp) {
      tmp =
          (tmp + mul(phi[it.first], mul(it.second, it.second, mod), mod)) % mod;
    }
    ans = (ans + mul(phi[d], tmp, mod)) % mod;
  }
  printf("%d\n", ans);
}
signed main() {
  scanf("%d", &n);
  init();
  solve();
}
