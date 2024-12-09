#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
const long long INF = (long long)2e18;
const long long one = (long long)1e5 + 1;
const long double PI = 3.141592653589793238462;
long long mod = (long long)1000000007;
long long mod2 = (long long)998244353;
long long expo(long long a, long long b, long long mod) {
  long long res = 1ll;
  while (b > 0) {
    if (b & 1ll) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1ll;
  }
  return res;
}
void extendgcd(long long a, long long b, long long* v) {
  if (b == 0) {
    v[0] = 1;
    v[1] = 0;
    v[2] = a;
    return;
  }
  extendgcd(b, a % b, v);
  long long x = v[1];
  v[1] = v[0] - v[1] * (a / b);
  v[0] = x;
  return;
}
long long mminv(long long a, long long b) {
  long long arr[3];
  extendgcd(a, b, arr);
  return arr[0];
}
long long mminvprime(long long a, long long b) { return expo(a, b - 2, b); }
bool revsort(long long a, long long b) { return a > b; }
void swap(int& x, int& y) {
  int temp = x;
  x = y;
  y = temp;
}
long long combination(long long n, long long r, long long m, long long* fact,
                      long long* ifact) {
  long long val1 = fact[n];
  long long val2 = ifact[n - r];
  long long val3 = ifact[r];
  return (((val1 * val2) % m) * val3) % m;
}
void google(int t) { cout << "Case #" << t << ": "; }
vector<long long> sieve(int n) {
  int* arr = new int[n + 1]();
  vector<long long> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long mod_div(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}
long long phin(long long n) {
  long long number = n;
  if (n % 2 == 0) {
    number /= 2;
    while (n % 2 == 0) n /= 2;
  }
  for (long long i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      number = (number / i * (i - 1));
    }
  }
  if (n > 1) number = (number / n * (n - 1));
  return number;
}
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <typename T>
void sort(vector<T>& v) {
  sort(v.begin(), v.end());
  return;
}
template <typename T>
void sortbig(vector<T>& v) {
  sort(v.begin(), v.end(), greater<T>());
  return;
}
template <typename T>
ostream& operator<<(ostream& stream, vector<T>& v) {
  for (T& x : v) stream << x << " ";
  return stream;
}
template <typename T>
istream& operator>>(istream& stream, vector<T>& v) {
  for (T& x : v) stream >> x;
  return stream;
}
struct Node {
  long long index;
  long long value;
  Node(long long index, long long value) : index(index), value(value) {}
};
struct Edge {
  int to;
  long long cost;
  Edge(int to, long long cost) : to(to), cost(cost) {}
};
bool sortbysec(const pair<long long, long long>& a,
               const pair<long long, long long>& b) {
  return (a.second < b.second);
}
struct CompareNode {
  bool operator()(Node const& p1, Node const& p2) {
    return p1.value > p2.value;
  }
};
struct ComparePair {
  bool operator()(pair<long long, long long> const& p1,
                  pair<long long, long long> const& p2) {
    return p1.second < p2.second;
  }
};
bool sortcolbig(const vector<long long>& v1, const vector<long long>& v2) {
  return v1[0] > v2[0];
}
bool sortcol(const vector<long long>& v1, const vector<long long>& v2) {
  return v1[1] < v2[1];
}
void solve(int test) {
  long long n;
  cin >> n;
  vector<long long> arr(n + 1);
  for (long long i = (0); i < long long(long long(n)); ++i) {
    cin >> arr[i + 1];
  }
  if (n == 1) {
    cout << "YES" << endl;
    cout << arr[1] << endl;
    return;
  }
  long long sums = 0ll;
  long long xa = 0ll;
  for (long long i = (1); i < long long(n + 1); ++i) {
    sums += arr[i];
  }
  long long na = (n * (n + 1ll)) / 2ll;
  if (sums % na) {
    cout << "NO" << endl;
    return;
  }
  xa = sums / na;
  vector<long long> brr(n + 1);
  int cc = 1;
  long long temp = xa - arr[1] + arr[n];
  if (temp > 0 and (temp % n == 0)) {
    brr[1] = temp / n;
  } else {
    cc = 0;
  }
  for (long long i = (2); i < long long(n + 1); ++i) {
    long long temp = xa - arr[i] + arr[i - 1];
    if (temp > 0 and (temp % n == 0)) {
      brr[i] = temp / n;
    } else {
      cc = 0;
    }
  }
  if (cc == 0) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  for (long long i = (1); i < long long(n + 1); ++i) {
    cout << brr[i] << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  int tp = 1;
  cin >> t;
  while (t--) {
    auto src = high_resolution_clock::now();
    solve(tp);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - src);
    tp++;
  }
  return 0;
}
