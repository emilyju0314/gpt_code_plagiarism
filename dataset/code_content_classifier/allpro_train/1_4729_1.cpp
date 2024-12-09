#include <bits/stdc++.h>
using namespace std;
const int IINF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const long long MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int DY[] = {0, 1, 0, -1, 1, -1, -1, 1};
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long sqr(long long x) { return x * x; }
long long sqr(int x) { return (long long)x * x; }
double sqr(double x) { return x * x; }
long double sqr(long double x) { return x * x; }
const int N = 200500;
class SSet {
  multiset<int> s1, s2;
  long long sum = 0;

 public:
  void insert(int x) {
    if (s2.empty() || (*s2.begin()) > x) {
      s1.insert(x);
      sum += x;
    } else
      s2.insert(x);
  }
  void erase(int x) {
    auto it = s1.find(x);
    if (it != s1.end()) {
      s1.erase(it);
      sum -= x;
    } else
      s2.erase(s2.find(x));
  }
  long long getSum(int m) {
    if (((int)((s1).size())) + ((int)((s2).size())) < m || m < 0) return LINF;
    while (((int)((s1).size())) > m) {
      auto it = s1.end();
      --it;
      s2.insert(*it);
      sum -= *it;
      s1.erase(it);
    }
    while (((int)((s1).size())) < m) {
      auto it = s2.begin();
      s1.insert(*it);
      sum += *it;
      s2.erase(it);
    }
    return sum;
  }
} ss;
int n, m, k;
int costs[N];
bool good1[N], good2[N];
vector<int> c[2][2];
vector<long long> cs[2][2];
int main() {
  ios::sync_with_stdio(false);
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; ++i) scanf("%d", &costs[i]);
  int gc;
  scanf("%d", &gc);
  for (int i = 0; i < gc; ++i) {
    int x;
    scanf("%d", &x);
    --x;
    good1[x] = 1;
  }
  scanf("%d", &gc);
  for (int i = 0; i < gc; ++i) {
    int x;
    scanf("%d", &x);
    --x;
    good2[x] = 1;
  }
  for (int i = 0; i < n; ++i) c[good1[i]][good2[i]].push_back(costs[i]);
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) {
      sort(c[i][j].begin(), c[i][j].end());
      cs[i][j].push_back(0);
      for (int x : c[i][j]) cs[i][j].push_back(cs[i][j].back() + x);
    }
  for (int x : c[0][0]) ss.insert(x);
  for (int i = k; i < ((int)((c[0][1]).size())); ++i) ss.insert(c[0][1][i]);
  for (int i = k; i < ((int)((c[1][0]).size())); ++i) ss.insert(c[1][0][i]);
  long long ans = LINF;
  for (int cnt11 = 0; cnt11 <= ((int)((c[1][1]).size())); ++cnt11) {
    if (cnt11 >= k)
      ans = min(ans, cs[1][1][cnt11] + ss.getSum(m - cnt11));
    else if (k - cnt11 <= ((int)((c[1][0]).size())) &&
             k - cnt11 <= ((int)((c[0][1]).size())))
      ans = min(ans, cs[1][1][cnt11] + cs[0][1][k - cnt11] +
                         cs[1][0][k - cnt11] + ss.getSum(m - 2 * k + cnt11));
    if (cnt11 != ((int)((c[1][1]).size()))) {
      if (k - cnt11 - 1 >= 0 && k - cnt11 - 1 < ((int)((c[0][1]).size())))
        ss.insert(c[0][1][k - cnt11 - 1]);
      if (k - cnt11 - 1 >= 0 && k - cnt11 - 1 < ((int)((c[1][0]).size())))
        ss.insert(c[1][0][k - cnt11 - 1]);
    }
  }
  if (ans >= LINF) ans = -1;
  cout << ans << "\n";
  return 0;
}
