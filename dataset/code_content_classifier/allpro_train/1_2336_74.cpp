#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
struct SegmentTree {
private:
    int n;
    vector<ll> node;
 
public:
    SegmentTree() {
        int sz = 100050;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = 0;
        for(int i=n-2; i>=0; i--) node[i] = max(node[2*i+1], node[2*i+2]);
    }
 
    void update(int x, ll val) {
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = max(node[2*x+1], node[2*x+2]);
        }
    }
    // hannkaikukann 
    ll getmax(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];
 
        ll vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
};

ll N;
ll x[105000];
ll xsum;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    SegmentTree seg;
    for(int i = 0; i < N; i++) {
        cin >> x[i];
        xsum += x[i];
        ll val = seg.getmax(0, x[i]);
        seg.update(x[i], val + x[i]);
    }
    cout << xsum - seg.getmax(0, N + 1) << endl;
    return 0;
}
