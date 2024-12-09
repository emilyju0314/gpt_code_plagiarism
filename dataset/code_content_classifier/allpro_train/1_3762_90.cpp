#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long arr[n];
  vector<pair<long long, long long> > v;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long maxn = -1e7 + 7;
  for (long long i = 0; i < n; i++) {
    for (long long j = i; j < n; j++) {
      vector<long long> outRange;
      long long res = 0;
      for (long long t = 0; t < i; t++) outRange.push_back(arr[t]);
      for (long long t = j + 1; t < n; t++) outRange.push_back(arr[t]);
      vector<long long> inRange;
      for (long long t = i; t <= j; t++)
        inRange.push_back(arr[t]), res += arr[t];
      sort(outRange.begin(), outRange.end(), greater<long long>());
      sort(inRange.begin(), inRange.end());
      long long t = 0;
      long long m = 0;
      while (t < k && t < outRange.size() && m < inRange.size()) {
        if (inRange[m] > outRange[t]) break;
        res -= inRange.at(m);
        res += outRange.at(t);
        t++;
        m++;
      }
      maxn = max(res, maxn);
    }
  }
  cout << maxn << endl;
  return 0;
}
