#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 1005;
int n, k;
char mt[lim][lim];
string str[5] = {"aeiou", "eioua", "iouae", "ouaei", "uaeio"};
void fillMT() {
  for (int i = 0; i < lim; i += 5) {
    for (int j = 0; j < lim; j += 5) {
      for (int c = 0; c < 5; c++)
        for (int d = 0; d < 5; d++) mt[i + c][j + d] = str[c][d];
    }
  }
}
void printMT(int rw, int col) {
  for (int i = 0; i < rw; i++) {
    for (int j = 0; j < col; j++) {
      cout << mt[i][j] << " ";
    }
    cout << "\n";
  }
}
void solve() {
  cin >> k;
  for (int i = 0; i < lim; i++)
    for (int j = 0; j < lim; j++) mt[i][j] = '$';
  int rw = 1, col = 0;
  for (int i = 2; i * i <= k; i++) {
    if (k % i == 0) rw = i;
  }
  col = k / rw;
  if (min(rw, col) < 5) {
    cout << -1;
    return;
  }
  fillMT();
  string answ = "";
  for (int i = 0; i < rw; i++)
    for (int j = 0; j < col; j++) answ += mt[i][j];
  cout << answ;
}
void fastIO() {
  cin.sync_with_stdio(false);
  cin.tie(0);
}
void IO() {
  if (fopen("d:\\lmo.in", "r") != NULL) {
    freopen("d:\\lmo.in", "r", stdin);
  } else if (fopen("/media/Beijing/lmo.in", "r") != NULL) {
    freopen("/media/Beijing/lmo.in", "r", stdin);
  }
}
int main() {
  IO();
  fastIO();
  solve();
}
