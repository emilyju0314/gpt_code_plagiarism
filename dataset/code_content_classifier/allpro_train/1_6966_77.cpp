#include <bits/stdc++.h>
using namespace std;
long long int h;
int q;
vector<pair<long long int, long long int> > v;
long long int L[52];
long long int R[52];
long long int lef(long long int i1, long long int val) {
  while (i1 < h) {
    val *= 2LL;
    i1++;
  }
  return val;
}
long long int rig(long long int i1, long long int val) {
  while (i1 < h) {
    val *= 2LL;
    val++;
    i1++;
  }
  return val;
}
vector<pair<long long int, long long int> > mm;
bool merge_able(pair<long long int, long long int> a,
                pair<long long int, long long int> b) {
  if (a.second + 1LL < b.first) {
    return false;
  } else {
    return true;
  }
}
pair<long long int, long long int> M(pair<long long int, long long int> a,
                                     pair<long long int, long long int> b) {
  a.first = min(a.first, b.first);
  a.second = max(a.second, b.second);
  return a;
}
vector<pair<long long int, long long int> > y;
int main() {
  scanf("%I64d%d", &h, &q);
  L[0] = 1LL;
  R[0] = 1LL;
  for (int i = 1; i < h; i++) {
    L[i] = L[i - 1] * 2LL;
    R[i] = R[i - 1] * 2LL + 1LL;
  }
  h--;
  for (int i = 0; i < q; i++) {
    long long int i1;
    long long int l;
    long long int r;
    long long int ans;
    scanf("%I64d%I64d%I64d%I64d", &i1, &l, &r, &ans);
    i1--;
    if (ans == 0LL) {
      l = lef(i1, l);
      r = rig(i1, r);
      v.push_back(make_pair(l, r));
      continue;
    }
    if (ans == 1LL) {
      y.push_back(make_pair(lef(i1, l), rig(i1, r)));
      long long int RR = lef(i1, l);
      if (RR) {
        v.push_back(make_pair(0, RR - 1LL));
      }
      long long int LL = rig(i1, r);
      RR = R[h];
      LL++;
      if (LL <= RR) {
        v.push_back(make_pair(LL, RR));
      }
    }
  }
  sort(v.begin(), v.end());
  if (v.size()) {
    pair<long long int, long long int> p = v[0];
    for (int i = 1; i < v.size(); i++) {
      if (merge_able(p, v[i])) {
        p = M(p, v[i]);
        continue;
      } else {
        mm.push_back(p);
        p = v[i];
      }
    }
    mm.push_back(p);
  }
  swap(mm, v);
  for (int i = 0; i < y.size(); i++) {
    long long int l = y[i].first;
    long long int r = y[i].second;
    int ind = upper_bound(v.begin(), v.end(), make_pair(l, -1LL)) - v.begin();
    ind--;
    ind = max(ind, 0);
    if (ind == v.size()) {
      continue;
    }
    if (v[ind].first <= y[i].first && y[i].second <= v[ind].second) {
      puts("Game cheated!");
      return 0;
    }
  }
  if (v.size() == 0) {
    if (h == 0) {
      puts("1");
      return 0;
    } else {
      puts("Data not sufficient!");
      return 0;
    }
  }
  bool zero = false;
  bool en = false;
  if (v[0].first == L[h] + 1LL) {
    zero = true;
  }
  if (v[0].first > L[h] + 1LL) {
    puts("Data not sufficient!");
    return 0;
  }
  if (v.back().second == R[h] - 1LL) {
    en = true;
  }
  if (v.back().second < R[h] - 1LL) {
    puts("Data not sufficient!");
    return 0;
  }
  if (v.size() > 2) {
    puts("Data not sufficient!");
    return 0;
  }
  bool chu = false;
  if (v.size() == 2) {
    if (v[0].second + 2LL == v[1].first) {
      chu = true;
    } else {
      puts("Data not sufficient!");
      return 0;
    }
  }
  int countt = 0;
  if (zero) {
    countt++;
  }
  if (chu) {
    countt++;
  }
  if (en) {
    countt++;
  }
  if (countt == 0) {
    puts("Game cheated!");
    return 0;
  }
  if (countt != 1) {
    puts("Data not sufficient!");
    return 0;
  }
  if (zero) {
    printf("%I64d\n", L[h]);
    return 0;
  }
  if (en) {
    printf("%I64d\n", R[h]);
    return 0;
  }
  if (chu) {
    printf("%I64d\n", v[0].second + 1LL);
    return 0;
  }
  return 0;
}
