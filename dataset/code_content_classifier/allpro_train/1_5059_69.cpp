#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[1 << 18];
int gcd(int a, int b) {
  int small = min(a, b);
  int large = max(a, b);
  if (small == 0) return large;
  return gcd(small, large % small);
}
pair<int, int> add(pair<int, int> a, pair<int, int> b) {
  int ngcd = gcd(a.first, b.first);
  int count =
      ((ngcd == a.first) ? a.second : 0) + ((ngcd == b.first) ? b.second : 0);
  return make_pair(ngcd, count);
}
pair<int, int> query(int qlower, int qupper, int curr = 0, int lower = 0,
                     int upper = (1 << 17) - 1) {
  if (qupper < lower || upper < qlower) return make_pair(0, 0);
  if (qlower <= lower && upper <= qupper) return arr[curr];
  int mid = (lower + upper) / 2;
  return add(query(qlower, qupper, 2 * curr + 1, lower, mid),
             query(qlower, qupper, 2 * curr + 2, mid + 1, upper));
}
int main() {
  int N;
  cin >> N;
  int e;
  for (int i = 0; i < N; ++i) {
    cin >> e;
    arr[(1 << 17) + i - 1] = make_pair(e, 1);
  }
  for (int i = (1 << 17) - 2; i >= 0; --i) {
    arr[i] = add(arr[2 * i + 1], arr[2 * i + 2]);
  }
  int T;
  cin >> T;
  int l, r;
  for (int i = 0; i < T; ++i) {
    cin >> l >> r;
    cout << (r - l + 1) - query(l - 1, r - 1).second << endl;
  }
  return 0;
}
