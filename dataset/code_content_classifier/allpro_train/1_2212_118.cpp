#include <bits/stdc++.h>
#pragma comment(linker, "/stack:225450978")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116, EPS = 1e-9,
                  Gold = ((1 + sqrt(5)) / 2);
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
long long keyCount = sizeof(keymod) / sizeof(long long);
template <class T>
int getbit(T s, int i) {
  return (s >> i) & 1;
}
template <class T>
T onbit(T s, int i) {
  return s | (T(1) << i);
}
template <class T>
T offbit(T s, int i) {
  return s & (~(T(1) << i));
}
template <class T>
int cntbit(T s) {
  return __builtin_popcountll(s);
}
auto TimeStart = chrono::steady_clock::now();
auto TimeEnd = chrono::steady_clock::now();
void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();
long long n, m, MSTSize = 0;
vector<pair<long long, long long> > E;
vector<pair<pair<long long, long long>, long long> > A;
vector<long long> DSUsize, DSUpar;
bool edgesort(pair<pair<long long, long long>, long long> x,
              pair<pair<long long, long long>, long long> y) {
  if (x.first.first < y.first.first) return true;
  if (x.first.first > y.first.first) return false;
  if (x.first.first == y.first.first) return (x.first.second > y.first.second);
}
long long DSUfind(long long x) {
  while (DSUpar[x] != -1) x = DSUpar[x];
  return x;
}
void DSUmerge(long long a, long long b) {
  long long u = DSUfind(a), v = DSUfind(b);
  if (u == v) return;
  if (DSUsize[u] < DSUsize[v]) swap(u, v);
  DSUsize[u] += DSUsize[v];
  DSUpar[v] = u;
}
long long TrueMST() {
  long long res = 0;
  DSUsize.resize(n + 1, 1);
  DSUpar.resize(n + 1, -1);
  for (auto z : A) {
    long long id = z.second, d = z.first.first;
    long long u = E[id].first, v = E[id].second;
    if (DSUfind(u) != DSUfind(v)) {
      res += d;
      DSUmerge(u, v);
    }
  }
  return res;
}
void Input() {
  cin >> n >> m;
  A.resize(m);
  E.resize(m);
  for (long long i = 0; i < m; i++) {
    cin >> A[i].first.first >> A[i].first.second;
    A[i].second = i;
    MSTSize += A[i].first.first * A[i].first.second;
  }
}
void Solve() {
  sort(A.begin(), A.end(), edgesort);
  vector<long long> Dist(n + 1, 0LL), Ptr(n + 1);
  set<pair<long long, pair<long long, long long> > > Set;
  long long cnt = 1;
  set<pair<long long, long long> > Missing;
  for (long long i = 2; i <= n; i++) {
    Ptr[i] = i + 1;
    Missing.insert(make_pair(i + 1, i));
  }
  for (auto x : A) {
    long long id = x.second;
    long long a = x.first.first, b = x.first.second;
    if (b == 1) {
      while (!Missing.empty()) {
        pair<long long, long long> Z = *Missing.begin();
        long long z = Z.second;
        if (Z.first > cnt + 1) break;
        Missing.erase(Z);
        Ptr[z] = Z.first;
        Set.insert(make_pair(Dist[z] + a, make_pair(z, Z.first)));
      }
      E[id].first = 1;
      E[id].second = cnt + 1;
      Dist[cnt] = a;
      cnt++;
      continue;
    }
    if (Set.empty()) {
      cout << "-1";
      return;
    }
    pair<long long, pair<long long, long long> > Z = *Set.begin();
    long long L = Z.second.first, R = Z.second.second;
    Set.erase(Z);
    if (R + 1 <= cnt) {
      Set.insert(make_pair(Dist[L] + Dist[R + 1], make_pair(L, R + 1)));
      Ptr[L] = R + 1;
    } else {
      Missing.insert(make_pair(R + 1, L));
      Ptr[L] = R + 1;
    }
    E[id].first = L;
    E[id].second = R;
    R++;
    Ptr[L]++;
  }
  if (TrueMST() < MSTSize) {
    cout << "-1";
    return;
  }
  for (auto x : E) cout << x.first << " " << x.second << '\n';
}
int main(int argc, char* argv[]) {
  ControlIO(argc, argv);
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  Input();
  TimerStart();
  Solve();
  TimerStop();
  return 0;
}
void ControlIO(int argc, char* argv[]) {}
void TimerStart() {}
void TimerStop() {}
void Exit() {
  TimerStop();
  exit(0);
}
