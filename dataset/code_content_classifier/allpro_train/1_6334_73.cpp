#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int siz = (1 << 21);
const int siz2 = 1000007;
struct node {
  long long w, xl, xr, akt;
};
int n, q, li;
int tab[siz2];
pair<int, int> pom[siz2];
pair<int, int> zap[siz2];
node tree[siz];
long long pot[siz2];
void upd(int i) {
  tree[i].w = (tree[i * 2].w * pot[tree[i * 2 + 1].akt]) % mod;
  tree[i].w =
      (tree[i].w + (tree[i * 2 + 1].w * pot[tree[i * 2].akt]) % mod) % mod;
  tree[i].w = (tree[i].w + (tree[i * 2].xl * tree[i * 2 + 1].xr) % mod) % mod;
  tree[i].akt = tree[i * 2].akt + tree[i * 2 + 1].akt;
  tree[i].xl =
      (tree[i * 2].xl + (tree[i * 2 + 1].xl * pot[tree[i * 2].akt]) % mod) %
      mod;
  tree[i].xr =
      (tree[i * 2 + 1].xr + (tree[i * 2].xr * pot[tree[i * 2 + 1].akt]) % mod) %
      mod;
}
void aktualizuj(int j, int p) {
  int i = j + siz / 2;
  if (p == 1) {
    tree[i].akt = 1LL;
    tree[i].xl = tree[i].xr = (long long)pom[j].first;
  } else {
    tree[i].akt = 0LL;
    tree[i].xl = tree[i].xr = 0LL;
  }
  while (i != 1) {
    i /= 2;
    upd(i);
  }
}
long long poteguj(long long x, int p) {
  if (p == 1) return x;
  if (p == 0) return 1LL;
  long long pm = poteguj(x, p / 2);
  pm = (pm * pm) % mod;
  if (p % 2 != 0) pm = (pm * x) % mod;
  return pm;
}
long long odw(long long a) { return poteguj(a, mod - 2); }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &pom[i].first);
    pom[i].second = i;
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int j, x;
    scanf("%d %d", &j, &x);
    pom[n + i] = {x, n + i};
    zap[i].second = j;
  }
  li = n + q;
  sort(pom + 1, pom + 1 + li);
  pot[0] = 1LL;
  for (int i = 1; i <= n; i++) {
    pot[i] = (pot[i - 1] * 2LL) % mod;
  }
  for (int i = 1; i <= li; i++) {
    if (pom[i].second > n)
      zap[pom[i].second - n].first = i;
    else
      tab[pom[i].second] = i;
  }
  long long r = odw(pot[n]);
  for (int i = 1; i <= n; i++) aktualizuj(tab[i], 1);
  printf("%lld\n", (tree[1].w * r) % mod);
  for (int i = 1; i <= q; i++) {
    aktualizuj(tab[zap[i].second], -1);
    tab[zap[i].second] = zap[i].first;
    aktualizuj(zap[i].first, 1);
    printf("%lld\n", (tree[1].w * r) % mod);
  }
  return 0;
}
