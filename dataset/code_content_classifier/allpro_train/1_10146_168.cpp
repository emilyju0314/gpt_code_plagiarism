#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  long long int a[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  vector<long long int> v;
  v.push_back(sqrt((a[0][1] * a[0][2]) / a[1][2]));
  v.push_back(sqrt((a[1][0] * a[1][2]) / a[0][2]));
  for (int i = 2; i < n; i++) {
    v.push_back(sqrt((a[i][0] * a[i][1]) / a[0][1]));
  }
  for (int i = 0; i < n; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
