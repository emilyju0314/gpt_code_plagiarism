#include <bits/stdc++.h>
using namespace std;
function<void(void)> ____ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
};
const int MAXN = 1e5 + 7;
int n, a, b, root[MAXN];
vector<int> A;
int findx(int x) { return x == root[x] ? x : root[x] = findx(root[x]); }
int sta[MAXN], bel[MAXN];
int main() {
  ____();
  cin >> n >> a >> b;
  A.resize(n + 1);
  map<int, int> msk;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    msk[A[i]] = i;
  }
  for (int i = 1; i <= n; i++) root[i] = i;
  for (int i = 1; i <= n; i++) {
    if (msk.count(a - A[i])) root[findx(i)] = findx(msk[a - A[i]]), sta[i] |= 1;
    if (msk.count(b - A[i])) root[findx(i)] = findx(msk[b - A[i]]), sta[i] |= 2;
  }
  for (int i = 1; i <= n; i++) bel[i] = 3;
  for (int i = 1; i <= n; i++) bel[findx(i)] &= sta[i];
  for (int i = 1; i <= n; i++)
    if (bel[findx(i)] == 0) {
      cout << "NO" << endl;
      return 0;
    }
  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) cout << (bel[findx(i)] == 1 ? 0 : 1) << ' ';
  cout << endl;
  return 0;
}
