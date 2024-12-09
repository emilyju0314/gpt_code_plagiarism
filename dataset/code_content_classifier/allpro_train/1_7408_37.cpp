#include <bits/stdc++.h>
using namespace std;
class Compare {
 public:
  bool operator()(const int& l, const int& r) { return l > r; }
};
typedef priority_queue<int> pq;
typedef priority_queue<int, vector<int>, Compare> PQ;
const int MOD = 1000000007;
const double EPS = 1e-11;
const double INF = 2e30;
const double PI = 2 * acos(0.0);
int divide(string a, int base) {
  int b = a.size(), c = 0, r = 0, i = 0;
  while (i < b) {
    c = c * base + a[i++] - '0';
    if (c / b > 0) {
      r = r * base + c / b;
      c = c % b;
    }
  }
  if (c == 0) return r;
  return 0;
}
bool Prime(int n) {
  int sqt = sqrt(n);
  for (int i = 2; i <= sqt; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int Bset(int N, int pos) { return N = N | (1 << pos); }
int Breset(int N, int pos) { return N = N & ~(1 << pos); }
bool Bcheck(int N, int pos) { return (bool)(N & (1 << pos)); }
long long n;
long long a[100];
int main() {
  scanf("%lld", &n);
  a[0] = 1;
  a[1] = 2;
  int r;
  for (int i = 2; i <= 90; i++) {
    a[i] = a[i - 1] + a[i - 2];
    if (a[i] > n) {
      r = i - 1;
      break;
    }
  }
  cout << r << endl;
}
