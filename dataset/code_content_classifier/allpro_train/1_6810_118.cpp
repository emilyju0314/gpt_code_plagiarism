#include <bits/stdc++.h>
using namespace std;
const long long int INF = 9223372036854775807;
const long long int mod = 998244353;
const int NUM = 21;
long long int MOD(long long int a, long long int b) {
  if (a > b)
    return a - b;
  else
    return b - a;
}
long long int max3(long long int a, long long int b, long long int c) {
  return max(c, max(a, b));
}
long long int min3(long long int a, long long int b, long long int c) {
  return min(a, min(b, c));
}
long long int power(long long int x, long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long int power1(long long int x, long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res % mod;
}
long long int logg(long long int a) {
  long long int x = 0;
  while (a > 1) {
    x++;
    a /= 2;
  }
  return x;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int abso(long long int x) {
  if (x < 0) {
    return -x;
  }
  return x;
}
long long int ceiling(long long int a, long long int b) {
  if (a % b == 0) {
    return a / b;
  } else {
    return a / b + 1;
  }
}
long long int modinv(long long int x) { return power1(x, mod - 2); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  string str;
  cin >> str;
  int x = 0;
  int y = 0;
  vector<int> temp;
  vector<int> fina;
  for (int i = 0; i < n; i++) {
    if (str[i] == '0') {
      sort(temp.begin(), temp.end());
      fina.insert(fina.end(), temp.begin(), temp.end());
      temp.resize(0);
      fina.push_back(a[i]);
    } else {
      if (i + 1 < n) {
        if (str[i + 1] == '0') {
          temp.push_back(a[i]);
          temp.push_back(a[i + 1]);
          i++;
          sort(temp.begin(), temp.end());
          fina.insert(fina.end(), temp.begin(), temp.end());
          temp.resize(0);
        } else {
          temp.push_back(a[i]);
        }
      } else {
        temp.push_back(a[i]);
      }
    }
  }
  sort(temp.begin(), temp.end());
  fina.insert(fina.end(), temp.begin(), temp.end());
  bool c = true;
  for (int i = 0; i < n - 1; i++) {
    if (fina[i] <= fina[i + 1]) {
    } else {
      c = false;
    }
  }
  if (c) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
