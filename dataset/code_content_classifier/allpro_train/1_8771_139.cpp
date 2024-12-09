#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int num;
  cin >> num;
  vector<int> tri(44721);
  for (long long i = 1;; i++) {
    if (i * (i + 1) / 2 > MOD) break;
    tri[i - 1] = i * (i + 1) / 2;
  }
  int n = tri.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if (tri[i] + tri[j] == num) {
        cout << "YES";
        return 0;
      }
      if (tri[i] + tri[j] > num) break;
    }
    if (tri[i] > num) break;
  }
  cout << "NO";
}
