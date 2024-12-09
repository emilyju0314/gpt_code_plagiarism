#include <bits/stdc++.h>
using namespace std;
map<int, int> mb;
map<int, int> ma[210005];
int cnt[210005];
vector<int> a;
vector<int> qs;
int main() {
  int n, m, p, x;
  scanf(" %d %d %d", &n, &m, &p);
  for (int i = 0; i < n; i++) {
    scanf(" %d", &x);
    a.push_back(x);
  }
  for (int i = 0; i < m; i++) {
    scanf(" %d", &x);
    mb[x]++;
  }
  for (int i = 0; i < n; i++) {
    map<int, int>& _m = ma[i % p];
    long long k = i - (long long)p * m;
    if (k >= 0 && _m[a[k]]-- <= mb[a[k]]) cnt[i % p]--;
    if (mb[a[i]] >= ++_m[a[i]]) cnt[i % p]++;
    if (cnt[i % p] == m) qs.push_back((k + p >= 0 ? k + p : 0));
  }
  printf("%d\n", qs.size());
  for (int i = 0; i < qs.size(); i++) printf("%d ", qs[i] + 1);
  printf("\n");
  return 0;
}
