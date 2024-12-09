#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long ar[n];
  long long i;
  for (i = 0; i < n; i++) {
    cin >> ar[i];
  }
  sort(ar, ar + n);
  if (n % 2 == 0) {
    vector<long long> v1;
    vector<long long> v2;
    for (i = 0; i < n / 2; i++) v1.push_back(ar[i]);
    for (i = n / 2; i < n; i++) v2.push_back(ar[i]);
    long long x1 = 0;
    long long x2 = 0;
    vector<long long> v3;
    for (i = 0; i < n; i++) {
      if (i % 2 == 0) {
        v3.push_back(v2[x1]);
        x1++;
      } else {
        v3.push_back(v1[x2]);
        x2++;
      }
    }
    long long sum = 0;
    for (i = 1; i < n - 1; i++) {
      if (v3[i] < v3[i - 1] and v3[i] < v3[i + 1]) sum++;
    }
    cout << sum << "\n";
    for (i = 0; i < n; i++) cout << v3[i] << " ";
  } else {
    vector<long long> v1;
    vector<long long> v2;
    for (i = 0; i < n / 2; i++) v1.push_back(ar[i]);
    for (i = n / 2; i < n; i++) v2.push_back(ar[i]);
    long long x1 = 0;
    long long x2 = 0;
    vector<long long> v3;
    for (i = 0; i < n; i++) {
      if (i % 2 == 0) {
        v3.push_back(v2[x1]);
        x1++;
      } else {
        v3.push_back(v1[x2]);
        x2++;
      }
    }
    long long sum = 0;
    for (i = 1; i < n - 1; i++) {
      if (v3[i] < v3[i - 1] and v3[i] < v3[i + 1]) sum++;
    }
    cout << sum << "\n";
    for (i = 0; i < n; i++) cout << v3[i] << " ";
  }
}
