#include <bits/stdc++.h>
using namespace std;
template <class T>
void splitstr(const string &s, vector<T> &out) {
  istringstream in(s);
  out.clear();
  copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}
string read_line() {
  string ret_val;
  getline(std::cin, ret_val);
  return ret_val;
}
template <class T>
void init_array(T *arr, int size, T value) {
  for (int i = 0; i < size; i++) arr[i] = value;
}
template <class T>
inline T gcd(T a, T b) {
  return (!a) ? b : gcd(b % a, a);
}
template <class T>
inline T mod(T a, T p) {
  a %= p;
  return (a < 0) ? a + p : a;
}
template <class T>
inline int num_bits(T n) {
  return (!n) ? 0 : 1 + numbits(n & (n - 1));
}
template <class T>
inline T inverse(T a, T m) {
  a = mod<T>(a, m);
  return (a == 1) ? 1 : mod((1 - m * inverse(m % a, a)) / a, m);
}
template <class T>
inline bool is_prime(T a) {
  T lim = (T)sqrt((double)a);
  for (T i = 2; i <= T(lim + 1E-9); i++)
    if (a % i == 0) return false;
  return true;
}
template <class T>
inline T power(T a, T p, T mod) {
  if (!p) return 1;
  T temp = power(a, p >> 1, mod);
  temp = (temp * temp) % mod;
  if (p & 1) temp = (temp * a) % mod;
  return temp;
}
void get_primes(int start, int end, vector<int> &vi) {
  int *p = new int[end + 1];
  init_array<int>(p, end + 1, 0);
  p[1] = 1;
  for (int i = 2; i <= end; i++) {
    if (!p[i]) {
      if (i >= start) vi.push_back(i);
      for (int j = 2 * i; j <= end; j += i) p[j] = 1;
    }
  }
  delete[] p;
}
bool dfs(int current, int final, int total, int *visited, int **edges,
         bool flow) {
  if (current == final) return true;
  if (visited[current]) return false;
  visited[current] = true;
  for (int i = 0; i < total; i++)
    if (edges[current][i] && dfs(i, final, total, visited, edges, flow)) {
      if (flow) {
        edges[current][i]--;
        edges[i][current]++;
      }
      return true;
    }
  return false;
}
int flow(int in, int out, int total, int **edges) {
  int result = 0;
  int *visited = new int[total];
  while (init_array<int>(visited, total, 0),
         dfs(in, out, total, visited, edges, true))
    result++;
  delete[] visited;
  return result;
}
void create_set(int x, int *P, int *rank) {
  P[x] = x;
  rank[x] = 0;
}
int find_set(int x, int *P) {
  if (x != P[x]) P[x] = find_set(P[x], P);
  return P[x];
}
bool merge_sets(int x, int y, int *P, int *rank) {
  int Px = find_set(x, P);
  int Py = find_set(y, P);
  if (Px == Py) return false;
  if (rank[Px] > rank[Py])
    P[Py] = Px;
  else
    P[Px] = Py;
  if (rank[Px] == rank[Py]) rank[Py]++;
  return true;
}
template <typename T>
int read_cum_freq(int index, T *tree) {
  int sum = 0;
  while (index) {
    sum += tree[index];
    index -= (index & -index);
  }
  return sum;
}
template <typename T>
void upd_freq(int index, int mxIndex, int value, T *tree) {
  while (index <= mxIndex) {
    tree[index] += value;
    index += (index & -index);
  }
}
template <typename T>
int read_freq(int index, T *tree) {
  return read_cum_freq(index, tree) - read_cum_freq(index - 1, tree);
}
void build_failure_function(const string &str, int *temp_arr) {
  temp_arr[0] = temp_arr[1] = 0;
  for (int i = 2; i <= ((int)(str).size()); i++) {
    temp_arr[i] = -1;
    for (int ind = temp_arr[i - 1]; temp_arr[i] == -1; ind = temp_arr[ind]) {
      if (str[ind] == str[i - 1]) {
        temp_arr[i] = ind + 1;
      } else if (ind == 0) {
        temp_arr[i] = 0;
      }
    }
  }
}
void KMP(const string &text, const string &pattern, int *res) {
  int *temp_arr = new int[((int)(pattern).size()) + 1];
  build_failure_function(pattern, temp_arr);
  int i = 0;
  int ind = 0;
  while (i < ((int)(text).size())) {
    if (text[i] == pattern[ind]) {
      res[i] = ++ind;
      if (res[i] == ((int)(pattern).size())) {
        ind = temp_arr[ind];
      }
      i++;
    } else if (ind == 0) {
      res[i++] = 0;
    } else {
      ind = temp_arr[ind];
    }
  }
  delete[] temp_arr;
}
void setup(int value, string name) {
  string name_in = name + ".in";
  string name_out = name + ".out";
  freopen(name_in.c_str(), "r", stdin);
  if (value) {
    freopen(name_out.c_str(), "w", stdout);
  }
}
vector<string> table;
map<pair<int, int>, int> dict;
map<char, vector<pair<int, int> > > mp;
vector<int> solution;
bool visited[100];
void init_dict() {
  bool vis[32][32];
  memset(vis, 0, sizeof(vis));
  int cur = 0;
  for (int i = 0; i < table.size(); i++)
    for (int j = 0; j < table[0].size(); j++) {
      if (table[i][j] != '.') {
        mp[table[i][j]].push_back(make_pair(i, j));
      }
      if (!vis[i][j] && table[i][j] != '.') {
        for (int k = 0; k < 2; k++)
          for (int t = 0; t < 2; t++) {
            int x = i + k;
            int y = j + t;
            vis[x][y] = true;
            dict[make_pair(x, y)] = cur;
          }
        cur++;
      }
    }
}
bool check(const vector<int> &vi) {
  memset(visited, 0, sizeof(visited));
  for (map<char, vector<pair<int, int> > >::iterator it = mp.begin();
       it != mp.end(); it++) {
    int col1 = vi[dict[it->second[0]]];
    int col2 = vi[dict[it->second[1]]];
    int koef = min(col1 * 10 + col2, col2 * 10 + col1);
    if (visited[koef]) return false;
    visited[koef] = true;
  }
  return true;
}
int res = 0;
void go(vector<int> &vi, int step) {
  if (step == 7) {
    if (check(vi)) {
      res++;
      solution = vi;
    }
    return;
  }
  int ind = 0;
  while (vi[ind] != -1) ind++;
  vi[ind] = step;
  for (int j = ind + 1; j < vi.size(); j++)
    if (vi[j] == -1) {
      vi[j] = step;
      go(vi, step + 1);
      vi[j] = -1;
    }
  vi[ind] = -1;
}
int main() {
  int n, m;
  std::cin >> n >> m;
  table.resize(n);
  for (int i = 0; i < n; i++) std::cin >> table[i];
  init_dict();
  vector<int> vi(14, -1);
  go(vi, 0);
  std::cout << res * 5040 << std::endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (table[i][j] == '.') {
        std::cout << '.';
      } else {
        std::cout << solution[dict[make_pair(i, j)]];
      }
    }
    std::cout << std::endl;
  }
  return 0;
}
