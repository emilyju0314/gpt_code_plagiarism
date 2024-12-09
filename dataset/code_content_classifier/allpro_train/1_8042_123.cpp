#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>
#include <cstring>
#include <cassert>


using namespace std;
#define SZ(x) (int)(x.size())
#define REP(i, n) for(int i=0;i<n;++i)
#define FOR(i, a, b) for(int i=a;i<b;++i)
#define RREP(i, n) for(int i=n-1;i>=0;--i)
#define RFOR(i, a, b) for(int i=b-1;i>=a;--i)

#define all(x) begin(x),end(x)
#define dump(x) cerr<<#x<<" = "<<(x)<<endl
#define debug(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<< endl;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<int, int>;
const double eps = 1e-8;
const ll MOD = 1000000007;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;

template<class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}


template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> p) {
    os << p.first << ":" << p.second;
    return os;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    REP(i, SZ(v)) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}

template<class T1, class T2>
ostream &operator<<(ostream &os, const map<T1, T2> &mp) {
    os << "[";
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if (it != mp.begin()) {
            os << ", ";
        }
        os << *it;
    }
    return os << "]";
}

// edit

bool solve() {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0) return false;

    string sm = to_string(m);

    if (sm.size() == 1) {
        if (n < m) {
            cout << "error" << endl;
            return true;
        } else {
            cout << m << " " << m << endl;
            return true;
        }
    }

    vector<vector<vector<int>>> vv(n + 1);

    int sz = sm.size();
    for (int mask = 0; mask < 1 << (sz - 1); ++mask) {
        vector<int> vec;
        int buf = 0;
        for (int i = 0; i < sz - 1; ++i) {
            buf *= 10;
            buf += sm[i] - '0';
            if (mask >> i & 1) {
                vec.push_back(buf);
                buf = 0;
            }
        }
        buf *= 10;
        buf += sm[sz - 1] - '0';
        vec.push_back(buf);

        int sum = accumulate(all(vec), 0);
        if (sum <= n) {
            vv[sum].push_back(vec);
        }
    }

//    for (int i = 0; i <= n; ++i) {
    for (int i = n; i >= 0; --i) {
        if (vv[i].size() == 0) continue;
        if (vv[i].size() >= 2) {
            cout << "rejected" << endl;
            return true;
        }
        if (vv[i].size() == 1) {
            cout << i << " ";
            for (int j = 0; j < vv[i][0].size(); ++j) {
                cout << vv[i][0][j];
                if (j + 1 == vv[i][0].size()) {
                    cout << endl;
                } else {
                    cout << ' ';
                }
            }
            return true;
        }
    }

    cout << "error" << endl;
    return true;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
//    std::ifstream in("input.txt");
//    std::cin.rdbuf(in.rdbuf());

    while (solve());


    return 0;
}

