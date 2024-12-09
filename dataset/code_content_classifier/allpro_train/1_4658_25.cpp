#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define REP(i, a, n) for(int i = ((int) a); i < ((int) n); i++)
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

int R, C, N, X[200000], Y[200000];

pii frame(int x, int y) {
  if(x == 0) return pii(0, y);
  if(y == C) return pii(1, x);
  if(x == R) return pii(2, R - y);
  if(y == 0) return pii(3, C - x);
  return pii(-1, -1);
}

int main(void) {
  cin >> R >> C >> N;
  REP(i, 0, N) cin >> X[i * 2] >> Y[i * 2] >> X[i * 2 + 1] >> Y[i * 2 + 1];

  vector<ppi> v;
  REP(i, 0, N) {
    pii p = frame(X[i * 2], Y[i * 2]);
    pii q = frame(X[i * 2 + 1], Y[i * 2 + 1]);
    if(p != pii(-1, -1) && q != pii(-1, -1)) {
      v.push_back(ppi(p, i));
      v.push_back(ppi(q, i));
    }
  }

  sort(v.begin(), v.end());

  stack<int> stk;
  REP(i, 0, v.size()) {
    if(stk.size() > 0 && stk.top() == v[i].se) stk.pop();
    else stk.push(v[i].se);
  }
  if(stk.size() == 0) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}
