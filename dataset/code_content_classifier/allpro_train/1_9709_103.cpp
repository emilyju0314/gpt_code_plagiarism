#include <bits/stdc++.h>
using namespace std;
const long long MAX_N = 1 << 18;
long long sum[2 * MAX_N];
long long minVal[2 * MAX_N];
long long posSum[2 * MAX_N];
long long value[2 * MAX_N];
map<int, int> M;
void update(long long node, long long low, long long high, long long nlow,
            long long nhigh, long long val) {
  if (nhigh < low || nlow > high) return;
  if (low >= nlow && high <= nhigh) {
    value[node] = val;
    sum[node] = (long long)val * (posSum[high + 1] - posSum[low]);
    if (val >= 0) {
      minVal[node] = 0;
    } else {
      minVal[node] = sum[node];
    }
    return;
  }
  long long mid = (low + high) / 2;
  if (value[node] != -1000000001) {
    value[node * 2 + 1] = value[node];
    value[node * 2 + 2] = value[node];
    sum[node * 2 + 1] =
        (long long)value[node] * (posSum[mid + 1] - posSum[low]);
    sum[node * 2 + 2] =
        (long long)value[node] * (posSum[high + 1] - posSum[mid + 1]);
    if (value[node] >= 0) {
      minVal[node * 2 + 1] = 0;
      minVal[node * 2 + 2] = 0;
    } else {
      minVal[node * 2 + 1] = sum[node * 2 + 1];
      minVal[node * 2 + 2] = sum[node * 2 + 2];
    }
    value[node] = -1000000001;
  }
  update(node * 2 + 1, low, mid, nlow, nhigh, val);
  update(node * 2 + 2, mid + 1, high, nlow, nhigh, val);
  minVal[node] =
      min(minVal[node * 2 + 1], sum[node * 2 + 1] + minVal[node * 2 + 2]);
  sum[node] = sum[node * 2 + 1] + sum[node * 2 + 2];
}
double findPos(long long node, long long low, long long high, long long val) {
  if (low == high) {
    if (val == 0) return (double)posSum[low];
    if (value[node] >= 0) return -1.0;
    return posSum[low] + val / (double)(-value[node]);
  }
  long long mid = (low + high) / 2;
  if (value[node] != -1000000001) {
    value[node * 2 + 1] = value[node];
    value[node * 2 + 2] = value[node];
    sum[node * 2 + 1] =
        (long long)value[node] * (posSum[mid + 1] - posSum[low]);
    sum[node * 2 + 2] =
        (long long)value[node] * (posSum[high + 1] - posSum[mid + 1]);
    if (value[node] >= 0) {
      minVal[node * 2 + 1] = 0;
      minVal[node * 2 + 2] = 0;
    } else {
      minVal[node * 2 + 1] = sum[node * 2 + 1];
      minVal[node * 2 + 2] = sum[node * 2 + 2];
    }
    value[node] = -1000000001;
  }
  if (-minVal[node * 2 + 1] >= val)
    return findPos(node * 2 + 1, low, (low + high) / 2, val);
  return findPos(node * 2 + 2, (low + high) / 2 + 1, high,
                 val + sum[node * 2 + 1]);
}
pair<double, long long> get(long long node, long long low, long long high,
                            long long nlow, long long nhigh, long long val) {
  if (nhigh < low || nlow > high) return {-1.0, 0};
  if (low >= nlow && high <= nhigh) {
    if (-minVal[node] >= val) {
      return {findPos(node, low, high, val), 0};
    }
    return {-1.0, sum[node]};
  }
  long long mid = (low + high) / 2;
  if (value[node] != -1000000001) {
    value[node * 2 + 1] = value[node];
    value[node * 2 + 2] = value[node];
    sum[node * 2 + 1] =
        (long long)value[node] * (posSum[mid + 1] - posSum[low]);
    sum[node * 2 + 2] =
        (long long)value[node] * (posSum[high + 1] - posSum[mid + 1]);
    if (value[node] >= 0) {
      minVal[node * 2 + 1] = 0;
      minVal[node * 2 + 2] = 0;
    } else {
      minVal[node * 2 + 1] = sum[node * 2 + 1];
      minVal[node * 2 + 2] = sum[node * 2 + 2];
    }
    value[node] = -1000000001;
  }
  auto res = get(node * 2 + 1, low, mid, nlow, nhigh, val);
  if (res.first > -0.5) return res;
  auto ret = get(node * 2 + 2, mid + 1, high, nlow, nhigh, res.second + val);
  ret.second += res.second;
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  vector<int> type(q);
  vector<int> a(q);
  vector<int> b(q);
  vector<int> c(q);
  vector<int> t;
  t.clear();
  for (long long i = 0; i < q; ++i) {
    cin >> type[i];
    if (type[i] == 1)
      cin >> a[i] >> b[i], t.push_back(a[i]);
    else if (type[i] == 2)
      cin >> a[i];
    else
      cin >> a[i] >> b[i] >> c[i], t.push_back(a[i]), t.push_back(b[i]);
  }
  sort(t.begin(), t.end());
  t.push_back(t.back() + 1);
  vector<int> nt = t;
  t.clear();
  for (long long i = 0; i < nt.size(); ++i)
    if (i == 0 || nt[i] != nt[i - 1]) t.push_back(nt[i]);
  M.clear();
  for (long long i = 0; i < t.size(); ++i) {
    posSum[i] = t[i];
    M[t[i]] = i;
  }
  for (int i = t.size(); i < 2 * MAX_N; ++i) posSum[i] = posSum[i - 1];
  set<pair<int, int>> S;
  S.clear();
  S.insert({t.back(), 1e9});
  for (long long i = 0; i < q; ++i) {
    if (type[i] == 1) {
      auto it = S.lower_bound({a[i], 0});
      update(0, 0, MAX_N - 1, M[a[i]], M[(*it).first] - 1, b[i]);
      S.insert({a[i], b[i]});
    } else if (type[i] == 2) {
      auto it = S.lower_bound({a[i], -1e9 - 1});
      long long val = 0;
      if (it != S.begin()) {
        --it;
        val = (*it).second;
        ++it;
      }
      ++it;
      update(0, 0, MAX_N - 1, M[a[i]], M[(*it).first] - 1, val);
      --it;
      S.erase(it);
    } else {
      auto it = S.lower_bound({a[i], -1e9 - 1});
      if (it == S.end() || (*it).first > b[i] || c[i] == 0) {
        printf("%.7lf\n", c[i] == 0 ? a[i] : -1.0);
      } else {
        auto pos = get(0, 0, MAX_N - 1, M[(*it).first], M[b[i]], c[i]);
        printf("%.7lf\n", (pos.first > b[i] ? -1.0 : pos.first));
      }
    }
  }
  return 0;
}
