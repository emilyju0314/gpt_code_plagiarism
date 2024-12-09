#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ar[n + 1];
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    sum += a;
  }
  for (int i = 0; i < n; i++) cin >> ar[i];
  sort(ar, ar + n, greater<int>());
  long long cnt = ar[0] + ar[1];
  if (cnt >= sum)
    cout << "YES";
  else
    cout << "NO";
}
