#include <bits/stdc++.h>
using namespace std;
const double pi = acos(0.0) * 2.0;
const long double eps = 1e-10;
const int step[8][2] = {{-1, 0}, {0, 1}, {1, 0},  {0, -1},
                        {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
template <class T>
inline T abs1(T a) {
  return a < 0 ? -a : a;
}
template <typename t, typename t1>
t min1(t a, t1 b) {
  return a < b ? a : b;
}
template <typename t, typename... arg>
t min1(t a, arg... arr) {
  return min1(a, min1(arr...));
}
template <typename t, typename t1>
t max1(t a, t1 b) {
  return a > b ? a : b;
}
template <typename t, typename... arg>
t max1(t a, arg... arr) {
  return max1(a, max1(arr...));
}
inline int jud(double a, double b) {
  if (abs(a) < eps && abs(b) < eps)
    return 0;
  else if (abs1(a - b) / max(abs1(a), abs1(b)) < eps)
    return 0;
  if (a < b) return -1;
  return 1;
}
template <typename t>
inline int jud(t a, t b) {
  if (a < b) return -1;
  if (a == b) return 0;
  return 1;
}
template <typename it, typename t1>
inline int find(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1) {
  if (na == 0) return 0;
  int be = 0, en = na - 1;
  if (*a <= *(a + na - 1)) {
    if (f_lb == 0)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != 1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != -1)
          en = mid;
        else
          be = mid + 1;
      }
    if (f_small && jud(*(a + be), val) == 1) be--;
    if (!f_small && jud(*(a + be), val) == -1) be++;
  } else {
    if (f_lb)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != -1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != 1)
          en = mid;
        else
          be = mid + 1;
      }
    if (!f_small && jud(*(a + be), val) == -1) be--;
    if (f_small && jud(*(a + be), val) == 1) be++;
  }
  return be;
}
template <class T>
inline T lowb(T num) {
  return num & (-num);
}
inline int bitnum(unsigned int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(unsigned long long nValue) {
  return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32);
}
inline int bitnum(long long nValue) {
  return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32);
}
inline int bitmaxl(unsigned int a) {
  if (a == 0) return 0;
  return 32 - __builtin_clz(a);
}
inline int bitmaxl(int a) {
  if (a == 0) return 0;
  return 32 - __builtin_clz(a);
}
inline int bitmaxl(unsigned long long a) {
  int temp = a >> 32;
  if (temp) return 32 - __builtin_clz(temp) + 32;
  return bitmaxl(int(a));
}
inline int bitmaxl(long long a) {
  int temp = a >> 32;
  if (temp) return 32 - __builtin_clz(temp) + 32;
  return bitmaxl(int(a));
}
long long pow(long long n, long long m, long long mod = 0) {
  if (m < 0) return 0;
  long long ans = 1;
  long long k = n;
  while (m) {
    if (m & 1) {
      ans *= k;
      if (mod) ans %= mod;
    }
    k *= k;
    if (mod) k %= mod;
    m >>= 1;
  }
  return ans;
}
template <class t1, class t2>
inline void add(t1 &a, t2 b, int mod = -1) {
  if (mod == -1) mod = 1000000007;
  a += b;
  while (a >= mod) a -= mod;
  while (a < 0) a += mod;
}
template <class t>
void output1(t arr) {
  for (int i = 0; i < (int)arr.size(); i++) cerr << arr[i] << ' ';
  cerr << endl;
}
template <class t>
void output2(t arr) {
  for (int i = 0; i < (int)arr.size(); i++) output1(arr[i]);
}
const int maxn = 300100;
const int fen = 300;
int to[maxn], lto;
int arr[maxn];
int n, nq;
pair<int, int> q[maxn];
int ans[maxn];
vector<pair<int, int> > sq[maxn];
vector<int> rq[maxn];
int nxt[maxn], pre[maxn];
vector<int> stat[maxn];
int mem[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
    to[i] = arr[i];
  }
  sort(to, to + n);
  lto = unique(to, to + n) - to;
  for (int i = 0; i < n; i++) arr[i] = find(arr[i], to, lto);
  scanf("%d", &nq);
  for (int i = 0; i < nq; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    q[i] = make_pair(a, b);
    rq[a / fen].push_back(i);
  }
  memset(nxt, -1, sizeof(nxt));
  memset(pre, -1, sizeof(pre));
  for (int i = 0; i * fen < n; i++) {
    for (auto no : rq[i])
      sq[q[no].second].push_back(make_pair(q[no].first, no));
    int head = -1;
    int small = 1000000007 * 2;
    if ((i + 1) * fen < n) {
      for (int j = (i + 1) * fen; j < n; j++) stat[arr[j]].push_back(j);
      head = -1;
      for (int j = lto - 1; j >= 0; j--) {
        for (auto it : stat[j]) {
          if (head != -1) pre[head] = it;
          nxt[it] = head;
          head = it;
        }
      }
      pre[head] = -1;
      for (int j = n - 1; j >= (i + 1) * fen; j--) {
        if (nxt[j] != -1) pre[nxt[j]] = pre[j];
        if (pre[j] != -1) nxt[pre[j]] = nxt[j];
      }
      small = 1000000007 * 2;
      for (int j = (i + 1) * fen; j < n; j++) {
        if (nxt[j] != -1) small = min(small, abs(to[arr[nxt[j]]] - to[arr[j]]));
        if (pre[j] != -1) small = min(small, abs(to[arr[pre[j]]] - to[arr[j]]));
        mem[j] = small;
      }
    }
    for (int j = i * fen; j < min(n, (i + 1) * fen); j++)
      stat[arr[j]].push_back(j);
    head = -1;
    for (int j = lto - 1; j >= 0; j--) {
      for (auto it : stat[j]) {
        if (head != -1) pre[head] = it;
        nxt[it] = head;
        head = it;
      }
    }
    pre[head] = -1;
    for (int j = n - 1; j >= i * fen; j--) {
      if (nxt[j] != -1) pre[nxt[j]] = pre[j];
      if (pre[j] != -1) nxt[pre[j]] = nxt[j];
    }
    for (int j = i * fen; j < n; j++) {
      if (nxt[j] != -1) pre[nxt[j]] = j;
      if (pre[j] != -1) nxt[pre[j]] = j;
      if (sq[j].size()) {
        int rend = min(j, (i + 1) * fen);
        for (int k = i * fen; k < rend; k++) {
          if (nxt[k] != -1) pre[nxt[k]] = pre[k];
          if (pre[k] != -1) nxt[pre[k]] = nxt[k];
        }
        small = 1000000007 * 2;
        for (int k = rend - 1; k >= i * fen; k--) {
          if (nxt[k] != -1)
            small = min(small, abs(to[arr[nxt[k]]] - to[arr[k]]));
          if (pre[k] != -1)
            small = min(small, abs(to[arr[pre[k]]] - to[arr[k]]));
          mem[k] = small;
          if (nxt[k] != -1) pre[nxt[k]] = k;
          if (pre[k] != -1) nxt[pre[k]] = k;
        }
        for (auto it : sq[j]) {
          ans[it.second] =
              min(mem[it.first], j < (i + 1) * fen ? 1000000007 * 2 : mem[j]);
        }
      }
    }
    for (auto no : rq[i]) sq[q[no].second].clear();
    for (int j = i * fen; j < n; j++) stat[arr[j]].clear();
  }
  for (int i = 0; i < nq; i++) cout << ans[i] << endl;
  return 0;
}
