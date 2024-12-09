#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<string> arr;
int optimal(int i, bool turn, string a, string b) {
  int r1 = 0, r2 = 0;
  for (int j = 0; j < m; j += 2) {
    if (!turn) {
      r1 += (arr[i][j] != a[0]);
      if (j + 1 < m) r1 += (arr[i][j + 1] != a[1]);
      r2 += (arr[i][j] != a[1]);
      if (j + 1 < m) r2 += (arr[i][j + 1] != a[0]);
    } else {
      r1 += (arr[i][j] != b[0]);
      if (j + 1 < m) r1 += (arr[i][j + 1] != b[1]);
      r2 += (arr[i][j] != b[1]);
      if (j + 1 < m) r2 += (arr[i][j + 1] != b[0]);
    }
  }
  return min(r1, r2);
}
int solve(string a, string b) {
  int ret = 0;
  for (auto i = 0; i < (long long)(n); i++) {
    bool turn = (i & 1);
    ret += optimal(i, turn, a, b);
  }
  return ret;
}
void applyOptimal(int i, bool turn, string a, string b) {
  int r1 = 0, r2 = 0;
  for (int j = 0; j < m; j += 2) {
    if (!turn) {
      r1 += (arr[i][j] != a[0]);
      if (j + 1 < m) r1 += (arr[i][j + 1] != a[1]);
      r2 += (arr[i][j] != a[1]);
      if (j + 1 < m) r2 += (arr[i][j + 1] != a[0]);
    } else {
      r1 += (arr[i][j] != b[0]);
      if (j + 1 < m) r1 += (arr[i][j + 1] != b[1]);
      r2 += (arr[i][j] != b[1]);
      if (j + 1 < m) r2 += (arr[i][j + 1] != b[0]);
    }
  }
  if (r2 <= r1) {
    for (int j = 0; j < m; j += 2) {
      if (!turn) {
        arr[i][j] = a[1];
        if (j + 1 < m) arr[i][j + 1] = a[0];
      } else {
        arr[i][j] = b[1];
        if (j + 1 < m) arr[i][j + 1] = b[0];
      }
    }
  } else {
    for (int j = 0; j < m; j += 2) {
      if (!turn) {
        arr[i][j] = a[0];
        if (j + 1 < m) arr[i][j + 1] = a[1];
      } else {
        arr[i][j] = b[0];
        if (j + 1 < m) arr[i][j + 1] = b[1];
      }
    }
  }
}
void apply(string a, string b) {
  for (auto i = 0; i < (long long)(n); i++) {
    bool turn = (i & 1);
    applyOptimal(i, turn, a, b);
  }
}
void transpose() {
  swap(n, m);
  vector<string> temp(n);
  for (auto i = 0; i < (long long)(n); i++)
    for (auto j = 0; j < (long long)(m); j++) temp[i].push_back(arr[j][i]);
  arr = temp;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  arr.resize(n);
  for (auto &x : arr) cin >> x;
  string hoba = "ACGT", target = "";
  bool flag = false;
  int mn = 1e9;
  do {
    int ans = solve(hoba.substr(0, 2), hoba.substr(2, 2));
    if (ans < mn) mn = ans, target = hoba;
  } while (next_permutation(((hoba).begin()), ((hoba).end())));
  sort(((hoba).begin()), ((hoba).end()));
  transpose();
  do {
    int ans = solve(hoba.substr(0, 2), hoba.substr(2, 2));
    if (ans < mn) mn = ans, target = hoba, flag = true;
  } while (next_permutation(((hoba).begin()), ((hoba).end())));
  if (!flag) transpose();
  apply(target.substr(0, 2), target.substr(2, 2));
  if (flag) transpose();
  for (auto i = 0; i < (long long)(n); i++) cout << arr[i] << '\n';
  return 0;
}
