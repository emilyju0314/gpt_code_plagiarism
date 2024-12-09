#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M, X;
  cin >> N >> M >> X;
  char arr[33][33];
  vector<pair<int, int> > sh;
  vector<double> val(100, -1);
  bool yes = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 'S')
        sh.push_back(make_pair(i, j)), yes = 1;
      else
        val[toupper(arr[i][j])] = 100;
    }
  }
  for (int i = 0; i < (int)sh.size(); i++) {
    int a = sh[i].first, b = sh[i].second;
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < M; k++) {
        if (arr[j][k] != 'S') {
          double dis = sqrt((a - j) * (a - j) + (b - k) * (b - k));
          val[toupper(arr[j][k])] = min(val[toupper(arr[j][k])], dis);
        }
      }
    }
  }
  int q, res = 0;
  cin >> q;
  while (q--) {
    char c;
    cin >> c;
    if (val[toupper(c)] == -1 || (isupper(c) && !yes)) {
      cout << "-1";
      return 0;
    }
    if (isupper(c) && val[toupper(c)] > X) res++;
  }
  cout << res;
  return 0;
}
