#include <bits/stdc++.h>

#define INF (2e9)
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)

using namespace std;

template<class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

using ll = long long;
using ld = long double;

#define ALL(x) (x).begin(), (x).end()
template<class T>
using vc = vector<T>;
using vi = vc<ll>;
using vvi = vc<vi>;

template<class T>
using va = valarray<T>;
using vad = va<ld>;
using vai = va<ll>;

vi Read(ll n) {
    auto      v = vi(n);
    for (auto i = std::size_t(0); i < n; ++i) {
        cin >> v[i];
    }
    return v;
}

template<class T>
void DumpRow(const T& A) {
    for (const auto& value : A)
        cout << value << "\n";
}

template<class T>
void DumpColumn(const T& A) {
    auto isFirst = true;
    for (const auto& value : A) {
        if (isFirst) {
            cout << value;
            isFirst = false;
        } else {
            cout << " " << value;
        }

    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    auto v = Read(n);

    ll q;
    cin >> q;

    REP(i, q) {
        ll b, m, e;
        cin >> b >> m >> e;
        swap_ranges(v.begin()+b, v.begin() + m, v.begin()+e);
    }

    DumpColumn(v);
    return 0;
}

