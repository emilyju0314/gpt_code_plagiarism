#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
namespace FastIO {
struct Reader {
 private:
  FILE* file;
  std::vector<char> buffer;
  int pos;
  bool was;
  void read() {
    if (!buffer.empty()) {
      buffer.resize(fread(&buffer[0], 1, (int)buffer.size(), file));
      pos = 0;
    }
  }

 public:
  Reader(FILE* file_ = stdin, const int size_ = 1 << 16)
      : file(file_), buffer(size_, '\0'), pos(size_), was(true) {}
  operator bool() const { return was; }
  char getChar() {
    if (pos == (int)buffer.size()) {
      read();
    }
    if (pos == (int)buffer.size()) {
      was = false;
      return EOF;
    } else {
      was = true;
      return buffer[pos++];
    }
  }
  std::string getStr() {
    char c = ' ';
    while (std::isspace(c)) {
      c = getChar();
    }
    std::string answ;
    while (c != EOF && !std::isspace(c)) {
      answ.push_back(c);
      c = getChar();
    }
    was = !answ.empty();
    return answ;
  }
  std::string getLine() {
    char c = '\n';
    while (c == '\n') {
      c = getChar();
    }
    std::string answ;
    while (c != '\n' && c != EOF) {
      answ.push_back(c);
      c = getChar();
    }
    was = !answ.empty();
    return answ;
  }
  template <typename T>
  T getInt() {
    char c = '?';
    while (!(c == '-' || ('0' <= c && c <= '9') || c == EOF)) {
      c = getChar();
    }
    bool positive = true;
    if (c == '-') {
      positive = false;
      c = getChar();
    }
    T answ(0);
    bool flag = false;
    while ('0' <= c && c <= '9') {
      flag = true;
      (answ *= 10) += (c - '0');
      c = getChar();
    }
    was = flag;
    return positive ? answ : -answ;
  }
  template <typename T>
  T getReal() {
    bool flag = false;
    char c = '?';
    while (!(c == '-' || ('0' <= c && c <= '9') || c == EOF)) {
      c = getChar();
    }
    bool positive = (c != '-');
    if (c == '-') {
      c = getChar();
    }
    long long first = 0;
    while ('0' <= c && c <= '9') {
      flag = true;
      (first *= 10) += (c - '0');
      c = getChar();
    }
    was = flag;
    if (c != '.') {
      return T(positive ? first : -first);
    }
    c = getChar();
    long long second = 0, pow = 1;
    while ('0' <= c && c <= '9') {
      (second *= 10) += (c - '0');
      c = getChar();
      pow *= 10;
    }
    T answ = first + (T)second / (T)pow;
    return positive ? answ : -answ;
  }
};
Reader& operator>>(Reader& reader, char& c) {
  return c = reader.getChar(), reader;
}
Reader& operator>>(Reader& reader, std::string& s) {
  return s = reader.getStr(), reader;
}
template <class T>
typename std::enable_if<std::is_floating_point<T>::value, Reader&>::type
operator>>(Reader& reader, T& t) {
  return t = reader.getReal<T>(), reader;
}
template <class T>
typename std::enable_if<std::is_integral<T>::value, Reader&>::type operator>>(
    Reader& reader, T& t) {
  return t = reader.getInt<T>(), reader;
}
template <class T>
Reader& operator>>(Reader& reader, std::vector<T>& vec) {
  for (auto& it : vec) {
    reader >> it;
  }
  return reader;
}
struct Writer {
 private:
  FILE* file;
  std::vector<char> buffer;
  int pos;
  int defaultPrecision, defaultWidth;
  char defaultFill;

 public:
  Writer(FILE* file_ = stdout, const int size_ = 1 << 16)
      : file(file_),
        buffer(size_, '\0'),
        pos(0),
        defaultPrecision(6),
        defaultWidth(0),
        defaultFill(' ') {}
  ~Writer() { flush(); }
  void flush() { putChar(EOF); }
  void setprecision(int precision) { defaultPrecision = precision; }
  void setw(int width) { defaultWidth = width; }
  void setfill(char fill) { defaultFill = fill; }
  int getPrecision() const { return defaultPrecision; }
  int getWidth() const { return defaultWidth; }
  char getFill() const { return defaultFill; }
  void putChar(char c) {
    if (pos == (int)buffer.size() || c == EOF) {
      fwrite(&buffer[0], 1, pos, file);
      pos = 0;
    }
    if (c != EOF) {
      buffer[pos++] = c;
    }
  }
  void putStr(const std::string& s) {
    for (auto it : s) putChar(it);
  }
  template <typename T>
  void putInt(T value, int width = 0, char fill = ' ') {
    bool positive = !(value < 0);
    if (value < 0) {
      value = -value;
    }
    char buf[24];
    int p = 0;
    do {
      buf[p++] = char(value % 10 + '0');
      value /= 10;
    } while (value > 0);
    if (!positive) {
      buf[p++] = '-';
    }
    while (p < width) buf[p++] = fill;
    while (p > 0) putChar(buf[--p]);
  }
  template <typename T>
  void putReal(T value, int precision = 6, int width = 0, char fill = ' ') {
    putInt((long long)value, width - precision - 1, fill);
    value = std::abs(value - (long long)value);
    if (precision == 0) {
      return;
    }
    putChar('.');
    while (precision >= 6) {
      value *= 1000000;
      putInt((int)value, 6, '0');
      value -= (int)value;
      precision -= 6;
    }
    while (precision >= 3) {
      value *= 1000;
      putInt((int)value, 3, '0');
      value -= (int)value;
      precision -= 3;
    }
    while (precision >= 1) {
      value *= 10;
      putInt((int)value, 1, '0');
      value -= (int)value;
      precision -= 1;
    }
  }
};
Writer& operator<<(Writer& writer, const char c) {
  return writer.putChar(c), writer;
}
Writer& operator<<(Writer& writer, const std::string& s) {
  return writer.putStr(s), writer;
}
template <class T>
typename std::enable_if<std::is_floating_point<T>::value, Writer&>::type
operator<<(Writer& writer, const T& t) {
  writer.putReal(t, writer.getPrecision(), writer.getWidth(), writer.getFill());
  return writer;
}
template <class T>
typename std::enable_if<std::is_integral<T>::value, Writer&>::type operator<<(
    Writer& writer, const T& t) {
  writer.putInt(t, writer.getWidth(), writer.getFill());
  return writer;
}
}  // namespace FastIO
using std::string;
using std::vector;
using ll = long long;
using real = long double;
using u64t = uint64_t;
using vi = vector<int>;
using vell = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vell>;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vchar = vector<char>;
using vvchar = vector<vchar>;
const ll mod = 1e9 + 7;
template <class A, class B>
void remin(A& a, const B& b) {
  a = (a < b) ? a : b;
}
template <class A, class B>
void remax(A& a, const B& b) {
  a = (a > b) ? a : b;
}
ll gcd(ll a, ll b, ll& x, ll& y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  ll x1, y1;
  ll d = gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
vi par;
vi sz;
int getParent(int x) {
  if (par[x] == x) return x;
  return par[x] = getParent(par[x]);
}
struct decomp {
  bool bridge = false;
  int lessComp;
  int lessCompSize;
};
void unite(int x, int y, decomp& cur, bool fictive = true) {
  int par1 = getParent(x), par2 = getParent(y);
  if (par1 == par2) return;
  if (sz[par1] > sz[par2]) std::swap(x, y), std::swap(par1, par2);
  par[par1] = par2;
  if (!fictive) cur.bridge = true;
  if (!fictive) cur.lessComp = x;
  if (!fictive) cur.lessCompSize = sz[par1];
  sz[par2] += sz[par1];
}
vector<std::list<pii>> st;
vector<std::list<pii>::iterator> listIters;
vector<std::set<int>> adj, adj2;
vi p;
vi belongsTo;
int freeNum = 1;
std::list<pii> ficitveList;
static vi toDelete;
static vpii toNewList;
void divide(int x, int y, decomp& cur) {
  toDelete.clear();
  toNewList.clear();
  int small = cur.lessComp;
  assert(small == x || small == y);
  int smallSize = cur.lessCompSize;
  int largeNum = belongsTo[small];
  std::unordered_map<int, int> used;
  std::queue<int> q;
  q.push(small);
  used[small] = 1;
  while (q.size()) {
    int u = q.front();
    q.pop();
    toDelete.push_back(u);
    for (auto& v : adj2[u]) {
      if (!used[v]) used[v] = 1, q.push(v);
    }
  }
  for (auto& item : toDelete) belongsTo[item] = freeNum;
  for (auto& item : toDelete) {
    auto it = listIters[item];
    if (it == ficitveList.end()) continue;
    toNewList.push_back(*it);
    st[largeNum].erase(it);
  }
  std::sort(begin(toNewList), end(toNewList));
  for (auto& item : toNewList) st[freeNum].push_back(item);
  for (auto it = st[freeNum].begin(); it != st[freeNum].end(); ++it)
    listIters[(*it).second] = it;
  ++freeNum;
}
int main() {
  FastIO::Reader cin;
  FastIO::Writer cout;
  toDelete.reserve(2e5 + 10);
  toNewList.reserve(2e5 + 10);
  int n, m, q;
  cin >> n >> m >> q;
  par.resize(n + 1);
  std::iota(begin(par), end(par), 0);
  belongsTo.resize(n + 1);
  st.resize(n + 2);
  sz.resize(n + 1, 1);
  listIters.resize(n + 2);
  p.resize(n + 1);
  adj.resize(n + 1);
  adj2.resize(n + 1);
  for (int u = 1; u <= n; ++u) cin >> p[u];
  vpii edges(m + 1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
    adj2[u].insert(v);
    adj2[v].insert(u);
    edges[i + 1] = {u, v};
  }
  vpii order(q);
  int deletedEdges = 0;
  for (int i = 0; i < q; ++i) {
    int u, v;
    cin >> u >> v;
    order[i] = {u, v};
    if (u == 2) ++deletedEdges;
  }
  vector<decomp> events(deletedEdges);
  for (auto& req : order) {
    if (req.first == 2) {
      auto it = edges[req.second];
      int u = it.first, v = it.second;
      adj[u].erase(v);
      adj[v].erase(u);
    }
  }
  decomp tmp{};
  for (int u = 1; u <= n; ++u)
    for (auto& v : adj[u]) unite(u, v, tmp);
  int ptr = 0;
  for (int i = order.size() - 1; i >= 0; --i) {
    if (order[i].first == 2) {
      auto it = edges[order[i].second];
      int u = it.first, v = it.second;
      unite(u, v, events[ptr], false);
      ++ptr;
    }
  }
  std::reverse(begin(events), end(events));
  vi used(n + 1, 0);
  vi curComponent;
  std::function<void(int)> dfs = [&](int u) {
    used[u] = 1;
    curComponent.push_back(u);
    for (auto& v : adj2[u])
      if (!used[v]) dfs(v);
  };
  for (int u = 1; u <= n; ++u) {
    if (!used[u]) {
      curComponent.clear();
      dfs(u);
      vpii tmp;
      for (auto& item : curComponent) tmp.push_back({p[item], item});
      std::sort(begin(tmp), end(tmp));
      for (auto& item : tmp) st[freeNum].push_back(item);
      for (auto it = st[freeNum].begin(); it != st[freeNum].end(); ++it)
        listIters[(*it).second] = it;
      for (auto& item : curComponent) belongsTo[item] = freeNum;
      ++freeNum;
    }
  }
  ptr = 0;
  for (int i = 0; i < q; ++i) {
    if (order[i].first == 1) {
      int u = order[i].second;
      auto& curSet = st[belongsTo[u]];
      if (curSet.size()) {
        auto it = --curSet.end();
        cout << it->first << "\n";
        listIters[it->second] = ficitveList.end();
        curSet.erase(it);
      } else
        cout << 0 << "\n";
    } else {
      auto it = edges[order[i].second];
      int u = it.first, v = it.second;
      adj2[u].erase(v);
      adj2[v].erase(u);
      if (events[ptr].bridge) divide(u, v, events[ptr]);
      ++ptr;
    }
  }
  return 0;
}
