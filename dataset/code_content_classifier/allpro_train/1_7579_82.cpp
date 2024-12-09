#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};
int year[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool prime[10000005];
long long M = 1e9 + 7;
long long fast_power(long long b, long long p) {
  long long res = 1;
  while (p > 0) {
    if (p & 1) res = (res * b);
    p /= 2, b = (b * b);
  }
  return res;
}
bool p[2000005];
int arr[1000005];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  for (int i = 2; i < 2000005; ++i) p[i] = 1;
  for (int i = 2; i * i < 2000005; ++i) {
    if (p[i]) {
      for (int j = i + i; j < 2000005; j += i) p[j] = 0;
    }
  }
  int n, x;
  cin >> n;
  vector<int> v;
  while (n--) {
    cin >> x;
    if (!arr[x]) v.push_back(x);
    ++arr[x];
  }
  n = v.size();
  sort(v.begin(), v.end());
  bool f = 0;
  int a = 0, b = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (p[(v[i] + v[j])]) {
        f = 1, a = i, b = j;
        break;
      }
    }
    if (f) break;
  }
  if (f) {
    if (v[a] != 1) {
      if (v[0] == 1 && arr[1] > 1) {
        cout << arr[1] << "\n";
        for (int i = 0; i < arr[1]; ++i) cout << "1 ";
      } else {
        cout << 2 << "\n";
        cout << v[a] << " " << v[b];
      }
    } else {
      cout << arr[1] + 1 << "\n";
      for (int i = 0; i < arr[1]; ++i) cout << "1 ";
      cout << v[b];
    }
  } else {
    if (v[0] == 1) {
      cout << arr[1] << "\n";
      for (int i = 0; i < arr[1]; ++i) cout << "1 ";
    } else
      cout << "1\n" << v[0];
  }
  return 0;
}
