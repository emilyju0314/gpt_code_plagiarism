#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long n;
  cin >> n;
  vector<long long> v1;
  vector<long long> v2;
  for (long i = 0; i < n; i++) {
    long long w, h;
    cin >> w >> h;
    v1.push_back(w);
    v2.push_back(h);
  }
  long long comp = max(v1[0], v2[0]);
  long long flag = 1;
  for (long long j = 1; j < n; j++) {
    if (v1[j] > comp && v2[j] > comp) {
      cout << "NO" << endl;
      break;
    } else if (v1[j] <= comp && v2[j] <= comp) {
      comp = max(v1[j], v2[j]);
      flag += 1;
    } else {
      comp = min(v1[j], v2[j]);
      flag += 1;
    }
  }
  if (flag == n) {
    cout << "YES" << endl;
  }
  return 0;
}
