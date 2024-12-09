#include <bits/stdc++.h>
using namespace std;
bool is_prime(long long int n) {
  if (n <= 1) return false;
  if (n == 2) return true;
  if (n > 2 && n % 2 == 0) return false;
  long long int max_div = floor(pow(n, 0.5));
  for (int i = 3; i < 1 + max_div; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}
bool comp(int a, int b) { return a > b; }
bool cmp(pair<long long int, long long int> a,
         pair<long long int, long long int> b) {
  return a.first > b.first;
}
int main() {
  long long int n, s;
  cin >> n >> s;
  if (s % 2 == 0) {
    if (s / n == 1)
      cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      for (int i = 0; i < n - 1; i++) {
        cout << "2 ";
      }
      cout << s - (n - 1) * 2 << endl;
      if (s == 2)
        cout << "1" << endl;
      else
        cout << "3" << endl;
    }
  } else {
    if (s / n < 2) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      for (int i = 0; i < n - 1; i++) {
        cout << "2 ";
      }
      cout << s - (n - 1) * 2 << endl;
      if (s - (n - 1) * 2 == 1)
        cout << "3" << endl;
      else
        cout << "1" << endl;
    }
  }
}
