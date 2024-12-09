#include "bits/stdc++.h"
using namespace std;
//#include "testlib.h"
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define int long long
#define ll long long
#define M 1000000007
#define MM 998244353
#define inputarr(a,n) for(int i=0;i<n;++i) cin>>a[i]
#define GCD(m,n) __gcd(m,n)
#define LCM(m,n) m*(n/GCD(m,n))
#define mii  map<ll ,ll >
#define msi  map<string,ll >
#define rep(a,b)    for(ll i=a;i<b;i++)
#define rep0(n)    for(ll i=0;i<n;i++)
#define repi(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define vi vector<ll>
#define vs vector<string>
#define ppb pop_back
#define endl '\n'
#define asdf ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define r0 return 0;
#define FORD(i, a, b) for (int i = (int) (a); i >= (int) (b); --i)
#define inputoutput freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define Set(a, s) (a, s, sizeof (a))
#define FOR repi
#define vii vector<pii>
#define pii pair<int,int>
#define REVERSE(v) reverse(all(v))
#define trav(a, x) for(auto& a : x)
#define display(x) trav(a,x) cout<<a<<" ";cout<<endl
#define debug cerr<<"bhau"<<endl
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
template<typename T, typename U> static inline void amin(T &x, U y) 
{ 
    if (y < x) 
        x = y; 
}
template<typename T, typename U> static inline void amax(T &x, U y) 
{ 
    if (x < y) 
        x = y; 
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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



ll max(ll a, ll b) { return (a > b)? a : b;}
int min(int a, int b) { return (a < b)? a : b;} 

int n,m;
mii hola;
vi ind2;
void randomizeMyArray(vector<vi> &v){
    vi ind1;
    for(int i=0;i<n;i++){
        ind1.pb(i);
    }
    for(int i=0;i<m;i++){
        ind2.pb(i);
    }
    shuffle(all(ind1),rng);
    shuffle(all(ind2),rng);
    // shuffle(all(v),rng);
    auto t = v;
    for(int i=0;i<m;i++){
        hola[ind2[i]] = i;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            v[i][j] = t[ind1[i]][ind2[j]];
        }
    }


}

bool check(const vector<vi> v,vi z){
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<m;j++){
            if(v[i][j]!=z[j]){
                cnt++;
            }
            if(cnt==3)
                return false;
        }
    }
    return true;
}
void printCur(vi v){
    vi res(m);
    for(int i=0;i<m;i++){
        // trace(ind2[i]);
        res[ind2[i]] = v[i];
    }
    for(auto i:res)
        cout<<i<<" ";
}
int solve(){


    cin>>n>>m;
    vector<vi> v(n,vi(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }

    randomizeMyArray(v);

    mii z[m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // cout<<v[i][j]<<" ";
            z[j][v[i][j]]++;   
        }
        // cout<<endl;
    }

    vi pos[m];
    vi cur;
    for(int i=0;i<m;i++){   
        vii x;
        for(auto j:z[i])
            x.pb({j.ss,j.ff});
        sort(all(x),greater<pii>());

        cur.pb(x[0].ss);
        for(int j=0;j<min(x.size(),3);j++){
            for(int k=0;k<3-j;k++){
                pos[i].pb(x[j].ss);
            }
        }
    }


    if(check(v,cur)){
        cout<<"Yes"<<endl;
        printCur(cur);
        // for(auto i:cur)
            // cout<<i<<" ";
        cout<<endl;
        return 0;
    }

    for(int _=0;_<100;_++){
        vi z;
        for(int i=0;i<m;i++){
            shuffle(all(pos[i]),rng);
            z.pb(pos[i][0]);
        }
        if(check(v,z)){
            cout<<"Yes"<<endl;
            printCur(z);
            // for(auto i:cur)
                // cout<<i<<" ";
            cout<<endl;
            return 0;
        }

    }

    cout<<"No"<<endl;

   
    return 0;
}
signed main(){
    asdf
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}