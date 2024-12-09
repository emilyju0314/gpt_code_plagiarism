#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
int parent(int i, vector<long long> &a) {
  if (a[i] == i) return i;
  return parent(a[i], a);
}
void make_par(vector<long long> &a, int x, int y) {
  int para = parent(x, a);
  int parb = parent(y, a);
  a[parb] = para;
}
long long jjjj(long long j) {
  long long c = 0;
  while (j != 0) {
    j /= 2;
    ++c;
  }
  return c;
}
long long maxi(long long a, long long b) { return (a > b) ? a : b; }
int rminutil(vector<long long> &a, int si, int sj, int i, int j, int k) {
  if (si >= i && sj <= j) {
    return a[k];
  }
  if (sj < i || si > j) {
    return INT_MAX;
  }
  int mid = si + (sj - si) / 2;
  return min(rminutil(a, si, mid, i, j, 2 * k),
             rminutil(a, mid + 1, sj, i, j, 2 * k + 1));
}
int rmin(vector<long long> &a, int n, int i, int j) {
  if (i < 0 || j > n - 1 || i > j) {
    cout << "invalid";
    return -1;
  }
  return rminutil(a, 0, n - 1, i, j, 1);
}
void RMQ(vector<long long> &a, int b[], int i, int j, int n, int k) {
  if (i == j) {
    a[k] = b[i];
  }
  int mid = i + (j - i) / 2;
  if (a[k] == -1) {
    if (a[2 * k] == -1) {
      RMQ(a, b, i, mid, n, 2 * k);
    }
    if (a[2 * k + 1] == -1) {
      RMQ(a, b, mid + 1, j, n, 2 * k + 1);
    }
    a[k] = min(a[2 * k], a[2 * k + 1]);
  }
}
void minupdate(vector<long long> &a, int si, int sj, int i, int old, int ne,
               int k) {
  if (i < si || i > sj) {
    return;
  }
  if (si == sj) {
    a[k] = ne;
  }
  if (si != sj) {
    int mid = si + (sj - si) / 2;
    if (i <= mid) {
      minupdate(a, si, mid, i, old, ne, 2 * k);
    } else {
      minupdate(a, mid + 1, sj, i, old, ne, 2 * k + 1);
    }
    a[k] = min(a[2 * k], a[2 * k + 1]);
  }
}
void sumupdate(vector<long long> &a, int si, int sj, int i, int old, int ne,
               int k) {
  if (i < si || i > sj) {
    return;
  }
  a[k] = a[k] + ne - old;
  if (si != sj) {
    int mid = si + (sj - si) / 2;
    sumupdate(a, si, mid, i, old, ne, 2 * k);
    sumupdate(a, mid + 1, sj, i, old, ne, 2 * k + 1);
  }
}
long long rsumutil(vector<long long> &a, int si, int sj, int i, int j, int k) {
  if (si >= i && sj <= j) {
    return a[k];
  }
  if (sj < i || si > j) {
    return 0;
  }
  int mid = si + (sj - si) / 2;
  return rsumutil(a, si, mid, i, min(j, mid), 2 * k) +
         rsumutil(a, mid + 1, sj, max(i, mid + 1), j, 2 * k + 1);
}
long long rsum(vector<long long> &a, int n, int i, int j) {
  if (i < 0 || j >= n || i > j) {
    cout << "invalid";
    return -1;
  }
  return rsumutil(a, 0, n - 1, i, j, 1);
}
void RSQ(vector<long long> &a, int b[], int i, int j, int n, int k) {
  if (i == j) {
    a[k] = b[i];
  }
  int mid = i + (j - i) / 2;
  if (a[k] == -1) {
    if (a[2 * k] == -1) {
      RSQ(a, b, i, mid, n, 2 * k);
    }
    if (a[2 * k + 1] == -1) {
      RSQ(a, b, mid + 1, j, n, 2 * k + 1);
    }
    a[k] = a[2 * k] + a[2 * k + 1];
  }
}
long long binaryexp(long long a, long long b, long long i) {
  if (b == 0) return 1LL;
  if (b == 1) return a;
  long long k = binaryexp(a, b / 2, i);
  if (b & 1) {
    return (((k * k) % i) * a) % i;
  } else
    return (k * k) % i;
}
long long mini(long long a, long long b) { return (a < b) ? a : b; }
void diff(int a[], int h, vector<long long> &v) {
  if (h == 0) {
    v[0] = a[0];
    v[1] += a[0];
  }
  diff(a, h - 1, v);
}
bool prime(long long n) {
  int c = 2;
  long long k = sqrt(n);
  for (long long i = 2; i < sqrt(n); i++) {
    if (n % i == 0) ++c;
  }
  if (k * k == n) {
    ++c;
  }
  return c == 2;
}
void func(vector<long long> &v, int n) {
  bool a[1001];
  memset(a, 0, sizeof a);
  for (long long i = 2; i < n + 1; i++) {
    if (a[i] == 0) {
      for (int j = 2 * i; j <= n; j += i) {
        a[j] = 1;
      }
    }
  }
  for (long long i = 2; i < n + 1; i++) {
    if (a[i] == 0) {
      v.push_back(i);
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, c;
    cin >> a >> c;
    string s;
    cin >> s;
    int n = s.length();
    long long *b = new long long[n];
    memset(b, 0, sizeof b);
    int pre;
    if (s[0] == '0') {
      b[0] = 0;
      pre = -1;
    } else {
      b[0] = a;
      pre = 0;
    }
    for (long long i = 1; i < n; i++) {
      if (s[i] == '0') {
        b[i] = b[i - 1];
      } else {
        if (s[i] == '1') {
          if (i - 1 >= 0) {
            if (pre != -1) {
              int dist = i - pre - 1;
              b[i] = mini(a, dist * c) + b[pre];
              pre = i;
            } else {
              b[i] = a;
              pre = i;
            }
          }
        }
      }
    }
    cout << b[n - 1] << "\n";
    ;
  }
}
