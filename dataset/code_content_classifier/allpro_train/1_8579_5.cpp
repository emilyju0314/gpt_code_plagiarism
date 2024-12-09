#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
mt19937 kk(490571098);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long N;
  cin >> N;
  long long sx = 0, dx = 1e9 + 1;
  long long t = 0;
  while (sx < dx - 1) {
    t++;
    long long m = (sx + dx) / 2;
    cout << "> " << m << endl;
    long long a;
    cin >> a;
    if (a)
      sx = m;
    else
      dx = m;
  }
  long long x = sx + 1;
  vector<long long> p;
  vector<long long> kkk;
  for (int i = 0; i < N; i++) kkk.push_back(i);
  shuffle(kkk.begin(), kkk.end(), kk);
  for (long long i = 0; i < min(60 - t, N); i++) {
    cout << "? " << kkk[i] + 1 << endl;
    long long a;
    cin >> a;
    if (a != x) p.push_back(a);
  }
  p.push_back(x);
  sort(p.begin(), p.end());
  reverse(p.begin(), p.end());
  vector<long long> di;
  long long diff = p[0] - p[1];
  for (long long i = 1; i * i <= diff; i++) {
    if (diff % i == 0) {
      di.push_back(i);
      di.push_back(diff / i);
    }
  }
  for (long long i = 0; i < di.size(); i++) {
    bool ok = 1;
    for (long long j = 1; j < p.size(); j++) {
      long long g = p[0] - p[j];
      if (g % di[i] == 0 && g / di[i] < (N - p.size() + j + 1)) continue;
      ok = 0;
      break;
    }
    if (ok && p[0] - (N - 1) * di[i] >= 0) {
      cout << "! " << p[0] - (N - 1) * di[i] << " " << di[i] << endl;
      return 0;
    }
  }
  return 0;
}
