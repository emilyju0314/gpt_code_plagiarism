#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  long long s = 0;
  vector<int> arr;
  for (int k = 0; k < N; k++) {
    int v;
    cin >> v;
    arr.push_back(v);
  }
  if (N == 1) {
    cout << 1 << endl;
    return 0;
  }
  int cnt = 1;
  for (int k = 0; k < N - 1; k++) {
    if (arr[k] == arr[k + 1])
      cnt++;
    else {
      s += ((cnt * 1LL) * ((cnt + 1) * 1LL)) / 2;
      cnt = 1;
    }
  }
  s += ((cnt * 1LL) * ((cnt + 1) * 1LL)) / 2;
  cout << s << endl;
  return 0;
}
