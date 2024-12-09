#include <bits/stdc++.h>
using namespace std;
int ma, mb, target_x;
vector<int> ca[100001];
vector<int> cb[100001];
int rev(int x) {
  int res = 0;
  while (x) {
    res = res * 10 + x % 10;
    x /= 10;
  }
  return res;
}
bool is_palin(int x) { return (x == rev(x)); }
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
void gen1(int x) {
  int rx = rev(x);
  int g = gcd(x, rx);
  int ix = x;
  x /= g;
  rx /= g;
  int ry, y;
  for (y = rx; y <= mb; y += rx) {
    ry = rev(y);
    if ((long long)x * y == (long long)rx * ry) {
      ca[ix].push_back(y);
      cb[y].push_back(ix);
    }
  }
}
void gen_all_pairs() {
  int i;
  for (i = 11; i <= ma; i++)
    if (i % 10 != 0 && !is_palin(i)) gen1(i);
}
int cura, curb;
int pa, pb;
long long npal, npair, n_x;
void inc_b() {
  curb++;
  if (is_palin(curb)) pb++;
}
void inc_a() {
  cura++;
  if (is_palin(cura)) pa++;
  npal = pa * pb;
  int i;
  for (i = 0; i < ca[cura].size(); i++)
    if (ca[cura][i] <= curb) npair++;
  n_x = npal + npair;
}
void dec_b() {
  if (is_palin(curb)) pb--;
  npal = pa * pb;
  int i;
  for (i = 0; i < cb[curb].size(); i++)
    if (cb[curb][i] <= cura) npair--;
  n_x = npal + npair;
  curb--;
}
int main() {
  scanf("%d %d %d", &ma, &mb, &target_x);
  gen_all_pairs();
  cura = curb = 0;
  pa = pb = 0;
  npal = npair = n_x = 0;
  int ra, rb;
  while (curb < mb) inc_b();
  long long res = 1000000000000LL;
  while (cura < ma) {
    inc_a();
    while (n_x >= target_x && curb >= 1) {
      if ((long long)cura * curb < res) {
        res = (long long)cura * curb;
        ra = cura;
        rb = curb;
      }
      dec_b();
    }
    if (curb == 0) break;
  }
  if (res == 1000000000000LL)
    printf("-1\n");
  else
    printf("%d %d\n", ra, rb);
  return 0;
}
