#include "bits/stdc++.h"
using namespace std;
#define mod 1000000007
#define umap unordered_map
#define uset unordered_set
#define umset unordered_multiset
#define ummap unordered_multimap
#define sbitc(n) __builtin_popcount(n)
#define PI 3.141592653589793238462
#define imax INT_MAX
#define llmax INT64_MAX-100
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mkp make_pair
#define dyarr(size) int *arr{new int[size]{}}
#define popb pop_back
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())     
#define nline "\n"
#define ff first
#define ss second
#define loop(i, a, b) for(int i = a; i<=b; i++)
#define revl(i, a, b) for(int i = a; i>=b; i--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#ifndef ONLINE_JUDGE
    #define file  freopen("Error.txt", "w", stderr);freopen("input.txt", "r", stdin ); freopen("output.txt", "w", stdout);
    #define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
    #define debug(x)
    #define file
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef long l;
/*-----------------------------------------------------------------------------------------------------------------------------------*/
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll mexpo(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
vector<int> prime;
void seive(ll n){int lp[n+1];for (int i=2; i<=n; ++i) {if (lp[i] == 0) {lp[i] = i;prime.push_back (i);}for (int j=0; j<(int)prime.size() && prime[j]<=lp[i] && i*prime[j]<=n; ++j)lp[i * prime[j]] = prime[j];}}

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/
ll find(ll num)
{
	//ll count = num - 1;
	ll count = 0;
	ll dig = log10(num);
	ll nine = 0;
	string s = to_string(num);
	int i = 0;
	while(dig > 0)
	{
		count+=dig*(s[i]-'0')+(nine*dig);	
		nine += (nine*9+(s[i]-'0')*9);
		dig--;
		i++;
	}
	count+=(num-1);
	return count;
}
int main()
{
    clock_t begin = clock();
    fastio;
    
    file;
    // write you code here
    int T;
    cin>>T;
    while(T--)
    {
		ll l, r;
		cin>>l>>r;
		ll count = find(r)-find(l);
		cerr<<find(r)<< nline;
		cerr<<find(l)<< nline;
		cout<< count<< nline;
    }



    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted In: "<< double(end-begin)/ CLOCKS_PER_SEC<< "sec";
    #endif
    return 0;
}  