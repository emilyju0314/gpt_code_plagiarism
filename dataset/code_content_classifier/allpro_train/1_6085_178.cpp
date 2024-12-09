#include <bits/stdc++.h>
using namespace std;
map<int, int> sidx;
map<int, long long> cache[123456];
map<int, int> bt[123456];
int n, m;
class Tshoes {
 public:
  long long cost, size;
  int buyer, oi;
  bool operator<(const Tshoes &s) const { return size < s.size; }
  void get(int idx) {
    cin >> cost >> size;
    buyer = -1;
    oi = idx;
  }
} shoes[123456];
vector<int> shoesBuy[123456];
vector<int> buyerShoes[123456];
long long rec(int at, int last = -1) {
  if (at == n) {
    return 0;
  } else if (shoes[at].buyer != -1) {
    bt[at][last] = -1;
    return rec(at + 1);
  }
  if (cache[at].count(last)) {
    return cache[at][last];
  }
  long long best = 0;
  int bi = -1;
  for (int i = 0; i < shoesBuy[at].size(); i++) {
    if (shoesBuy[at][i] == last) {
      continue;
    }
    long long cmp = shoes[at].cost + rec(at + 1, shoesBuy[at][i]);
    if (cmp >= best) {
      bi = shoesBuy[at][i];
      best = cmp;
    }
  }
  long long cmp = rec(at + 1);
  if (bi != -1 && best > cmp) {
    bt[at][last] = bi;
  } else {
    bt[at][last] = -1;
  }
  best = max(best, rec(at + 1));
  return cache[at][last] = best;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    shoes[i].get(i);
  }
  sort(shoes, shoes + n);
  for (int i = 0; i < n; i++) {
    sidx[shoes[i].size] = i;
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    int mi, si, tmp;
    cin >> mi >> si;
    for (int j = si; j < si + 2; j++) {
      if (sidx.count(j) && shoes[tmp = sidx[j]].cost <= mi) {
        buyerShoes[i].push_back(tmp);
        if (shoesBuy[tmp].size() < 4) {
          shoesBuy[tmp].push_back(i);
        }
      }
    }
    if (buyerShoes[i].size() == 1) {
      int purId = buyerShoes[i][0];
      shoes[purId].buyer = i;
    }
  }
  rec(0);
  int ptr = -1;
  for (int i = 0; i < n; i++) {
    if (shoes[i].buyer == -1) {
      shoes[i].buyer = bt[i][ptr];
    }
    ptr = bt[i][ptr];
  }
  long long tot = 0, ct = 0;
  for (int i = 0; i < n; i++) {
    if (shoes[i].buyer != -1) {
      tot += shoes[i].cost;
      ct++;
    }
  }
  cout << tot << endl << ct << endl;
  for (int i = 0; i < n; i++) {
    if (shoes[i].buyer != -1) {
      cout << shoes[i].buyer + 1 << " " << shoes[i].oi + 1 << endl;
    }
  }
  return 0;
}
