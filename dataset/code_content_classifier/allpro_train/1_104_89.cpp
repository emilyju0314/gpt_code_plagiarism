#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, m;
  cin >> n;
  m = n;
  vector<pair<long long int, int> > p;
  int sum = 0;
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      int c = 0;
      while (n % i == 0) {
        c++;
        sum++;
        n /= i;
      }
      p.push_back({i, c});
      if (sum > 2) {
        long long int temp = 1;
        int t = 0;
        for (int j = 0; j < p.size() && t < 2; j++) {
          if (p[j].second > 1) {
            temp = (p[j].first * p[j].first);
            break;
          } else {
            temp = (temp * p[j].first);
            t++;
          }
        }
        cout << 1 << endl << temp;
        return 0;
      }
    }
  }
  if (n != 1) {
    sum++;
    p.push_back({n, 1});
    if (sum > 2) {
      long long int temp = 1;
      int t = 0;
      for (int i = 0; i < p.size() && t < 2; i++) {
        if (p[i].second > 1) {
          temp = (p[i].first * p[i].first);
          break;
        } else {
          temp = (temp * p[i].first);
          t++;
        }
      }
      cout << 1 << endl << temp;
      return 0;
    } else if (sum == 1) {
      cout << 1 << endl << 0;
      return 0;
    }
  }
  if (sum == 0) {
    cout << 1 << endl << 0;
    return 0;
  }
  cout << 2;
}
