#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
vector<long long> g[100005];
long long a, b, n, mas[105][105], m, k;
const long long INF = LONG_MAX;
bool used[100005], zap[100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  if (n == 0)
    cout << 15;
  else if (n == 1)
    cout << 14;
  else if (n == 2)
    cout << 12;
  else if (n == 3)
    cout << 13;
  else if (n == 4)
    cout << 8;
  else if (n == 5)
    cout << 9;
  else if (n == 6)
    cout << 10;
  else if (n == 7)
    cout << 11;
  else if (n == 8)
    cout << 0;
  else if (n == 9)
    cout << 1;
  else if (n == 10)
    cout << 2;
  else if (n == 11)
    cout << 3;
  else if (n == 12)
    cout << 4;
  else if (n == 13)
    cout << 5;
  else if (n == 14)
    cout << 6;
  else if (n == 15)
    cout << 7;
  return 0;
}
