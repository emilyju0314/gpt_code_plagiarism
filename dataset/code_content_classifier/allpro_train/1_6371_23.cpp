#include <bits/stdc++.h>
using namespace std;
vector<int> V[100005];
long long A[100005], n, u, v, i, r;
bool H[100005];
long long f(int x) {
  long long mx = 0, d = 0, t = 0;
  int i;
  vector<long long> Q;
  H[x] = 1;
  for (i = 0; i < V[x].size(); i++)
    if (!H[V[x][i]]) {
      A[V[x][i]]--;
      Q.push_back(f(V[x][i]));
      t += A[V[x][i]];
      d = 1;
    }
  if (!d) return 0;
  sort(Q.rbegin(), Q.rend());
  for (i = 0; i < Q.size() && A[x]; i++) {
    A[x]--;
    mx += Q[i] + 2;
  }
  long long k = min(A[x], t);
  A[x] -= k;
  return mx + 2 * k;
}
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> A[i];
  for (i = n; --i;) {
    cin >> u >> v;
    V[u].push_back(v);
    V[v].push_back(u);
  }
  cin >> r;
  cout << f(r) << endl;
  return 0;
}
