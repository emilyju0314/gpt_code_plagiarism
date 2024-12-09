#include <bits/stdc++.h>
using namespace std;
int main() {
  long long sum = 0, n, flag = 0, arr[100010];
  vector<pair<long, long> > vect;
  scanf("%lld", &n);
  ;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    if (arr[i] != 0) {
      flag = 1;
    }
  }
  if (flag == 0) {
    cout << "NO" << endl;
    return 0;
  }
  long long l = 1, r = 0;
  for (int i = 1; i <= n; i++) {
    r = i;
    sum += arr[i];
    if (sum != 0) {
      vect.push_back(make_pair(l, r));
      sum = 0;
      l = r + 1;
    }
  }
  if (sum == 0) {
    vect[vect.size() - 1].second = n;
  }
  cout << "YES" << endl;
  cout << vect.size() << endl;
  for (int i = 0; i < vect.size(); i++) {
    cout << vect[i].first << " " << vect[i].second << endl;
  }
  return 0;
}
