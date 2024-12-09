#include<bits/stdc++.h>
#define maxe    1000000000
#define MOD   1000000007
#define hurry   ios_base::sync_with_stdio(false);cin.tie(NULL);
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma optimization_level 3
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//data type
#define ll long long int
#define ull unsigned long long int
#define ld                long double 
#define bigint            int64_t

#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
//set
#define si             set<int> 
#define spl            set< pair<ll,ll> >
#define spi            set< pair<int,int> >
#define spp            set< pair<pair<ll,ll>,ll> >

//pair
#define pll             pair<ll,ll>
#define pi              pai<int,int>

 //vector
#define  vvi            vector< vector<int> > v;
#define  vi             vector<int> v;
#define  vpii           vector< pair<int,int> >
#define vpl             vector< pair<ll,ll> >
#define all(v)          v.begin(),v.end()
#define MINIMUM(a)      *min_element(a.begin(), a.end())
#define MAXIMUM(a)      *max_element(a.begin(), a.end())
#define                  pb push_back
#define mp               make_pair




#define sz(a)            sizeof(a)
#define forn(i,n)        for(ll (i) = 0 ; (i) < (n) ; ++(i))
#define for1(i,n)        for(ll (i) = 1 ; (i) <= (n) ; ++(i))
using namespace std;

#define ps(y,x) fixed<<setprecision(y)<<x;
#define F first
#define S second
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)


#define FOREACH_FN(v, fn) for_each(ALL(v), myobject);

#define SORT(a) sort(a.begin(),a.end())
#define RSORT(a) sort(a.rbegin(),a.rend())
#define REV(a) reverse(a.begin(),a.end())
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

/// Trace
#define trace1(a)               cerr << #a << ": " << a << endl;
#define trace2(a,b)             cerr << #a << ": " << a << " | " << #b << ": " << b << endl;
#define trace3(a,b,c)           cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << endl;
#define trace4(a,b,c,d)         cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a,b,c,d,e)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a,b,c,d,e,f)     cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
 #define deb(x)           cout << #x << "=" << x << endl;




#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll


#define W(t)              while(t--)
#define forn(i,n)         for(ll (i) = 0 ; (i) < (n) ; ++(i))
#define for1(i,n)         for(ll (i) = 1 ; (i) <= (n) ; ++(i))
#define forr(i,n)         for(ll (i) = (n)-1 ; (i)>=0 ; --(i))
#define forab(i,a,b,c)    for(ll (i) = a ; (i) <= (b) ; (i)+=(c))
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define mp                make_pair
#define pb                push_back
int READ_INT(){int temp;cin>>temp;return temp;}      // read an int
ll READ_LONG(){ll temp;cin>>temp;return temp;}      // read a long long
string READ_STRING(){string temp;cin>>temp;return temp;}      // read a string

///templates///////


const long  double p = 3.14159265358979323846;
const long long INF=2e+5;
const int N =2e+5;
#define mod 998244353;
long long int inverse(long long int i){
    if(i==1) return 1;
    return (MOD - ((MOD/i)*inverse(MOD%i))%MOD+MOD)%MOD;
}
ll POW(ll a,ll b)
{
    if(b==0) return 1;
    if(b==1) return a%MOD;
    ll temp=POW(a,b/2);
    if(b%2==0) return (temp*temp)%MOD;
    else return (((temp*temp)%MOD)*a)%MOD;
}


/*vector<int> isprime(N,1);
vector<int> primes;


void seive()
{
for (int i = 2; i <= N; i++) {
    if (isprime[i] && (long long)i * i <= N) {
        for (int j = i * i; j <= N; j += i)
            isprime[j] = 0;
    }
}

for(int i=2;i<=N;i++)
{
    if(isprime[i])
        primes.pb(i);
}
}*/

void bootcoder()
{
    
//check N (space)
// check integer overflow
// check corner cases

int x;


cin>>x;
int pos,ans;

for(int i=0;i<=x;i++)
{
	if(((i*(i+1)*1ll)/2)>=x)
		{  pos=i;
			break;
		}
}
ans=(pos*(pos+1)*1ll)/2;
//cout<<ans<<pos<<'\n';
int rem=ans-x;
if(rem==1)
{
	cout<<pos+1<<"\n";
}
else
{
cout<<pos<<'\n';
}
}








int main()

{
hurry;
#ifndef ONLINE_JUDGE
 freopen("inputs.txt", "r",stdin);
 freopen("oss.txt","w",stdout);
#endif
int test;
      
cin>>test;

    
//test=1;
W(test)
{

bootcoder();
}
}









