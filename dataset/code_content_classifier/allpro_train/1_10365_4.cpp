#include <bits/stdc++.h>
using namespace std;
inline void EnableFileIO(const string& fileName, bool local = 0) {
  if (fileName.empty()) return;
  if (local) {
    freopen((fileName + ".in").c_str(), "r", stdin);
    freopen((fileName + ".out").c_str(), "w", stdout);
    return;
  }
  freopen((fileName + ".in").c_str(), "r", stdin);
  freopen((fileName + ".out").c_str(), "w", stdout);
}
const int INF = (1 << 30) - 1;
const long long LINF = (1LL << 61) - 1;
const double EPS = 1e-10, PI = acos(-1);
const int N = 2e6 + 100, P = 1e9 + 7;
int u[N], isp[N], sum[N];
int ans = 0;
vector<int> prime;
int pw[N];
int qpow(long long b, long long k) {
  long long r = 1;
  while (k) {
    if (k & 1) r = r * b % P;
    b = b * b % P;
    k >>= 1;
  }
  return int(r);
}
void preproc() {
  prime.clear();
  memset(isp, 1, sizeof isp);
  u[1] = 1;
  isp[0] = isp[1] = 0;
  for (int i = 2; i < N; i++) {
    if (isp[i]) {
      prime.push_back(i);
      u[i] = -1;
    }
    for (int j = 0; j < prime.size(); j++) {
      if (i * 1LL * prime[j] >= N) break;
      isp[i * prime[j]] = 0;
      if (i % prime[j] == 0) {
        u[i * prime[j]] = 0;
        break;
      } else {
        u[i * prime[j]] = -u[i];
      }
    }
  }
  for (int i = 1; i < N; i++) sum[i] = sum[i - 1] + u[i];
}
int n;
inline int getpw(int k) {
  if (!pw[k]) pw[k] = qpow(k, n);
  return pw[k];
}
inline void add(int& a, int b) {
  a += b;
  if (a >= P) a -= P;
  if (a < 0) a += P;
}
inline void add(long long& a, long long b) {
  a += b;
  if (a >= P) a -= P;
  if (a < 0) a += P;
}
int proc(int k) {
  int last, res = 0;
  for (int i = 1; i <= k; i = last + 1) {
    last = k / (k / i);
    if (i == 100) cerr << i << ' ' << last << ' ' << k / i << endl;
    add(res, (sum[last] - sum[i - 1]) * getpw(k / i) % P);
  }
  return res;
}
long long pre[N];
void addseg(int l, int r, long long k) {
  k %= P;
  add(pre[l], k);
  add(pre[r + 1], -k);
}
void calc(int K) {
  for (int i = 1; i <= K; i++) {
    for (int k = i; k <= K; k += i) {
      int nxt = min(k + i - 1, K);
      addseg(k, nxt, u[i] * getpw(k / i));
    }
  }
}
queue<pair<pair<int, int>, int> > que;
void calc() {}
int k;
int main() {
  preproc();
  cin >> n >> k;
  long long ans = 0;
  calc(k);
  for (int i = 1; i <= k; i++) {
    pre[i] += pre[i - 1];
    pre[i] = (pre[i] % P + P) % P;
    ans += (pre[i] ^ i);
    ans %= P;
  }
  cout << (ans + P) % P << endl;
  return 0;
}
