#include <bits/stdc++.h>
using namespace std;
int ri() {
  int x;
  if (scanf(" %d", &x) == EOF) return -1;
  return x;
}
long long int rl() {
  long long int x;
  if (cin >> x) return x;
  return -1;
}
string rs() {
  string s;
  if (cin >> s) return s;
  return "";
}
struct FactorCount {
  vector<map<int, int> > memo;
  map<int, int>& getCounts(int k) {
    if (memo.size() < k + 1) {
      memo.resize(k + 1);
    }
    doit(k);
    return memo[k];
  }
  void doit(int k) {
    if (k <= 1) {
      memo[k] = {};
      return;
    }
    if (!memo[k].empty()) return;
    doit(k - 1);
    map<int, int>& M = memo[k];
    M = memo[k - 1];
    int N = k;
    for (int i = 2; i * i <= N; i++)
      if (N % i == 0) {
        int r = 0;
        while (N % i == 0) {
          N /= i;
          r++;
        }
        M[i] += r;
      }
    if (N > 1) M[N]++;
  }
};
FactorCount factorCounts;
struct FactorState {
  const int n;
  const int count;
  int length;
  vector<pair<int, int> > factors;
  FactorState(int n, int count) : n(n), count(count) {
    _factorize();
    length = _length();
  }
  int next() {
    if (factors.empty()) {
      return -1;
    }
    int p = factors.back().first;
    if (--factors.back().second == 0) factors.erase(factors.end() - 1);
    return p;
  }
  int _length() {
    int ret = 0;
    for (auto [_, v] : factors) ret += v;
    return ret;
  }
  void _factorize() {
    for (auto [k, v] : factorCounts.getCounts(n)) {
      factors.push_back({k, v});
    }
  }
};
struct LengthCalculator {
  vector<FactorState> FS;
  int totalCount;
  LengthCalculator(const vector<int>& numbers) {
    totalCount = numbers.size();
    map<int, int> M;
    for (auto x : numbers) M[x]++;
    for (auto [n, count] : M) {
      FS.push_back({n, count});
    }
  }
  vector<int> filter(vector<int> input) {
    map<int, int> M;
    vector<int> primes;
    for (auto idx : input) {
      int p = FS[idx].next();
      primes.push_back(p);
      if (p >= 2) M[p] += FS[idx].count;
    }
    int maxCount = -1, maxP = -1;
    for (auto [p, count] : M)
      if (count > maxCount) maxCount = count, maxP = p;
    if (maxCount <= totalCount / 2) {
      return vector<int>();
    }
    vector<int> ret;
    for (int i = 0; i < primes.size(); ++i)
      if (primes[i] == maxP) ret.push_back(input[i]);
    return ret;
  }
  void printInput(string message, const vector<int>& input) {
    return;
    printf("%s: ", message.c_str());
    for (auto idx : input) printf("%d ", FS[idx].n);
    cout << " <end>" << endl;
  }
  long long int calculate() {
    long long int ret = 0;
    for (auto& fs : FS) {
      ret += fs.length * (long long int)fs.count;
    }
    vector<int> input;
    for (int i = 0; i < FS.size(); ++i) input.push_back(i);
    printInput("Initial input", input);
    while (true) {
      input = filter(input);
      printInput("Filtered to", input);
      if (input.empty()) break;
      int filteredCount = 0;
      for (auto idx : input) filteredCount += FS[idx].count;
      ret = ret - 2 * filteredCount + totalCount;
    }
    return ret;
  }
};
struct SingleCase {
  int n;
  bool solveCase() {
    n = ri();
    if (n < 0) return false;
    vector<int> v;
    for (int i = 0; i < n; ++i) v.push_back(ri());
    LengthCalculator lc{v};
    long long int ret = lc.calculate();
    cout << ret << endl;
    return true;
  }
};
int primeTotal(int k) {
  vector<int> v(k + 1, 0);
  int ret = 0;
  long long int total = 0;
  for (long long int n = 2; n <= k; n++) {
    if (v[n] == 0) {
      long long int N = n;
      while (N < k) {
        for (long long int T = N; T <= k; T += N) {
          v[T]++;
        }
        N *= n;
      }
    }
    ret += v[n];
    total += ret;
    if (n <= 10) printf("%lld %lld\n", n, ret);
  }
  printf("%lld expSum = %lld, cum. expSum = %lld\n", k, ret, total);
  return 0;
}
int main() {
  while (SingleCase().solveCase()) {
  };
  return 0;
}
