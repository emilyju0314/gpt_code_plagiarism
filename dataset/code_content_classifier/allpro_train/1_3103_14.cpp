#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<ll, P> P3;
typedef pair<P ,P> PP;
constexpr ll MOD = ll(1e9) + 7;
constexpr int IINF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
constexpr int MAX_N = int(1e5) + 5;
constexpr double EPS = 1e-9;
constexpr int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i > 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define ALL(v) (v).begin(), (v).end()

struct UnionFindTree {
    vector<int> par;
    vector<int> rank;
    vector<int> siz;

    void init(int n) {
        par.resize(n);
        rank.resize(n);
        siz.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
            siz[i] = 1;
        }
    }
    int root(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = root(par[x]);
        }
    }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) rank[x]++;
        par[y] = x;
        siz[x] += siz[y];
    }
    bool is_same(int x, int y) {
        return root(x) == root(y);
    }
    int size(int x) {
        x = root(x);
        return siz[x];
    }
};

bool isPrime[MAX_N];
vector<int> primes;
map<int, int> p2n;

void sieve(int n){
    fill(isPrime, isPrime+n+1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=i*i; j<=n; j+=i){
                isPrime[j] = false;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            primes.push_back(i);
            p2n[i] = int(primes.size())-1;
        }
    }
}

int n, a[MAX_N];

int main() {
    sieve(100001);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    UnionFindTree g;
    g.init(n + int(primes.size()));


    for(int i=0;i<n;i++){
        for(int j=0;j<int(primes.size());j++){
            int p = primes[j];
            if(a[i]%p==0){
                g.unite(i, n+j);
                g.unite(i, n+p2n[a[i]/p]);
            }
            if(a[i] < primes[j]*primes[j])break;
        }
        if(isPrime[a[i]]) g.unite(i, n+p2n[a[i]]);
    }
    map<int, vector<int> > ls;
    for(int i=0;i<n;i++){
        ls[g.root(i)].push_back(a[i]);
    }
    for(auto &l : ls){
        sort(l.second.rbegin(), l.second.rend());
    }
    int pre = 0;
    bool ok = true;
    for(int i=0;i<n;i++){
        int x = ls[g.root(i)].back();
        ls[g.root(i)].pop_back();
        if(x < pre) ok = false;
        pre = x;
        //cout << pre << endl;
    }
    cout << (ok?1:0) << endl;
    return 0;
}


