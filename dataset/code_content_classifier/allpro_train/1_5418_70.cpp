#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const string LN = "\n";
const double eps = 1e-9;
const double pi = acos(-1.0);
const int INF = (int)1e9 + 7;
const long long LINF = (long long)9e18 + 7;
const long long P = 353251;
const long long P1 = 353251;
const long long P2 = 239017;
const long long MOD = 1e9 + 7;
const long long MOD1 = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
int n, a, b, k;
string s;
vector<pair<int, int> > q;
const bool is_testing = 0;
int main() {
  srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
  if (is_testing) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  } else {
  }
  cin >> n >> a >> b >> k >> s;
  s += '1';
  int st = -1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      if (st == -1) st = i;
    } else {
      if (st != -1) {
        q.push_back(make_pair(st, i - st));
        st = -1;
      }
    }
  }
  int can = 0;
  for (int i = 0; i < q.size(); i++) {
    can += q[i].second / b;
  }
  int kk = can - a + 1;
  printf("%d\n", kk);
  for (int i = 0; i < q.size(); i++) {
    for (int d = q[i].first + b - 1; d <= q[i].first + q[i].second - 1;
         d += b) {
      printf("%d ", d + 1);
      kk--;
      if (kk == 0) exit(0);
    }
  }
}
