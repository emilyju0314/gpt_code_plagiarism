#include <bits/stdc++.h>
using namespace std;
void fail() {
  cout << "NO" << endl;
  exit(0);
}
int main() {
  int i, j, k;
  int N;
  cin >> N;
  int A[100000];
  for (i = 0; i < N; i++) cin >> A[i];
  int fst = 0;
  while (fst < N && A[fst] == 0) fst++;
  int sec = fst + 1;
  while (sec < N && A[sec] == 0) sec++;
  vector<vector<int>> ans;
  while (fst < N - 2) {
    int x, y, z;
    if (fst + (sec - fst) * 2 < N) {
      x = fst;
      y = sec;
      z = fst + (sec - fst) * 2;
    } else {
      x = fst;
      y = fst + (N - 1 - fst) / 2;
      z = x + (y - x) * 2;
    }
    ans.push_back({x, y, z});
    for (auto c : {x, y, z}) {
      A[c] = 1 - A[c];
    }
    fst = y;
    while (fst < N && A[fst] == 0) fst++;
    sec = fst + 1;
    while (sec < N && A[sec] == 0) sec++;
  }
  if (A[N - 1] == 1) {
    if (N < 7) fail();
    ans.push_back({N - 7, N - 4, N - 1});
    ans.push_back({N - 7, N - 6, N - 5});
    ans.push_back({N - 6, N - 5, N - 4});
  }
  if (A[N - 2] == 1) {
    if (N < 8) fail();
    ans.push_back({N - 8, N - 5, N - 2});
    ans.push_back({N - 8, N - 7, N - 6});
    ans.push_back({N - 7, N - 6, N - 5});
  }
  cout << "YES" << endl;
  cout << ans.size() << endl;
  for (auto v : ans) {
    cout << v[0] + 1 << " " << v[1] + 1 << " " << v[2] + 1 << endl;
  }
  return 0;
}
