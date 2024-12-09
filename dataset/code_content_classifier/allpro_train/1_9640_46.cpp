#include <bits/stdc++.h>
using namespace std;
//define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#define debug(x) cout << #x << '\t' << x << endl
#else
#define debug(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
#define lowbit(x) ((x) & -(x))
#define mem(a, b) memset(a, b, sizeof(a))
#define PI acos(-1)
#define endl '\n'
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
//#define int long long
//ll gcd(ll a, ll b){a = abs(a);b = abs(b);return a == 0 ? b : gcd(b % a, a);}
//inline ll Pow(ll a, ll n, ll MOD) { ll t = 1; a %= MOD; while (n > 0) { if (n & 1) t = t * a % MOD; a = a * a % MOD, n >>= 1; } return t % MOD; }

const int N = 3e5 + 5;
int lg[N],n;
int a[N];

void init(){
    lg[0] = -1;
    for (int i = 1; i <= 300002; ++i)
        lg[i] = lg[i >> 1] + 1;
}

struct st {
    //预处理lg[N]
    int cmin[N][19], cmax[N][19];
    void pre()
    {
        for (int i = 0; i <= n; ++i) { //从0开始
            cmax[i][0] = a[i]+i;
            cmin[i][0] = a[i]+i;
        }
        for (int i = 1; (1 << i) <= n; ++i)
            for (int j = 0; j + (1 << i) - 1 <= n; ++j) {
                cmax[j][i] = max(cmax[j][i - 1], cmax[j + (1 << i - 1)][i - 1]);
                cmin[j][i] = max(cmin[j][i - 1], cmin[j + (1 << i - 1)][i - 1]);
            }
    }
    int querymax(int l, int r) //区间最大
    {
        if (l > r)
            return 0;
        int t = lg[r - l + 1];
        return max(cmax[l][t], cmax[r - (1 << t) + 1][t]);
    }
    int querymin(int l, int r) //区间最小
    {
        if (l > r)
            return 0;
        int t = lg[r - l + 1];
        return min(cmin[l][t], cmin[r - (1 << t) + 1][t]);
    }
} A;

int dp[N];
int pr[N];
int dir[N],s[N];

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);
#endif
    fast;
    int T;
    cin>>T;
    init();
    while(T--){
        cin>>n;
        for(int i = 1; i <= n; i++){
            cin>>a[i];
        }
        a[++n] = 0;
        for(int i = 0; i <= n; i++){
            dir[i] = 0;
            s[i] = 0;
            pr[i] = 0;
            dp[i] = 0;
        }
        A.pre();
        int mx = -1;
        int las = 0;
        //debug(A.querymax(0,10));
        for(int i = 1; i <= n; i++){
            int l = 0, r = i-1;
            int res = -1;
            debug(i);
            while(l<=r){
                int mid = l+r>>1;
                if(dp[mid]>=i-a[i]-1){
                    res = mid;
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            if(res>=0){
                debug(res);
                debug(A.querymax(res+1,i-1));//res+1~i-1都可以向右
                dp[i] = max(i-1,A.querymax(res+1,i-1));
                pr[i] = res;
            }
            if(dp[i-1]>=i&&dp[i]<i+a[i]){//把本身加进去 看本省可不可以向右
                dp[i] = i+a[i];
                pr[i] = i-1;
                s[i] = 1;
            }
            if(mx > dp[i]){//每次维护一个最大值
                dp[i] = mx;
                pr[i] = las;
            }
            else{
                mx = dp[i];
                las = i;
            }
            
            debug(dp[i]);
        }
        if(dp[n]>=n-1){
            cout<<"YES"<<endl;
            for(int i = n; i >= 1; i = pr[i]){
                for(int j = pr[i]+1; j < i; j++){
                    dir[j] = 1;
                }
                dir[i] = s[i];
            }
            for(int i = 1; i < n; i++){
                cout<<(dir[i]?'R':'L');
            }
            cout<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}