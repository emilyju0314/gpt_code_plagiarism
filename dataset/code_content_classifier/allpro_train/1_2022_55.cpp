#include <bits/stdc++.h>
using namespace std;
vector<int> applyPerm(const vector<int>& p, const vector<int>& q) {
  vector<int> r(p.size());
  for (int i = 0; i < p.size(); i++) r[i] = p[q[i]];
  return r;
}
vector<int> invert(vector<int> p) {
  vector<int> r(p.size());
  for (int i = 0; i < p.size(); i++)
    if (p[i] > 0) {
      int prev = i;
      do {
        int next = p[prev];
        p[prev] *= -1;
        r[next] = prev;
        prev = next;
      } while (prev != i);
    }
  return r;
}
bool check(vector<int> p, vector<int> q, int k, int n) {
  vector<int> tp(n);
  for (int i = 0; i < n; i++) tp[i] = i;
  if (q == tp) return false;
  if (applyPerm(p, p) == tp) return k == 1;
  for (int i = 0; i <= k; i++) {
    if (tp == q && (k - i) % 2 == 0) return true;
    tp = applyPerm(tp, p);
  }
  for (int i = 0; i < n; i++) tp[i] = i;
  vector<int> in = invert(p);
  for (int i = 0; i <= k; i++) {
    if (tp == q && (k - i) % 2 == 0) return true;
    tp = applyPerm(tp, in);
  }
  return false;
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> p(n), q(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    p[i]--;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &q[i]);
    q[i]--;
  }
  if (check(p, q, k, n))
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
