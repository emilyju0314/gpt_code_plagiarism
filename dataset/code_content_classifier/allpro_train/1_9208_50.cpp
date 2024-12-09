#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
vector<long long> minDiv(1e7 + 1);
void esieve(long long s) {
  for (int i = 2; i * i <= s; i++) {
    if (!minDiv[i])
      for (int k = i * i; k <= s; k += i) minDiv[k] = i;
  }
}
vector<long long> primes(long long n) {
  vector<long long> p;
  while (n != 1) {
    p.push_back(minDiv[n]);
    n /= minDiv[n];
  }
  return p;
}
int main() {
  long long T = 1;
  while (T--) {
    esieve(1e7);
    for (int i = 0; i <= 1e7; i++) {
      if (!minDiv[i]) minDiv[i] = i;
    }
    long long n, m;
    cin >> n >> m;
    vector<long long> pcnt(1e7 + 1, 0), A, B;
    for (int i = 0; i < n; i++) {
      int tn;
      cin >> tn;
      A.push_back(tn);
      vector<long long> p = primes(tn);
      for (auto x : p) pcnt[x]++;
    }
    for (int i = 0; i < m; i++) {
      int tn;
      cin >> tn;
      B.push_back(tn);
      vector<long long> p = primes(tn);
      for (auto x : p) pcnt[x]--;
    }
    vector<long long> a, b;
    for (int i = 0; i < n; i++) {
      long long cur = 1;
      long long ab = A[i];
      while (ab != 1) {
        if (pcnt[minDiv[ab]] > 0) {
          cur *= minDiv[ab];
          pcnt[minDiv[ab]]--;
        }
        ab /= minDiv[ab];
      }
      a.push_back(cur);
    }
    for (int i = 0; i < m; i++) {
      long long cur = 1;
      long long ab = B[i];
      while (ab != 1) {
        if (pcnt[minDiv[ab]] < 0) {
          cur *= minDiv[ab];
          pcnt[minDiv[ab]]++;
        }
        ab /= minDiv[ab];
      }
      b.push_back(cur);
    }
    if (a.size() == 0) a.push_back(1);
    if (b.size() == 0) b.push_back(1);
    cout << a.size() << " " << b.size() << endl;
    for (auto x : a) cout << x << " ";
    cout << endl;
    for (auto x : b) cout << x << " ";
    cout << endl;
  }
}
