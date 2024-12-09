#include <bits/stdc++.h>
using namespace std;
long long int maxipower(long long m, long long k) {
  long long y = 1;
  long long x = 0;
  while (1) {
    if (y <= m / k) {
      x++;
      y = y * k;
    } else {
      return x;
    }
  }
}
long long b[200004], a[200004], k, x;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<tuple<long long, long long, long long>> v;
  long long n, i, cnt = 0;
  cin >> n;
  long long mmm;
  long long tt = n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]]++;
    if (b[a[i]] > k) {
      k = b[a[i]];
      mmm = a[i];
      x = i;
    }
  }
  for (i = 0; i < tt; i++) {
    if (a[i] == mmm) {
      x = i;
      break;
    }
  }
  for (i = x; i < tt - 1; i++) {
    if (a[i + 1] == mmm) {
      continue;
    } else {
      cnt++;
      if (a[i + 1] > mmm) {
        v.push_back(make_tuple(2, i + 2, i + 1));
      } else {
        v.push_back(make_tuple(1, i + 2, i + 1));
      }
      a[i + 1] = mmm;
    }
  }
  for (i = x; i >= 1; i--) {
    if (a[i - 1] == mmm) {
    } else {
      cnt++;
      if (a[i - 1] > mmm) {
        v.push_back(make_tuple(2, i, i + 1));
      } else {
        v.push_back(make_tuple(1, i, i + 1));
      }
      a[i - 1] = mmm;
    }
  }
  cout << v.size() << "\n";
  for (i = 0; i < v.size(); i++) {
    cout << get<0>(v[i]) << " " << get<1>(v[i]) << " " << get<2>(v[i]) << "\n";
  }
  return 0;
}
