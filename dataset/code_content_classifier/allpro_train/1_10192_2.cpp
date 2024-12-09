#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  while (t--) {
    long long int N;
    cin >> N;
    long long int K;
    cin >> K;
    string T;
    cin >> T;
    int now = 0;
    int count = 0;
    while (now != N - 1) {
      int d = K;
      while (now + d > N - 1 || T[now + d] == '0') {
        d--;
      }
      if (d == 0) {
        cout << -1;
        return 0;
      }
      now = now + d;
      count++;
    }
    cout << count;
  }
}
