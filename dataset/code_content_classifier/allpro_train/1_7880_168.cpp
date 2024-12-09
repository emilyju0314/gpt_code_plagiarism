#include <bits/stdc++.h>
using namespace std;

#define rep(i,j,n) for(int i=j;i<n;++i)
#define all(i) i.begin(),i.end()
#define rall(i) i.rbegin(), i.rend()
#define INF 1e9
#define LINF 1e18
const int mod = 1e9 + 7;

typedef long long i64;
typedef pair<int, int> pi;

template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;

i64 gcd(i64 n, i64 m) {return (m == 0? n : gcd(m, n % m));}
i64 lcd(i64 n, i64 m) {return (n / gcd(n, m) * m);}
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

template <class Abel> class WeightedUnionFind {
  private:
    std::vector<int> par;
    std::vector<int> rank;
    std::vector<Abel> diff_weight;

  public:
    WeightedUnionFind(int n, Abel SUM_UNITY = 0) : par(n), rank(n, 0), diff_weight(n, SUM_UNITY) {
      for(int i = 0; i < n; ++i) par[i] = i;
    }

    Abel weight(int x) {
      find(x);
      return diff_weight[x];
    }

    int find(int x) {
      if(x == par[x]) return x;

      int r = find(par[x]);
      diff_weight[x] += diff_weight[par[x]];
      return par[x] = r;
    }

    void unite(int x, int y, Abel w) {
      w += weight(x);
      w -= weight(y);
      x = find(x);
      y = find(y);

      if(x == y) return;
      if(rank[x] < rank[y]) {
        std::swap(x, y);
        w = -w;
      }
      par[y] = x;
      diff_weight[y] = w;
      if(rank[x] == rank[y]) rank[x]++;
    }

    bool same(int x, int y) {
      return find(x) == find(y);
    }

    Abel diff(int x, int y) {
      return weight(y) - weight(x);
    }
};


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  WeightedUnionFind<int> uf(n);
  rep(i, 0, q) {
    int c, x, y;
    cin >> c >> x >> y;
    if(c == 0) {
      int z;
      cin >> z;
      uf.unite(x, y, z);
    }
    else {
      if(uf.same(x, y)) cout << uf.diff(x, y) << endl;
      else cout << '?' << endl;
    }
  }
}
