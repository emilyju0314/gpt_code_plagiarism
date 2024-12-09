#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
template <class C, class I>
bool has(C con, I item) {
  return con.find(item) != con.end();
}
const int maxN = 200 * 1000 + 8;
int N;
vector<int> X[maxN];
int M;
vector<int> res;
bool solve() {
  cin >> N;
  for (int i = (1); i < (N + 1); i++) {
    int a;
    cin >> a;
    X[a].push_back(i);
    M = max(M, a);
  }
  int cur = 0;
  while (N-- > 0) {
    while (cur > M) {
      cur -= 3;
      if (cur < 0) return false;
      M = cur - 1;
      for (int tmp = (0); tmp < (3); tmp++) {
        if (int((X[cur + tmp]).size())) M = cur + tmp;
      }
    }
    if (int((X[cur]).size()) == 0) return false;
    res.push_back(X[cur].back());
    X[cur].pop_back();
    cur++;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  if (!solve()) {
    cout << "Impossible" << endl;
    return 0;
  }
  cout << "Possible" << endl;
  for (int i = (0); i < (int((res).size())); i++) {
    if (i != 0) cout << " ";
    cout << res[i];
  }
  cout << endl;
}
