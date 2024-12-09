#include <bits/stdc++.h>
using namespace std;

long N, A, B;
vector<long> H;

bool f(long mid) {
  vector<long> V = H;
  for (auto &v : V) v -= B * mid;
  long cnt = 0, tmp = A - B;
  for (auto v : V) if (v > 0) cnt += (v + tmp - 1) / tmp;
  return (cnt <= mid) ? true : false;
}

int main() {
  cin >> N >> A >> B;
  H.resize(N);
  for (auto &h : H) cin >> h;
  long ok = 1e9, ng = -1e9;
    while (ok - ng > 1) {
      long mid = (ok + ng) / 2;
      (f(mid)) ? ok = mid : ng = mid;
    }
  cout << ok << "\n";
}