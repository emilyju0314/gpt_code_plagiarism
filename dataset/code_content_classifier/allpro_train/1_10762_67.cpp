#include<bits/stdc++.h>
#define     fastasfuckboi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define     test int t;cin>>t;while(t--)
#define     REP(i,n) for(int i=0; i<n;i++)
#define     rep(i,a,b) for(int i=a;i<b;i++)
#define     mod 1000000007
#define     mod2 998244353
#define     ll long long
#define     ld long double
#define     int long long
#define     pb push_back
#define     mp make_pair
#define     ii pair<int,int>
#define     llll pair<ll,ll>
#define     vi vector<int>
#define     vll vector<ll>
#define     vii vector<ii>
#define     vllll vector<llll>
#define     f first
#define     s second
#define     INF 1000000000
#define     HINF 1000000000000000
#define     mem(a,b) memset(a,b,sizeof(a))
#define     arrin(x,n) int x[n]; for(int o=0;o<n;o++) cin>>x[o]
#define     arrout(x,n) for(int o=0;o<n;o++) cout<<x[o]<<" "; cout<<endl
#define     vecin(x,n); vi x; for(int o=0;o<n;o++) {cin>>hool; x.pb(hool);}
#define     vecout(x,n) for(int o=0;o<n;o++) cout<<x[o]<<" "; cout<<endl
#define     all(x) x.begin(),x.end()
#define     endl '\n'
int hool;
using namespace std;

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

namespace number_theory{
   
    int powersimple(int a, int b){//a^b
        int res=1;
        while(b>0){
            if(b&1)
            {res=(res*a);
            b--;}
            a=(a*a);
            b>>=1;
        }
        return res;
    }
   
    int ncr(int n,int k)
    {
        int ans=1;
        if(k>n-k)
        k=n-k;
        for(int i=1;i<=k;i++)
        ans*=(n-i+1),ans/=i;
        return ans;
    }
   
    int power(int x,int y,int p)
    {
        int res = 1;
        x = x % p;
        while (y > 0) {
            if (y & 1)
                res = (res * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }
   
    int modInverse(int n, int p)
    {
        return power(n, p - 2, p);
    }
   
    int ncrModPFermat(int n,int r, int p)
    {
        if (r == 0)
            return 1;
        int fac[n + 1];
        fac[0] = 1;
        for (int i = 1; i <= n; i++)
            fac[i] = (fac[i - 1] * i) % p;
        return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
    }
   
    int gcd(int a, int b){
        return (b==0)?a:gcd(b,a%b);
    }
}
using namespace number_theory;

// https://codeforces.com/blog/entry/62393
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
//use: unordered_map<int,int,custom_hash> mp;

void solve(){
    int a,b;cin>>a>>b;
    set<int>s;
    int c=0;
    while(a){
        int te=a%b;
        s.insert(te);
        a/=b;
        c++;
    }
    cout<<(c==s.size()?"yes":"no");
}

signed main()
{
    fastasfuckboi;
    int t;
    t=1;
    //cin>>t;
    while(t-->0){
        solve();
    }
    return 0;
}