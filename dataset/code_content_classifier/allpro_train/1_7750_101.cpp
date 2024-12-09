#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[(1 << 17)], b[(1 << 17)], c[(1 << 17)];
bool del[(1 << 17)];
int nnn;
pair<int, int> Ans[(1 << 17)];
int ttttt;
inline bool Paraaaa(int xid, int yid) {
  if (a[xid] == 0) {
    if (a[yid] == 0) {
      return true;
    } else {
      return false;
    }
  } else {
    double xxx = (double)(b[xid]) / (double)(a[xid]);
    double yyy = (double)(b[yid]) / (double)(a[yid]);
    if (abs(xxx - yyy) < (0.0000001)) {
      return true;
    } else {
      return false;
    }
  }
}
inline int Forward() {
  int xx[20];
  vector<int> redid;
  if (nnn <= k) {
    return 0;
  }
  int cnt = 0;
  for (int i = 0; i < n && cnt < k + 1; i++) {
    if (!del[i]) {
      xx[cnt++] = i;
    }
  }
  for (int i = 0; i < cnt - 1; i++) {
    for (int j = i + 1; j < cnt; j++) {
      if (!Paraaaa(xx[i], xx[j])) {
        double XX, YY;
        if (b[xx[i]] == 0) {
          XX = -(double)(c[xx[i]]) / (double)(a[xx[i]]);
          YY = (((double)(a[xx[j]]) * double(c[xx[i]]) -
                 (double)(c[xx[j]]) * (double)(a[xx[i]]))) /
               ((double)(a[xx[i]]) * (double)(b[xx[j]]));
        } else {
          XX = ((double)(b[xx[j]]) * (double)(c[xx[i]]) -
                (double)(c[xx[j]]) * (double)(b[xx[i]])) /
               ((double)(a[xx[j]]) * (double)(b[xx[i]]) -
                (double(b[xx[j]])) * (double)(a[xx[i]]));
          YY = ((double)(-c[xx[i]]) - (double)(a[xx[i]]) * XX) /
               ((double)(b[xx[i]]));
        }
        Ans[ttttt++] = make_pair(xx[i], xx[j]);
        int recc = 0;
        for (int z = 0; z < n; z++) {
          if (!del[z]) {
            double ttmp =
                ((double)(a[z]) * XX + (double)(b[z]) * YY + (double)(c[z]));
            if (abs(ttmp) < (0.0000001)) {
              del[z] = true;
              recc++;
              redid.push_back(z);
            }
          }
        }
        k--;
        nnn -= recc;
        int TRES = Forward();
        if (TRES == 0) {
          return 0;
        }
        ttttt--;
        k++;
        nnn += recc;
        for (int z = 0; z < redid.size(); z++) {
          del[redid[z]] = false;
        }
      }
    }
  }
  return 2;
}
int main() {
  srand(4841218);
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &a[i], &b[i], &c[i]);
  }
  nnn = n;
  if (k == 5 && n >= (15 * k * k)) {
    for (int kaka = 0; kaka < 100; kaka++) {
      int ti = rand() * rand() % n;
      int tj = rand() * rand() % n;
      double XX, YY;
      if (b[ti] == 0) {
        XX = -(double)(c[ti]) / (double)(a[ti]);
        YY = (((double)(a[tj]) * double(c[ti]) -
               (double)(c[tj]) * (double)(a[ti]))) /
             ((double)(a[ti]) * (double)(b[tj]));
      } else {
        XX = ((double)(b[tj]) * (double)(c[ti]) -
              (double)(c[tj]) * (double)(b[ti])) /
             ((double)(a[tj]) * (double)(b[ti]) -
              (double(b[tj])) * (double)(a[ti]));
        YY = ((double)(-c[ti]) - (double)(a[ti]) * XX) / ((double)(b[ti]));
      }
      int tmpcnt = 0;
      for (int z = 0; z < n; z++) {
        double ttmp =
            ((double)(a[z]) * XX + (double)(b[z]) * YY + (double)(c[z]));
        if (abs(ttmp) < (0.0000001)) {
          tmpcnt++;
        }
      }
      if (tmpcnt >= k + 1) {
        for (int z = 0; z < n; z++) {
          double ttmp =
              ((double)(a[z]) * XX + (double)(b[z]) * YY + (double)(c[z]));
          if (abs(ttmp) < (0.0000001)) {
            del[z] = true;
            nnn--;
          }
        }
        k--;
        Ans[ttttt++] = make_pair(ti, tj);
        break;
      }
    }
  }
  int Res = Forward();
  if (Res == 0) {
    printf("YES\n");
    printf("%d\n", ttttt + nnn);
    for (int i = 0; i < ttttt; i++) {
      printf("%d %d\n", Ans[i].first + 1, Ans[i].second + 1);
    }
    for (int i = 0; i < n; i++) {
      if (!del[i]) {
        printf("%d -1\n", i + 1);
      }
    }
    return 0;
  } else if (Res == 2) {
    printf("NO\n");
    return 0;
  }
  return 0;
}
