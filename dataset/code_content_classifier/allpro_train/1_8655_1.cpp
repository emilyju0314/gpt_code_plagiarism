#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}
const int MN = 100100;

int n;
ll c[MN];
bool nim(ll a) {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans ^= (c[i] % (a+1));
    }
    return (ans != 0);
}
bool solve() {
    ll a, b;
    cin >> n >> a >> b;
    ll ma = -1;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        ma = max(ma, c[i]);
    }
    if (a == b) return nim(a);
    if (ma <= min(a, b)) return nim(a);
    if (a > b) return true;
    if (2*a < ma) return false;
    int u = 0;
    for (int i = 0; i < n; i++) {
        if (a < c[i]) u++;
    }
    if (2 <= u) return false;
    //[ma-a ~ a]
    ll nim = 0;
    for (int i = 0; i < n; i++) {
        if (a < c[i]) continue;
        nim ^= c[i];
    }
    if (ma-a <= nim and nim <= a) return true;
    return false;
}
int main() {
    string H = "Hanako";
    string J = "Jiro";
    if (solve()) {
        cout << H << endl;
    } else {
        cout << J << endl;
    }
    return 0;
}