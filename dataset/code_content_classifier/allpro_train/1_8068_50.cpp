#include <bits/stdc++.h>
using namespace std;
template <typename T>
void UpdateMax(T& a, T b) {
  if (a < b) a = b;
}
template <typename T>
void UpdateMin(T& a, T b) {
  if (a > b) a = b;
}
template <typename T>
inline void read(T& x) {
  x = 0;
  char c = getchar();
  int flag = 1;
  while (!isdigit(c)) {
    if (c == '-') flag = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  x *= flag;
}
template <typename T>
void Unique(vector<T>& vec) {
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
}
template <typename T>
void Relabel(vector<T>& vec, T& value) {
  value = lower_bound(vec.begin(), vec.end(), value) - vec.begin() + 1;
}
template <typename T, typename V>
void Print(const pair<T, V>& x) {
  cout << x.first << " @ " << x.second << " | ";
}
template <typename T>
void Print(const T& x) {
  cout << x << " ";
}
template <typename T>
void Pcon(const T& x) {
  cout << "\nsize: " << x.size() << endl;
  for (const auto& item : x) Print(item);
}
std::vector<int> LABS;
template <typename T>
void Print(const T* x, int offset, int loop) {
  for (int i = 0; i <= loop; i++) {
    cout << "[";
    for (int item : LABS) cout << item - offset << ",";
    cout << i - offset << "]:";
    cout << x[i] << " ";
  }
}
template <typename T, typename... Args>
void Print(const T* f, int offset, int loop, Args... args) {
  for (int i = 0; i <= loop; i++) {
    LABS.push_back(i);
    Print(f[i], offset, args...);
    cout << endl;
    LABS.pop_back();
  }
}
const int N = 5e2 + 5;
string c[N];
int f[N][N], mark[N][N], acc[N][N][252];
int n, m, q, r1, r2, c1, c2;
int Get(int x, int y, int a, int b, int cnt) {
  return acc[a + 1][b + 1][cnt + 1] - acc[x - 1 + 1][b + 1][cnt + 1] -
         acc[a + 1][y - 1 + 1][cnt + 1] + acc[x - 1 + 1][y - 1 + 1][cnt + 1];
}
int main() {
  cin.sync_with_stdio(false);
  cin >> n >> m >> q;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) f[i][j] = 1;
  for (int i = 0; i < n; i++) {
    c[i].resize(N);
    cin >> c[i];
  }
  for (int i = n - 1; i >= 0; i--)
    for (int j = m - 1; j >= 0; j--)
      if (c[i + 1][j] == c[i][j + 1] && c[i + 1][j] == c[i][j]) {
        f[i][j] = min(f[i + 1][j], f[i][j + 1]);
        const auto& len = f[i][j];
        if (i + len < n && j + len < m && c[i][j] == c[i + len][j + len])
          f[i][j]++;
      }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (c[i][j] == 'R') {
        const auto& len = f[i][j];
        if (c[i][j + len] == 'G' && f[i][j + len] >= len &&
            c[i + len][j] == 'Y' && f[i + len][j] >= len &&
            c[i + len][j + len] == 'B' && f[i + len][j + len] >= len)
          UpdateMax(mark[i + len - 1][j + len - 1], len);
      }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      for (int cnt = 250; cnt >= 0; cnt--) {
        acc[i + 1][j + 1][cnt + 1] = mark[i][j] == cnt;
        acc[i + 1][j + 1][cnt + 1] += acc[i - 1 + 1][j + 1][cnt + 1] +
                                      acc[i + 1][j - 1 + 1][cnt + 1] -
                                      acc[i - 1 + 1][j - 1 + 1][cnt + 1];
      }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      for (int cnt = 250; cnt >= 0; cnt--)
        acc[i + 1][j + 1][cnt + 1] += acc[i + 1][j + 1][cnt + 1 + 1];
  for (int i = 0; i < q; i++) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    x--, y--, a--, b--;
    int l = 0, r = min(a - x + 1, b - y + 1) / 2;
    while (l != r) {
      int mid = l + (r - l + 1) / 2;
      if (Get(x + mid - 1, y + mid - 1, a - mid, b - mid, mid) > 0)
        l = mid;
      else
        r = mid - 1;
    }
    cout << l * l * 4 << endl;
  }
}
