#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define fo2(i,a,b) for (i = (a); i < (b); i++)
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

ll dx[] = {0,1,0,-1};
ll dy[] = {-1,0,1,0};
int n, ut[4], ov[4], v[4];
ll d, s, t, x, y, o[4][40], cum[4][40];
ll xx[40], yy[40];
int main() {
    scanf("%d %lld %lld %lld", &n, &d, &s, &t);
    fo(i,0,n) {
        scanf("%lld %lld", &x, &y);
        xx[i] = x; yy[i] = y;
        if (x == -d) o[0][ut[0]++] = -y;
        else if (y == -d) o[1][ut[1]++] = x;
        else if (x == d) o[2][ut[2]++] = y;
        else o[3][ut[3]++] = -x;
    }
    fo(i,0,4) {
        sort(o[i], o[i]+ut[i]);
        fo(j,0,ut[i]) {
            cum[i][j] = o[i][j];
            if (j) cum[i][j] += cum[i][j-1];
        }
    }

    ll ans = 1e18;
    fo2(ov[0],0,n+1) fo2(ov[1],0,n+1) fo2(ov[2],0,n+1) fo2(ov[3],0,n+1) {
        fo(i,0,4) v[i] = ov[i];

        int cnt[4];
        fo(i,0,4) cnt[i] = ut[i];
        fo(i,0,8) {
            int ii = i%4;
            int mv = min(v[ii], cnt[ii]);
            v[ii] -= mv;
            cnt[ii] -= mv;
            cnt[(ii+1)%4] += mv;
        }
        int g = 1;
        fo(i,0,4) if (v[i]) g = 0;
        if (!g) continue;

        ll tans = n;
        ll ts = s, tt = t;
        fo(i,0,n) {
            ts -= xx[i];
            tt -= yy[i];
        }

      /*  fo(i,0,8) {
            int ii = i%4;
            while (v[ii] && !ss[ii].empty()) {
                v[ii]--;
                ll num = *ss[ii].rbegin();
                ss[ii].erase(ss[ii].find(num));
                tans += d - num;
                ts -= dx[ii] * (d - num);
                tt -= dy[ii] * (d - num);
                ss[(ii+1)%4].insert(-d);
            }
        }
        int g = 1;
        fo(j,0,4) if (v[j]) g = 0;
        if (!g) continue;
       */
//        printf("%d %d %d %d\n", ov[0], ov[1], ov[2], ov[3]);

        ll sum[4] = {0,0,0,0};
        fo(i,0,4) {
            int ovout = ov[i], ovin = ov[(i+3)%4];
            int bal = ut[i] + ovin - ovout;
            int keep = max(0, ut[i] - ovout);
            if (keep) {
                sum[i] += d*keep - cum[i][keep-1];
            }
            sum[i] += 2*d* min(bal, ovin);

            int origout = min(ovout, ut[i]);
            ll mv = 0;
            if (origout) {
                mv += d*origout - (cum[i][ut[i] - 1] - (origout==ut[i] ? 0 : cum[i][ut[i] - 1 - origout]));
            }
            mv += 2*d * max(0, ovout - ut[i]);
            tans += mv;

            ts -= dx[i] * mv;
            tt -= dy[i] * mv;

            assert(keep + origout == ut[i]);
        }

  //      fo(i,0,4) printf("%lld\n", sum[i]);

        if (tt < 0 && abs(tt) > sum[0]) continue;
        if (tt > 0 && tt > sum[2]) continue;
        if (ts < 0 && abs(ts) > sum[3]) continue;
        if (ts > 0 && ts > sum[1]) continue;

        tans += abs(ts) + abs(tt);

        ans = min(ans, tans);
    }
    printf("%lld\n", ans);

    return 0;
}