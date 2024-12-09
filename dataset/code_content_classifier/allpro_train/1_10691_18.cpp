#include <bits/stdc++.h>
using namespace std;
bool myCmp(pair<int, int> &p1, pair<int, int> &p2) {
  return p1.first > p2.first;
}
unsigned long long choose(unsigned long long n, unsigned long long k) {
  if (k > n) {
    return 0;
  }
  unsigned long long r = 1;
  for (unsigned long long d = 1; d <= k; ++d) {
    r *= n--;
    r /= d;
  }
  return r;
}
const int OO = 10e9;
const int MAXN = 101;
char arr[MAXN][MAXN];
bool rem[MAXN][MAXN];
bool skip[MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> arr[i + 1][j + 1];
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < n + 1; i++)
    for (int j = 0; j < m + 1; j++) rem[i][j] = true;
  int vld = 0;
  int cnt = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j < n; j++) {
      if ((rem[j][vld] == false) ||
          (rem[j][vld] && (arr[j][i] < arr[j + 1][i])))
        rem[j][vld + 1] = false;
      else if (rem[j][vld] && (arr[j][i] == arr[j + 1][i])) {
        rem[j][vld + 1] = true;
      } else if (rem[j][vld]) {
        cnt++;
        vld--;
        break;
      }
    }
    vld++;
  }
  cout << cnt << endl;
  return 0;
}
