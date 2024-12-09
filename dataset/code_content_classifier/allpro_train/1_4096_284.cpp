#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int main() {
  vector<long long> v1, v2;
  long long n, a, b, arr[N];
  cin >> n >> a >> b;
  for (long long i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  for (long long i = 0; i < b; i++) v1.push_back(arr[i]);
  for (long long i = b; i < n; i++) v2.push_back(arr[i]);
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  cout << v2[0] - v1[v1.size() - 1];
  return 0;
}
