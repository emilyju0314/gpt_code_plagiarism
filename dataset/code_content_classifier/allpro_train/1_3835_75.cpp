#include <bits/stdc++.h>
#define de(x)   cerr << "  debug  " << #x << "  ==  " << x << endl;
using namespace std;
typedef long long  LL;
const LL mod = 1e9 + 7;
int mqpow(int x, int n) {
    int res = 1;
    while(n) {
        if(n & 1) res = 1ll * res * x % mod;
        n >>= 1;
        x = 1ll * x * x % mod;
    }
    return res;
}
const int maxn = 1e5 + 7;
int n;
void solve () {
    cin >> n;
    int l = 1, r = n, res = -1;
    bool  same = false;
    int be;
    cout << '?' << ' ' << 1 << ' ' << r << endl;
    fflush(stdout);
    cin >> be;
    if(n == 2) {
        if(be == 1) res = 2;
        else {
            res = 1;
        }
        cout << '!' << ' ' << res << endl;
        fflush(stdout);
        return ;
    }
    bool left = false;
    if(be != 1) {
        int to;
        cout << '?' << ' ' << 1 << ' ' << be << endl;
        fflush(stdout);
        cin >> to;
        left = (to != be);
    } else left = true;
    if(left) {
        l = be; r = n;
        while(l <= r) {
            if(l == r) {
                res = l;
                break;
            }
            int mid = l + r >> 1;
            int to;
            if(mid == l) {
               cout << '?' << ' ' << l << ' ' << r << endl;
               fflush(stdout); 
               cin >> to;
               if(to == l) {
                   res = r;
                   break;
               } else {
                   res = l;
                   break;
               }
            }
            cout << '?' << ' ' << be << ' ' << mid << endl;
            fflush(stdout);
            cin >> to;
            if(to == be) {
                r = mid;
            } else l = mid + 1;
        }
    } else {
        l = 1; r = be;
        while(l <= r) {
            if(l == r) {
                res = l;
                break;
            }
            int mid = l + r >> 1;
            int to;
            if(mid == l) {
               cout << '?' << ' ' << l << ' ' << r << endl;
               fflush(stdout); 
               cin >> to;
               if(to == l) {
                   res = r;
                   break;
               } else {
                   res = l;
                   break;
               }
            }
            cout << '?' << ' ' << mid << ' ' << be << endl;
            fflush(stdout);
            cin >> to;
            if(to == be) {
                l = mid;
            } else r = mid - 1;
        }
    }
    cout << '!' << ' ' << res << endl;
    fflush(stdout);
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    // scanf("%d", &T);
    while(T --) {
        solve ();
    }
    #ifdef iyua
        system("pause");
    #endif 
    return 0;
}