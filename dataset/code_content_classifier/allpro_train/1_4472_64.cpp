#include <bits/stdc++.h>
using namespace std;
void dm(vector<vector<long long> >& m) {
  for (long long i = 0; i < m.size(); i++) {
    for (long long j = 0; j < m[i].size(); j++) {
      if (j != m[i].size() - 1) {
        cout << m[i][j] << " ";
      } else {
        cout << m[i][j] << endl;
      }
    }
  }
}
void dv(vector<long long>& v) {
  for (long long i = 0; i < v.size() - 1; i++) {
    cout << v[i] << " ";
  }
  cout << v[v.size() - 1] << endl;
}
void swap(long long& a, long long& b) {
  long long temp = a;
  a = b;
  b = temp;
}
long long minval(long long a, long long b) {
  if (a < b) {
    return a;
  }
  return b;
}
long long maxval(long long a, long long b) {
  if (a > b) {
    return a;
  }
  return b;
}
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long powmod(long long a, long long b, long long mod) {
  if (b == 0) return 1;
  if (b % 2 == 0) {
    long long c = powmod(a, b / 2, mod);
    return (c * c) % mod;
  } else {
    return (a * powmod(a, b - 1, mod)) % mod;
  }
}
long long modInverse(long long A, long long M) { return powmod(A, M - 2, M); }
long long lower_bound_sq(long long num) {
  long long lo = 1;
  long long hi = 1000000;
  while (lo < hi) {
    long long mid = (lo + hi + 1) / 2;
    if ((mid * mid) <= (num)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
    cout << lo << " " << hi << endl;
  }
  return lo;
}
pair<long long, long long> mk_pair(long long a, long long b) {
  pair<long long, long long> p;
  p.first = a;
  p.second = b;
  return p;
}
void solve() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long a, b;
  cin >> a >> b;
  long long g = gcd(a, b);
  if (a < b) {
    if ((a + g) == b) {
      cout << "Equal" << endl;
    } else {
      if (b > (a + g)) {
        cout << "Dasha" << endl;
      } else {
        cout << "Masha" << endl;
      }
    }
  } else {
    if ((b + g) == a) {
      cout << "Equal" << endl;
    } else {
      if (a > (b + g)) {
        cout << "Masha" << endl;
      } else {
        cout << "Dasha" << endl;
      }
    }
  }
  return 0;
}
