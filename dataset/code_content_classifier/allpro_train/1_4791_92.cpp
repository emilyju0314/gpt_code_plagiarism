#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector<vector<long long> > orij;
vector<vector<long long> > matMult(vector<vector<long long> > x,
                                   vector<vector<long long> > y) {
  vector<vector<long long> > ans(x.size(), vector<long long>(y.size(), 0));
  for (long long i = 0; i < x.size(); i++)
    for (long long j = 0; j < y.size(); j++)
      for (long long k = 0; k < y.size(); k++) {
        ans[i][j] += (long long)x[i][k] * y[k][j] % m;
        ans[i][j] %= m;
      }
  return ans;
}
vector<vector<long long> > matpower(long long p) {
  if (p == 1) return orij;
  vector<vector<long long> > cur = matpower(p / 2);
  cur = matMult(cur, cur);
  if (p % 2) cur = matMult(cur, orij);
  return cur;
}
int main() {
  cin >> n >> m;
  if (n == 1) {
    cout << 2 % m << "\n";
    return 0;
  }
  n--;
  vector<long long> tpush;
  tpush.push_back(3);
  tpush.push_back(1);
  orij.push_back(tpush);
  tpush.clear();
  tpush.push_back(0);
  tpush.push_back(1);
  orij.push_back(tpush);
  vector<vector<long long> > newm = matpower(n);
  cout << (newm[0][0] % m + newm[0][1] % m) * 2 % m << "\n";
  return 0;
}
