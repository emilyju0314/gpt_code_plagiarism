#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int main() {
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  for (int k = 0; k < N; k++) {
    int v;
    cin >> v;
    arr.push_back(v);
  }
  if (N == 1 || N == 2) {
    cout << N << endl;
    return 0;
  }
  int cnt = 2;
  int mx = 2;
  for (int k = 2; k < N; k++) {
    if (arr[k] == (arr[k - 1] + arr[k - 2])) {
      cnt++;
    } else {
      mx = max(mx, cnt);
      cnt = 2;
    }
  }
  mx = max(mx, cnt);
  cout << mx << endl;
  return 0;
}
