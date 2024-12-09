#include <bits/stdc++.h>
using namespace std;
inline void op() {}
long long int bin(vector<long long int> a, long long int x, long long int n) {
  long long int start = 0, end = n - 1, ans = 0;
  while (start <= end) {
    long long int mid = (start + end) / 2;
    if (a[mid] < x) {
      ans = mid;
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return ans;
}
long long int bi(vector<long long int> a, long long int x, long long int n) {
  long long int start = 0, end = n - 1, ans = n - 1;
  while (start <= end) {
    long long int mid = (start + end) / 2;
    if (a[mid] <= x) {
      start = mid + 1;
    } else {
      ans = mid;
      end = mid - 1;
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  op();
  long long int n, m;
  cin >> n >> m;
  vector<long long int> d(n + m), a;
  for (int i = 0; i <= n + m - 1; i = i + 1) {
    cin >> d[i];
  }
  long long int b[n + m];
  for (int i = 0; i <= m + n - 1; i = i + 1) {
    cin >> b[i];
  }
  long long int l[m + n + 1];
  l[0] = INT_MIN;
  unordered_map<long long int, long long int> x;
  for (int i = 1; i <= m + n; i = i + 1) {
    if (b[i - 1] == 1) {
      l[i] = d[i - 1];
    } else {
      l[i] = l[i - 1];
    }
  }
  long long int r[m + n + 2];
  r[m + n + 1] = INT_MAX;
  for (int i = m + n; i >= 1; i = i - 1) {
    if (b[i - 1] == 1) {
      r[i] = d[i - 1];
    } else {
      r[i] = r[i + 1];
    }
  }
  for (int i = 1; i <= m + n; i = i + 1) {
    if (b[i - 1] == 0) {
      if (l[i] == INT_MIN) {
        x[r[i]]++;
      } else if (r[i] == INT_MAX) {
        x[l[i]]++;
      } else {
        if (d[i - 1] - l[i] <= r[i] - d[i - 1]) {
          x[l[i]]++;
        } else {
          x[r[i]]++;
        }
      }
    }
  }
  for (int i = 0; i <= m + n - 1; i = i + 1) {
    if (b[i] == 1) {
      cout << x[d[i]] << " ";
    }
  }
  return 0;
}
