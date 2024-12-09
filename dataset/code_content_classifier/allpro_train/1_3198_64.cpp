#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(int)(a); (i)<(int)(b); ++(i))
#define rFor(i, a, b) for(int (i)=(int)(a)-1; (i)>=(int)(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<int, lint> pil;
typedef pair<lint, lint> pll;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T> bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}
template<class T> T div_floor(const T a, const T b){return a>=0 ? a/b : (a+1)/b-1;}
template<class T> T div_ceil(const T a, const T b){return a>=0 ? (a-1)/b+1 : a/b;}

constexpr lint mod = 1e9+7;
constexpr lint INF = mod*mod;
constexpr int MAX = 100010;

string s[1010];
vector<int> G[1010];

void dfs(int v, int dep){
    if(v != 0){
        rep(i, dep) printf("%c", '.');
        cout << s[v] << "\n";
    }
    for(int nv: G[v]) dfs(nv, dep+1);
}

int main(){
    int n;
    scanf("%d", &n);
    For(i, 1, n+1){
        int K;
        scanf("%d", &K);
        G[K].push_back(i);
        cin >> s[i];
    }
    dfs(0, -1);
}
