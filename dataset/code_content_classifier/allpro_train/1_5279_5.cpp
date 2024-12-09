#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

constexpr int N = 10001, MOD = 1e9+7;

int n, r;
char s[N];

struct Vec {
  LL a[4];
  Vec() { memset(a, 0, sizeof(a)); }
  LL& operator [] (const int &i) { return a[i]; }
  const LL& operator [] (const int &i) const { return a[i]; }
  void print() {
    for(int i = 0; i < 4; ++i)
      fprintf(stderr, "%lld%c", a[i], "\t\n"[i==3]);
  }
};
struct Mat {
  Vec a[4];
  Vec& operator [] (const int &i) { return a[i]; }
  const Vec& operator [] (const int &i) const { return a[i]; }
  Mat operator * (const Mat &b) {
    Mat rtn;
    for(int i = 0; i < 4; ++i)
      for(int j = 0; j < 4; ++j)
        for(int k = 0; k < 4; ++k)
          rtn[i][j] = (MOD + rtn[i][j] + a[i][k] * b[k][j]) % MOD;
    return rtn;
  }
  Vec operator * (const Vec &v) {
    Vec rtn;
    for(int i = 0; i < 4; ++i)
      for(int j = 0; j < 4; ++j)
        rtn[i] = (MOD + rtn[i] + a[i][j] * v[j]) % MOD;
    return rtn;
  }
  void print() {
    cerr << string(30, '-') << endl;
    for(int i = 0; i < 4; ++i)
      a[i].print();
  }
};

int main() {
  Mat eye, mul, pos, neg, dig;
  for(int i = 0; i < 4; ++i)
    eye[i][i] = 1;
  mul[0][0] = mul[1][2] = mul[3][3] = 1;
  pos[0][0] = pos[0][2] = pos[1][3] = pos[3][3] = 1;
  neg[0][0] = neg[0][2] = neg[3][3] = 1;
  neg[1][3] = -1;
  dig[0][0] = dig[1][1] = dig[3][3] = 1;
  dig[2][2] = 10;
  Vec v;
  v[1] = v[3] = 1;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d %s", &r, s);
    Mat t = eye;
    for(int j = 0; s[j]; ++j) {
      if(s[j] == '*')
        t = mul * t;
      else if(s[j] == '+')
        t = pos * t;
      else if(s[j] == '-')
        t = neg * t;
      else {
        dig[2][1] = (s[j] - '0');
        t = dig * t;
      }
    }
    Mat cur = eye;
    while(r) {
      if(r & 1)
        cur = t * cur;
      r >>= 1;
      t = t * t;
    }
    v = cur * v;
  }
  printf("%lld\n", (MOD + v[0] + v[2]) % MOD);
}