#include <bits/stdc++.h>
using namespace std;
class Stock {
 public:
  Stock() {
    p = -1;
    q = -1;
  }
  static const int BUY = 0;
  static const int SELL = 1;
  int p;
  int q;
};
vector<Stock> insert(vector<Stock> v, Stock stock, int d) {
  for (int i = 0; i < v.size(); ++i) {
    if (d == Stock::BUY) {
      if (v[i].p == -1) {
        v[i] = stock;
        break;
      }
      if (v[i].p < stock.p) {
        v.insert(v.begin() + i, stock);
        break;
      }
      if (v[i].p == stock.p) {
        v[i].q += stock.q;
        break;
      }
    } else if (d == Stock::SELL) {
      if (v[i].p == -1) {
        v[i] = stock;
        break;
      }
      if (v[i].p > stock.p) {
        v.insert(v.begin() + i, stock);
        break;
      }
      if (v[i].p == stock.p) {
        v[i].q += stock.q;
        break;
      }
    }
  }
  return v;
}
int main() {
  int n, s;
  cin >> n >> s;
  vector<Stock> S(s, Stock()), B(s, Stock());
  for (int i = 0; i < n; ++i) {
    char d;
    Stock stock;
    cin >> d >> stock.p >> stock.q;
    if (d == 'B') {
      B = insert(B, stock, Stock::BUY);
    } else if (d == 'S') {
      S = insert(S, stock, Stock::SELL);
    }
  }
  for (int i = s - 1; i >= 0; --i)
    if (S[i].p != -1) cout << "S " << S[i].p << " " << S[i].q << endl;
  for (int i = 0; i < s; ++i) {
    if (B[i].p == -1) break;
    cout << "B " << B[i].p << " " << B[i].q << endl;
  }
  return 0;
}
