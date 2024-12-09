#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int x = 0; x < T; x++) {
    vector<long long> arry(7);
    for (int i = 0; i < 7; i++) cin >> arry[i];
    long long least, all_sum;
    all_sum = arry[6];
    least = arry[0];
    vector<long long> a(3);
    a[0] = least;
    long long ab = all_sum - least;
    a[1] = arry[1];
    a[2] = all_sum - a[1] - a[0];
    cout << a[0] << " " << a[1] << " " << a[2] << endl;
  }
}
