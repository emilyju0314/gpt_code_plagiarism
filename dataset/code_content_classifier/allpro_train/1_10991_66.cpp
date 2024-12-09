#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = uint32_t;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;

int add(vector<int> &v, int x, int y){
    v[x]++;
    return v[x] >= y;
}

int main() {
    int n, a, b, m;
    cin >> n >> a >> b >> m;
    if(n == 1){
        if(a >= 2) a = INF<int>;
        if(b >= 2) b = INF<int>;
    }
    using P = pair<int, int>;
    map<int, P> v, u;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int y;
            cin >> y;
            v[y] = {i, j};
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int y;
            cin >> y;
            u[y] = {i, j};
        }
    }
    vector<int> x(2*n+2), y(2*n+2);
    int X = 0, Y = 0;
    for (int i = 0; i < m; ++i) {
        int z;
        scanf("%d", &z);
        if(v.count(z)){
            auto p = v[z];
            if(add(x, p.first, n)) X++;
            if(add(x, p.second+n, n)) X++;
            if(p.first == p.second) {
                if(add(x, 2*n, n)){
                    X++;
                }
            }
            if(p.first == n-p.second-1) {
                if(add(x, 2*n+1, n)){
                    X++;
                }
            }
        }
        if(u.count(z)){
            auto p = u[z];
            if(add(y, p.first, n)) Y++;
            if(add(y, p.second+n, n)) Y++;
            if(p.first == p.second) {
                if(add(y, 2*n, n)){
                    Y++;
                }
            }
            if(p.first == n-p.second-1) {
                if(add(y, 2*n+1, n)){
                    Y++;
                }
            }
        }
        int f = X >= a, g = Y >= b;
        if(f+g == 1){
            puts(f ? "USAGI" : "NEKO");
            return 0;
        }else if(f+g >= 2){
            puts("DRAW");
            return 0;
        }
    }
    puts("DRAW");
    return 0;
}
