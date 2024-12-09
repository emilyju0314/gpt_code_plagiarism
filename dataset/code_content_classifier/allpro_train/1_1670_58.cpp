#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define reverseall(x) reverse(all(x))
#define to_upper(x) transform(x.begin(), x.end(), x.begin(), ::toupper)
#define to_lower(x) transform(x.begin(), x.end(), x.begin(), ::tolower)
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORS(i,s,n) for(int i=s;i<n;i++)
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL); cout.tie(NULL);}
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "= " << x << ", " << #y << "= " << y << endl
#define clr(x) memset(x, 0, sizeof(x))
#define clrv(x, y) memset(x, y, sizeof(x))
#define gcd __gcd
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pll>		vpll;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
typedef priority_queue<int, vi, greater<int>> minpq;
typedef priority_queue<ll, vi, greater<ll>> minpql;

// DEBUG
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}

template <typename T, typename V>
void __print(const pair<T, V> &x);
template <typename T>
void __print(const vector<T> &x);

template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << "}";}
template<typename T>
void __print(const vector<T> &x) {cout << "{";for(int u69=0;u69<x.size();u69++){__print(x[u69]);cout << (u69+1==x.size()?"":",");};cout << "}";}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
//
const int mod = 1000000007;
const double eps = 1e-14;
void YES(bool t = 1) { const string YESNO[2] = {"NO", "YES"};cout << YESNO[t] << endl; }
void Yes(bool t = 1) { const string YesNo[2] = {"No", "Yes"};cout << YesNo[t] << endl; }
void yes(bool t = 1) { const string yesno[2] = {"no", "yes"};cout << yesno[t] << endl; }

struct custom_hash {    //Custom Hash_func for unordered_map
    /*OR DO
        mp.max_load_factor(0.25);
        mp.reserve(1024);
    */
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
ll mpow(int b, int e, int modu=0, int mod=1000000007) {
    ll result = 1,base = b, exp = e;
    if(modu) base %= mod;
    while (exp > 0) {
        if (exp & 1){
            result = ((ll)result * base) ;
            if(modu) result %= mod;
        }
        base = ((ll)base * base);
        if(modu) base %= mod;
        exp >>= 1;
    }
    return result;
}
inline bool isPowerOfTwo(ll x) { return x && (!(x&(x-1))); } 
bool isPerfectSquare(long double x){long double sr = sqrt(x); return ((sr - floor(sr)) == 0);} 
bool isIn(string &s2, string &s1){if (s1.find(s2) != string::npos) return true;return false;}
bool isSorted(vi &arr){for(int i=0;i<(int)arr.size()-1;i++) if(arr[i] > arr[i+1]) return false;return true;}
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

int TEST_CASES = 1;
void submain(){
    int n;
    cin >> n;
    vl mp[n+1];
    vl arr(n), brr(n);
    FOR(i,n){
        cin >> arr[i];
    }
    FOR(i, n){
        cin >> brr[i];
    }
    FOR(i,n){
        mp[arr[i]].pb(brr[i]);   
    }
    
    vl ans(n+1);
    for(int j=1;j<=n;j++){
        sortall(mp[j]);
        reverseall(mp[j]);
        for(int i=1;i<mp[j].size();i++){
            mp[j][i] += mp[j][i-1];
        }
        for(int k=1;k<=mp[j].size();k++){
            ll modd = mp[j].size()%k;
            // debug(mp[j]);
            ans[k] += (ll)mp[j][mp[j].size() - modd - 1];
        }
    }
    
    FORS(i,1,n+1){
        cout << ans[i] << ' ';
    }
    cout << '\n';
    
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    send help
    //// Preprocessing space

    ////
    if(TEST_CASES){
        int t;
        cin >> t;
        while(t--){
            submain();
        }
    }else{
        submain();
    }
    return 0;    
}