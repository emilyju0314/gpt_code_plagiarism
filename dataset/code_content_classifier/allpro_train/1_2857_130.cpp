#include <bits/stdc++.h>
using namespace std;
const int nn = 1e5 + 5;
int sparsemin[nn][28], sparsemax[nn][28], ancestor[nn][28];
int dist[nn], preorder[nn], in[nn], out[nn], p[nn], n, q, curr = 0;
vector<int> v[nn];
int query_min(int l, int r) {
  int pangkat = log2(r - l + 1);
  return min(sparsemin[l][pangkat], sparsemin[r - (1 << pangkat) + 1][pangkat]);
}
int query_max(int l, int r) {
  int pangkat = log2(r - l + 1);
  return max(sparsemax[l][pangkat], sparsemax[r - (1 << pangkat) + 1][pangkat]);
}
void dfs(int now, int lvl) {
  in[now] = ++curr;
  dist[now] = lvl;
  preorder[curr] = now;
  int l1 = v[now].size();
  for (int i = 0; i < l1; i++) {
    int ttg = v[now][i];
    if (dist[ttg] == -1) dfs(ttg, lvl + 1);
  }
  out[now] = curr;
}
void build_lca() {
  for (int i = 0; i < 26; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == 0)
        ancestor[j][i] = p[j];
      else
        ancestor[j][i] = ancestor[ancestor[j][i - 1]][i - 1];
    }
  }
}
void build_preorder() {
  for (int i = 0; i <= log2(n); i++) {
    for (int j = 1; j <= n; j++) {
      if (i == 0) {
        sparsemin[j][i] = in[j];
        sparsemax[j][i] = in[j];
      } else {
        if (j + (1 << i) - 1 > n) break;
        sparsemax[j][i] =
            max(sparsemax[j][i - 1], sparsemax[j + (1 << (i - 1))][i - 1]);
        sparsemin[j][i] =
            min(sparsemin[j][i - 1], sparsemin[j + (1 << (i - 1))][i - 1]);
      }
    }
  }
}
int lca(int nod1, int nod2) {
  if (dist[nod1] > dist[nod2]) swap(nod1, nod2);
  for (int i = 26; i >= 0; i--) {
    if (dist[nod2] - (1 << i) >= dist[nod1]) nod2 = ancestor[nod2][i];
  }
  if (nod1 == nod2) return nod1;
  for (int i = 26; i >= 0; i--) {
    if (ancestor[nod1][i] != ancestor[nod2][i]) {
      nod1 = ancestor[nod1][i];
      nod2 = ancestor[nod2][i];
    }
  }
  return ancestor[nod1][0];
}
int main() {
  memset(dist, -1, sizeof dist);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> q;
  p[1] = 1;
  for (int i = 2; i <= n; i++) {
    cin >> p[i];
    v[p[i]].push_back(i);
    v[i].push_back(p[i]);
  }
  dfs(1, 0);
  build_lca();
  build_preorder();
  while (q--) {
    int l, r;
    cin >> l >> r;
    int mini = preorder[query_min(l, r)];
    int maks = preorder[query_max(l, r)];
    int q1 = 1e6, q2 = -1e6;
    if (mini > l) {
      q1 = min(q1, query_min(l, mini - 1));
      q2 = max(q2, query_max(l, mini - 1));
    }
    if (mini < r) {
      q1 = min(q1, query_min(mini + 1, r));
      q2 = max(q2, query_max(mini + 1, r));
    }
    int lca1 = lca(preorder[q1], preorder[q2]);
    q1 = 1e6, q2 = -1e6;
    if (maks > l) {
      q1 = min(q1, query_min(l, maks - 1));
      q2 = max(q2, query_max(l, maks - 1));
    }
    if (maks < r) {
      q1 = min(q1, query_min(maks + 1, r));
      q2 = max(q2, query_max(maks + 1, r));
    }
    int lca2 = lca(preorder[q1], preorder[q2]);
    if (dist[lca1] > dist[lca2])
      cout << mini << ' ' << dist[lca1] << "\n";
    else
      cout << maks << ' ' << dist[lca2] << "\n";
  }
}
