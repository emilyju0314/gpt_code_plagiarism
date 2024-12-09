#include <bits/stdc++.h>
using namespace std;
void update(int l, int r, int b, int e, int v, vector<int> &Tree) {
  if (e <= l || r <= b) {
  } else if (l <= b && e <= r)
    Tree[b + e] = v;
  else {
    update(l, r, b, (b + e) / 2, v, Tree);
    update(l, r, (b + e) / 2, e, v, Tree);
    Tree[b + e] = (Tree[b + (b + e) / 2] + Tree[(b + e) / 2 + e]);
  }
}
int query(int l, int r, int b, int e, vector<int> &Tree) {
  if (e <= l || r <= b)
    return 0;
  else if (l <= b && e <= r)
    return Tree[b + e];
  return query(l, r, b, (b + e) / 2, Tree) + query(l, r, (b + e) / 2, e, Tree);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> P(n);
  for (int i = 0; i < n; i++) {
    cin >> P[i];
    P[i]--;
  }
  vector<vector<int> > W(q, vector<int>(4));
  for (int i = 0; i < q; i++)
    for (int j = 0; j < 4; j++) cin >> W[i][j], W[i][j]--;
  vector<long long> Ans(q, 1ll * n * (n - 1) / 2);
  for (int i = 0; i < q; i++)
    for (int j = 0; j < 2; j++)
      Ans[i] -= (1ll * W[i][j] * (W[i][j] - 1) / 2 +
                 1ll * (n - 1 - W[i][j + 2]) * (n - 1 - W[i][j + 2] - 1) / 2);
  int j = 0, s = 1, r;
  while (s < 2 * n) s *= 2;
  vector<int> Tree(s, 0);
  vector<pair<pair<int, int>, int> > V(q);
  for (int i = 0; i < q; i++) V[i] = {{W[i][0], W[i][1]}, i};
  sort(V.begin(), V.end());
  for (int c = 0; c < n; c++) {
    while (j < q && V[j].first.first == c) {
      r = query(0, V[j].first.second, 0, s / 2, Tree);
      Ans[V[j].second] += (1ll * r * (r - 1) / 2);
      j++;
    }
    update(P[c], P[c] + 1, 0, s / 2, 1, Tree);
  }
  for (int i = 0; i < s; i++) Tree[i] = 0;
  for (int i = 0; i < q; i++) V[i] = {{W[i][2], W[i][3]}, i};
  sort(V.begin(), V.end());
  j = q - 1;
  for (int c = n - 1; c >= 0; c--) {
    while (j >= 0 && V[j].first.first == c) {
      r = query(V[j].first.second + 1, s / 2, 0, s / 2, Tree);
      Ans[V[j].second] += (1ll * r * (r - 1) / 2);
      j--;
    }
    update(P[c], P[c] + 1, 0, s / 2, 1, Tree);
  }
  for (int i = 0; i < s; i++) Tree[i] = 0;
  for (int i = 0; i < q; i++) V[i] = {{W[i][0], W[i][3]}, i};
  sort(V.begin(), V.end());
  j = 0;
  for (int c = 0; c < n; c++) {
    while (j < q && V[j].first.first == c) {
      r = query(V[j].first.second + 1, s / 2, 0, s / 2, Tree);
      Ans[V[j].second] += (1ll * r * (r - 1) / 2);
      j++;
    }
    update(P[c], P[c] + 1, 0, s / 2, 1, Tree);
  }
  for (int i = 0; i < s; i++) Tree[i] = 0;
  for (int i = 0; i < q; i++) V[i] = {{W[i][2], W[i][1]}, i};
  sort(V.begin(), V.end());
  j = q - 1;
  for (int c = n - 1; c >= 0; c--) {
    while (j >= 0 && V[j].first.first == c) {
      r = query(0, V[j].first.second, 0, s / 2, Tree);
      Ans[V[j].second] += (1ll * r * (r - 1) / 2);
      j--;
    }
    update(P[c], P[c] + 1, 0, s / 2, 1, Tree);
  }
  for (int i = 0; i < q; i++) cout << Ans[i] << "\n";
  return 0;
}
