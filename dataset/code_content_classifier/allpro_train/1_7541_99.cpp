#include <bits/stdc++.h>
using namespace std;
inline void smin(double &a, const double &b) {
  if (b < a) a = b;
}
const double eps = 1e-7, pi2 = 2 * acos(-1);
inline double nor(int x, int y) { return sqrt((double)x * x + (double)y * y); }
int num[101010][17], K;
int first[101010], second[101010], n, m, N;
double dst[101010], al[101010], vec[202020];
pair<double, double> pd[101010];
pair<int, int> p[202020];
inline pair<double, double> range(int id, double R) {
  double d = acos(R / dst[id]);
  double st = fmod(al[id] - d + pi2, pi2);
  double ed = fmod(al[id] + d, pi2);
  return {vec[N++] = st, vec[N++] = ed};
}
inline bool is_in(pair<int, int> a, pair<int, int> b) {
  while (a.first < b.first) a.first += N, a.second += N;
  return a.second <= b.second;
}
inline bool can(double R) {
  if (R < eps) return true;
  N = 0;
  for (int i = 1; i <= n; i++) pd[i] = range(i, R);
  sort(vec, vec + N), N = unique(vec, vec + N) - vec;
  for (int i = 1; i <= n; i++) {
    p[i].first = lower_bound(vec, vec + N, pd[i].first) - vec;
    p[i].second = lower_bound(vec, vec + N, pd[i].second) - vec;
  }
  sort(p + 1, p + n + 1);
  for (int i = 1; i <= n; i++)
    if (p[i].first > p[i].second) p[i].second += N;
  int st = 1, ed = 1;
  for (int i = 2; i <= n; i++) {
    if (is_in(p[st], p[i]) || is_in(p[ed], p[i])) continue;
    while (st <= ed && is_in(p[i], p[st])) st++;
    while (st <= ed && is_in(p[i], p[ed])) ed--;
    p[++ed] = p[i];
  }
  int nn = 0;
  for (int i = st; i <= ed; i++) p[nn++] = p[i];
  if (nn <= m) return true;
  for (int i = 0; i < nn; i++) p[nn + i] = {p[i].first + N, p[i].second + N};
  for (int i = 0, ed = 0; i < nn; i++) {
    if (ed < i) ed = i;
    for (; ed < nn + i && p[ed].first <= p[i].second; ed++)
      ;
    if (ed == nn + i) return true;
    num[i][0] = ed - i;
  }
  for (int j = 1; j <= K; j++) {
    for (int i = 0; i < nn; i++) {
      num[i][j] = min(nn, num[i][j - 1] + num[(i + num[i][j - 1]) % nn][j - 1]);
    }
  }
  for (int i = 0; i < nn; i++) {
    int id = i, j, sum = 0;
    for (int u = m; u; u ^= u & -u) {
      j = __builtin_ctz(u);
      sum += num[id][j];
      if (sum >= nn) return true;
      id = (id + num[id][j]) % nn;
    }
  }
  return false;
}
int main() {
  scanf("%d %d", &n, &m), K = 31 - __builtin_clz(m);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", first + i, second + i);
    dst[i] = nor(first[i], second[i]);
    al[i] = atan2(second[i], first[i]);
    if (al[i] < -eps) al[i] += pi2;
  }
  double st = 0, ed = dst[n];
  for (int i = 1; i < n; i++) smin(ed, dst[i]);
  while ((ed - st) / max(1., ed) > 1e-6) {
    double md = (st + ed) / 2;
    if (can(md))
      st = md;
    else
      ed = md;
  }
  printf("%.8lf\n", st);
}
