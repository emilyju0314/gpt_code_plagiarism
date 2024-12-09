#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")

#define ios               ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define rev(x)            (x).rbegin(),(x).rend()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
#define max3(a,b,c)       max(max(a,b),c)
#define max4(a,b,c,d)     max(max(a,b),max(c,d))
#define min3(a,b,c)       min(min(a,b),c)
#define min4(a,b,c,d)     min(min(a,b), min(c,d))
#define poss(flag)        cout << (flag ? "YES\n" : "NO\n")
template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
 
const int inf = 1000000000000000000;
const long double pi = 3.14159265358979323846264338;
const long long mod = 1000000007;
 
 
int pow(int x, unsigned int y, int p){
    int res=1;
    x=x%p;
    if (x==0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int _pow(int a, int b){
    if(!b)
        return 1;
    int temp = _pow(a, b / 2);
    temp = (temp * temp);
    if(b % 2)
        return (a * temp);
    return temp;
}
 
int invmod(int a,int m){
    return pow(a,m-2,m);
}
int cl(int a,int x){
    if(a%x==0)
        return a/x;
    else
        return a/x+1;
}
void ins(vector<int> &v, int n){
    int y = v.size();
    int ind = lower_bound(v.begin(), v.end(), n) - v.begin();
    if(v[y-1] > n) v.push_back(v[y-1]);
    else{
        v.push_back(n);
        return;
    }
    for(int i = y-1; i>ind; i--){
        v[i] = v[i-1];
    }
    v[ind] = n;
}
void swap(vector<int> &a, int n){
    for(int i = 0; i<n; i++){
        int temp = a[i];
        a[i] = a[n+i];
        a[n+i] = temp;
    }
    return;
}

void swapadj(vector<int> &a, int n){
    for(int i = 0; i<2*n; i+=2){
        int temp = a[i];
        a[i] = a[i+1];
        a[i+1] = temp;
    }
}
int fac(int n){
    int ans = 1;
    for(int i = 2; i<=n; i++){
        ans = (1LL*ans*i)%mod;
    }
    return ans;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);     
} 
int max(int a, int b) { return (a > b) ? a : b; }

void solve(){
    int k;
    cin >> k;
    int w = 100-k;
    int u = gcd(k,w);
    k/=u;
    w/=u;
    cout << k+w << endl;
}
signed main(){
    ios
    int tt = 1;
    cin >> tt;
    while(tt--)
       solve();
    return 0;
}