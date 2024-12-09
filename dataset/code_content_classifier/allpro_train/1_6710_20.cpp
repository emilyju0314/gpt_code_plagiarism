#include <bits/stdc++.h>
using namespace std;
long long a[11000], n, T, Ans, Max_m, b[11000];
map<int, int> Map;
vector<int> A;
int main() {
  int i, j, k;
  cin >> n >> T;
  for (i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i] = a[i];
    Map[a[i]]++;
  }
  sort(b + 1, b + n + 1);
  for (i = n + 1; i <= min(T, n) * n; ++i) {
    a[i] = a[(i - 1) % n + 1];
  }
  j = 1;
  for (i = 1; i <= min(T, n) * n && j <= n; ++i) {
    if (a[i] == b[j]) j++;
  }
  for (; (i - 1) % n + 1 != 1; ++i)
    ;
  for (k = 1; k < i; ++k) {
    if (A.empty() || a[k] >= A.back())
      A.push_back(a[k]);
    else
      *upper_bound(A.begin(), A.end(), a[k]) = a[k];
  }
  Ans = A.size();
  for (j = 1; j <= n; ++j) {
    if (Map[a[j]] > Max_m) Max_m = Map[a[j]];
  }
  i--;
  Ans += (T * n - i) / n * Max_m;
  cout << Ans << endl;
  return 0;
}
