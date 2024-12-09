#include <bits/stdc++.h>
using namespace std;
template <class T>
int size(const T &x) {
  return x.size();
}
const int INF = ~(1 << 31);
const double pi = acos(-1);
const double EPS = 1e-9;
int dist[100500];
int first[100500];
int last[100500];
int main() {
  cin.sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> A(k);
  for (int i = (0); i < (n); i++) first[i] = INF;
  for (int i = (0); i < (n); i++) last[i] = 0;
  for (int i = (0); i < (k); i++) cin >> A[i], A[i]--;
  for (int i = (0); i < (k); i++) {
    last[A[i]] = max(last[A[i]], i);
    first[A[i]] = min(first[A[i]], i);
  }
  set<int> T;
  for (int i = k - 1; i >= 0; i--) {
    dist[i] = T.size();
    T.insert(A[i]);
  }
  long long sm = 0;
  for (int i = (0); i < (n); i++) {
    if (first[i] == INF) {
      if (i == 0) {
        sm += 2;
      } else if (i == n - 1) {
        sm += 2;
      } else {
        sm += 3;
      }
    } else {
      if (i != n - 1 && last[(i + 1) % n] <= first[i]) {
        sm++;
      }
      if (i != 0 && last[(i - 1 + n) % n] <= first[i]) {
        sm++;
      }
    }
  }
  cout << sm << endl;
  return 0;
}
