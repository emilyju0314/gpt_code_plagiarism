#include <bits/stdc++.h>
using namespace std;
const int E = 1e5 + 5, M = 1e9 + 5;
bool asccmp(pair<int, int> x, pair<int, int> y) { return x.second < y.second; }
long long a, b, c, o, x;
map<char, int> j;
string s[E];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int q = 0; q < 3; q++) {
    cin >> s[q];
    for (int w = 0; w < 3; w++) {
      j[s[q][w]]++;
    }
  }
  for (int q = 0; q < 3; q++) {
    if (s[q] == "000")
      o = 1;
    else if (s[q] == "XXX")
      x = 1;
  }
  for (int w = 0; w < 3; w++) {
    if (s[0][w] == s[1][w] && s[1][w] == s[2][w]) {
      if (s[0][w] == '0') {
        o = 1;
      } else if (s[0][w] == 'X') {
        x = 1;
      }
    }
  }
  if ((s[0][0] == s[1][1] && s[1][1] == s[2][2]) ||
      (s[0][2] == s[1][1] && s[1][1] == s[2][0])) {
    if (s[1][1] == '0') {
      o = 1;
    } else if (s[1][1] == 'X') {
      x = 1;
    }
  }
  if (j['0'] > j['X'] || (j['X'] > j['0'] && j['X'] - j['0'] > 1) || (x && o) ||
      (o && j['X'] != j['0']) || (x && j['0'] != j['X'] - 1)) {
    printf("illegal");
    return 0;
  }
  if (o && !x) {
    printf("the second player won\n");
    return 0;
  } else if (x && !o) {
    printf("the first player won\n");
    return 0;
  } else if (!j['.'] && !x && !o) {
    printf("draw\n");
    return 0;
  }
  if (j['0'] == j['X']) {
    printf("first");
  } else if (j['X'] > j['0'] && j['X'] - j['0'] == 1) {
    printf("second");
  } else {
    printf("draw");
  }
}
