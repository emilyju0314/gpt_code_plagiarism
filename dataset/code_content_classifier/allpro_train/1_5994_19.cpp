#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef string str;
template<typename T> using vec = vector<T>;
template<typename T> using uset = unordered_set<T>;
template<typename T,typename U> using umap = unordered_map<T,U>;
template<typename T> using pq = priority_queue<T, vector<T>, std::greater<T>>;
template<typename T> using mxpq = priority_queue<T>;
template<typename A, typename B>
istream& operator>>(istream& s, pair<A,B>& p) {
    return s>>p.first>>p.second;
}
template<typename T>
istream& operator>>(istream& s, vec<T>& p) {
    for (T& t : p) s >> t;
    return s;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int n; cin >> n;
        map<pair<int,int>, ll> s;
        ll c = 0;
        for (int i = 0; i < n; i++) {
            int x, y, u, v; cin >> x >> y >> u >> v;
            u -= x;
            v -= y;
            int d = gcd(abs(u), abs(v));
            u /= d;
            v /= d;
            if (s.find({-u, -v}) != s.end()) c += s[{-u, -v}];
            s[{u, v}]++;
        }
        cout<<c<<endl;
    }
}
