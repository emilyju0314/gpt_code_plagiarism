#include <bits/stdc++.h>
using namespace std;
const int md = 1e9 + 7;
long long int power(long long int a, int n) {
  if (n == 0) return 1;
  long long int aa = power(a, n >> 1);
  aa = (aa * aa) % md;
  if (n & 1) aa = (aa * a) % md;
  return aa;
}
const int N = 200005;
const int NN = 1000005;
long long int bit[N];
void update(int ind, long long int val) {
  while (ind < N) {
    bit[ind] = (bit[ind] * val) % md;
    ind += (ind & (-ind));
  }
}
long long int query(int ind) {
  long long int s = 1;
  while (ind > 0) {
    s = (s * bit[ind]) % md;
    ind -= (ind & (-ind));
  }
  return s;
}
struct ppair {
  int first, second;
};
vector<ppair> queries[N];
long long int pre[N];
int ans[N];
int last[NN];
int a[N];
bitset<NN> prime;
vector<int> d_primes[NN];
void sieve() {
  for (int i = 2; i < NN; i++) {
    if (!prime[i]) {
      for (int j = i; j < NN; j += i) {
        prime[j] = 1;
        d_primes[j].push_back(i);
      }
    }
  }
}
long long int inv(long long int x) { return power(x, md - 2); }
int main() {
  fill(bit, bit + N, 1);
  sieve();
  int n;
  scanf("%d", &n);
  pre[0] = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    pre[i] = (pre[i - 1] * a[i]) % md;
  }
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    queries[r].push_back({l, i});
  }
  for (int i = 1; i <= n; i++) {
    for (int x : d_primes[a[i]]) {
      if (last[x]) {
        update(last[x], (x * inv(x - 1)) % md);
      }
      last[x] = i;
      update(last[x], ((x - 1) * inv(x)) % md);
    }
    for (ppair x : queries[i]) {
      long long int ans1 = (pre[i] * inv(pre[x.first - 1])) % md;
      ans1 = (ans1 * query(i)) % md;
      ans1 = (ans1 * inv(query(x.first - 1))) % md;
      ans[x.second] = ans1;
    }
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}
