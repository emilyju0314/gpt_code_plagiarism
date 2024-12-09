#include <bits/stdc++.h>
using namespace std;
namespace mainns {
using std::swap;
using std::vector;
class DisjointSet {
 public:
  DisjointSet(int size) : rank_(size, 0), parent_(size) {
    for (int i = 0; i < size; ++i) parent_[i] = i;
    componentsCount_ = size;
  }
  int rep(int elt) {
    if (parent_[elt] == elt) {
      return elt;
    } else {
      parent_[elt] = rep(parent_[elt]);
      return parent_[elt];
    }
  }
  bool inSameSet(int elt1, int elt2) { return (rep(elt1) == rep(elt2)); }
  void unionSets(int elt1, int elt2) {
    auto rep1 = rep(elt1);
    auto rep2 = rep(elt2);
    if (rep1 != rep2) {
      if (rank_[rep1] < rank_[rep2]) swap(rep1, rep2);
      parent_[rep2] = rep1;
      if (rank_[rep1] == rank_[rep2]) rank_[rep1]++;
      --componentsCount_;
    }
  }
  int getComponentsCount() const { return componentsCount_; }

 private:
  vector<int> rank_;
  vector<int> parent_;
  int componentsCount_;
};
template <class PerEdgeData, class PerVertexData>
class Graph {
 public:
  Graph(int nVertices, vector<PerVertexData> vertexData = {})
      : edges_(nVertices), vertexData_(move(vertexData)) {
    if (vertexData_.empty()) vertexData_.resize(nVertices);
  };
  void addEdge(size_t from, size_t to, PerEdgeData data = {}) {
    edges_[from].push_back({to, data});
    edges_[to].push_back({from, data});
  }
  const vector<pair<size_t, PerEdgeData>>& vertexNeighbors(size_t vInd) const {
    return edges_[vInd];
  }
  const PerVertexData& getVertexData(int vInd) const {
    return vertexData_[vInd];
  }
  void setVertexData(int vInd, const PerVertexData& d) {
    vertexData_[vInd] = d;
  }
  size_t vertexCount() const { return edges_.size(); }

 private:
  vector<vector<pair<size_t, PerEdgeData>>> edges_;
  vector<PerVertexData> vertexData_;
};
struct EmptyStruct {};
using SimpleGraph = Graph<EmptyStruct, EmptyStruct>;
template <typename T>
int64_t sgn(T val) {
  return (T(0) < val) - (val < T(0));
}
namespace {
inline uint64_t gcdInternal(uint64_t a, uint64_t b) {
  if (b == 0) return a;
  return gcdInternal(b, a % b);
}
inline uint64_t gcdDecompositionInternal(uint64_t a, uint64_t b, int64_t& x,
                                         int64_t& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int64_t xx, yy;
  auto gcd = gcdDecompositionInternal(b, a % b, xx, yy);
  x = yy;
  y = xx - (a / b) * yy;
  return gcd;
}
}  // namespace
inline uint64_t greatestCommonDivisor(int64_t a, int64_t b) {
  a *= sgn(a);
  b *= sgn(b);
  if (a < b) std::swap(a, b);
  return gcdInternal(a, b);
}
inline uint64_t greatestCommonDivisor(const std::vector<int64_t>& numbers) {
  uint64_t res = 0;
  for (auto a : numbers) res = greatestCommonDivisor(res, a);
  return res;
}
inline uint64_t gcdDecomposition(int64_t a, int64_t b, int64_t& x, int64_t& y) {
  auto aUnsigned = a * sgn(a);
  auto bUnsigned = b * sgn(b);
  auto gcd = (aUnsigned < bUnsigned)
                 ? gcdDecompositionInternal(aUnsigned, bUnsigned, x, y)
                 : gcdDecompositionInternal(bUnsigned, aUnsigned, y, x);
  x *= sgn(a);
  y *= sgn(b);
  return gcd;
}
template <typename UnderlyingInt, UnderlyingInt MOD>
class Residue {
 public:
  Residue(UnderlyingInt from = 0) {
    UnderlyingInt remainder = from % MOD;
    if (remainder < 0) remainder += MOD;
    rep_ = remainder;
  }
  bool operator==(Residue<UnderlyingInt, MOD> other) const {
    return rep_ == other.rep_;
  }
  Residue<UnderlyingInt, MOD> operator++(int) {
    return *this = Residue(rep_ + 1);
  }
  Residue<UnderlyingInt, MOD> operator++() { return *this = Residue(rep_ + 1); }
  Residue<UnderlyingInt, MOD> operator--(int) {
    return *this = Residue(rep_ - 1);
  }
  Residue<UnderlyingInt, MOD> operator--() { return *this = Residue(rep_ - 1); }
  Residue<UnderlyingInt, MOD> operator+=(Residue<UnderlyingInt, MOD> v) {
    return *this = Residue(rep_ + v.rep());
  }
  Residue<UnderlyingInt, MOD> operator-=(Residue<UnderlyingInt, MOD> v) {
    return *this = Residue(rep_ - v.rep());
  }
  Residue<UnderlyingInt, MOD> operator*=(Residue<UnderlyingInt, MOD> v) {
    return *this = Residue(rep_ * v.rep());
  }
  Residue<UnderlyingInt, MOD> inversed() const {
    int64_t x, y;
    auto gcd = gcdDecomposition(rep_, MOD, x, y);
    assert(gcd == 1);
    return {x};
  }
  UnderlyingInt rep() const { return rep_; }

 private:
  UnderlyingInt rep_;
};
template <typename UnderlyingInt, UnderlyingInt MOD>
Residue<UnderlyingInt, MOD> operator+(Residue<UnderlyingInt, MOD> a,
                                      Residue<UnderlyingInt, MOD> b) {
  return a += b;
}
template <typename UnderlyingInt, UnderlyingInt MOD>
Residue<UnderlyingInt, MOD> operator-(Residue<UnderlyingInt, MOD> a,
                                      Residue<UnderlyingInt, MOD> b) {
  return a -= b;
}
template <typename UnderlyingInt, UnderlyingInt MOD>
Residue<UnderlyingInt, MOD> operator*(Residue<UnderlyingInt, MOD> a,
                                      Residue<UnderlyingInt, MOD> b) {
  return a *= b;
}
template <typename UnderlyingInt, UnderlyingInt MOD>
Residue<UnderlyingInt, MOD> operator+(Residue<UnderlyingInt, MOD> a,
                                      UnderlyingInt b) {
  return a += b;
}
template <typename UnderlyingInt, UnderlyingInt MOD>
Residue<UnderlyingInt, MOD> operator-(Residue<UnderlyingInt, MOD> a,
                                      UnderlyingInt b) {
  return a -= b;
}
template <typename UnderlyingInt, UnderlyingInt MOD>
Residue<UnderlyingInt, MOD> operator*(Residue<UnderlyingInt, MOD> a,
                                      UnderlyingInt b) {
  return a *= b;
}
template <typename UnderlyingInt, UnderlyingInt MOD>
Residue<UnderlyingInt, MOD> operator/(Residue<UnderlyingInt, MOD> a,
                                      Residue<UnderlyingInt, MOD> b) {
  return a *= b.inversed();
}
template <typename UnderlyingInt, UnderlyingInt MOD>
Residue<UnderlyingInt, MOD> operator/(Residue<UnderlyingInt, MOD> a,
                                      UnderlyingInt b) {
  return a *= Residue<UnderlyingInt, MOD>(b).inversed();
}
template <typename UnderlyingInt, UnderlyingInt MOD>
std::ostream& operator<<(std::ostream& outStream,
                         Residue<UnderlyingInt, MOD> a) {
  return outStream << a.rep();
}
const int cCodeforcesModulo = 1000000007;
using CodeforcesResidue = Residue<int, cCodeforcesModulo>;
using CodeforcesResidue64 = Residue<int64_t, cCodeforcesModulo>;
class Solver554E {
 public:
  void run();
  unique_ptr<SimpleGraph> graph;
  bool bipartite() {
    part = vector<int>(graph->vertexCount(), -1);
    bool res = true;
    for (size_t i = 0; i < graph->vertexCount(); ++i) {
      if (part[i] == -1) {
        res = res && dfs(i);
      }
    }
    return res;
  }
  vector<int> part;
  int currentPart = 0;
  bool dfs(size_t vInd) {
    part[vInd] = currentPart;
    currentPart = 1 - currentPart;
    bool res = true;
    for (auto p : graph->vertexNeighbors(vInd)) {
      auto neiInd = p.first;
      if (part[neiInd] == -1)
        res = res && dfs(neiInd);
      else
        res = res && (currentPart == part[neiInd]);
    }
    currentPart = 1 - currentPart;
    return res;
  }
};
void Solver554E::run() {
  int n, m;
  cin >> n >> m;
  unordered_set<int> knownPersons;
  vector<pair<int, int>> love, hate;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    if (c == 1)
      love.emplace_back(a - 1, b - 1);
    else
      hate.emplace_back(a - 1, b - 1);
  }
  DisjointSet ds(n);
  for (auto& p : love) ds.unionSets(p.first, p.second);
  if (!hate.empty()) {
    for (auto& p : hate)
      if (ds.inSameSet(p.first, p.second)) {
        cout << 0;
        return;
      }
    graph.reset(new SimpleGraph(n));
    for (auto& p : hate) graph->addEdge(ds.rep(p.first), ds.rep(p.second));
    if (!bipartite()) {
      cout << 0;
      return;
    }
    for (auto& p : hate) ds.unionSets(p.first, p.second);
  }
  int compsCount = ds.getComponentsCount();
  CodeforcesResidue64 ans = 1;
  for (int i = 1; i < compsCount; ++i) ans *= 2;
  cout << ans;
}
}  // namespace mainns
using CurrentSolver = mainns::Solver554E;
int main() {
  ios::sync_with_stdio(false);
  CurrentSolver().run();
  return 0;
}
