#include <bits/stdc++.h>
using namespace std;
long long int union_parent[100005];
void union_init() {
  for (long long int i = 0; i < ((long long int)(100005)); i++)
    union_parent[i] = i;
}
long long int union_find(long long int a) {
  if (union_parent[a] == a) return a;
  return union_parent[a] = union_find(union_parent[a]);
}
void union_union(long long int a, long long int b) {
  union_parent[union_find(a)] = union_find(b);
  return;
}
int main() {
  long long int res = 1, n, m, mod = 1000000009;
  union_init();
  cin >> n >> m;
  for (long long int i = 0; i < ((long long int)(m)); i++) {
    long long int a, b;
    cin >> a >> b;
    if (union_find(a - 1) == union_find(b - 1)) res = (res * 2) % mod;
    union_union(a - 1, b - 1);
    cout << (res - 1 + mod) % mod << endl;
  }
}
