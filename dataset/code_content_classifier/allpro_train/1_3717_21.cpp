#include<bits/stdc++.h>
using namespace std;
#define int long long
int H, ha, ma, sa;

int gcd(int a, int b) {
    if(a == 0) return b;
    if(b == 0) return a;
    if(a < b) swap(a, b);
    if(a % b == 0) return b;
    return gcd(b, a % b);
}

struct Clock {
    int h, m, n, d;
    Clock(int _h, int _m, int _n, int _d) {
        h = _h;
        m = _m;
        n = _n;
        d = _d;
        int g = gcd(n, d);
        n /= g;
        d /= g;
    }
};

bool operator <(Clock a, Clock b) {
    if(a.h != b.h) return a.h < b.h;
    if(a.m != b.m) return a.m < b.m;
    return a.n * b.d < b.n * a.d;
}

bool operator <=(Clock a, Clock b) {
    if(a.h != b.h) return a.h < b.h;
    if(a.m != b.m) return a.m < b.m;
    return a.n * b.d <= b.n * a.d;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    while(true) {
        cin >> H >> ha >> ma >> sa;
        if(H == 0 && ha == 0 && ma == 0 && sa == 0) break;
        Clock a(ha, ma, sa, 1);
        Clock ans(-1, -1, 0, 1);
        for(int h = 0; h < H; h++) {
            for(int m = 0; m < 60; m++) {
                for(int delta = -1; delta <= 1; delta++) {
                    int Left = delta * 3600 * H + 60 * 60 * h + 60 * m * (H + 1);
                    if(Left < 0) continue;
                    if(Left >= 60 * (H * 120 - H - 1)) continue;
                    Clock now(h, m, Left, H * 120 - H - 1);
                    if(60 * now.m * now.d == 59 * now.n) continue;
                    if(ans.h == -1) {
                        ans = now;
                    } else if(ans < a && a <= now) {
                        ans = now;
                    } else if(a <= now && now < ans) {
                        ans = now;
                    } else if(now <= ans && ans < a) {
                        ans = now;
                    }
                }
            }
        }
        cout << ans.h << " " << ans.m << " " << ans.n << " " << ans.d << endl;
    }
    return 0;
}
