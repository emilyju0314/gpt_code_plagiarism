#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int main() {
    int n, q;
    cin >> n >> q;
    n *= 2;
    VL a(n), b(n);
    REP(i,n) scanf("%lld", &a[i]);
    REP(i,n) scanf("%lld", &b[i]);

    ll suma = 0;
    REP(i,n) suma += a[i];

    multiset<ll> st;
    ll pos = 0;
    int c = 0;
    FOR(i,1,n-2){
        st.insert(b[i] - a[i]);
        if (b[i] > a[i]){
            pos += b[i] - a[i];
            c++;
        }
    }

    while (q--){
        int i;
        ll x, y;
        scanf("%d %lld %lld", &i, &x, &y);
        i--;
        if (i == 0 || i == n-1){
            suma += x - a[i];
        }else{
            suma += x - a[i];
            ll od = b[i] - a[i];
            ll nw = y - x;
            st.erase(st.find(od));
            st.insert(nw);
            if (od > 0){
                c--;
                pos -= od;
            }
            if (nw > 0){
                c++;
                pos += nw;
            }
        }
        a[i] = x;
        b[i] = y;

        // cout << "suma " << suma << endl;
        // cout << "c " << c << "  sumpos " << pos << endl;
        // for (ll x : st) cout << x << " ";
        // cout << endl;

        ll ans = suma;
        if (c % 2 == 0){
            ans += pos;
        }else{
            ll p, q;
            auto itr = st.upper_bound(0);
            p = *itr;
            itr--;
            q = *itr;
            ans += max(pos - p, pos + q);
        }
        printf("%lld\n", ans);
    }

    return 0;
}
