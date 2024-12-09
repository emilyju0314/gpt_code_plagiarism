#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

bool isnumber(char a) {
    if(a >= '0' && a <= '9') return true;
    return false;
}
vector<string> parse() {
    string tmp;
    cin >> tmp;
    vector<string> ret;
    ret.push_back("");
    int l = 0;
    for(int i = 0; i < tmp.size(); i++) {
        if(isnumber(tmp[l]) ^ isnumber(tmp[i])) {
            ret.push_back("");
            l = i;
        }
        ret.back().push_back(tmp[i]);
    }
    return ret;
}

bool comp(vector<string> &a, vector<string> &b, int index) {
    if(index == a.size()) return true;
    if(index == b.size()) return false;
    if(isnumber(a[index][0]) && !isnumber(b[index][0])) return true;
    if(!isnumber(a[index][0]) && isnumber(b[index][0])) return false;
    if(isnumber(a[index][0])) {
        if(a[index].size() != b[index].size()) {
            return a[index].size() < b[index].size();
        }
        if(a[index] != b[index]) return a[index] < b[index];
    } else {
        if(a[index] != b[index]) return a[index] < b[index];
    }
    return comp(a, b, index + 1);

}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> v0 = parse();
    while(n--) {
        vector<string> now = parse();
        if(now == v0) {
            cout << "+" << endl;
            continue;
        }
        if(comp(v0, now, 0)) cout << "+" << endl;
        else cout << "-" << endl;
    }
    return 0;
}
