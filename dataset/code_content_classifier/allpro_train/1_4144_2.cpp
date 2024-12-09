#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;



struct SegmentTree{
    int sz;
    vector<set<int>> seg;
    explicit SegmentTree(int n) {
        sz = 1;
        while(sz < n) sz <<= 1;
        seg.resize(2*sz);
    }

    void update(int k, int a, int b){
        for(a += sz, b += sz; a < b; a >>=1, b>>=1){
            if(a & 1) seg[a++].emplace(k);
            if(b & 1) seg[--b].emplace(k);
        }
    }

    bool query(int x, int a, int b){
        for (x += sz; x; x >>= 1) {
            if(seg[x].lower_bound(a) != seg[x].lower_bound(b)) return false;
        }
        return true;
    }

};
int main() {
    int n;
    cin >> n;
    vector<int> px(n), py(n), qx(n), qy(n);
    vector<int> zx(2*n), zy(2*n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &px[i], &py[i], &qx[i], &qy[i]);
        zx[i] = px[i]; zx[i+n] = qx[i];
        zy[i] = py[i]; zy[i+n] = qy[i];
    }
    sort(zx.begin(), zx.end());
    zx.erase(unique(zx.begin(), zx.end()), zx.end());
    sort(zy.begin(), zy.end());
    zy.erase(unique(zy.begin(), zy.end()), zy.end());
    auto fx = [&](int x){ return lower_bound(zx.begin(),zx.end(), x) - zx.begin(); };
    auto fy = [&](int y){ return lower_bound(zy.begin(),zy.end(), y) - zy.begin(); };
    SegmentTree segx(zx.size()), segy(zy.size());
    vector<set<int>> sx(zx.size()), sy(zy.size());
    for (int i = 0; i < n; ++i) {
        px[i] = fx(px[i]), py[i] = fy(py[i]);
        qx[i] = fx(qx[i]), qy[i] = fy(qy[i]);
        if(px[i] > qx[i]) swap(px[i], qx[i]);
        if(py[i] > qy[i]) swap(py[i], qy[i]);
        if(px[i] == qx[i]){
            int ok = 1;
            if(!sx[px[i]].empty()){
                auto l = sx[px[i]].lower_bound(py[i]<<1), r = sx[px[i]].lower_bound((qy[i]+1)<<1);
                if(l != r){
                    ok = 0;
                }else if(l != sx[px[i]].end() && (*l&1)){
                    ok = 0;
                }
            }
            if(ok && !segx.query(px[i], py[i], qy[i]+1)){
                ok = 0;
            }
            if(ok){
                sx[px[i]].emplace((py[i]<<1)|0);
                sx[px[i]].emplace((qy[i]<<1)|1);
                segy.update(px[i], py[i], qy[i]+1);
                puts("1");
            }else {
                puts("0");
            }
        }else {
            int ok = 1;
            if(!sy[py[i]].empty()){
                auto l = sy[py[i]].lower_bound(px[i]<<1), r = sy[py[i]].lower_bound((qx[i]+1)<<1);
                if(l != r){
                    ok = 0;
                }else if(l != sy[py[i]].end() && (*l&1)){
                    ok = 0;
                }
            }
            if(ok && !segy.query(py[i], px[i], qx[i]+1)){
                ok = 0;
            }
            if(ok){
                sy[py[i]].emplace((px[i]<<1)|0);
                sy[py[i]].emplace((qx[i]<<1)|1);
                segx.update(py[i], px[i], qx[i]+1);
                puts("1");
            }else puts("0");
        }
    }
    return 0;
}


