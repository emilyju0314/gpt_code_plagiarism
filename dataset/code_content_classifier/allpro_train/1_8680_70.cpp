#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
struct IoSetup {
    IoSetup() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;
template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}
template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
    is >> p.first >> p.second;
    return is;
}
template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
    for(int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i + 1 != (int)v.size() ? " " : "");
    }
    return os;
}
template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
    for(T &in : v) is >> in;
    return is;
}

string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef PLOKI_LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> s(n);
        cin >> s;

        ll ans = 0;
        vector<ll> stock(n, 0);
        for (int i = 0; i < n; ++i) {
            ll sum = max(0ll, stock[i] - (s[i] - 1));
            ll nsi = max(1ll, s[i] - stock[i] - sum);
            ans += nsi - 1;
            if(sum > 0 && i + 1 < n) {
                stock[i+1] += sum;
            }

            for (int j = i+2; j < min(n, i+s[i]+1); ++j) {
                stock[j]++;
            }
            s[i] = 1;
        }
        cout << ans << endl;
    }
}
