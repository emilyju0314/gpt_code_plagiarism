#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
using namespace std;
using namespace rel_ops;
using ll = int64_t;
using Vi = vector<int>;
using Pii = pair<int, int>;
void dbgx(...) {}
template <class T, class U = int, class... V>
void dbgx(T s, U a, V... b) {
  while (*s && *s != ',') cerr << *s++;
  cerr << ": " << a << *s++;
  dbgx(s, b...);
}
template <class T, class U = int, class... V>
auto operator<<(ostream& o, T x) -> decltype(&T::print, cout) {
  x.print();
  return o;
}
template <class T, class U = int, class... V>
auto operator<<(ostream& o, pair<T, U> x) -> decltype(0, cout) {
  return o << "(" << x.first << ", " << x.second << ")";
}
template <class T, class U = int, class... V>
auto operator<<(ostream& o, T x) -> decltype(T().begin(), cout) {
  o << "[";
  for (auto& e : (x)) o << e << ", ";
  return o << "]";
}
int hei, wid;
vector<int> board;
inline bool check(int i, int j) {
  i = board[i];
  j = board[j];
  if (i > j) swap(i, j);
  return i + 1 == j || i + wid == j;
}
bool tryIt() {
  random_shuffle((board).begin(), (board).end());
  for (int y = (0); y < (hei); y++) {
    int i = y * wid;
    for (int x = (1); x < (wid); x++)
      if (check(i + x - 1, i + x)) return false;
    if (y > 0) {
      for (int x = (0); x < (wid); x++)
        if (check(i + x - wid, i + x)) return false;
    }
  }
  cout << "YES\n";
  for (int i = (0); i < (int((board).size())); i++) {
    cout << board[i] << " ";
    if ((i + 1) % wid == 0) cout << endl;
  }
  return true;
}
void checkDet() {
  int oy = 1;
  cout << "YES\n";
  for (int y = (0); y < (hei); y++) {
    int ox = 1;
    for (int x = (0); x < (wid); x++) {
      cout << (oy - 1) * wid + ox << " ";
      ox += 2;
      if (ox > wid) ox = 2;
    }
    oy += 2;
    if (oy > hei) oy = 2;
    cout << endl;
  }
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> hei >> wid;
  board.resize(hei * wid);
  iota((board).begin(), (board).end(), 1);
  if (wid >= 6 && hei >= 6) {
    checkDet();
    return 0;
  }
  while (clock() < CLOCKS_PER_SEC)
    if (tryIt()) return 0;
  cout << "NO\n";
  return 0;
}
