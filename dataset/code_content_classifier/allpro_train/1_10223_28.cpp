#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,tree-vectorize")
#pragma GCC target("popcnt,mmx,sse,sse2,sse3,sse4.1,sse4.2,avx,tune=native")
using namespace std;
using namespace rel_ops;
using ll = int64_t;
using Pii = pair<int, int>;
using ull = uint64_t;
using Vi = vector<int>;
void run();
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(10);
  run();
  return 0;
}
constexpr int MOD = 998244353;
struct Zp {
  int first;
  Zp(ll a = 0) {
    first = int(a % MOD);
    if (first < 0) first += MOD;
  }
  Zp operator+(Zp r) const {
    Zp second;
    second.first = first + r.first;
    if (second.first >= MOD) second.first -= MOD;
    return second;
  }
  Zp operator-(Zp r) const {
    Zp second;
    second.first = first - r.first;
    if (second.first < 0) second.first += MOD;
    return second;
  }
  Zp operator*(Zp r) const {
    Zp second;
    second.first = int(ll(first) * r.first % MOD);
    return second;
  }
  Zp operator/(Zp r) const {
    Zp second;
    second.first = int(ll(first) * r.inv().first % MOD);
    return second;
  }
  Zp operator-() const {
    Zp second;
    second.first = MOD - first;
    return second;
  }
  Zp inv() const { return pow(MOD - 2); }
  Zp pow(int e) const {
    Zp t = 1, m = *this;
    while (e) {
      if (e & 1) t *= m;
      e >>= 1;
      m *= m;
    }
    return t;
  }
  Zp& operator+=(Zp r) { return *this = *this + r; }
  Zp& operator-=(Zp r) { return *this = *this - r; }
  Zp& operator*=(Zp r) { return *this = *this * r; }
  Zp& operator/=(Zp r) { return *this = *this / r; }
  void print() { cerr << first; }
};
constexpr int ROOT = 646;
using Vfft = vector<Zp>;
Vfft bases;
void initFFT(int n) {
  bases.resize(n + 1, 1);
  auto b = Zp(ROOT).pow((1 << 20) / n);
  for (int i = (1); i < (n + 1); i++) bases[i] = b * bases[i - 1];
}
template <int dir>
void fft(Vfft& buf) {
  int n = int((buf).size()), bits = 31 - __builtin_clz(n);
  int i = (dir > 0 ? 0 : bits - 1);
  for (; i >= 0 && i < bits; i += dir) {
    int shift = 1 << (bits - i - 1);
    for (int j = (0); j < (1 << i); j++)
      for (int k = (0); k < (shift); k++) {
        int a = (j << (bits - i)) | k;
        int b = a | shift;
        auto v1 = buf[a], v2 = buf[b];
        auto base = bases[(dir * (k << i)) & (n - 1)];
        if (dir > 0) {
          buf[b] = (v1 - v2) * base;
        } else {
          v2 = v2 * base;
          buf[b] = v1 - v2;
        }
        buf[a] = v1 + v2;
      }
  }
  if (dir < 0)
    for (auto& first : (buf)) first = first / n;
}
using Poly = Vfft;
Poly tmp;
struct PolyPair {
  Poly W, Q;
  void merge(PolyPair& r) {
    int s = int((Q).size()) + int((r.Q).size());
    s = max(s, int((Q).size()) + int((r.W).size()));
    s = max(s, int((W).size()));
    int n = 1;
    while (n < s) n *= 2;
    Q.resize(n);
    W.resize(n);
    r.Q.resize(n);
    r.W.resize(n);
    initFFT(n);
    if (n < 100) {
      tmp.assign(n, 0);
      for (int i = (0); i < (n); i++)
        for (int j = (0); j < (n - i); j++) tmp[i + j] += r.W[i] * Q[j];
      r.W.swap(tmp);
      tmp.assign(n, 0);
      for (int i = (0); i < (n); i++)
        for (int j = (0); j < (n - i); j++) tmp[i + j] += Q[i] * r.Q[j];
      Q.swap(tmp);
    } else {
      fft<1>(Q);
      fft<1>(r.Q);
      fft<1>(r.W);
      for (int i = (0); i < (n); i++) r.W[i] *= Q[i];
      for (int i = (0); i < (n); i++) Q[i] *= r.Q[i];
      fft<-1>(Q);
      fft<-1>(r.W);
    }
    for (int i = (0); i < (n); i++) W[i] += r.W[i];
    Poly().swap(r.W);
    Poly().swap(r.Q);
    while (!W.empty() && W.back().first == 0) W.pop_back();
    while (!Q.empty() && Q.back().first == 0) Q.pop_back();
  }
};
struct Vert {
  Vi E;
  int parent, size, depth, chain, chainPos;
};
struct Chain {
  Vi verts;
};
vector<Vert> G;
vector<Chain> chains;
void hld(int i, int parent = -1, int d = 0) {
  int h = -1;
  G[i].parent = parent;
  G[i].depth = d;
  G[i].size = 1;
  for (auto& e : (G[i].E))
    if (e != parent) {
      hld(e, i, d + 1);
      G[i].size += G[e].size;
      if (h < 0 || G[h].size < G[e].size) h = e;
    }
  if (h < 0) {
    h = int((chains).size());
    chains.emplace_back();
  } else {
    h = G[h].chain;
  }
  chains[h].verts.push_back(i);
  G[i].chain = h;
  if (parent < 0) {
    for (auto& p : (chains)) {
      reverse((p.verts).begin(), (p.verts).end());
      for (int j = (0); j < (int((p.verts).size())); j++)
        G[p.verts[j]].chainPos = j;
    }
  }
}
void mergePairs(vector<PolyPair>& polys, int begin, int end) {
  if (begin + 1 >= end) return;
  int mid = (begin + end) / 2;
  mergePairs(polys, begin, mid);
  mergePairs(polys, mid, end);
  polys[begin].merge(polys[mid]);
}
Poly compute(int root) {
  auto& chain = chains[G[root].chain];
  vector<PolyPair> polys(int((chain.verts).size()));
  for (int i = (0); i < (int((chain.verts).size())); i++) {
    int v = chain.verts[i];
    int next = (i + 1 < int((chain.verts).size()) ? chain.verts[i + 1] : -1);
    bool ok = false;
    for (auto& e : (G[v].E))
      if (e != G[v].parent && e != next) {
        polys[i].W.push_back(1);
        polys[i].Q = compute(e);
        polys[i].Q.insert(polys[i].Q.begin(), 0);
        ok = true;
        break;
      }
    if (ok) continue;
    if (next == -1) {
      polys[i].W.push_back(1);
      polys[i].W.push_back(1);
    } else {
      polys[i].W.push_back(1);
      polys[i].Q.push_back(0);
      polys[i].Q.push_back(1);
    }
  }
  mergePairs(polys, 0, int((polys).size()));
  return move(polys[0].W);
}
void run() {
  int n;
  ll first;
  cin >> n >> first;
  G.resize(n);
  for (int i = (1); i < (n); i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].E.push_back(b);
    G[b].E.push_back(a);
  }
  hld(0);
  Poly poly = compute(0);
  Zp ans = 0, mult = 1, up = first;
  for (int i = (1); i < (n + 1); i++) {
    ans += mult * poly[i];
    up += 1;
    mult = mult * up / i;
  }
  cout << ans.first << endl;
}
