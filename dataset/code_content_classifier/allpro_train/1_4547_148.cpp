#include <bits/stdc++.h>
using namespace std;
struct Op {
  int i;
  int pos;
  int type;
};
inline bool comp(const Op &a, const Op &b) {
  return a.pos > b.pos || (a.pos == b.pos && a.i > b.i);
}
inline bool comp2(const int &a, const int &b) { return a > b; }
int main() {
  std::ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> A(n);
  for (int i = 0; i < (n); i++) cin >> A[i];
  vector<Op> op(m);
  for (int i = 0; i < (m); i++) {
    int x, y;
    cin >> x >> y;
    y--;
    op[i].i = i;
    op[i].pos = y;
    op[i].type = x;
  }
  sort(op.begin(), op.end(), comp);
  multiset<int> num;
  for (int i = 0; i <= op[0].pos; i++) {
    num.insert(A[i]);
  }
  int bp = -1, mi = -1;
  vector<Op> vop;
  for (int i = 0; i < m; i++) {
    if (op[i].pos > mi || op[i].i > bp) {
      mi = op[i].pos;
      bp = op[i].i;
      vop.push_back(op[i]);
    }
  }
  for (int i = 0; i < vop.size(); i++) {
    if (i == vop.size() - 1) {
      if (vop[i].type == 1) {
        int x = 0;
        for (int p : num) {
          A[x++] = p;
        }
      } else {
        int x = vop[i].pos;
        for (int p : num) {
          A[x--] = p;
        }
      }
    } else {
      if (vop[i].type == 1) {
        int x = vop[i].pos;
        while (x > vop[i + 1].pos) {
          auto itr = num.end();
          itr--;
          A[x--] = *itr;
          num.erase(itr);
        }
      } else {
        int x = vop[i].pos;
        while (x > vop[i + 1].pos) {
          auto itr = num.begin();
          A[x--] = *itr;
          num.erase(itr);
        }
      }
    }
  }
  for (int i = 0; i < (n); i++) {
    cout << A[i] << " ";
  }
  cout << endl;
  return 0;
}
