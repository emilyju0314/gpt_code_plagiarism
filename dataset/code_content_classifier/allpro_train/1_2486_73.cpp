#include <bits/stdc++.h>
const int MAXN = 200007;
struct Trie {
  int data[MAXN * 31][2], tot = 1;
  inline void insert(int n) {
    int p = 1;
    for (int k = 30; k >= 0; --k) {
      int num = (n >> k) & 1;
      if (!data[p][num]) data[p][num] = ++tot;
      p = data[p][num];
    }
    return;
  }
  int xor_search(int now, int level, int val) {
    if (level == -1) return 0;
    int num = (val >> level) & 1;
    if (data[now][num])
      return xor_search(data[now][num], level - 1, val);
    else
      return xor_search(data[now][!num], level - 1, val) ^ (1 << level);
  }
  int leaf[MAXN], time_stamp = 0;
  long long Boruvka_on_Trie(int now, int level, int val) {
    if (level == -1) {
      leaf[++time_stamp] = val;
      return 0;
    }
    int l = data[now][0], r = data[now][1], inDFN, l_outDFN, outDFN;
    long long ret = 0;
    inDFN = time_stamp + 1;
    if (l) ret += Boruvka_on_Trie(l, level - 1, val << 1);
    l_outDFN = time_stamp;
    if (r) ret += Boruvka_on_Trie(r, level - 1, val << 1 | 1);
    outDFN = time_stamp;
    if (l && r) {
      int delta = 1 << 30;
      if (l_outDFN - inDFN < outDFN - l_outDFN - 1) {
        for (int i = inDFN; i <= l_outDFN; ++i)
          delta = std::min(delta, xor_search(r, level - 1, leaf[i]));
        ret += delta ^ (1 << level);
      } else {
        for (int i = l_outDFN + 1; i <= outDFN; ++i)
          delta = std::min(delta, xor_search(l, level - 1, leaf[i]));
        ret += delta ^ (1 << level);
      }
    }
    return ret;
  }
} trie;
int a[MAXN];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    trie.insert(a[i]);
  }
  printf("%I64d\n", trie.Boruvka_on_Trie(1, 30, 0));
  return 0;
}
