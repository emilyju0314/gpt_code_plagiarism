#include <bits/stdc++.h>
using namespace std;
template <typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T> p) {
  out << "(" << p.first << "," << p.second << ")";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  for (auto a : v) out << a << " ";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const set<T>& S) {
  for (auto a : S) cout << a << " ";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const multiset<T>& S) {
  for (auto a : S) cout << a << " ";
  return out;
}
template <typename S, typename T>
ostream& operator<<(ostream& out, const map<S, T>& M) {
  for (auto m : M) cout << "(" << m.first << "->" << m.second << ") ";
  return out;
}
template <typename S, typename T>
pair<S, T> operator+(pair<S, T> a, pair<S, T> b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
template <typename S, typename T>
pair<S, T> operator-(pair<S, T> a, pair<S, T> b) {
  return make_pair(a.first - b.first, a.second - b.second);
}
struct Prime {
  int upper;
  vector<int> prime;
  vector<int> A;
  Prime(int n) {
    upper = n;
    A.assign(n + 1, 1);
    A[0] = A[1] = 0;
    for (int i = 0; i <= n; i++)
      if (A[i])
        for (int j = i + i; j <= n; j += i) A[j] = 0;
    for (int i = 0; i <= n; i++)
      if (A[i]) prime.push_back(i);
  }
  bool is_prime(long long n) {
    if (n <= upper) return A[n];
    if (n < 2) return false;
    for (int i = 0; i < prime.size() && prime[i] <= sqrt(n); i++) {
      if (n % prime[i] == 0) return false;
    }
    return true;
  }
  void factor(long long n, map<long long, int>& M) {
    M.clear();
    for (int i = 0; i < prime.size() && prime[i] <= sqrt(n); i++) {
      while (n % prime[i] == 0) {
        M[prime[i]]++;
        n /= prime[i];
      }
    }
    if (n > 1) M[n]++;
  }
  void factor(long long n, vector<long long>& F) {
    F.clear();
    for (int i = 0; i < prime.size() && prime[i] <= sqrt(n); i++) {
      while (n % prime[i] == 0) {
        F.push_back(prime[i]);
        n /= prime[i];
      }
    }
    if (n > 1) F.push_back(n);
  }
  map<long long, int> _M;
  long long euler_totient(long long n) {
    map<long long, int>& M = _M;
    factor(n, M);
    for (auto p : M) n = n / p.first * (p.first - 1);
    return n;
  }
  long long query_number_of_divisors(long long n) {
    map<long long, int>& M = _M;
    factor(n, M);
    long long ans = 1;
    for (auto p : M) ans *= p.second + 1;
    return ans;
  }
  void backtrack_query_divisors(map<long long, int>& M, vector<long long>& P,
                                int cur, long long val,
                                vector<long long>& ans) {
    if (cur == P.size()) {
      ans.push_back(val);
      return;
    }
    long long p = P[cur];
    for (int i = 0; i <= M[P[cur]]; i++) {
      backtrack_query_divisors(M, P, cur + 1, val, ans);
      val *= p;
    }
  }
  vector<long long> _P;
  vector<long long> query_divisors(long long n) {
    map<long long, int>& M = _M;
    vector<long long>& P = _P;
    factor(n, M);
    P.clear();
    for (auto p : M) P.push_back(p.first);
    vector<long long> ans;
    long long val = 1;
    backtrack_query_divisors(M, P, 0, val, ans);
    return ans;
  }
};
Prime prime(1e4);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  int m;
  vector<long long> F;
  cin >> n >> m;
  prime.factor(n, F);
  if (F.size() < m) {
    cout << -1 << endl;
  } else {
    for (int i = m; i < F.size(); i++) {
      F[m - 1] *= F[i];
    }
    F.resize(m);
    cout << F << endl;
  }
  return 0;
}
