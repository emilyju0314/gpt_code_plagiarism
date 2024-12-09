#include <bits/stdc++.h>
using namespace std;
int interactor_n;
vector<int> interactor_a;
int interactor_queries;
bool interactor_ans;
const int QUERIES_LIMIT = 60;
void interactor_init() {
  cin >> interactor_n;
  assert(interactor_n > 0);
  assert(interactor_n % 2 == 0);
  interactor_a = vector<int>(interactor_n);
  for (int i = 0; i < interactor_n; ++i) cin >> interactor_a[i];
  for (int i = 0; i < interactor_n; ++i) {
    int j = i + 1 == interactor_n ? 0 : i + 1;
    assert(abs(interactor_a[i] - interactor_a[j]) == 1);
  }
  interactor_ans = 0;
  for (int i = 0; i + interactor_n / 2 < interactor_n; ++i)
    interactor_ans |= interactor_a[i] == interactor_a[i + interactor_n / 2];
}
int query(int i) {
  cout << "? " << i + 1 << endl;
  int res;
  cin >> res;
  return res;
}
void answer(int i) {
  if (i != -1) ++i;
  cout << "! " << i << endl;
  exit(0);
}
void guess(int n) {
  if (n % 4 == 0) {
    int l = 0, r = n / 2 - 1;
    pair<int, int> lp = {query(l), query(l + n / 2)};
    pair<int, int> rp = {query(r), query(r + n / 2)};
    if (lp.first == lp.second) answer(l);
    if (rp.first == rp.second) answer(r);
    while (r - l > 1) {
      int m = (l + r) / 2;
      pair<int, int> mp = {query(m), query(m + n / 2)};
      if (mp.first == mp.second) answer(m);
      bool cl = lp.first < lp.second, cm = mp.first < mp.second;
      if (cm == cl) {
        l = m;
        lp = mp;
      } else {
        r = m;
        rp = mp;
      }
    }
  }
  answer(-1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  guess(n);
  return 0;
}
