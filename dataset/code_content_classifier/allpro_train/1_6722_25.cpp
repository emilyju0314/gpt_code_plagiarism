#include <bits/stdc++.h>
using namespace std;
template <class T>
void splitstr(const string &s, vector<T> &out) {
  istringstream in(s);
  out.clear();
  copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
static void redirect(int argc, const char **argv) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  if (argc > 1) {
    static filebuf f;
    f.open(argv[1], ios::in);
    cin.rdbuf(&f);
    if (!cin) {
      cerr << "Failed to open '" << argv[1] << "'" << endl;
      exit(1);
    }
  }
  if (argc > 2) {
    static filebuf f;
    f.open(argv[2], ios::out | ios::trunc);
    cout.rdbuf(&f);
    if (!cout) {
      cerr << "Failed to open '" << argv[2] << "'" << endl;
    }
  }
}
static inline long long dot(const std::complex<long long> &a,
                            const std::complex<long long> &b) {
  return real(conj(a) * b);
}
static inline long long cross(const std::complex<long long> &a,
                              const std::complex<long long> &b) {
  return imag(conj(a) * b);
}
static inline long long cross(const std::complex<long long> &a,
                              const std::complex<long long> &b,
                              const std::complex<long long> &c) {
  return cross(b - a, c - a);
}
class CompareAngle {
 private:
  const std::complex<long long> base;

 public:
  explicit CompareAngle(const std::complex<long long> &base) : base(base) {}
  bool operator()(const std::complex<long long> &a,
                  const std::complex<long long> &b) const {
    return cross(base, a, b) > 0;
  }
};
template <typename T, typename Op = std::plus<T>>
class SegTree {
  T identity;
  Op op;
  std::vector<T> nodes;

 public:
  explicit SegTree(std::size_t n = 0, const T &identity = T(),
                   const Op &op = Op())
      : identity(identity), op(op), nodes(2 * n, this->identity) {
    for (int i = n - 1; i > 0; i--)
      nodes[i] = this->op(nodes[2 * i], nodes[2 * i + 1]);
  }
  template <typename Iterator>
  SegTree(Iterator first, Iterator last, const T &identity = T(),
          const Op &op = Op())
      : identity(identity), op(op) {
    std::size_t n = std::distance(first, last);
    nodes.reserve(2 * n);
    nodes.resize(n, this->identity);
    nodes.insert(nodes.end(), first, last);
    for (int i = n - 1; i > 0; i--)
      nodes[i] = this->op(nodes[2 * i], nodes[2 * i + 1]);
  }
  std::size_t size() const { return nodes.size() / 2; }
  void set(std::size_t idx, T value) {
    assert(0 <= idx && idx < size());
    idx += size();
    nodes[idx] = std::move(value);
    while (idx > 0) {
      idx /= 2;
      nodes[idx] = op(nodes[2 * idx], nodes[2 * idx + 1]);
    }
  }
  const T &operator[](std::size_t idx) const {
    assert(0 <= idx && idx < size());
    return nodes[idx + size()];
  }
  T query(std::size_t a, std::size_t b) const {
    assert(0 <= a && a <= size());
    assert(0 <= b && b <= size());
    a += size();
    b += size();
    T left = identity, right = identity;
    while (a < b) {
      if (a & 1) left = op(left, nodes[a++]);
      if (b & 1) right = op(nodes[--b], right);
      a /= 2;
      b /= 2;
    }
    return op(left, right);
  }
};
struct opmin {
  pair<int, int> operator()(const pair<int, int> &a,
                            const pair<int, int> &b) const {
    return min(a, b);
  }
};
struct event {
  int t;
  int x, y;
};
static bool cut_within(const std::complex<long long> &a,
                       const std::complex<long long> &p,
                       const std::complex<long long> &b,
                       const std::complex<long long> &q) {
  std::complex<long long> dp = p - a;
  std::complex<long long> dq = q - b;
  return dot(dp, dq) < 0;
}
int main(int argc, const char **argv) {
  redirect(argc, argv);
  long long R, N;
  cin >> R >> N;
  vector<event> events;
  vector<std::complex<long long>> pnts;
  for (int i = 0; i < N; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      events.push_back(event{1, ((int)(pnts).size()), -1});
      pnts.emplace_back(x, y);
    } else if (t == 2) {
      int idx;
      cin >> idx;
      idx--;
      events.push_back(event{2, idx, -1});
    } else {
      int a, b;
      cin >> a >> b;
      events.push_back(event{3, a - 1, b - 1});
    }
  }
  std::complex<long long> A(-R, 0);
  std::complex<long long> B(R, 0);
  int P = ((int)(pnts).size());
  vector<int> byA(P);
  for (int i = 0; i < P; i++) byA[i] = i;
  auto byB = byA;
  CompareAngle cmpA(A);
  CompareAngle cmpB(B);
  sort(begin(byA), end(byA),
       [&](int a, int b) { return cmpA(pnts[b], pnts[a]); });
  sort(begin(byB), end(byB),
       [&](int a, int b) { return cmpB(pnts[a], pnts[b]); });
  vector<pair<int, int>> rank(P);
  rank[byA[0]].first = 0;
  int nxt = 0;
  for (int i = 1; i < P; i++) {
    if (cmpA(pnts[byA[i]], pnts[byA[i - 1]])) nxt++;
    rank[byA[i]].first = nxt;
  }
  int NA = nxt + 1;
  rank[byB[0]].second = 0;
  nxt = 0;
  for (int i = 1; i < P; i++) {
    if (cmpB(pnts[byB[i - 1]], pnts[byB[i]])) nxt++;
    rank[byB[i]].second = nxt;
  }
  vector<set<pair<int, int>>> line(NA);
  for (int i = 0; i < NA; i++) line[i].emplace(INT_MAX, INT_MAX);
  auto get_sample = [&](int row) { return *line[row].begin(); };
  SegTree<pair<int, int>, opmin> seg(NA, get_sample(0));
  auto add = [&](int idx) {
    auto r = rank[idx];
    line[r.first].emplace(r.second, idx);
    seg.set(r.first, get_sample(r.first));
  };
  auto remove = [&](int idx) {
    auto r = rank[idx];
    line[r.first].erase(line[r.first].find(make_pair(r.second, idx)));
    seg.set(r.first, get_sample(r.first));
  };
  for (const event &ev : events) {
    if (ev.t == 1)
      add(ev.x);
    else if (ev.t == 2)
      remove(ev.x);
    else {
      std::complex<long long> p =
          cross(A, pnts[ev.x], pnts[ev.y]) >= 0 ? pnts[ev.x] : pnts[ev.y];
      std::complex<long long> q =
          cross(B, pnts[ev.x], pnts[ev.y]) >= 0 ? pnts[ev.y] : pnts[ev.x];
      bool good = true;
      if (cut_within(A, p, B, q))
        good = false;
      else {
        int ar = max(rank[ev.x].first, rank[ev.y].first);
        int br = max(rank[ev.x].second, rank[ev.y].second);
        remove(ev.x);
        remove(ev.y);
        pair<int, int> samp = seg.query(0, ar + 1);
        if (samp.first <= br) good = false;
        add(ev.x);
        add(ev.y);
      }
      cout << (good ? "YES\n" : "NO\n");
    }
  }
  return 0;
}
