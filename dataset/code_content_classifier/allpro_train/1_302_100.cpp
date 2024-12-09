#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
inline void up(int& x, int y) {
  if (y > x) x = y;
}
int n, w, k, a[N], t[N], ans;
struct HeapA {
  priority_queue<int> A, B;
  int size() { return A.size() - B.size(); }
  void update() {
    while (B.size() && A.top() == B.top()) A.pop(), B.pop();
  }
  void push(int x) { A.push(x); }
  void del(int x) { B.push(x); }
  void pop() {
    update();
    A.pop();
  }
  int top() {
    update();
    return A.top();
  }
} A;
struct Heap {
  priority_queue<int, vector<int>, greater<int> > A, B;
  int size() { return A.size() - B.size(); }
  void update() {
    while (B.size() && A.top() == B.top()) A.pop(), B.pop();
  }
  void push(int x) { A.push(x); }
  void del(int x) { B.push(x); }
  void pop() {
    update();
    A.pop();
  }
  int top() {
    update();
    return A.top();
  }
} B;
int main() {
  scanf("%d%d%d", &n, &w, &k);
  for (int i = (1); i <= (n); ++i) scanf("%d", &a[i]);
  for (int i = (1); i <= (n); ++i) scanf("%d", &t[i]);
  for (int i = n, j = n, sum = 0, st = 0; i >= 1; --i) {
    st += t[i];
    if (B.size() == w && t[i] / 2 > B.top())
      st += B.top(), A.push(B.top()), B.pop();
    if (B.size() < w)
      B.push(t[i] / 2), st -= t[i] / 2;
    else
      A.push(t[i] / 2);
    sum += a[i];
    while (st > k) {
      sum -= a[j];
      st -= t[j];
      if (t[j] / 2 >= B.top())
        B.del(t[j] / 2), st += t[j] / 2;
      else
        A.del(t[j] / 2);
      if (B.size() < w && A.size()) B.push(A.top()), st -= A.top(), A.pop();
      --j;
    }
    up(ans, sum);
  }
  printf("%d", ans);
  return 0;
}
