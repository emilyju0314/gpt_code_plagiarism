#include <bits/stdc++.h>
using namespace std;
template <typename T>
T BigMod(T b, T p, T m) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    T s = BigMod(b, p / 2, m);
    return ((s % m) * (s % m)) % m;
  }
  return ((b % m) * (BigMod(b, p - 1, m) % m)) % m;
}
template <typename T>
T ModInv(T b, T m) {
  return BigMod(b, m - 2, m);
}
template <typename T>
T in() {
  char ch;
  T n = 0;
  bool ng = false;
  while (1) {
    ch = getchar();
    if (ch == '-') {
      ng = true;
      ch = getchar();
      break;
    }
    if (ch >= '0' && ch <= '9') break;
  }
  while (1) {
    n = n * 10 + (ch - '0');
    ch = getchar();
    if (ch < '0' || ch > '9') break;
  }
  return (ng ? -n : n);
}
template <typename T>
T POW(T B, T printf) {
  if (printf == 0) return 1;
  if (printf & 1)
    return B * POW(B, printf - 1);
  else
    return (POW(B, printf / 2) * POW(B, printf / 2));
}
template <typename T>
T Bigmod(T b, T p, T m) {
  if (p == 0)
    return 1;
  else if (!(p & 1))
    return (Bigmod(b, p / 2, m) * Bigmod(b, p / 2, m)) % m;
  else
    return ((b % m) * Bigmod(b, p - 1, m)) % m;
}
template <typename T>
T Dis(T x1, T y1, T x2, T y2) {
  return sqrt((x1 - x2 * x1 - x2) + (y1 - y2 * y1 - y2));
}
template <typename T>
T Angle(T x1, T y1, T x2, T y2) {
  return atan(double(y1 - y2) / double(x1 - x2));
}
template <typename T>
T DIFF(T a, T b) {
  T d = a - b;
  if (d < 0)
    return -d;
  else
    return d;
}
template <typename T>
T ABS(T a) {
  if (a < 0)
    return -a;
  else
    return a;
}
template <typename T>
T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <typename T>
T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
}
template <typename T>
T euclide(T a, T b, T &x, T &y) {
  if (a < 0) {
    T d = euclide(-a, b, x, y);
    x = -x;
    return d;
  }
  if (b < 0) {
    T d = euclide(a, -b, x, y);
    y = -y;
    return d;
  }
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    T d = euclide(b, a % b, x, y);
    T t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
  }
}
template <typename T>
void ia(T a[], int n) {
  for (int i = 0; i < n; i++) cin >> a[i];
}
template <typename T>
void pa(T a[], int n) {
  for (int i = 0; i < n - 1; i++) cout << a[i] << " ";
  cout << a[n - 1] << endl;
}
template <typename T>
long long int isLeft(T a, T b, T c) {
  return (a.x - b.x) * (b.y - c.y) - (b.x - c.x) * (a.y - b.y);
}
int Set(int N, int pos) { return N = N | (1 << pos); }
int Reset(int N, int pos) { return N = N & ~(1 << pos); }
bool Check(int N, int pos) { return (bool)(N & (1 << pos)); }
template <class T, class first>
inline T togglebit(T a, first i) {
  T t = 1;
  return (a ^ (t << i));
}
int toInt(string s) {
  int sm;
  stringstream ss(s);
  ss >> sm;
  return sm;
}
int toLlint(string s) {
  long long int sm;
  stringstream ss(s);
  ss >> sm;
  return sm;
}
int cdigittoint(char ch) { return ch - '0'; }
bool isVowel(char ch) {
  ch = toupper(ch);
  if (ch == 'A' || ch == 'U' || ch == 'I' || ch == 'O' || ch == 'E')
    return true;
  return false;
}
bool isConst(char ch) {
  if (isalpha(ch) && !isVowel(ch)) return true;
  return false;
}
double DEG(double x) { return (180.0 * x) / (2.0 * acos(0.0)); }
double RAD(double x) { return (x * (double)2.0 * acos(0.0)) / (180.0); }
char s[100007], str[100007];
int SA[100007], tmpSA[100007], Grp[100007], tmpGrp[100007], GrpSt[100007],
    Counting[100007];
int Rank[100007], LCP[100007];
int DP[19][100007];
int ans[100007];
void ComputeLCP(int L) {
  int k = 0;
  for (int i = 0; i < L; i++) {
    if (k) k--;
    int j = SA[Rank[i] - 1];
    while (i + k < L && j + k < L && s[i + k] == s[j + k]) k++;
    LCP[Rank[i]] = k;
  }
}
int SuffixArray(int mxAlpha) {
  int L = 0;
  for (int i = 0; i < mxAlpha; i++) Counting[i] = 0;
  for (L = 0; s[L]; L++) Counting[s[L]]++;
  for (int i = 1; i < mxAlpha; i++) Counting[i] += Counting[i - 1];
  for (int i = L - 1; i >= 0; i--) SA[Counting[s[i]]--] = i;
  int gNo = 0;
  GrpSt[0] = 1;
  Grp[SA[1]] = 0;
  for (int i = 2; i <= L; i++) {
    if (s[SA[i]] != s[SA[i - 1]]) gNo++, GrpSt[gNo] = i;
    Grp[SA[i]] = gNo;
  }
  for (int d = 1; d < L; d <<= 1) {
    for (int i = L - d; i < L; i++) tmpSA[GrpSt[Grp[i]]++] = i;
    for (int i = 1; i <= L; i++)
      if (SA[i] >= d) tmpSA[GrpSt[Grp[SA[i] - d]]++] = SA[i] - d;
    gNo = 0;
    GrpSt[0] = 1;
    SA[1] = tmpSA[1];
    tmpGrp[SA[1]] = 0;
    Rank[SA[1]] = 1;
    for (int i = 2; i <= L; i++) {
      if (Grp[tmpSA[i]] != Grp[tmpSA[i - 1]])
        gNo++, GrpSt[gNo] = i;
      else if (tmpSA[i] + d >= L)
        gNo++, GrpSt[gNo] = i;
      else if (tmpSA[i - 1] + d >= L)
        gNo++, GrpSt[gNo] = i;
      else if (Grp[tmpSA[i] + d] != Grp[tmpSA[i - 1] + d])
        gNo++, GrpSt[gNo] = i;
      SA[i] = tmpSA[i];
      Rank[SA[i]] = i;
      tmpGrp[SA[i]] = gNo;
    }
    for (int i = 0; i < L; i++) Grp[i] = tmpGrp[i];
  }
  SA[0] = L;
  Rank[L] = 0;
  ComputeLCP(L);
  return L;
}
void Sparse(int n) {
  for (int i = 1; i <= n; i++) DP[0][i] = LCP[i];
  for (int i = 1; (1 << i) <= n; i++)
    for (int j = 1; j + (1 << i) - 1 <= n; j++)
      DP[i][j] = min(DP[i - 1][j], DP[i - 1][j + (1 << (i - 1))]);
}
int Query(int st, int ed) {
  int b = 31 - __builtin_clz(ed - st + 1);
  return min(DP[b][st], DP[b][ed - (1 << b) + 1]);
}
int FindLeft(int x, int n, int y) {
  int l = 0, h = x - 1;
  while (l <= h) {
    int mid = (l + h) >> 1;
    int len = Query(mid + 1, x);
    if (len < y)
      l = mid + 1;
    else
      h = mid - 1;
  }
  return l;
}
int FindRight(int x, int n, int y) {
  int l = x + 1, h = n;
  while (l <= h) {
    int mid = (l + h) >> 1;
    int len = Query(x + 1, mid);
    if (len < y)
      h = mid - 1;
    else
      l = mid + 1;
  }
  return l;
}
void Solve(int L) {
  int x, y, l1, l2;
  for (int i = 0; i < L; i++) {
    x = Rank[i];
    y = Rank[0];
    if (x > y) swap(x, y);
    if (x == y)
      l1 = L - i;
    else
      l1 = Query(x + 1, y);
    x = Rank[i];
    y = Rank[L - l1];
    if (x > y) swap(x, y);
    if (x == y)
      l2 = L - i;
    else
      l2 = Query(x + 1, y);
    if (l1 != l2) continue;
    int lft = FindLeft(Rank[i], L, l1);
    int rgt = FindRight(Rank[i], L, l2);
    ans[l1] = rgt - lft;
  }
}
int main() {
  scanf("%s", s);
  int L = SuffixArray(130), sz = 0;
  Sparse(L);
  Solve(L);
  for (int i = 1; i <= L; i++)
    if (ans[i]) sz++;
  printf("%d\n", sz);
  for (int i = 1; i <= L; i++)
    if (ans[i]) printf("%d %d\n", i, ans[i]);
  return 0;
}
